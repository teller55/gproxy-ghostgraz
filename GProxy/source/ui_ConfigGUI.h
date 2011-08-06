/********************************************************************************
** Form generated from reading UI file 'ConfigGUI.ui'
**
** Created: Fri 5. Aug 20:11:19 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGGUI_H
#define UI_CONFIGGUI_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>
#include "widget/ClickableLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_ConfigGUI
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *optionsTabWidget;
    QWidget *connectionTab;
    QLabel *channelLabel;
    QLabel *serverLabel;
    QLabel *tftKeyLabel;
    QLabel *war3versionLabel;
    QLabel *usernameLabel;
    QLabel *war3pathLabel;
    QLabel *rocKeyLabel;
    QLabel *passwordLabel;
    QLabel *portLabel;
    QLabel *connectionHeaderLabel;
    QLineEdit *cdkeyrocTextfield;
    QLineEdit *cdkeytftTextfield;
    QLineEdit *usernameTextfield;
    QLineEdit *passwordTextfield;
    QLineEdit *channelTextfield;
    QLineEdit *war3versionTextfield;
    QLineEdit *portTextfield;
    QComboBox *serverCombobox;
    QPushButton *war3pathButton;
    ClickableLineEdit *war3pathTextfield;
    QWidget *pvpgnTab;
    QLabel *pvpgnHeaderLabel;
    QLabel *exeversionhashLabel;
    QLineEdit *exeversionhashTextfield;
    QLabel *exeversionLabel;
    QLineEdit *exeversionTextfield;
    QLabel *passwordhashtypeLabel;
    QLineEdit *passwordhashtypeTextfield;
    QWidget *appearanceTab;
    QLabel *appearanceHeaderLabel;
    QTabWidget *appearanceTabWidget;
    QWidget *appearanceGeneralTab;
    QLabel *generalHeaderLabel;
    QLabel *backgroundcolorLabel;
    QPushButton *backgroundcolorButton;
    QWidget *appearanceOutputareaTab;
    QLabel *outputareaForegroundcolorLabel;
    QLabel *outputareaHeaderLabel;
    QLabel *outputareaFontLabel;
    QPushButton *outputareaForegroundcolorButton;
    QPushButton *outputareaFontButton;
    QWidget *appearanceInputareaTab;
    QWidget *appearanceGamelistTab;
    QWidget *miscellaneousTab;
    QLabel *miscellaneousHeaderLabel;
    QLabel *soundLabel;
    QLabel *privategamenameLabel;
    QLabel *botprefixLabel;
    QLabel *loggingLabel;
    QComboBox *soundCombobox;
    QLineEdit *privategamenameTextfield;
    QLineEdit *botprefixTextfield;
    QComboBox *logCombobox;
    QLabel *ghostgrazPasswordLabel;
    QLabel *ghostgrazUsernameLabel;
    QLineEdit *ghostgrazUsernameTextfield;
    QLineEdit *ghostgrazPasswordTextfield;

    void setupUi(QDialog *ConfigGUI)
    {
        if (ConfigGUI->objectName().isEmpty())
            ConfigGUI->setObjectName(QString::fromUtf8("ConfigGUI"));
        ConfigGUI->setWindowModality(Qt::ApplicationModal);
        ConfigGUI->resize(450, 550);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConfigGUI->sizePolicy().hasHeightForWidth());
        ConfigGUI->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConfigGUI->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(ConfigGUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(0, 520, 450, 30));
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        optionsTabWidget = new QTabWidget(ConfigGUI);
        optionsTabWidget->setObjectName(QString::fromUtf8("optionsTabWidget"));
        optionsTabWidget->setGeometry(QRect(0, 0, 450, 520));
        sizePolicy.setHeightForWidth(optionsTabWidget->sizePolicy().hasHeightForWidth());
        optionsTabWidget->setSizePolicy(sizePolicy);
        connectionTab = new QWidget();
        connectionTab->setObjectName(QString::fromUtf8("connectionTab"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        connectionTab->setFont(font);
        channelLabel = new QLabel(connectionTab);
        channelLabel->setObjectName(QString::fromUtf8("channelLabel"));
        channelLabel->setGeometry(QRect(10, 300, 160, 20));
        channelLabel->setFont(font);
        serverLabel = new QLabel(connectionTab);
        serverLabel->setObjectName(QString::fromUtf8("serverLabel"));
        serverLabel->setGeometry(QRect(10, 180, 160, 20));
        serverLabel->setFont(font);
        tftKeyLabel = new QLabel(connectionTab);
        tftKeyLabel->setObjectName(QString::fromUtf8("tftKeyLabel"));
        tftKeyLabel->setGeometry(QRect(10, 140, 160, 20));
        tftKeyLabel->setFont(font);
        war3versionLabel = new QLabel(connectionTab);
        war3versionLabel->setObjectName(QString::fromUtf8("war3versionLabel"));
        war3versionLabel->setGeometry(QRect(10, 340, 160, 20));
        war3versionLabel->setFont(font);
        usernameLabel = new QLabel(connectionTab);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setGeometry(QRect(10, 220, 160, 20));
        usernameLabel->setFont(font);
        war3pathLabel = new QLabel(connectionTab);
        war3pathLabel->setObjectName(QString::fromUtf8("war3pathLabel"));
        war3pathLabel->setGeometry(QRect(10, 60, 160, 20));
        war3pathLabel->setFont(font);
        rocKeyLabel = new QLabel(connectionTab);
        rocKeyLabel->setObjectName(QString::fromUtf8("rocKeyLabel"));
        rocKeyLabel->setGeometry(QRect(10, 100, 160, 20));
        rocKeyLabel->setFont(font);
        passwordLabel = new QLabel(connectionTab);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(10, 260, 160, 20));
        passwordLabel->setFont(font);
        portLabel = new QLabel(connectionTab);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));
        portLabel->setGeometry(QRect(10, 380, 160, 20));
        portLabel->setFont(font);
        connectionHeaderLabel = new QLabel(connectionTab);
        connectionHeaderLabel->setObjectName(QString::fromUtf8("connectionHeaderLabel"));
        connectionHeaderLabel->setGeometry(QRect(0, 0, 450, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Calibri"));
        font1.setPointSize(18);
        connectionHeaderLabel->setFont(font1);
        connectionHeaderLabel->setAlignment(Qt::AlignCenter);
        cdkeyrocTextfield = new QLineEdit(connectionTab);
        cdkeyrocTextfield->setObjectName(QString::fromUtf8("cdkeyrocTextfield"));
        cdkeyrocTextfield->setGeometry(QRect(180, 100, 240, 20));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        cdkeyrocTextfield->setFont(font2);
        cdkeytftTextfield = new QLineEdit(connectionTab);
        cdkeytftTextfield->setObjectName(QString::fromUtf8("cdkeytftTextfield"));
        cdkeytftTextfield->setGeometry(QRect(180, 140, 240, 20));
        cdkeytftTextfield->setFont(font2);
        usernameTextfield = new QLineEdit(connectionTab);
        usernameTextfield->setObjectName(QString::fromUtf8("usernameTextfield"));
        usernameTextfield->setGeometry(QRect(180, 220, 240, 20));
        usernameTextfield->setFont(font2);
        passwordTextfield = new QLineEdit(connectionTab);
        passwordTextfield->setObjectName(QString::fromUtf8("passwordTextfield"));
        passwordTextfield->setGeometry(QRect(180, 260, 240, 20));
        passwordTextfield->setFont(font2);
        passwordTextfield->setEchoMode(QLineEdit::Password);
        channelTextfield = new QLineEdit(connectionTab);
        channelTextfield->setObjectName(QString::fromUtf8("channelTextfield"));
        channelTextfield->setGeometry(QRect(180, 300, 240, 20));
        channelTextfield->setFont(font2);
        war3versionTextfield = new QLineEdit(connectionTab);
        war3versionTextfield->setObjectName(QString::fromUtf8("war3versionTextfield"));
        war3versionTextfield->setGeometry(QRect(180, 340, 240, 20));
        war3versionTextfield->setFont(font2);
        portTextfield = new QLineEdit(connectionTab);
        portTextfield->setObjectName(QString::fromUtf8("portTextfield"));
        portTextfield->setGeometry(QRect(180, 380, 240, 20));
        portTextfield->setFont(font2);
        serverCombobox = new QComboBox(connectionTab);
        serverCombobox->setObjectName(QString::fromUtf8("serverCombobox"));
        serverCombobox->setGeometry(QRect(180, 180, 240, 20));
        serverCombobox->setFont(font2);
        serverCombobox->setMaxCount(6);
        war3pathButton = new QPushButton(connectionTab);
        war3pathButton->setObjectName(QString::fromUtf8("war3pathButton"));
        war3pathButton->setGeometry(QRect(390, 60, 30, 20));
        war3pathTextfield = new ClickableLineEdit(connectionTab);
        war3pathTextfield->setObjectName(QString::fromUtf8("war3pathTextfield"));
        war3pathTextfield->setGeometry(QRect(180, 60, 210, 20));
        war3pathTextfield->setFont(font2);
        optionsTabWidget->addTab(connectionTab, QString());
        pvpgnTab = new QWidget();
        pvpgnTab->setObjectName(QString::fromUtf8("pvpgnTab"));
        pvpgnHeaderLabel = new QLabel(pvpgnTab);
        pvpgnHeaderLabel->setObjectName(QString::fromUtf8("pvpgnHeaderLabel"));
        pvpgnHeaderLabel->setGeometry(QRect(0, 0, 450, 40));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pvpgnHeaderLabel->sizePolicy().hasHeightForWidth());
        pvpgnHeaderLabel->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Calibri"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        pvpgnHeaderLabel->setFont(font3);
        pvpgnHeaderLabel->setAlignment(Qt::AlignCenter);
        exeversionhashLabel = new QLabel(pvpgnTab);
        exeversionhashLabel->setObjectName(QString::fromUtf8("exeversionhashLabel"));
        exeversionhashLabel->setGeometry(QRect(10, 100, 160, 20));
        exeversionhashLabel->setFont(font);
        exeversionhashTextfield = new QLineEdit(pvpgnTab);
        exeversionhashTextfield->setObjectName(QString::fromUtf8("exeversionhashTextfield"));
        exeversionhashTextfield->setGeometry(QRect(180, 100, 240, 20));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(9);
        exeversionhashTextfield->setFont(font4);
        exeversionLabel = new QLabel(pvpgnTab);
        exeversionLabel->setObjectName(QString::fromUtf8("exeversionLabel"));
        exeversionLabel->setGeometry(QRect(10, 60, 160, 20));
        exeversionLabel->setFont(font);
        exeversionTextfield = new QLineEdit(pvpgnTab);
        exeversionTextfield->setObjectName(QString::fromUtf8("exeversionTextfield"));
        exeversionTextfield->setGeometry(QRect(180, 60, 240, 20));
        exeversionTextfield->setFont(font4);
        passwordhashtypeLabel = new QLabel(pvpgnTab);
        passwordhashtypeLabel->setObjectName(QString::fromUtf8("passwordhashtypeLabel"));
        passwordhashtypeLabel->setGeometry(QRect(10, 140, 160, 20));
        passwordhashtypeLabel->setFont(font);
        passwordhashtypeTextfield = new QLineEdit(pvpgnTab);
        passwordhashtypeTextfield->setObjectName(QString::fromUtf8("passwordhashtypeTextfield"));
        passwordhashtypeTextfield->setGeometry(QRect(180, 140, 240, 20));
        passwordhashtypeTextfield->setFont(font4);
        optionsTabWidget->addTab(pvpgnTab, QString());
        appearanceTab = new QWidget();
        appearanceTab->setObjectName(QString::fromUtf8("appearanceTab"));
        appearanceHeaderLabel = new QLabel(appearanceTab);
        appearanceHeaderLabel->setObjectName(QString::fromUtf8("appearanceHeaderLabel"));
        appearanceHeaderLabel->setGeometry(QRect(0, 0, 450, 40));
        sizePolicy1.setHeightForWidth(appearanceHeaderLabel->sizePolicy().hasHeightForWidth());
        appearanceHeaderLabel->setSizePolicy(sizePolicy1);
        appearanceHeaderLabel->setFont(font3);
        appearanceHeaderLabel->setAlignment(Qt::AlignCenter);
        appearanceTabWidget = new QTabWidget(appearanceTab);
        appearanceTabWidget->setObjectName(QString::fromUtf8("appearanceTabWidget"));
        appearanceTabWidget->setGeometry(QRect(0, 40, 450, 460));
        appearanceGeneralTab = new QWidget();
        appearanceGeneralTab->setObjectName(QString::fromUtf8("appearanceGeneralTab"));
        generalHeaderLabel = new QLabel(appearanceGeneralTab);
        generalHeaderLabel->setObjectName(QString::fromUtf8("generalHeaderLabel"));
        generalHeaderLabel->setGeometry(QRect(0, 0, 450, 40));
        sizePolicy1.setHeightForWidth(generalHeaderLabel->sizePolicy().hasHeightForWidth());
        generalHeaderLabel->setSizePolicy(sizePolicy1);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Calibri"));
        font5.setPointSize(16);
        font5.setBold(true);
        font5.setWeight(75);
        generalHeaderLabel->setFont(font5);
        generalHeaderLabel->setAlignment(Qt::AlignCenter);
        backgroundcolorLabel = new QLabel(appearanceGeneralTab);
        backgroundcolorLabel->setObjectName(QString::fromUtf8("backgroundcolorLabel"));
        backgroundcolorLabel->setGeometry(QRect(10, 60, 160, 20));
        backgroundcolorLabel->setFont(font);
        backgroundcolorButton = new QPushButton(appearanceGeneralTab);
        backgroundcolorButton->setObjectName(QString::fromUtf8("backgroundcolorButton"));
        backgroundcolorButton->setGeometry(QRect(180, 60, 240, 20));
        appearanceTabWidget->addTab(appearanceGeneralTab, QString());
        appearanceOutputareaTab = new QWidget();
        appearanceOutputareaTab->setObjectName(QString::fromUtf8("appearanceOutputareaTab"));
        outputareaForegroundcolorLabel = new QLabel(appearanceOutputareaTab);
        outputareaForegroundcolorLabel->setObjectName(QString::fromUtf8("outputareaForegroundcolorLabel"));
        outputareaForegroundcolorLabel->setGeometry(QRect(10, 60, 160, 20));
        outputareaForegroundcolorLabel->setFont(font);
        outputareaHeaderLabel = new QLabel(appearanceOutputareaTab);
        outputareaHeaderLabel->setObjectName(QString::fromUtf8("outputareaHeaderLabel"));
        outputareaHeaderLabel->setGeometry(QRect(0, 0, 450, 40));
        sizePolicy1.setHeightForWidth(outputareaHeaderLabel->sizePolicy().hasHeightForWidth());
        outputareaHeaderLabel->setSizePolicy(sizePolicy1);
        outputareaHeaderLabel->setFont(font5);
        outputareaHeaderLabel->setAlignment(Qt::AlignCenter);
        outputareaFontLabel = new QLabel(appearanceOutputareaTab);
        outputareaFontLabel->setObjectName(QString::fromUtf8("outputareaFontLabel"));
        outputareaFontLabel->setGeometry(QRect(10, 100, 160, 20));
        outputareaFontLabel->setFont(font);
        outputareaForegroundcolorButton = new QPushButton(appearanceOutputareaTab);
        outputareaForegroundcolorButton->setObjectName(QString::fromUtf8("outputareaForegroundcolorButton"));
        outputareaForegroundcolorButton->setGeometry(QRect(180, 60, 240, 20));
        outputareaFontButton = new QPushButton(appearanceOutputareaTab);
        outputareaFontButton->setObjectName(QString::fromUtf8("outputareaFontButton"));
        outputareaFontButton->setGeometry(QRect(180, 100, 240, 20));
        appearanceTabWidget->addTab(appearanceOutputareaTab, QString());
        appearanceInputareaTab = new QWidget();
        appearanceInputareaTab->setObjectName(QString::fromUtf8("appearanceInputareaTab"));
        appearanceTabWidget->addTab(appearanceInputareaTab, QString());
        appearanceGamelistTab = new QWidget();
        appearanceGamelistTab->setObjectName(QString::fromUtf8("appearanceGamelistTab"));
        appearanceTabWidget->addTab(appearanceGamelistTab, QString());
        optionsTabWidget->addTab(appearanceTab, QString());
        miscellaneousTab = new QWidget();
        miscellaneousTab->setObjectName(QString::fromUtf8("miscellaneousTab"));
        miscellaneousHeaderLabel = new QLabel(miscellaneousTab);
        miscellaneousHeaderLabel->setObjectName(QString::fromUtf8("miscellaneousHeaderLabel"));
        miscellaneousHeaderLabel->setGeometry(QRect(0, 0, 450, 40));
        sizePolicy1.setHeightForWidth(miscellaneousHeaderLabel->sizePolicy().hasHeightForWidth());
        miscellaneousHeaderLabel->setSizePolicy(sizePolicy1);
        miscellaneousHeaderLabel->setFont(font3);
        miscellaneousHeaderLabel->setAlignment(Qt::AlignCenter);
        soundLabel = new QLabel(miscellaneousTab);
        soundLabel->setObjectName(QString::fromUtf8("soundLabel"));
        soundLabel->setGeometry(QRect(10, 140, 160, 20));
        soundLabel->setFont(font);
        privategamenameLabel = new QLabel(miscellaneousTab);
        privategamenameLabel->setObjectName(QString::fromUtf8("privategamenameLabel"));
        privategamenameLabel->setGeometry(QRect(10, 180, 160, 20));
        privategamenameLabel->setFont(font);
        botprefixLabel = new QLabel(miscellaneousTab);
        botprefixLabel->setObjectName(QString::fromUtf8("botprefixLabel"));
        botprefixLabel->setGeometry(QRect(10, 220, 160, 20));
        botprefixLabel->setFont(font);
        loggingLabel = new QLabel(miscellaneousTab);
        loggingLabel->setObjectName(QString::fromUtf8("loggingLabel"));
        loggingLabel->setGeometry(QRect(10, 260, 160, 20));
        loggingLabel->setFont(font);
        soundCombobox = new QComboBox(miscellaneousTab);
        soundCombobox->setObjectName(QString::fromUtf8("soundCombobox"));
        soundCombobox->setGeometry(QRect(180, 140, 240, 20));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Arial"));
        font6.setPointSize(9);
        font6.setBold(false);
        font6.setWeight(50);
        soundCombobox->setFont(font6);
        soundCombobox->setMaxCount(10);
        privategamenameTextfield = new QLineEdit(miscellaneousTab);
        privategamenameTextfield->setObjectName(QString::fromUtf8("privategamenameTextfield"));
        privategamenameTextfield->setGeometry(QRect(180, 180, 240, 20));
        privategamenameTextfield->setFont(font4);
        botprefixTextfield = new QLineEdit(miscellaneousTab);
        botprefixTextfield->setObjectName(QString::fromUtf8("botprefixTextfield"));
        botprefixTextfield->setGeometry(QRect(180, 220, 240, 20));
        botprefixTextfield->setFont(font4);
        logCombobox = new QComboBox(miscellaneousTab);
        logCombobox->setObjectName(QString::fromUtf8("logCombobox"));
        logCombobox->setGeometry(QRect(180, 260, 240, 20));
        logCombobox->setFont(font6);
        logCombobox->setMaxCount(10);
        ghostgrazPasswordLabel = new QLabel(miscellaneousTab);
        ghostgrazPasswordLabel->setObjectName(QString::fromUtf8("ghostgrazPasswordLabel"));
        ghostgrazPasswordLabel->setGeometry(QRect(10, 100, 160, 20));
        ghostgrazPasswordLabel->setFont(font);
        ghostgrazUsernameLabel = new QLabel(miscellaneousTab);
        ghostgrazUsernameLabel->setObjectName(QString::fromUtf8("ghostgrazUsernameLabel"));
        ghostgrazUsernameLabel->setGeometry(QRect(10, 60, 160, 20));
        ghostgrazUsernameLabel->setFont(font);
        ghostgrazUsernameTextfield = new QLineEdit(miscellaneousTab);
        ghostgrazUsernameTextfield->setObjectName(QString::fromUtf8("ghostgrazUsernameTextfield"));
        ghostgrazUsernameTextfield->setGeometry(QRect(180, 60, 240, 20));
        ghostgrazUsernameTextfield->setFont(font4);
        ghostgrazPasswordTextfield = new QLineEdit(miscellaneousTab);
        ghostgrazPasswordTextfield->setObjectName(QString::fromUtf8("ghostgrazPasswordTextfield"));
        ghostgrazPasswordTextfield->setGeometry(QRect(180, 100, 240, 20));
        ghostgrazPasswordTextfield->setFont(font4);
        ghostgrazPasswordTextfield->setEchoMode(QLineEdit::Password);
        optionsTabWidget->addTab(miscellaneousTab, QString());

        retranslateUi(ConfigGUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigGUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigGUI, SLOT(reject()));
        QObject::connect(war3pathTextfield, SIGNAL(clicked()), ConfigGUI, SLOT(onWar3pathChangeRequest()));
        QObject::connect(war3pathButton, SIGNAL(clicked()), ConfigGUI, SLOT(onWar3pathChangeRequest()));
        QObject::connect(backgroundcolorButton, SIGNAL(clicked()), ConfigGUI, SLOT(onBackgroundcolorButtonClicked()));
        QObject::connect(outputareaFontButton, SIGNAL(clicked()), ConfigGUI, SLOT(onOutputareaFontButtonClicked()));
        QObject::connect(outputareaForegroundcolorButton, SIGNAL(clicked()), ConfigGUI, SLOT(onOutputareaForegroundcolorButtonClicked()));

        optionsTabWidget->setCurrentIndex(2);
        appearanceTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ConfigGUI);
    } // setupUi

    void retranslateUi(QDialog *ConfigGUI)
    {
        ConfigGUI->setWindowTitle(QApplication::translate("ConfigGUI", "GProxy Options", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        channelLabel->setWhatsThis(QApplication::translate("ConfigGUI", "This is the first channel that GProxy will join after logging in to battle.net.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        channelLabel->setText(QApplication::translate("ConfigGUI", "Channel:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        serverLabel->setWhatsThis(QApplication::translate("ConfigGUI", "Select the battle.net server you want GProxy to connect to.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        serverLabel->setText(QApplication::translate("ConfigGUI", "Battle.net server:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        tftKeyLabel->setWhatsThis(QApplication::translate("ConfigGUI", "GProxy needs your cd keys to connect to battle.net.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        tftKeyLabel->setText(QApplication::translate("ConfigGUI", "The Frozen Throne CD key:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        war3versionLabel->setWhatsThis(QApplication::translate("ConfigGUI", "This is the Warcraft 3 patch version.\n"
"If you had to update Warcraft 3, you probably have to increase this number too.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        war3versionLabel->setText(QApplication::translate("ConfigGUI", "Warcraft 3 patch version:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        usernameLabel->setWhatsThis(QApplication::translate("ConfigGUI", "Fill in your battle.net username.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        usernameLabel->setText(QApplication::translate("ConfigGUI", "Username:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        war3pathLabel->setWhatsThis(QApplication::translate("ConfigGUI", "The Warcraft 3 install direcoty is needed to connected to battle.net.\n"
"It is also needed to start Warcraft 3 with GProxy.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        war3pathLabel->setText(QApplication::translate("ConfigGUI", "Warcraft 3 Install directory:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        rocKeyLabel->setWhatsThis(QApplication::translate("ConfigGUI", "GProxy needs your cd keys to connect to battle.net.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        rocKeyLabel->setText(QApplication::translate("ConfigGUI", "Reign of Chaos CD key:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        passwordLabel->setWhatsThis(QApplication::translate("ConfigGUI", "Fill in your battle.net password.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        passwordLabel->setText(QApplication::translate("ConfigGUI", "Password:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        portLabel->setWhatsThis(QApplication::translate("ConfigGUI", "This is the port which GProxy will use.\n"
"If you don't know what a port is I recommend you to not change this number.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        portLabel->setText(QApplication::translate("ConfigGUI", "Port:", 0, QApplication::UnicodeUTF8));
        connectionHeaderLabel->setText(QApplication::translate("ConfigGUI", "Connection", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        cdkeyrocTextfield->setWhatsThis(QApplication::translate("ConfigGUI", "GProxy needs your cd keys to connect to battle.net.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        cdkeyrocTextfield->setText(QString());
        cdkeyrocTextfield->setPlaceholderText(QApplication::translate("ConfigGUI", "Reign of Chaos CD key", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        cdkeytftTextfield->setWhatsThis(QApplication::translate("ConfigGUI", "GProxy needs your cd keys to connect to battle.net.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        cdkeytftTextfield->setPlaceholderText(QApplication::translate("ConfigGUI", "The Frozen Throne CD key", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        usernameTextfield->setWhatsThis(QApplication::translate("ConfigGUI", "Fill in your battle.net username.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        usernameTextfield->setPlaceholderText(QApplication::translate("ConfigGUI", "Username", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        passwordTextfield->setWhatsThis(QApplication::translate("ConfigGUI", "Fill in your battle.net password.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        passwordTextfield->setText(QString());
        passwordTextfield->setPlaceholderText(QApplication::translate("ConfigGUI", "Password", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        channelTextfield->setWhatsThis(QApplication::translate("ConfigGUI", "This is the first channel that GProxy will join after logging in to battle.net.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        channelTextfield->setPlaceholderText(QApplication::translate("ConfigGUI", "Channel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        war3versionTextfield->setWhatsThis(QApplication::translate("ConfigGUI", "This is the Warcraft 3 patch version.\n"
"If you had to update Warcraft 3, you probably have to increase this number too.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        war3versionTextfield->setPlaceholderText(QApplication::translate("ConfigGUI", "Warcraft 3 patch version", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        portTextfield->setWhatsThis(QApplication::translate("ConfigGUI", "This is the port which GProxy will use.\n"
"If you don't know what a port is I recommend you to not change this number.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        portTextfield->setPlaceholderText(QApplication::translate("ConfigGUI", "Port", 0, QApplication::UnicodeUTF8));
        serverCombobox->clear();
        serverCombobox->insertItems(0, QStringList()
         << QApplication::translate("ConfigGUI", "US West (Lordaeron)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigGUI", "US East (Azeroth)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigGUI", "Asia (Kalimdor)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigGUI", "Europe (Northrend)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigGUI", "PvPGN Server", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_WHATSTHIS
        serverCombobox->setWhatsThis(QApplication::translate("ConfigGUI", "Select the battle.net server you want GProxy to connect to.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        war3pathButton->setWhatsThis(QApplication::translate("ConfigGUI", "If you click on this button, a file dialog will be opened to select the Warcraft 3 path.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        war3pathButton->setText(QApplication::translate("ConfigGUI", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        war3pathTextfield->setWhatsThis(QApplication::translate("ConfigGUI", "The Warcraft 3 install direcoty is needed to connected to battle.net.\n"
"It is also needed to start Warcraft 3 with GProxy.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        war3pathTextfield->setText(QString());
        war3pathTextfield->setPlaceholderText(QApplication::translate("ConfigGUI", "Warcraft 3 Install directory", 0, QApplication::UnicodeUTF8));
        optionsTabWidget->setTabText(optionsTabWidget->indexOf(connectionTab), QApplication::translate("ConfigGUI", "Connection", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        pvpgnHeaderLabel->setWhatsThis(QApplication::translate("ConfigGUI", "PvPGN (Player vs Player Gaming Network) is a bnetd based gaming network server emulation project. More information can be found at www.google.com ;P", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pvpgnHeaderLabel->setText(QApplication::translate("ConfigGUI", "Player vs Player Gaming Network", 0, QApplication::UnicodeUTF8));
        exeversionhashLabel->setText(QApplication::translate("ConfigGUI", "Exe vesion hash:", 0, QApplication::UnicodeUTF8));
        exeversionhashTextfield->setText(QString());
        exeversionhashTextfield->setPlaceholderText(QApplication::translate("ConfigGUI", "Exe version hash", 0, QApplication::UnicodeUTF8));
        exeversionLabel->setText(QApplication::translate("ConfigGUI", "Exe version:", 0, QApplication::UnicodeUTF8));
        exeversionTextfield->setText(QString());
        exeversionTextfield->setPlaceholderText(QApplication::translate("ConfigGUI", "Exe version", 0, QApplication::UnicodeUTF8));
        passwordhashtypeLabel->setText(QApplication::translate("ConfigGUI", "Password hash type:", 0, QApplication::UnicodeUTF8));
        passwordhashtypeTextfield->setText(QString());
        passwordhashtypeTextfield->setPlaceholderText(QApplication::translate("ConfigGUI", "Password hash type", 0, QApplication::UnicodeUTF8));
        optionsTabWidget->setTabText(optionsTabWidget->indexOf(pvpgnTab), QApplication::translate("ConfigGUI", "PvPGN", 0, QApplication::UnicodeUTF8));
        appearanceHeaderLabel->setText(QApplication::translate("ConfigGUI", "Appearance", 0, QApplication::UnicodeUTF8));
        generalHeaderLabel->setText(QApplication::translate("ConfigGUI", "General", 0, QApplication::UnicodeUTF8));
        backgroundcolorLabel->setText(QApplication::translate("ConfigGUI", "Background color:", 0, QApplication::UnicodeUTF8));
        backgroundcolorButton->setText(QApplication::translate("ConfigGUI", "Change background color", 0, QApplication::UnicodeUTF8));
        appearanceTabWidget->setTabText(appearanceTabWidget->indexOf(appearanceGeneralTab), QApplication::translate("ConfigGUI", "General", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        appearanceOutputareaTab->setWhatsThis(QApplication::translate("ConfigGUI", "The output area is the big field at the left side of GProxy.\n"
"Here you can will see all chat messages and much more.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        outputareaForegroundcolorLabel->setText(QApplication::translate("ConfigGUI", "Foreground color:", 0, QApplication::UnicodeUTF8));
        outputareaHeaderLabel->setText(QApplication::translate("ConfigGUI", "Output area", 0, QApplication::UnicodeUTF8));
        outputareaFontLabel->setText(QApplication::translate("ConfigGUI", "Font:", 0, QApplication::UnicodeUTF8));
        outputareaForegroundcolorButton->setText(QApplication::translate("ConfigGUI", "Change foreground color", 0, QApplication::UnicodeUTF8));
        outputareaFontButton->setText(QApplication::translate("ConfigGUI", "Change font", 0, QApplication::UnicodeUTF8));
        appearanceTabWidget->setTabText(appearanceTabWidget->indexOf(appearanceOutputareaTab), QApplication::translate("ConfigGUI", "Ouput area", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        appearanceInputareaTab->setWhatsThis(QApplication::translate("ConfigGUI", "The input area is the small textfield at the bottom.\n"
"Here you can type chat messages and commands.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        appearanceTabWidget->setTabText(appearanceTabWidget->indexOf(appearanceInputareaTab), QApplication::translate("ConfigGUI", "Input area", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        appearanceGamelistTab->setWhatsThis(QApplication::translate("ConfigGUI", "The (GhostGraz) gamelist contains all games hosted by GhostGraz.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        appearanceTabWidget->setTabText(appearanceTabWidget->indexOf(appearanceGamelistTab), QApplication::translate("ConfigGUI", "Gamelist", 0, QApplication::UnicodeUTF8));
        optionsTabWidget->setTabText(optionsTabWidget->indexOf(appearanceTab), QApplication::translate("ConfigGUI", "Appearance", 0, QApplication::UnicodeUTF8));
        miscellaneousHeaderLabel->setText(QApplication::translate("ConfigGUI", "Miscellaneous", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        soundLabel->setWhatsThis(QApplication::translate("ConfigGUI", "If the sound is enabled GProxy will play a sound for some events.\n"
"For example: Whipser or player left.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        soundLabel->setText(QApplication::translate("ConfigGUI", "Sound:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        privategamenameLabel->setWhatsThis(QApplication::translate("ConfigGUI", "The privategamename is needed for the /waitgame feature.\n"
"This is the name of the game the bot will create.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        privategamenameLabel->setText(QApplication::translate("ConfigGUI", "Privategamename:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        botprefixLabel->setWhatsThis(QApplication::translate("ConfigGUI", "The botprefix is needed for the /waitgame feature. Waitgame will wait for a bot which name starts with the botprefix.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        botprefixLabel->setText(QApplication::translate("ConfigGUI", "Botprefix:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        loggingLabel->setWhatsThis(QApplication::translate("ConfigGUI", "If logging is enabled GProxy will write various messages to the log file.\n"
"The log file is located in the folder where the .exe is and is named gproxy_log.txt.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        loggingLabel->setText(QApplication::translate("ConfigGUI", "Log:", 0, QApplication::UnicodeUTF8));
        soundCombobox->clear();
        soundCombobox->insertItems(0, QStringList()
         << QApplication::translate("ConfigGUI", "Enabled", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigGUI", "Disabled", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_WHATSTHIS
        soundCombobox->setWhatsThis(QApplication::translate("ConfigGUI", "If the sound is enabled GProxy will play a sound for some events.\n"
"For example: Whipser or player left.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        privategamenameTextfield->setWhatsThis(QApplication::translate("ConfigGUI", "The privategamename is needed for the /waitgame feature.\n"
"This is the name of the game the bot will create.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        privategamenameTextfield->setText(QString());
        privategamenameTextfield->setPlaceholderText(QApplication::translate("ConfigGUI", "Privategamename", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        botprefixTextfield->setWhatsThis(QApplication::translate("ConfigGUI", "The botprefix is needed for the /waitgame feature. Waitgame will wait for a bot which name starts with the botprefix.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        botprefixTextfield->setText(QString());
        botprefixTextfield->setPlaceholderText(QApplication::translate("ConfigGUI", "Botprefix", 0, QApplication::UnicodeUTF8));
        logCombobox->clear();
        logCombobox->insertItems(0, QStringList()
         << QApplication::translate("ConfigGUI", "Enabled", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigGUI", "Disabled", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_WHATSTHIS
        logCombobox->setWhatsThis(QApplication::translate("ConfigGUI", "If logging is enabled GProxy will write various messages to the log file.\n"
"The log file is located in the folder where the .exe is and is named gproxy_log.txt.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        ghostgrazPasswordLabel->setWhatsThis(QApplication::translate("ConfigGUI", "The GhostGraz password is needed for the connection to the statspage.\n"
"(E.g. retrieve stay ratio)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        ghostgrazPasswordLabel->setText(QApplication::translate("ConfigGUI", "GhostGraz password:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        ghostgrazUsernameLabel->setWhatsThis(QApplication::translate("ConfigGUI", "The GhostGraz username is needed for the connection to the statspage.\n"
"(E.g. retrieve stay ratio)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        ghostgrazUsernameLabel->setText(QApplication::translate("ConfigGUI", "GhostGraz username:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        ghostgrazUsernameTextfield->setWhatsThis(QApplication::translate("ConfigGUI", "The GhostGraz username is needed for the connection to the statspage.\n"
"(E.g. retrieve stay ratio)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        ghostgrazUsernameTextfield->setText(QString());
        ghostgrazUsernameTextfield->setPlaceholderText(QApplication::translate("ConfigGUI", "GhostGraz username", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        ghostgrazPasswordTextfield->setWhatsThis(QApplication::translate("ConfigGUI", "The GhostGraz password is needed for the connection to the statspage.\n"
"(E.g. retrieve stay ratio)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        ghostgrazPasswordTextfield->setText(QString());
        ghostgrazPasswordTextfield->setPlaceholderText(QApplication::translate("ConfigGUI", "GhostGraz password", 0, QApplication::UnicodeUTF8));
        optionsTabWidget->setTabText(optionsTabWidget->indexOf(miscellaneousTab), QApplication::translate("ConfigGUI", "Miscellaneous", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfigGUI: public Ui_ConfigGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGGUI_H
