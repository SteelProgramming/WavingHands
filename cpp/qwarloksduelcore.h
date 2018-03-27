#ifndef QWARLOKSDUELCORE_H
#define QWARLOKSDUELCORE_H

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSettings>
#include <QFile>
#include <QTextStream>
#include <QNetworkProxy>
#include <QList>
#include <QPair>

//#include "qwarlockutils.h"
#include "qwarlockspellchecker.h"
#include "qwarlockdictionary.h"

class QWarloksDuelCore : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isNeedLogin READ isNeedLogin NOTIFY needLogin)
    Q_PROPERTY(QString login READ login NOTIFY loginChanged)
    Q_PROPERTY(QString password READ password NOTIFY passwordChanged)
    Q_PROPERTY(QString proxyHost READ proxyHost NOTIFY proxyHostChanged)
    Q_PROPERTY(int proxyPort READ proxyPort NOTIFY proxyPortChanged)
    Q_PROPERTY(QString proxyUser READ proxyUser NOTIFY proxyUserChanged)
    Q_PROPERTY(QString proxyPass READ proxyPass NOTIFY proxyPassChanged)
    Q_PROPERTY(QString errorMsg READ errorMsg NOTIFY errorOccurred)
    Q_PROPERTY(QString playerInfo READ playerInfo NOTIFY playerInfoChanged)
    Q_PROPERTY(QString readyInBattles READ readyInBattles NOTIFY readyInBattlesChanged)
    Q_PROPERTY(QString waitingInBattles READ waitingInBattles NOTIFY waitingInBattlesChanged)
    Q_PROPERTY(QString finishedBattles READ finishedBattles NOTIFY finishedBattlesChanged)
    Q_PROPERTY(QString finishedBattle READ finishedBattle NOTIFY finishedBattleChanged)
    Q_PROPERTY(int readyBattle READ readyBattle NOTIFY readyBattleChanged)
    Q_PROPERTY(int loadedBattleID READ loadedBattleID NOTIFY loadedBattleIDChanged)
    Q_PROPERTY(int isLoading READ isLoading NOTIFY isLoadingChanged)
    Q_PROPERTY(QString targets READ targets NOTIFY targetsChanged)
    Q_PROPERTY(QString warlocks READ warlocks NOTIFY warlocksChanged)
    Q_PROPERTY(QString monsters READ monsters NOTIFY monstersChanged)
    Q_PROPERTY(QString leftGesture READ leftGesture NOTIFY leftGestureChanged)
    Q_PROPERTY(QString rightGesture READ rightGesture NOTIFY rightGestureChanged)
    Q_PROPERTY(int registerNewUser READ registerNewUser NOTIFY registerNewUserChanged)
    Q_PROPERTY(QString monsterCommandList READ monsterCommandList NOTIFY monsterCommandListChanged)
    Q_PROPERTY(QString leftHand READ leftHand NOTIFY leftHandChanged)
    Q_PROPERTY(QString rightHand READ rightHand NOTIFY rightHandChanged)
    Q_PROPERTY(int orderSubmited READ orderSubmited NOTIFY orderSubmitedChanged)
    Q_PROPERTY(int challengeSubmited READ challengeSubmited NOTIFY challengeSubmitedChanged)
    Q_PROPERTY(QString charmPerson READ charmPerson NOTIFY charmPersonChanged)
    Q_PROPERTY(QString paralyze READ paralyze NOTIFY paralyzeChanged)
    Q_PROPERTY(int timerState READ timerState NOTIFY timerStateChanged)
    Q_PROPERTY(int isDelay READ isDelay NOTIFY isDelayChanged)
    Q_PROPERTY(int isPermanent READ isPermanent NOTIFY isPermanentChanged)
    Q_PROPERTY(QString fire READ fire NOTIFY fireChanged)
    Q_PROPERTY(QString challengeList READ challengeList NOTIFY challengeListChanged)
    Q_PROPERTY(QString spellListHtml READ spellListHtml NOTIFY spellListHtmlChanged)
    Q_PROPERTY(QString defaultSpellListHtml READ defaultSpellListHtml NOTIFY defaultSpellListHtmlChanged)

public:
    explicit QWarloksDuelCore(QObject *parent = 0);

    bool isNeedLogin();
    QString login();
    QString password();
    QString proxyHost();
    int proxyPort();
    QString proxyUser();
    QString proxyPass();
    QString errorMsg();
    QString playerInfo();
    QString readyInBattles();
    QString waitingInBattles();
    QString finishedBattles();
    QString finishedBattle();
    int readyBattle();
    int isLoading();
    int loadedBattleID();
    QString targets();
    QString warlocks();
    QString monsters();
    QString leftGesture();
    QString rightGesture();
    int registerNewUser();
    QString monsterCommandList();
    QString leftHand();
    QString rightHand();
    int orderSubmited();
    QString charmPerson();
    QString paralyze();
    int timerState();
    int isDelay();
    int isPermanent();
    QString fire();
    int challengeSubmited();
    QString challengeList();
    QString spellListHtml();
    QString defaultSpellListHtml();

signals:
    void needLogin();
    void loginChanged();
    void passwordChanged();
    void proxyHostChanged();
    void proxyPortChanged();
    void proxyUserChanged();
    void proxyPassChanged();
    void errorOccurred();
    void playerInfoChanged();
    void readyInBattlesChanged();
    void waitingInBattlesChanged();
    void finishedBattlesChanged();
    void finishedBattleChanged();
    void readyBattleChanged();
    void isLoadingChanged();
    void loadedBattleIDChanged();
    void targetsChanged();
    void warlocksChanged();
    void monstersChanged();
    void leftGestureChanged();
    void rightGestureChanged();
    void registerNewUserChanged();
    void monsterCommandListChanged();
    void leftHandChanged();
    void rightHandChanged();
    void orderSubmitedChanged();
    void charmPersonChanged();
    void paralyzeChanged();
    void timerStateChanged();
    void isDelayChanged();
    void fireChanged();
    void isPermanentChanged();
    void challengeSubmitedChanged();
    void challengeListChanged();
    void spellListHtmlChanged();
    void defaultSpellListHtmlChanged();

public slots:

    void scanState();
    void getChallengeList();
    void acceptChallenge(int battle_id);
    void forceSurrender(int battle_id, int turn);
    void sendOrders(QString orders);
    void setLogin(QString Login, QString Password);
    void setProxySettings(QString IP, int Port, QString Username, QString Password);
    void createNewChallenge(bool Fast, bool Private, bool ParaFC, bool Maladroid, int Count, int FriendlyLevel, QString Description);
    void regNewUser(QString Login, QString Password, QString Email);
    void getBattle(int battle_id, int battle_type);

    void slotReadyRead();
    void slotError(QNetworkReply::NetworkError error);
    void slotSslErrors(QList<QSslError> error_list);

    QString getSpellList(QString left, QString right, bool strikt, bool Enemy);

    void prepareSpellHtmlList(bool emit_signal = true, bool force_emit = false);
protected slots:
    void loginToSite();

protected:
    bool processData(QString &Data, int StatusCode, QString url, QString new_url);
    bool finishLogin(QString &Data, int StatusCode, QUrl NewUrl);
    bool finishRegistration(QString &Data, int StatusCode, QUrl NewUrl);
    bool finishOrderSubmit(QString &Data, int StatusCode, QUrl NewUrl);
    bool finishCreateChallenge(QString &Data, int StatusCode, QUrl NewUrl);
    bool finishAccept(QString &Data, int StatusCode, QUrl NewUrl);
    bool finishScan(QString &Data, int StatusCode);
    bool finishGetFinishedBattle(QString &Data);
    void finishChallengeList(QString &Data, int StatusCode, QUrl NewUrl);
    bool butifyTurnMessage();
    bool parseTargetList(QString &Data);
    bool parseUnits(QString &Data);
    bool parseMonsterCommand(QString &Data);
    bool prepareMonsterHtml();
    bool prepareWarlockHtml();
    bool parseSpecReadyBattleValues(QString &Data);

    bool parseReadyBattle(QString &Data);
    void parsePlayerInfo(QString &Data);

    void saveParameters();
    void loadParameters();

private:
    // user login
    bool _isLogined;
    QString _login;
    QString _password;
    QString _errorMsg;

    // user statistic
    int _played;
    int _won;
    int _died;
    int _ladder;
    int _melee;
    int _elo;
    QList<int> _ready_in_battles;
    QList<int> _waiting_in_battles;
    QList<int> _finished_battles;
    QString _finishedBattle;

    // current battle
    int _loadedBattleID;
    int _loadedBattleType;
    int _loadedBattleTurn;
    QList<QValueName> _Targets;
    QList<QMonster *> _Monsters;
    QString _MonstersHtml;
    QList<QWarlock *> _Warlock;
    QString _WarlockHtml;
    QString _possibleLeftGestures;
    QString _possibleRightGestures;
    QString _leftGestures;
    QString _rightGestures;
    QString _monsterCommandList;
    QString _charmPersonList;
    QString _paralyzeList;
    bool _isDelay;
    bool _isPermanent;
    QString _fire;
    QString _challengeList;
    QString _spellListHtml;
    QString _prevGestures;

    // management
    bool _isTimerActive;

    // Spell checker
    QWarlockSpellChecker SpellChecker;

    // dictionary
    QWarlockDictionary *WarlockDictionary;

    // proxy
    QString _proxyHost;
    int _proxyPort;
    QString _proxyUser;
    QString _proxyPass;

    // network
    bool _isLoading;
    int _requestIdx;
    QNetworkAccessManager _nam;
    QNetworkReply *_reply;
    QNetworkProxy _proxy;

    void applyProxySettings();
    void saveRequest(QString &data);
};

#endif // QWARLOKSDUELCORE_H