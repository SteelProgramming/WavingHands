#include "qwarlockspellchecker.h"

QWarlockSpellChecker::QWarlockSpellChecker(QObject *parent) :
    QObject(parent)
{
    Spells.append(new QSpell(0,"cDPW","Dispel Magic", SPELL_TYPE_REMOVE_ENCHANTMENT,0,1,10));
    Spells.append(new QSpell(1,"cSWWS","Summon Ice Elemental", SPELL_TYPE_ELEMENTAL,4,0,15));
    Spells.append(new QSpell(2,"cWSSW","Summon Fire Elemental", SPELL_TYPE_ELEMENTAL,5,1,15));
    Spells.append(new QSpell(3,"cw","Magic Mirror", SPELL_TYPE_MAGIC_SHIELD,0,0,10));
    Spells.append(new QSpell(4,"DFFDD","Lightning Bolt", SPELL_TYPE_DAMAGE,1,1,16));
    Spells.append(new QSpell(5,"DFPW","Cure Heavy Wounds", SPELL_TYPE_CURE,0,1,10));
    Spells.append(new QSpell(6,"DFW","Cure Light Wounds", SPELL_TYPE_CURE,0,0,10));
    Spells.append(new QSpell(7,"DFWFd","Blindness", SPELL_TYPE_CONFUSION,4,0,15));
    Spells.append(new QSpell(8,"DPP","Amnesia", SPELL_TYPE_CONFUSION,6,1,12));
    Spells.append(new QSpell(9,"DSF","Confusion/Maladroitness", SPELL_TYPE_CONFUSION,6,0,12));
    Spells.append(new QSpell(10,"DSFFFc","Disease", SPELL_TYPE_POISON,4,1,17));
    Spells.append(new QSpell(11,"DWFFd","Blindness", SPELL_TYPE_CONFUSION,4,0,15));
    Spells.append(new QSpell(12,"DWSSSP","Delay Effect", SPELL_TYPE_SPEC,0,0,10));
    Spells.append(new QSpell(13,"DWWFWD","Poison", SPELL_TYPE_POISON,3,1,18));
    Spells.append(new QSpell(14,"FFF","Paralysis", SPELL_TYPE_CONFUSION,5,0,12));
    Spells.append(new QSpell(15,"WFPSFW","Summon Giant", SPELL_TYPE_SUMMON_MONSTER,4,4,14));
    Spells.append(new QSpell(16,"FPSFW","Summon Troll", SPELL_TYPE_SUMMON_MONSTER,3,3,13));
    Spells.append(new QSpell(17,"PSFW","Summon Ogre", SPELL_TYPE_SUMMON_MONSTER,2,2,12));
    Spells.append(new QSpell(18,"SFW","Summon Goblin", SPELL_TYPE_SUMMON_MONSTER,1,1,11));
    Spells.append(new QSpell(19,"FSSDD","Fireball", SPELL_TYPE_DAMAGE,3,1,15));
    Spells.append(new QSpell(20,"P","Shield", SPELL_TYPE_SHIELD,0,0,10));
    Spells.append(new QSpell(21,"PDWP","Remove Enchantment", SPELL_TYPE_REMOVE_ENCHANTMENT,0,0,13));
    Spells.append(new QSpell(22,"PPws","Invisibility", SPELL_TYPE_CONFUSION,3,0,13));
    Spells.append(new QSpell(23,"PSDD","Charm Monster", SPELL_TYPE_CHARM_MONSTER,0,0,12));
    Spells.append(new QSpell(24,"PSDF","Charm Person", SPELL_TYPE_CONFUSION,4,2,13));
    Spells.append(new QSpell(25,"PWPFSSSD","Finger of Death", SPELL_TYPE_DAMAGE,1,0,20));
    Spells.append(new QSpell(26,"PWPWWc","Haste", SPELL_TYPE_HASTLE,2,0,10));
    Spells.append(new QSpell(27,"SD","Magic Missile", SPELL_TYPE_DAMAGE,0,0,10));
    Spells.append(new QSpell(28,"SPFP","Anti-spell", SPELL_TYPE_CONFUSION,5,0,14));
    Spells.append(new QSpell(29,"SPFPSDW","Permanency", SPELL_TYPE_SPEC,3,0,16));
    Spells.append(new QSpell(30,"SPPc","Time Stop", SPELL_TYPE_HASTLE,3,0,10));
    Spells.append(new QSpell(31,"SPPFD","Time Stop", SPELL_TYPE_HASTLE,3,0,10));
    Spells.append(new QSpell(32,"SSFP","Resist Cold", SPELL_TYPE_RESIST,4,1,10));
    Spells.append(new QSpell(33,"SWD","Fear (No CFDS)", SPELL_TYPE_CONFUSION,5,0,12));
    Spells.append(new QSpell(34,"SWWc","Fire Storm", SPELL_TYPE_MASSIVE,3,0,14));
    Spells.append(new QSpell(35,"WDDc","Clap of Lightning", SPELL_TYPE_DAMAGE,4,0,14));
    Spells.append(new QSpell(36,"WFP","Cause Light Wounds", SPELL_TYPE_DAMAGE,4,0,12));
    Spells.append(new QSpell(37,"WPFD","Cause Heavy Wounds", SPELL_TYPE_DAMAGE,3,0,13));
    Spells.append(new QSpell(38,"WPP","Counter Spell", SPELL_TYPE_MAGIC_SHIELD,0,0,10));
    Spells.append(new QSpell(39,"WSSc","Ice Storm", SPELL_TYPE_MASSIVE,0,3,14));
    Spells.append(new QSpell(40,"WWFP","Resist Heat", SPELL_TYPE_RESIST,0,4,10));
    Spells.append(new QSpell(41,"WWP","Protection", SPELL_TYPE_SHIELD,0,1,10));
    Spells.append(new QSpell(42,"WWS","Counter Spell", SPELL_TYPE_MAGIC_SHIELD,0,1,10));
    Spells.append(new QSpell(43,"p","Surrender", SPELL_TYPE_SPEC,-10,0,0));
    Spells.append(new QSpell(44,">","Stab", SPELL_TYPE_STAB,-1,0,0));
}

bool QWarlockSpellChecker::checkSpellChar(QChar left, QChar right, QChar spell) {
    if (left != spell.toUpper()) {
        return false;
    }

    if (spell.isLower() && left != right) {
        return false;
    }

    return true;
}

bool QWarlockSpellChecker::checkStriktSpell(QString left, QString right, QString spell) {
    int Ln = spell.length();
    if (left.length() < Ln) {
        return false;
    }

    for (int i = 0; i < Ln; ++i) {
        if (!checkSpellChar(left.at(i), right.at(i), spell.at(i))) {
            return false;
        }
    }

    return true;
}

int QWarlockSpellChecker::checkSpellPosible(QString left, QString right, QString spell) {
    int Ln = spell.length() - 1, GLn = left.length() < right.length() ? left.length() : right.length();
    if (Ln == 0) {
        return 0;
    }
    QString work_spell = spell.left(Ln);
    //qDebug() << "checkSpellPosible " << spell << " work spell " << work_spell << " left " << left << " right" << right;
    bool perhapse;
    int spell_idx;
    QChar spell_char;
    for (int i = 0; i < Ln; ++i) {
        perhapse = true;
        spell_idx = -1;
        for (int j = Ln - i; j > 0; --j) {
            spell_char = work_spell.at(++spell_idx);
            if ((GLn - j < 0) || !checkSpellChar(left.at(GLn - j), right.at(GLn - j), spell_char)) {
                perhapse = false;
                break;
            }
        }
        if (perhapse) {
            return i + 1;
        }
    }
    return 0;
}

void QWarlockSpellChecker::checkHandOnSpell(QList<QSpell *> &Result, QSpell *Spell, QString left, QString right, int Hand, bool Enemy) {
    QString gestures = Spell->gesture(), w_left, w_right;
    int Ln = gestures.length();
    w_left = left.right(Ln);
    w_right = right.right(Ln);
    int l_turn_to_spell = checkSpellPosible(w_left, w_right, gestures);
    if (l_turn_to_spell > 0) {
        qDebug() << "left checkSpellPosible (" << w_left << ", " << w_right << ") " << gestures << l_turn_to_spell;
    } else {
        return;
    }
   // QSpell(QSpell *Spell, int Hand, int TurnToCast, bool Enemy = false);
    bool add = true;
    QSpell *hand_spell = new QSpell(Spell, Hand, l_turn_to_spell, Enemy);
    if (Result.count() > 0) {
        foreach(QSpell *spell, Result) {
            bool same_hand = spell->hand() == hand_spell->hand();
            bool same_spell = spell->spellID() == hand_spell->spellID();
            bool summon_moster_spell = (spell->spellType() == SPELL_TYPE_SUMMON_MONSTER) && (hand_spell->spellType() == SPELL_TYPE_SUMMON_MONSTER);
            bool priority_higer = spell->priority() < hand_spell->priority();
            if (same_hand && (same_spell || (summon_moster_spell && priority_higer))) {
                add = false;
                if (priority_higer) {
                    spell->setPriority(hand_spell->priority());
                }
                break;
            }
        }
    }
    if (add) {
        Result.append(hand_spell);
    } else {
        delete hand_spell;
    }
}

QList<QSpell *> QWarlockSpellChecker::getPosibleSpellsList(QString left, QString right, bool Enemy) {
    qDebug() << "QWarlockSpellChecker::getPosibleSpellsList" << left << right << Enemy;
    QList<QSpell *> res;

    foreach(QSpell *vn, Spells) {
        checkHandOnSpell(res, vn, left, right, WARLOCK_HAND_LEFT, Enemy);
        checkHandOnSpell(res, vn, right, left, WARLOCK_HAND_RIGHT, Enemy);
    }

    return res;
}

QList<QSpell *> QWarlockSpellChecker::getStriktSpellsList(QString left, QString right, bool Enemy) {
    qDebug() << "QWarlockSpellChecker::getStriktSpellsList" << left << right << Enemy;
    QString gestures, w_left, w_right;
    QList<QSpell *> res;

    foreach(QSpell *vn, Spells) {
        gestures = vn->gesture();
        int Ln = gestures.length();
        w_left = left.right(Ln);
        w_right = right.right(Ln);

        if (checkStriktSpell(w_left, w_right, gestures)) {
            res.append(new QSpell(vn, WARLOCK_HAND_LEFT, 0, Enemy));
        }

        if (checkStriktSpell(w_right, w_left, gestures)) {
            res.append(new QSpell(vn, WARLOCK_HAND_RIGHT, 0, Enemy));
        }
    }

    return res;
}

QList<QSpell *> QWarlockSpellChecker::getSpellsList(QString Left, QString Right, bool strikt, bool Enemy) {
    qDebug() << "QWarlockSpellChecker::getSpellsList" << Left << Right << strikt << Enemy;
    QString left = Left.replace(" ", "");
    QString right = Right.replace(" ", "");
    QList<QSpell *> sl;
    if (strikt) {
        sl = getStriktSpellsList(left, right, Enemy);
    } else {
        sl = getPosibleSpellsList(left, right, Enemy);
    }
    qDebug() << "before sort" << sl;
    qSort(sl.begin(), sl.end(), QSpell::sortDesc);
    qDebug() << "after sort" << sl;
    return sl;
}

QString QWarlockSpellChecker::checkSpells(QString Left, QString Right, bool strikt, bool Enemy) {
    qDebug() << "QWarlockSpellChecker::checkSpells" << Left << Right << strikt;
    QList<QSpell *> sl = getSpellsList(Left, Right, strikt, Enemy);

    QString res;
    foreach(QSpell *s, sl) {
        if (!res.isEmpty()) {
            res.append(",");
        }
        res.append(s->json());
        delete s;
    }
    res.prepend("[").append("]");

    //qDebug() << "spellCheckFinish result " << res;
    return res;
}