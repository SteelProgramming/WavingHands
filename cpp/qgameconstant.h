#ifndef QGAMECONSTANT
#define QGAMECONSTANT

#include <QList>
#include <QMap>

#define SALT "(casdDasfa4242323f$CKASDf*0#2222@*$Y&_(a)-FAASS23"
#define ORGANIZATION_NAME "Steel Programming"
#define APPLICATION_NAME "WarloksDuel"
#define APPLICATION_TITLE "Warloks Duel"
#define APPLICATION_VERSION_PRINT "0.1"
#define APPLICATION_VERSION       "1"
#define APPLICATION_VERSION_INT   1
#define APPLICATION_PACKAGE "net.is.games.WarlocksDuel"
#define APPLICATION_INSTALLER_PACKAGE ""

#define GAME_SERVER_URL "https://games.ravenblack.net/"
#define GAME_SERVER_URL_LOGIN "https://games.ravenblack.net/login"
#define GAME_SERVER_URL_PLAYER "https://games.ravenblack.net/player"
#define GAME_SERVER_URL_CHALLENGES "https://games.ravenblack.net/challenges"
#define GAME_SERVER_URL_PLAYERS "https://games.ravenblack.net/players"
#define GAME_SERVER_URL_ACCEPT_CHALLENGE "https://games.ravenblack.net/accept?back=%1&num=%2"
#define GAME_SERVER_URL_REFUSE_CHALLENGE "https://games.ravenblack.net/refuse?back=player&num=%1"
#define GAME_SERVER_URL_LEAVE_GAME "https://games.ravenblack.net/leave?num=%1"
#define GAME_SERVER_URL_DELLMESS "https://games.ravenblack.net/delmess?from=%1"
#define GAME_SERVER_URL_SUBMIT "https://games.ravenblack.net/warlocksubmit"
#define GAME_SERVER_URL_GET_BATTLE "https://games.ravenblack.net/warlocks?num=%1"
#define GAME_SERVER_URL_GET_PROFILE "https://games.ravenblack.net/player/%1.html"
#define GAME_SERVER_URL_NEW_CHALLENGE "https://games.ravenblack.net/newchallenge"
#define GAME_SERVER_URL_NEW_PLAYER "https://games.ravenblack.net/newplayer?action=new"
#define GAME_SERVER_URL_SENDMESS "https://games.ravenblack.net/sendmess"
#define GAME_SERVER_URL_GET_FINISHED_BATTLE "https://games.visk.in.ua/robot_gateway/wh/index.php?battle_id=%1&show_data=1"


#define SPELL_TYPE_SUMMON_MONSTER 0
#define SPELL_TYPE_POISON 1
#define SPELL_TYPE_CONFUSION 2
#define SPELL_TYPE_DAMAGE 3
#define SPELL_TYPE_SHIELD 4
#define SPELL_TYPE_MAGIC_SHIELD 5
#define SPELL_TYPE_MASSIVE 6
#define SPELL_TYPE_HASTLE 7
#define SPELL_TYPE_CHARM_MONSTER 8
#define SPELL_TYPE_CURE 9
#define SPELL_TYPE_SPEC 10
#define SPELL_TYPE_DEATH 11
#define SPELL_TYPE_RESIST 12
#define SPELL_TYPE_ELEMENTAL 13
#define SPELL_TYPE_REMOVE_ENCHANTMENT 14
#define SPELL_TYPE_STAB 15
#define SPELL_TYPE_DAMAGE_FIRE 16
#define SPELL_TYPE_DAMAGE_ICE 17

#define SPELL_DISPEL_MAGIC 0
#define SPELL_SUMMON_ICE_ELEMENTAL 1
#define SPELL_SUMMON_FIRE_ELEMENTAL 2
#define SPELL_MAGIC_MIRROR 3
#define SPELL_LIGHTNING_BOLT 4
#define SPELL_CURE_HEAVY_WOUNDS 5
#define SPELL_CURE_LIGHT_WOUNDS 6
#define SPELL_BLINDNESS1 7
#define SPELL_AMNESIA 8
#define SPELL_CONFUSION 9
#define SPELL_DISEASE 10
#define SPELL_BLINDNESS2 11
#define SPELL_DELAY_EFFECT 12
#define SPELL_POISON 13
#define SPELL_PARALYSIS 14
#define SPELL_SUMMON_GIANT 15
#define SPELL_SUMMON_TROLL 16
#define SPELL_SUMMON_OGRE 17
#define SPELL_SUMMON_GOBLIN 18
#define SPELL_FIREBALL 19
#define SPELL_SHIELD 20
#define SPELL_REMOVE_ENCHANTMENT 21
#define SPELL_INVISIBILITY 22
#define SPELL_CHARM_MONSTER 23
#define SPELL_CHARM_PERSON 24
#define SPELL_FINGER_OF_DEATH 25
#define SPELL_HASTE 26
#define SPELL_MAGIC_MISSILE 27
#define SPELL_ANTI_SPELL 28
#define SPELL_PERMANENCY 29
#define SPELL_TIME_STOP1 30
#define SPELL_TIME_STOP2 31
#define SPELL_RESIST_COLD 32
#define SPELL_FEAR 33
#define SPELL_FIRE_STORM 34
#define SPELL_CLAP_OF_LIGHTNING 35
#define SPELL_CAUSE_LIGHT_WOUNDS 36
#define SPELL_CAUSE_HEAVY_WOUNDS 37
#define SPELL_COUNTER_SPELL1 38
#define SPELL_ICE_STORM 39
#define SPELL_RESIST_HEAT 40
#define SPELL_PROTECTION 41
#define SPELL_COUNTER_SPELL2 42
#define SPELL_SURRENDER 43
#define SPELL_STAB 44
#define SPELL_DISEASE_FDF 45
#define SPELL_PARALYSIS_FDF 46
#define SPELL_PARALYSIS_FDFD 47

#define SPELL_ID_MAX 48

#define WARLOCK_HAND_NONE 0
#define WARLOCK_HAND_LEFT 1
#define WARLOCK_HAND_RIGHT 2

#define WARLOCK_PLAYER false
#define WARLOCK_ENEMY true

#define SPELL_PRIORITY_ZERO -999
#define SPELL_DEF_TARGER_NOBODY 0
#define SPELL_DEF_TARGER_SELF 1
#define SPELL_DEF_TARGER_ENEMY 2
#define SPELL_DEF_TARGER_ENEMY_MONSTER 3
#define SPELL_DEF_TARGER_SELF_MONSTER 4

static QStringList _possibleGestures {"W", "S", "D", "C", "F", "P"};
static QMap<QString, QString> gestureParaCFMap{{"C","F"},{"S","D"},{"W","P"}};
static QMap<QString, QString> gestureParaFCMap{{"F","C"},{"S","D"},{"W","P"}};
static QStringList _lstAI = QStringList({"CONSTRUCT", "EARTHGOLEM", "IRONGOLEM"});


#define intToStr QString::number
#define boolToInt(val) (val?1:0)
#define boolToIntS(val) (val?"1":"0")
#define boolToStr(val) (val?"true":"false")

#define DEBUG_MESSAGE_PATTERN "%{time} %{function} %{message}"

#include <QDebug>

#endif // QGAMECONSTANT

