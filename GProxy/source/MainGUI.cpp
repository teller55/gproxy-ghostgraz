#include "MainGUI.h"
#include "gproxy.h"
#include "bnet.h"
#include "delegate/ChannellistDelegate.h"
#include "delegate/GamelistDelegate.h"
#include "socket.h"
#include "thread/DownloadThread.h"
#include "ConfigGUI.h"
#include "GhostGrazLogininformationDialog.h"
#include "Util.h"

#include <QDesktopWidget>
#include <QScrollBar>
#include <QIcon>
#include <QMessageBox>
#include <QIcon>
#include <QProcess>
#include <QSound>
#include <QTimer>
#include <QFile>
#include <QDateTime>
#include <QClipboard>
#include <QFileInfo>
#include <QRegExp>
#include <QTextFrame>

MainGUI::MainGUI (CGProxy *p_gproxy)
{
    widget.setupUi(this);
    gproxy = p_gproxy;
}

MainGUI::~MainGUI ()
{
    delete statspage;
}

void MainGUI::onClose ()
{
    Config* config = gproxy->getConfig();
    config->setInt("width", this->width());
    config->setInt("height", this->height());
    config->commit();

    gproxy->cleanup();
}

void MainGUI::init ()
{
    Config *config = gproxy->getConfig();

    QDesktopWidget *desktop = QApplication::desktop();

    int screenWidth = desktop->width();
    int screenHeight = desktop->height();
    int appWidth = config->getInt("width");
    int appHeight = config->getInt("height");

    if (appWidth < 500 || appHeight < 200)
    {
        this->move((screenWidth - this->width()) / 2,
                (screenHeight - this->height()) / 2 - 50);
    }
    else
    {
        this->setGeometry((screenWidth - this->width()) / 2,
                (screenHeight - this->height()) / 2 - 50, appWidth, appHeight);
    }

    widget.channelList->setItemDelegate(new ChannellistDelegate(this));
    widget.gameList->setItemDelegate(new GamelistDelegate());

    QAction *startWarcraftAction = widget.menuBar->addAction("Start Warcraft");
    connect(startWarcraftAction, SIGNAL(activated()),
            this, SLOT(startWarcraft()));

    initStatspage();
    initLayout();
    initSlots();
}

void MainGUI::initStatspage ()
{
    statspage = new Statspage();

    connect(statspage, SIGNAL(loginFinished()),
            this, SLOT(statspageLoginFinished()));
    connect(statspage, SIGNAL(playerInformationReplyFinished(Player *)),
            this, SLOT(receivedPlayerInformation(Player *)));
    connect(statspage, SIGNAL(adminlistReplyFinished(QList<QString>)),
            this, SLOT(onAdminlistReceived(QList<QString>)));

    Config* config = gproxy->getConfig();
    QString ghostgrazUsername = config->getString("ghostgrazUsername");
    QString ghostgrazPassword = config->getString("ghostgrazPassword");

    if (ghostgrazUsername.isEmpty() && ghostgrazPassword.isEmpty()
            && config->hasRequiredValues())
    {
        GhostGrazLogininformationDialog *dialog =
                new GhostGrazLogininformationDialog(gproxy->getConfig(), statspage);
        dialog->setModal(true);
        dialog->show();
    }
    else
    {
        statspage->login(ghostgrazUsername, ghostgrazPassword);
    }
}

void MainGUI::initLayout ()
{
    int inputFieldHeight = 60;
    int channelfieldWidth = 200;
    int channelfieldHeight = 25;
    int gamelistWidth = 220;

    widget.refreshButton->setMinimumSize(gamelistWidth, channelfieldHeight);
    widget.refreshButton->setMaximumSize(gamelistWidth, channelfieldHeight);
    widget.refreshButton->move(width() - channelfieldWidth - gamelistWidth, 0);

    widget.titleLabel->setMinimumSize(channelfieldWidth, channelfieldHeight);
    widget.titleLabel->setMaximumSize(channelfieldWidth, channelfieldHeight);
    widget.titleLabel->move(width() - channelfieldWidth, 0);

    widget.channelList->setMinimumSize(channelfieldWidth,
            (height() - inputFieldHeight - channelfieldHeight) / 2);
    widget.channelList->setMaximumSize(channelfieldWidth,
            (height() - inputFieldHeight - channelfieldHeight) / 2);
    widget.channelList->move(width() - channelfieldWidth, channelfieldHeight);

    widget.friendList->setMinimumSize(channelfieldWidth,
            (height() - inputFieldHeight - channelfieldHeight) / 2);
    widget.friendList->setMaximumSize(channelfieldWidth,
            (height() - inputFieldHeight - channelfieldHeight) / 2);
    widget.friendList->move(width() - channelfieldWidth, channelfieldHeight +
            (height() - inputFieldHeight - channelfieldHeight) / 2);

    widget.gameList->setMinimumSize(gamelistWidth, height() - inputFieldHeight - channelfieldHeight);
    widget.gameList->setMaximumSize(gamelistWidth, height() - inputFieldHeight - channelfieldHeight);
    widget.gameList->move(width() - channelfieldWidth - gamelistWidth, channelfieldHeight);

    widget.inputTextArea->setMinimumSize(width(), inputFieldHeight);
    widget.inputTextArea->setMaximumSize(width(), inputFieldHeight);
    widget.inputTextArea->move(0, height() - inputFieldHeight);

    widget.outputTextArea->setMinimumSize(width() - channelfieldWidth - gamelistWidth, height() - inputFieldHeight);
    widget.outputTextArea->setMaximumSize(width() - channelfieldWidth - gamelistWidth, height() - inputFieldHeight);
    widget.outputTextArea->move(0, 0);
}

void MainGUI::initSlots ()
{
    connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(onClose()), Qt::QueuedConnection);
    connect(widget.outputTextArea->verticalScrollBar(), SIGNAL(rangeChanged(int, int)),
            this, SLOT(onOutputFieldSliderMoved()), Qt::QueuedConnection);
}

void MainGUI::initAdminlist ()
{
    statspage->getAdminlist();
}

void MainGUI::applyConfig()
{
    Config* config = gproxy->getConfig();

    // Set color
    QPalette palette = widget.centralwidget->palette();

    palette.setColor(QPalette::Base, config->getColor("backgroundcolor"));

    widget.centralwidget->setPalette(palette);
    widget.titleLabel->setPalette(palette);

    // Set font
    widget.outputTextArea->setFont(config->getFont("outputareaFont"));
}

void MainGUI::setColor(const QString& area, const QPalette::ColorRole& colorRole, const QColor& color)
{
    if (area == "all")
    {
        QPalette palette = widget.centralwidget->palette();
        palette.setColor(colorRole, color);
        widget.centralwidget->setPalette(palette);
        widget.titleLabel->setPalette(palette);
    }
}

void MainGUI::setFont(const QString& area, const QFont& font)
{
    if (area == "outputarea")
    {
        widget.outputTextArea->setFont(font);
    }
}

void MainGUI::resizeEvent (QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    initLayout();
}

void MainGUI::onInputTextAreaTextChanged ()
{
    if (widget.inputTextArea->toPlainText().contains("\n")
            && widget.inputTextArea->toPlainText().size() > 1)
    {
        QString input = widget.inputTextArea->toPlainText();
        input.replace("\n", "");

        widget.inputTextArea->setPlainText("");

        processInput(input);
    }
    else if (widget.inputTextArea->toPlainText().toLower() == "/r "
            && !gproxy->m_BNET->GetReplyTarget().empty())
    {
        widget.inputTextArea->setPlainText("/w "
                + QString::fromStdString(gproxy->m_BNET->GetReplyTarget()) + " ");
        widget.inputTextArea->moveCursor(QTextCursor::End);
    }
}

void MainGUI::onTitleLabelTextChanged ()
{
    QString text = widget.titleLabel->text();
    QFont font = widget.titleLabel->font();
    font.setPointSize(12);
    QFontMetrics *fm = new QFontMetrics(font);
    int width = widget.titleLabel->width();

    while (fm->boundingRect(text).width() >= width)
    {
        font.setPointSize(font.pointSize() - 1);
        fm = new QFontMetrics(font);
    }

    widget.titleLabel->setFont(font);
}

void MainGUI::onChannelContextMenu (const QPoint& pos)
{
    QPoint globalPos = widget.channelList->mapToGlobal(pos);
    QListWidgetItem* item = widget.channelList->itemAt(pos);

    if (!item)
    {
        return;
    }

    QString user = item->data(ChannellistDelegate::USER).toString();

    QMenu menu;

    if (gproxy->m_BNET->GetInGame())
    {
        if (user == "The Sentinel" || user == "The Scourge" || user.startsWith("Team "))
        {
            menu.addAction(QIcon(":/images/Play.png"), "Change team");
        }
        else if (item->data(ChannellistDelegate::SLOT_STATUS).toInt() == 2
                && item->data(ChannellistDelegate::SLOT_COMPUTER_STATUS).toInt() == 0)
        {
            menu.addAction(QIcon(":/images/Mail.png"), "Whisper");
            menu.addAction(QIcon(":/images/Add.png"), "Add as friend");
            menu.addAction(QIcon(":/images/Applications.png"), "Copy name");
            menu.addAction(QIcon(":/images/Edit.png"), "!stats");
            menu.addAction(QIcon(":/images/Edit Alt.png"), "!statsdota");
        }
    }
    else
    {
        menu.addAction(QIcon(":/images/Mail.png"), "Whisper");
        menu.addAction(QIcon(":/images/User.png"), "Whois");
        menu.addAction(QIcon(":/images/Applications.png"), "Copy name");
        menu.addAction(QIcon(":/images/Add.png"), "Add as friend");
    }

    QAction* action = menu.exec(globalPos);
    if (action)
    {
        if (action->text() == "Whisper")
        {
            widget.inputTextArea->setPlainText("/w " + user + " ");
            widget.inputTextArea->setFocus();
            widget.inputTextArea->moveCursor(QTextCursor::End);
        }
        else if (action->text() == "Whois")
        {
            gproxy->m_BNET->QueueChatCommand("/whois " + user, false);
        }
        else if (action->text() == "!stats" || action->text() == "!statsdota")
        {
            gproxy->sendGamemessage(action->text() + " " + user);
        }
        else if (action->text() == "Change team")
        {
            int team;

            if (user == "The Sentinel")
            {
                team = 0;
            }
            else if (user == "The Scourge")
            {
                team = 1;
            }
            else
            {
                team = user.mid(5).toInt();
            }

            gproxy->changeTeam(team);
        }
        else if (action->text() == "Copy name")
        {
            QApplication::clipboard()->setText(user);
        }
        else if (action->text() == "Add as friend")
        {
            gproxy->m_BNET->QueueChatCommand("/friends add " + user, false);
            gproxy->m_BNET->UpdateFriendList();
        }
        else
        {
            addMessage("[ERROR] Not yet implemented!", false);
        }
    }
}

void MainGUI::onFriendsContextMenu (const QPoint& pos)
{
    QPoint globalPos = widget.friendList->mapToGlobal(pos);
    QListWidgetItem* item = widget.friendList->itemAt(pos);

    if (!item)
    {
        return;
    }

    QMenu menu;
    menu.addAction(QIcon(":/images/Mail.png"), "Whisper");
    menu.addAction(QIcon(":/images/User.png"), "Whois");
    menu.addAction(QIcon(":/images/Chat Bubble.png"), "Whisper all");
    menu.addAction(QIcon(":/images/Remove.png"), "Remove friend");

    if (gproxy->m_BNET->GetInGame())
    {
        menu.addAction(QIcon(":/images/Edit.png"), "!stats");
        menu.addAction(QIcon(":/images/Edit Alt.png"), "!statsdota");
    }

    QAction* action = menu.exec(globalPos);
    if (action)
    {
        if (action->text() == "Whisper")
        {
            widget.inputTextArea->setPlainText("/w " + item->text() + " ");
            widget.inputTextArea->setFocus();
            widget.inputTextArea->moveCursor(QTextCursor::End);
        }
        else if (action->text() == "Whois")
        {
            gproxy->m_BNET->QueueChatCommand("/whois " + item->text(), false);
        }
        else if (action->text() == "Whisper all")
        {
            widget.inputTextArea->setPlainText("/f m ");
            widget.inputTextArea->setFocus();
            widget.inputTextArea->moveCursor(QTextCursor::End);
        }
        else if (action->text() == "!stats" || action->text() == "!statsdota")
        {
            gproxy->sendGamemessage(action->text() + " " + item->text());
        }
        else if (action->text() == "Remove friend")
        {
            gproxy->m_BNET->QueueChatCommand("/friends remove "
                    + item->text(), false);
            gproxy->m_BNET->UpdateFriendList();
        }
        else
        {
            addMessage("[ERROR] Not yet implemented!", false);
        }
    }
}

void MainGUI::onGameListItemClicked (QMouseEvent *mouseEvent)
{
    widget.inputTextArea->setFocus();

    QListWidgetItem *item = widget.gameList->itemAt(mouseEvent->pos());
    if (!item)
    {
        return;
    }

    QString gamename = item->data(GamelistDelegate::GAMENAME).toString();

    if (mouseEvent->button() == Qt::LeftButton && !gamename.isEmpty()
            && gamename != "-" && gamename != "in channel ghostgraz")
    {
        gproxy->m_BNET->SetSearchGameName(gamename.toStdString());
        autosearch(false);
        addMessage("[BNET] looking for a game named \"" + gamename
                + "\" for up to two minutes");
    }
    else if (mouseEvent->button() == Qt::RightButton)
    {
        QApplication::clipboard()->setText(gamename);
    }
}

void MainGUI::onOutputFieldSliderMoved ()
{
    QScrollBar* vsb = widget.outputTextArea->verticalScrollBar();
    if (vsb->value() >= (vsb->maximum() - vsb->singleStep() * 2))
    {
        vsb->setValue(vsb->maximum());
    }
}

void MainGUI::onRefreshButtonClicked ()
{
    widget.refreshButton->setEnabled(false);

    DownloadThread *dt = new DownloadThread(this);
    dt->refresh();

    widget.refreshButton->setText("Refresh (10)");
    QTimer::singleShot(1000, this, SLOT(updateRefreshButton()));
}

void MainGUI::updateRefreshButton ()
{
    QString text = widget.refreshButton->text();
    int secondsLeft = text.mid(9, text.length() - 10).toInt();

    if (secondsLeft != 1)
    {
        widget.refreshButton->setText("Refresh ("
                + QString::number(secondsLeft - 1) + ")");
        QTimer::singleShot(1000, this, SLOT(updateRefreshButton()));
    }
    else
    {
        widget.refreshButton->setText("Refresh");
        widget.refreshButton->setEnabled(true);
    }
}

void MainGUI::processInput (const QString& input)
{
    QString command = input.toLower();

    if (command == "/commands")
    {
        addMessage(">>> /commands", false);
        addMessage("", false);
        addMessage("  In the GProxy++ console:", false);
        addMessage("   /commands           : show command list", false);
        addMessage("   /exit or /quit      : close GProxy++", false);
        addMessage("   /filter <f>         : start filtering public game names for <f>", false);
        addMessage("   /filteroff          : stop filtering public game names", false);
        addMessage("   /game <gamename>    : look for a specific game named <gamename>", false);
        addMessage("   /help               : show help text", false);
        addMessage("   /public             : enable listing of public games", false);
        addMessage("   /publicoff          : disable listing of public games", false);
        addMessage("   /r <message>        : reply to the last received whisper", false);
        addMessage("   /pgn <privgamename> : sets privategamename temporary to <privgamename> (Alias: /privategamename)", false);
        addMessage("   /waitgame <option>  : waits for a bot joining channel with the name-prefix set in gproxy.cfg and hosts", false);
        addMessage("                         a private game named <value of privategamename> (Alias: /wg <option>", false);
        addMessage("   Optons:   quiet     : doesn't display the message to other users in the channel (Alias: q)", false);
        addMessage("             off       : stops waiting for a bot to host a game", false);
        addMessage("", false);
        addMessage("   /botprefix <prefix> : sets <value of botprefix> temporary to <prefix>", false);
        addMessage("   /parrot <plname>    : repeats anything that Player <plname> sais in Chat with [PARROT] <Player's message>", false);
        addMessage("   /parrotall          : repeats anything that Players say in Chat with [PARROT] <Player's message>", false);
        addMessage("   /parrotoff          : stops /parrot and /parrotall", false);
#ifdef WIN32
        addMessage("   /start              : start warcraft 3", false);
#endif
        addMessage("   /version            : show version text", false);
        addMessage("", false);
        addMessage("  In game:", false);
        addMessage("   /re <message>       : reply to the last received whisper", false);
        addMessage("   /sc                 : whispers \"spoofcheck\" to the game host", false);
        addMessage("   /status             : show status information", false);
        addMessage("   /w <user> <message> : whispers <message> to <user>", false);
        addMessage("", false);
    }
    else if (command == "/exit" || command == "/quit")
    {
        close();
        return;
    }
    else if (command.startsWith("/friends ") || command.startsWith("/f "))
    {
        gproxy->m_BNET->QueueChatCommand(input);
        gproxy->m_BNET->UpdateFriendList();
    }
    else if (command == "/filteroff" || command == "/filter off")
    {
        gproxy->m_BNET->SetPublicGameFilter(string());
        addMessage("[BNET] stopped filtering public game names");
    }
    else if (command.length() >= 9 && command.startsWith("/filter "))
    {
        QString filter = input.mid(8);

        if (!filter.isEmpty())
        {
            filter = filter.left(31);
            gproxy->m_BNET->SetPublicGameFilter(filter.toStdString());
            addMessage("[BNET] started filtering public game names for \"" + filter + "\"");
        }
    }
    else if (command.startsWith("/priv ") && command.length() >= 7
            && !gproxy->getPrivategamename().isEmpty())
    {
        QString botname = input.mid(6);
        if (!botname.isEmpty() && botname.length() <= 15)
        {
            QString pgn = gproxy->getPrivategamename();
            if (botname.length() > 2)
            {
                gproxy->m_BNET->QueueChatCommand("/w " + botname + " !priv " + pgn);
            }
            else
            {
                gproxy->m_BNET->QueueChatCommand("/w " + gproxy->getBotprefix()
                        + botname + " !priv " + pgn);
            }
            gproxy->m_BNET->SetSearchGameName(pgn.toStdString());
            autosearch(true);
            addMessage("[BNET] try to create a private game named ["
                    + pgn + "] at Bot ["
                    + botname + "].");
        }
    }
    else if (command.startsWith("/autosearch") || command.startsWith("/as"))
    {
        if (command == "/autosearch" || command == "/as")
        {
            if (gproxy->autosearch)
            {
                addMessage("[Pr0gm4n] 'autosearch' is on.");
            }
            else
            {
                addMessage("[Pr0gm4n] 'autosearch' is off.");
            }
        }
        else if (command == "/autosearch on" || command == "/as on")
        {
            autosearch(true);
            addMessage("[Pr0gm4n] Autosearch enabled.");
        }
        else if (command == "/autosearch off" || command == "/as off")
        {
            autosearch(false);
            addMessage("[Pr0gm4n] Autosearch disabled.");
        }
        else
        {
            addMessage("[Pr0gm4n] Invalid input.");
        }
    }
    else if (command == "/privategamename" || command == "/pgn")
    {
        addMessage("[Phyton] The value of 'privategamename' is: ["
                + gproxy->getPrivategamename() + "]. Change it with the input "
                + "'/privategamename <value>' alias '/pgn <value>'.");
    }
    else if (command.startsWith("/privategamename ") || command.startsWith("/pgn "))
    {
        if (command.startsWith("/privategamename "))
        {
            gproxy->setPrivategamename(input.mid(17, (input.length() - 17)));
        }
        else
        {
            gproxy->setPrivategamename(input.mid(5, (input.size() - 5)));
        }

        addMessage("[Phyton] Change value of 'privategamename' to ["
                + gproxy->getPrivategamename() + "].");

    }
    else if (command == "/botprefix")
    {
        addMessage("[Phyton] Value of 'botprefix' is ["
                + gproxy->getBotprefix()
                + "]. You can change it with '/botprefix <value>'.");
    }
    else if (command.startsWith("/botprefix "))
    {
        gproxy->setBotprefix(input.mid(11, input.size() - 11));
        addMessage("[Phyton] Change value of 'botprefix' to ["
                + gproxy->getBotprefix() + "].");
    }
    else if (command.startsWith("/wg"))
    {
        if (command == "/wg")
        {
            gproxy->setVShallCreateQuiet(false);
            gproxy->setVShallCreate(true);
            addMessage("[Phyton] waiting for a bot and then trying to create a game "
                    "and say [gn: " + gproxy->getPrivategamename() + "].");
            gproxy->m_BNET->QueueChatCommand("[GProxy++][Phyton] Waiting for a bot "
                    "and create a game with the name ["
                    + gproxy->getPrivategamename() + "].");
        }
        else if (command == "/wg off")
        {
            addMessage("[Phyton] stopped waiting for a bot to create a game.");
            gproxy->setVShallCreate(false);
        }
        else if (command == "/wg quiet" || command == "/wg q")
        {
            gproxy->setVShallCreate(true);
            gproxy->setVShallCreateQuiet(true);
            addMessage("[Phyton] waiting for a bot and then trying to create a game [quiet].");
        }
    }
    else if (command.startsWith("/waitgame") && gproxy->getBotprefix() != "")
    {
        if (command == "/waitgame")
        {
            gproxy->setVShallCreateQuiet(false);
            gproxy->setVShallCreate(true);
            addMessage("[Phyton] waiting for a bot and then trying to create a game "
                    "and say [gn: " + gproxy->getPrivategamename() + "].");
            gproxy->m_BNET->QueueChatCommand("[GProxy++][Phyton] Waiting for a bot "
                    "and create a game with the name ["
                    + gproxy->getPrivategamename() + "].");
        }
        else if (command == "/waitgame off")
        {
            addMessage("[Phyton] stopped waiting for a bot to create a game.");
            gproxy->setVShallCreate(false);
        }
        else if (command == "/waitgame quiet")
        {
            gproxy->setVShallCreate(true);
            gproxy->setVShallCreateQuiet(true);
            addMessage("[Phyton] waiting for a bot and then trying to create a game [quiet].");
        }
    }
    else if (command.startsWith("/parrot "))
    {
        gproxy->setParrot(input.mid(8, input.length() - 8));
        addMessage("[Phyton] Parrot [" + gproxy->getParrot() + "]!!!111");
    }
    else if (command == "/parrotoff")
    {
        gproxy->setParrot("");
        addMessage("[Phyton] Parrot off");
    }
    else if (input == "/parrotall")
    {
        gproxy->setParrot("Parrot parrot");
    }
    else if (input == "/parrotignore")
    {
        gproxy->setParrot("Ignore ignore");
    }
    else if (command.length() >= 7 && command.startsWith("/game "))
    {
        string GameName = input.mid(6).toStdString();

        if (!GameName.empty() && GameName.size() <= 31)
        {
            gproxy->m_BNET->SetSearchGameName(GameName);
            autosearch(false);
            addMessage("[BNET] looking for a game named \"" + QString::fromStdString(GameName)
                    + "\" for up to two minutes");
        }
    }
    else if (command == "/help")
    {
        addMessage(">>> /help", false);
        addMessage("", false);
        addMessage("  GProxy++ connects to battle.net and looks for games for you to join.", false);
        addMessage("  If GProxy++ finds any they will be listed on the Warcraft III LAN screen.", false);
        addMessage("  To join a game, simply open Warcraft III and wait at the LAN screen.", false);
        addMessage("  Standard games will be white and GProxy++ enabled games will be blue.", false);
        addMessage("  Note: You must type \"/public\" to enable listing of public games.", false);
        addMessage("", false);
        addMessage("  If you want to join a specific game, type \"/game <gamename>\".", false);
        addMessage("  GProxy++ will look for that game for up to two minutes before giving up.", false);
        addMessage("  This is useful for private games.", false);
        addMessage("", false);
        addMessage("  Please note:", false);
        addMessage("  GProxy++ will join the game using your battle.net name, not your LAN name.", false);
        addMessage("  Other players will see your battle.net name even if you choose another name.", false);
        addMessage("  This is done so that you can be automatically spoof checked.", false);
        addMessage("", false);
        addMessage("  Type \"/commands\" for a full command list.", false);
        addMessage("", false);
    }
    else if (command == "/public" || command == "/publicon" || command == "/public on"
            || command == "/list" || command == "/liston" || command == "/list on")
    {
        gproxy->m_BNET->SetListPublicGames(true);
        addMessage("[BNET] listing of public games enabled");
    }
    else if (command == "/publicoff" || command == "/public off"
            || command == "/listoff" || command == "/list off")
    {
        gproxy->m_BNET->SetListPublicGames(false);
        addMessage("[BNET] listing of public games disabled");
    }
    else if (command.length() >= 4 && command.startsWith("/r "))
    {
        if (!gproxy->m_BNET->GetReplyTarget().empty())
        {
            gproxy->m_BNET->QueueChatCommand(input.mid(3),
                    gproxy->m_BNET->GetReplyTarget(), true);
        }
        else
            addMessage("[BNET] nobody has whispered you yet");
    }
#ifdef WIN32
    else if (command == "/start")
    {
        startWarcraft();
    }
#endif
    else if (command == "/version")
    {
        addMessage("[GPROXY] Customized GProxy++ Version " + QString::fromStdString(gproxy->m_Version));
        addMessage("[GPROXY] |CFFE6E6E6"
                "This mod is by |CFF006400Phyton|r, "
                "|CFFFF1493Pr0gm4n|r and "
                "|CFFFFD700Manufactoring|r.");
    }
    else if (command == "/test")
    {
        // Isn't it obvious?
    }
    else if (command.startsWith("/p ") || command.startsWith("/phrase "))
    {
        QString filePath = "phrase/";

        if (command.startsWith("/p "))
        {
            filePath.append(command.mid(3));
        }
        else if (command.startsWith("/phrase "))
        {
            filePath.append(command.mid(8));
        }

        if (!filePath.endsWith(".txt"))
        {
            filePath.append(".txt");
        }

        QFile* phraseFile = new QFile(filePath);

        if (phraseFile->open(QFile::ReadOnly))
        {
            QStringList lines = QString(phraseFile->readAll()).split("\n");

            foreach(QString line, lines)
            {
                if (gproxy->m_BNET->GetInGame() && !line.startsWith("#"))
                {
                    if (!line.startsWith("%"))
                    {
                        if (!line.startsWith("~"))
                        {
                            gproxy->sendGamemessage(line);
                        }
                        else
                        {
                            // Sleep
                        }
                    }
                    else
                    {
                        gproxy->m_BNET->QueueChatCommand(line.mid(1));
                    }
                }
                else if (!line.startsWith("#"))
                {
                    gproxy->m_BNET->QueueChatCommand(line);
                }
            }
        }
        else
        {
            CONSOLE_Print("[ERROR] File \"" + filePath + "\" does not exist!");
            gproxy->SendLocalChat("File \"" + filePath + "\" does not exist!");
        }
    }
    else if (gproxy->m_BNET->GetInGame())
    {
        if (command == "/statslast" || command == "/sl"
                || command == "!statslast" || command == "!sl")
        {
            gproxy->sendGamemessage("!stats " + gproxy->getLastLeaver()->getName());
        }
        else if (command.startsWith("/allies "))
        {
            gproxy->sendGamemessage(input.mid(8), true);
        }
        else
        {
            gproxy->sendGamemessage(input);
        }
    }
    else
    {
        gproxy->m_BNET->QueueChatCommand(input);
    }
}

void MainGUI::addMessage (QString message, bool log)
{
    if (log)
    {
        LOG_Print(message);
    }

    widget.outputTextArea->moveCursor(QTextCursor::End);

    addColor(message);
    QString dateTime = QLocale().toString(QDateTime::currentDateTime(), "[hh:mm:ss] ");
    message.insert(10, dateTime);
    if (!widget.outputTextArea->textCursor().atStart())
    {
        message.insert(0, "\n");
    }

    // Print the message colored, if it contains a Warcraft like color code: "|cFF00FF00|r".
    QRegExp colorCodeRegExp = QRegExp("\\|c([a-f]|[0-9]){8}");
    colorCodeRegExp.setCaseSensitivity(Qt::CaseInsensitive);
    int i = 0;
    while (message.indexOf(colorCodeRegExp, i) != -1)
    {
        int colorStartIndex = message.indexOf(colorCodeRegExp, i);
        widget.outputTextArea->insertPlainText(message.mid(i, colorStartIndex - i));
        widget.outputTextArea->setTextColor(Util::toColor(message.mid(colorStartIndex, 10)));
        i = colorStartIndex + 10;

        if (message.indexOf("|r", i, Qt::CaseInsensitive) != -1)
        {
            int colorEndIndex = message.indexOf("|r", i, Qt::CaseInsensitive);
            int nextColorStartIndex = message.indexOf(colorCodeRegExp, i);
            if (nextColorStartIndex == -1 || nextColorStartIndex > colorEndIndex)
            {
                widget.outputTextArea->insertPlainText(message.mid(i, colorEndIndex - i));
                widget.outputTextArea->setTextColor(QColor(230, 230, 230));
                i = colorEndIndex + 2;
            }
        }
    }

    widget.outputTextArea->insertPlainText(message.mid(i));
    widget.outputTextArea->setTextColor(QColor(230, 230, 230));
}

void MainGUI::addColor (QString& message)
{
    if (message.startsWith("[WHISPER]")
            || message.startsWith("[QUEUED] /w ")
            || message.startsWith("[WHISPER TO]"))
    {
        message.prepend("|CFF00FF00");
    }
    else if (message.startsWith("[Phyton]")
            || message.startsWith("[Pr0gm4n]")
            || message.startsWith("[CONFIG]")
            || message.startsWith("Bot ["))
    {
        message.prepend("|CFF006400");
    }
    else if (message.startsWith("[Manufactoring]"))
    {
        message.prepend("|CFFFFD700");
    }
    else if (message.startsWith("[LOCAL]"))
    {
        // removing "[LOCAL] "
        message.remove(0, 8);

        // special coloring only for the chiefs
        if (message.startsWith("[baerli_graz]")
                || message.startsWith("[klingone_graz]"))
        {
            message.insert(1, "|CFFFF0000");
            message.insert(message.indexOf("]"), "|r");
        }

        message.prepend("|CFFE6E6E6");
    }
    else if (message.startsWith("[QUEUED]"))
    {
        // replacing "QUEUED" with the username
        message = "[" + QString::fromStdString(gproxy->m_BNET->m_UserName) + "]"
                + message.mid(8, message.size() - 8);

        // special coloring only for the chiefs
        if (message.startsWith("[baerli_graz]")
                || message.startsWith("[klingone_graz]"))
        {
            message.insert(1, "|CFFFF0000");
            message.insert(message.indexOf("]"), "|r");
        }

        message.prepend("|CFFE6E6E6");
    }
    else if (message.startsWith("[INFO]"))
    {
        message.remove(0, 7);
        message.prepend("|CFF00FFFF");
    }
    else if (message.startsWith("[TCPSOCKET]"))
    {
        message.prepend("|CFF4B0082");
    }
    else if (message.startsWith("[GPROXY]")
            || message.startsWith("[UDPSOCKET]"))
    {
        message.prepend("|CFF4B0082");
    }
    else if (message.startsWith("[BNET]"))
    {
        message.prepend("|CFF8B0000");
    }
    else if (message.startsWith("[EMOTE]"))
    {
        message.remove(0, 8);
        message.prepend("|CFF808080");
    }
    else if (message.endsWith(" has joined the game.")
            || message.endsWith(" has left the game."))
    {
        message.prepend("|CFFFFD700");
        message.insert(message.indexOf(" has "), "|CFFFFD700");
    }
    else if (message.startsWith("[ERROR]")
            || message.startsWith("[Manufactoring][ERROR]"))
    {
        message.prepend("|CFFFF0000");
    }
    else if (message.startsWith("[WARNING]"))
    {
        message.prepend("|CFFFF4500");
    }
    else
    {
        message.prepend("|CFFE6E6E6");
    }
}

void MainGUI::addColor (QListWidgetItem *item)
{
    QString username = item->data(ChannellistDelegate::USER).toString();

    if (username == "baerli_graz" || username == "klingone_graz")
    {
        item->setData(ChannellistDelegate::COLOR_USER, QColor(255, 0, 0));
        item->setToolTip("Creator of GhostGraz");
    }
    else if (username.startsWith("GhostGraz"))
    {
        item->setData(ChannellistDelegate::COLOR_USER, QColor(255, 255, 0));
        item->setToolTip("GhostGraz bot");
    }
    else if (username == "Phyton" || username == "Manufactoring")
    {

        item->setData(ChannellistDelegate::COLOR_USER, QColor(0, 255, 0));
        item->setToolTip("Creator of GProxy GhostGraz");
    }
    else if (isAdmin(username))
    {
        item->setData(ChannellistDelegate::COLOR_USER, QColor(0, 255, 200));
        item->setToolTip("GhostGraz admin");
    }
}

void MainGUI::sortChannelList ()
{
    for (int i = widget.channelList->count() - 1; i >= 0; i--)
    {
        QListWidgetItem *item = widget.channelList->item(i);
        if (item->data(ChannellistDelegate::USER).toString() == "baerli_graz"
                || item->data(ChannellistDelegate::USER).toString() == "klingone_graz"
                || item->data(ChannellistDelegate::USER).toString().startsWith("GhostGraz")
                || item->data(ChannellistDelegate::USER).toString() == "Phyton"
                || item->data(ChannellistDelegate::USER).toString() == "Manufactoring")
        {

            QListWidgetItem *newItem = new QListWidgetItem();
            newItem->setData(ChannellistDelegate::USER,
                    item->data(ChannellistDelegate::USER));
            newItem->setData(ChannellistDelegate::CLAN_TAG,
                    item->data(ChannellistDelegate::CLAN_TAG));
            addColor(newItem);
            delete widget.channelList->takeItem(i);
            widget.channelList->insertItem(0, newItem);
        }
    }
}

void MainGUI::sortFriendList ()
{
    for (int i = widget.friendList->count() - 1; i >= 0; i--)
    {
        QListWidgetItem *item = widget.friendList->item(i);
        if (item->foreground() == Qt::green)
        {

            QListWidgetItem *newItem = new QListWidgetItem();
            newItem->setText(item->text());
            newItem->setForeground(Qt::green);
            delete widget.friendList->takeItem(i);
            widget.friendList->insertItem(0, newItem);
        }
    }
}

void MainGUI::addChannelUser (QString username, QString clanTag)
{
    for (int i = 0; i < widget.channelList->count(); i++)
    {
        QListWidgetItem *item = widget.channelList->item(i);
        if (item->data(ChannellistDelegate::USER).toString() == username)
        {
            if (item->data(ChannellistDelegate::CLAN_TAG).toString() == clanTag)
            {
                return;
            }
            else
            {
                // Update
                QListWidgetItem *newItem = new QListWidgetItem();
                newItem->setData(ChannellistDelegate::USER, username);
                newItem->setData(ChannellistDelegate::CLAN_TAG, clanTag);
                addColor(newItem);
                delete widget.channelList->takeItem(i);
                widget.channelList->addItem(newItem);
                //                sortChannelList();
                return;
            }
        }
    }

    QListWidgetItem *newItem = new QListWidgetItem();
    newItem->setData(ChannellistDelegate::USER, username);
    if (!clanTag.isEmpty())
    {

        newItem->setData(ChannellistDelegate::CLAN_TAG, clanTag);
    }
    addColor(newItem);
    widget.channelList->addItem(newItem);
    //    sortChannelList();
}

void MainGUI::removeChannelUser (QString username)
{
    for (int i = 0; i < widget.channelList->count(); i++)
    {
        QListWidgetItem *item = widget.channelList->item(i);
        if (item->data(ChannellistDelegate::USER).toString() == username)
        {
            item = widget.channelList->takeItem(i);
            delete item;

            return;
        }
    }
}

void MainGUI::changeChannel (QString channel)
{
    widget.channelList->clear();
    widget.titleLabel->setText(channel);
}

void MainGUI::clearFriendlist ()
{

    widget.friendList->clear();
}

void MainGUI::addFriend (QString username, bool online, QString location)
{
    QListWidgetItem *newItem = new QListWidgetItem();
    newItem->setText(username);
    newItem->setToolTip(location);

    if (online)
    {
        newItem->setForeground(Qt::green);
    }
    else
    {

        newItem->setForeground(Qt::red);
    }

    widget.friendList->addItem(newItem);
    sortFriendList();
}

void MainGUI::addGame (QString botname, QString gamename, QString openSlots)
{

    QListWidgetItem* newItem = new QListWidgetItem();
    newItem->setData(GamelistDelegate::BOTNAME, botname);
    newItem->setData(GamelistDelegate::GAMENAME, gamename);
    newItem->setData(GamelistDelegate::OPEN_SLOTS, openSlots);
    widget.gameList->addItem(newItem);
}

void MainGUI::clearGamelist ()
{

    widget.gameList->clear();
}

void MainGUI::setGameslots (QList<Slot*> slotList)
{
    widget.channelList->clear();

    int currentTeam = -1;
    foreach (Slot* slot, slotList)
    {
        if (currentTeam != slot->getTeam())
        {
            currentTeam = slot->getTeam();

            QListWidgetItem* teamItem = new QListWidgetItem();

            if (gproxy->isDotaMap())
            {
                if (currentTeam == 0)
                {
                    teamItem->setData(ChannellistDelegate::USER, "The Sentinel");
                    teamItem->setData(ChannellistDelegate::SLOT_TEAM, 0);
                    teamItem->setData(ChannellistDelegate::COLOR_USER, QColor(255, 0, 0));
                }
                else
                {
                    teamItem->setData(ChannellistDelegate::USER, "The Scourge");
                    teamItem->setData(ChannellistDelegate::SLOT_TEAM, 1);
                    teamItem->setData(ChannellistDelegate::COLOR_USER, QColor(0, 255, 0));
                }
            }
            else
            {
                teamItem->setData(ChannellistDelegate::USER, "Team " + QString::number(currentTeam + 1));
                teamItem->setData(ChannellistDelegate::SLOT_TEAM, currentTeam);
            }

            widget.channelList->addItem(teamItem);
        }

        QListWidgetItem* playerItem = new QListWidgetItem();
        playerItem->setData(ChannellistDelegate::SLOT_PID, slot->getPlayerId());
        playerItem->setData(ChannellistDelegate::SLOT_DOWNLOAD_STATUS, slot->getDownloadProgress());
        playerItem->setData(ChannellistDelegate::SLOT_STATUS, slot->getSlotStatus());
        playerItem->setData(ChannellistDelegate::SLOT_COMPUTER_STATUS, slot->getComputerStatus());
        playerItem->setData(ChannellistDelegate::SLOT_TEAM, slot->getTeam());
        playerItem->setData(ChannellistDelegate::SLOT_COLOR, slot->getColor());
        playerItem->setData(ChannellistDelegate::SLOT_RACE, slot->getRace());
        playerItem->setData(ChannellistDelegate::SLOT_COMPUTER_TYPE, slot->getComputerType());
        playerItem->setData(ChannellistDelegate::SLOT_HANDICAP, slot->getHandicap());

        if (slot->getPlayer())
        {
            playerItem->setData(ChannellistDelegate::USER, slot->getPlayer()->getName());
        }
        else
        {
            playerItem->setData(ChannellistDelegate::USER, "");
        }
        widget.channelList->addItem(playerItem);
    }
}

void MainGUI::startWarcraft ()
{
    QString exePath;

    if (!gproxy->getCDKeyTFT().isEmpty())
    {
        exePath = gproxy->getWar3Path() + "Frozen Throne.exe";
    }
    else
    {
        exePath = gproxy->getWar3Path() + "Warcraft III.exe";
    }

    if( !QProcess::startDetached(exePath, QStringList()) )
    {
        showErrorMessage("Could not start " + exePath + ".\nPlease check your file permissions.");
    }
}

void MainGUI::showErrorMessage (QString errorMessage)
{
    addMessage("[ERROR] " + errorMessage);

    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon(":/images/Error.png"));
    msgBox.setWindowTitle("Error");
    msgBox.setText(errorMessage);
    msgBox.exec();
}
//
//void MainGUI::showConfigDialog ()
//{
//    showConfigDialog(false);
//}

void MainGUI::showConfigDialog (bool exitOnReject)
{
    ConfigGUI* config = new ConfigGUI(this);
    int exitCode = config->exec();
    if (exitOnReject)
    {
        if (exitCode == QDialog::Accepted)
        {
            // Restart GProxy.
            showErrorMessage("Restarting GProxy...");
            QString applicationName = QFileInfo(QApplication::applicationFilePath()).fileName();
            QProcess::startDetached(applicationName , QStringList());
            QApplication::quit();
        }
        else
        {
            showErrorMessage("GProxy cannot run without configuration.\nGood luck next time!");
            QApplication::quit();
        }
    }
}

void MainGUI::playerJoined (const QString& playername)
{
    addMessage("[LOBBY] " + playername + " has joined the game.");

    // If the player has a colored name (hostbot), return.
    if (playername.startsWith("|cff", Qt::CaseInsensitive))
    {
        return;
    }

    statspage->getPlayerInformation(playername);

    if (gproxy->getUsername() != playername && isAdmin(playername))
    {
        QSound::play("sounds/vip_joins.wav");
    }
    else
    {
        // If the player is a friend -> play sound.
        for (int i = 0; i < widget.friendList->count(); i++)
        {
            if (widget.friendList->item(i)->text() == playername)
            {
                QSound::play("sounds/vip_joins.wav");
                break;
            }
        }
    }
}

void MainGUI::onChannellistItemClicked (QMouseEvent *mouseEvent)
{
    widget.inputTextArea->setFocus();

    QListWidgetItem* item = widget.channelList->itemAt(mouseEvent->pos());
    if (!item)
    {
        return;
    }

    if (mouseEvent->button() == Qt::LeftButton)
    {
        QString user = item->data(ChannellistDelegate::USER).toString();
        int slotStatus = item->data(ChannellistDelegate::SLOT_STATUS).toInt();
        int computerStatus = item->data(ChannellistDelegate::SLOT_COMPUTER_STATUS).toInt();
        int team = item->data(ChannellistDelegate::SLOT_TEAM).toInt();

        if (gproxy->m_BNET->GetInGame())
        {
            if (user == "The Sentinel" || user == "The Scourge"
                    || user.startsWith("Team "))
            {
                gproxy->changeTeam(team);
            }
            else if (slotStatus == 0)
            {
                if (gproxy->isDotaMap())
                {
                    return; // Still buggy.

                    int requestedSlotNumber = 1;
                    for (int i = 0; i < widget.channelList->count(); i++)
                    {
                        if (item == widget.channelList->item(i))
                        {
                            requestedSlotNumber = i;
                            break;
                        }
                    }

                    int currentSlotNumber = 1;
                    foreach (Slot* slot, gproxy->getSlotList())
                    {
                        if (slot->getPlayer()) // Check for existing player.
                        {
                            if (slot->getPlayer()->getPlayerId() == gproxy->m_ChatPID)
                            {
                                currentSlotNumber = slot->getColor();
                                break;
                            }
                        }
                    }

                    if ((currentSlotNumber < 6 && requestedSlotNumber < 6)
                            || (currentSlotNumber > 6 && requestedSlotNumber > 6))
                    {
                        for (int i = currentSlotNumber + 1; i != requestedSlotNumber +1; i++)
                        {
                            if (team == 0 && i > 5)
                            {
                                i = 1;
                            }
                            else if (i > 11)
                            {
                                i = 7;
                            }

                            if (!gproxy->getSlotList().at(i)->getPlayer())
                            {
                                gproxy->changeTeam(team);
                            }
                        }
                    }
                    else
                    {
                        int i;
                        if (team == 0)
                        {
                            i = 1;
                        }
                        else
                        {
                            i = 7;
                        }

                        while (i != requestedSlotNumber)
                        {
                            if (!gproxy->getSlotList().at(i)->getPlayer())
                            {
                                gproxy->changeTeam(team);
                            }

                            i++;
                        }

                        /**
                         * SENT
                         * 1
                         * 2
                         * 3
                         * 4
                         * 5
                         * SCOU
                         * 7
                         * 8
                         * 9
                         * 10
                         * 11
                         */
                    }
                }
            }
            else if (slotStatus == 2 && computerStatus == 0)
            {
                widget.inputTextArea->setPlainText("/w " + user + " ");
                widget.inputTextArea->moveCursor(QTextCursor::End);
            }
        }
        else
        {
            widget.inputTextArea->setPlainText("/w " + user + " ");
            widget.inputTextArea->moveCursor(QTextCursor::End);
        }
    }
}

void MainGUI::onFriendlistItemClicked (QMouseEvent *mouseEvent)
{
    widget.inputTextArea->setFocus();

    QListWidgetItem *item = widget.friendList->itemAt(mouseEvent->pos());
    if (!item)
    {
        return;
    }

    if (mouseEvent->button() == Qt::LeftButton)
    {
        widget.inputTextArea->setPlainText("/w " + item->text() + " ");
        widget.inputTextArea->moveCursor(QTextCursor::End);
    }
}

void MainGUI::statspageLoginFinished ()
{
    if (statspage->isLoggedIn())
    {
        CONSOLE_Print("[GPROXY] Statspage available.");
        initAdminlist();
    }
    else
    {
        CONSOLE_Print("[ERROR] Statspage unavailable. "
                "You might have entered wrong username or password.");
    }
}

void MainGUI::receivedPlayerInformation (Player *player)
{
    QVector<Player*> players = gproxy->getPlayers();
    for (int i = 0; i < players.count(); i++)
    {
        if (players.at(i)->getName() == player->getName())
        {
            player->setPlayerId(players.at(i)->getPlayerId());
            players[i] = player;

            if (players[i]->getGamesPlayed() == 0)
            {
                addMessage("[WARNING] " + players[i]->getName()
                        + " hasn't played any games with the bot yet.");
                gproxy->SendLocalChat("[WARNING] " + players[i]->getName()
                        + " hasn't played any games with the bot yet.");
            }
            else if (players[i]->getStayPercent() < 80)
            {
                addMessage("[WARNING] " + players[i]->getName()
                        + " has a stay ratio below 80%. ("
                        + QString::number(players[i]->getStayPercent(), 'f', 2) + "%)");
                gproxy->SendLocalChat("WARNING: " + players[i]->getName()
                        + " has a stay ratio below 80%. ("
                        + QString::number(players[i]->getStayPercent(), 'f', 2) + "%)");
            }

            break;
        }
    }

    gproxy->setPlayers(players);
    widget.channelList->repaint();
}

/**
 * Slot: Executed when the adminlist was downloaded and parsed successfully.
 * @param admins The adminlist.
 */
void MainGUI::onAdminlistReceived (QList<QString> admins)
{
    this->admins = admins;
}

/**
 * Returns true if the name is the name of an GhostGraz admin.
 *
 * @param name Possible admin name.
 * @return True if the name is the name of an admin.
 */
bool MainGUI::isAdmin (const QString &name)
{
    QString adminName = name.toLower();
    foreach(QString admin, admins)
    {
        if (admin == adminName)
        {
            return true;
        }
    }

    return false;
}

CGProxy* MainGUI::getGproxy ()
{
    return gproxy;
}

Statspage* MainGUI::getStatspage ()
{
    return statspage;
}
