#ifndef _MAINGUI_H
#define	_MAINGUI_H

#include "ui_MainGUI.h"
#include "gproxy.h"
#include <string>
#include <QString>

using namespace std;

class MainGUI : public QMainWindow
{
    Q_OBJECT

private:
    CGProxy *gproxy;

public:
    MainGUI(CGProxy *p_gproxy);
    virtual ~MainGUI();
    void init();

    CGProxy* getGproxy();
    void startWarcraft();

private:
    Ui::MainGUI widget;
    void initLayout();
    void initSlots();
    void resizeEvent(QResizeEvent *event);
    void processInput(const QString &input);
    void addColor(QString &message);
    void addColor(QListWidgetItem *item);
    void sortChannelList();
    void sortFriendList();
    void sortSlots(int teams);

private slots:
    void onClose();
    void onInputFieldTextChanged();
    void onChannelChanged();
    void onChannelContextMenu(const QPoint&);
    void onFriendsContextMenu(const QPoint&);
    void onGameListItemClicked(QListWidgetItem*);
    void onOutputFieldSliderMoved();
    void onRefreshButtonClicked();
    void updateRefreshButton();

public slots:
    void addMessage(QString message, bool log = true);
    void changeChannel(QString channel);
    void addChannelUser(QString username, QString clanTag);
    void removeChannelUser(QString username);
    void clearFriendlist();
    void addFriend(QString username, bool online, QString location);
    void clearGamelist();
    void addGame(QString botname, QString gamename, QString openSlots);
    void setGameslots(vector<CIncomingSlots *> slotList);
    void showErrorMessage(QString errorMessage);
};

#endif	/* _MAINGUI_H */
