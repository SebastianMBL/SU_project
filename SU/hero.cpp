#include "hero.h"

Hero::Hero() {
    mQuery.exec("CREATE TABLE heroDB ("
                "id         INT PRIMARY KEY AUTO_INCREMENT,"
                "name       CHAR(100),"
                "xp         INT,"
                "gold       INT,"
                "lvl        INT,"
                "hp         INT,"
                "str        INT,"
                "chp        INT,"
                "ring       CHAR(100),"
                "mana       INT)");
}

bool Hero::newHero() {
    std::string Hname;
    include::cleanUp();

    std::cout << "you chose New game"                           << std::endl;
    std::cout << "Name your new Hero: "                         << std::endl;
    std::cin >> Hname;

    mQuery.prepare("INSERT INTO heroDB (name, xp, gold, lvl, hp, str, chp, ring, mana)"
                   "VALUES (:name, :xp, :gold, :lvl, :hp, :str, :chp, :ring, :mana)");
    mQuery.bindValue(":name",   QString::fromStdString(Hname));
    mQuery.bindValue(":xp",     0);
    mQuery.bindValue(":gold",   0);
    mQuery.bindValue(":lvl",    1);
    mQuery.bindValue(":hp",     10);
    mQuery.bindValue(":str",    2);
    mQuery.bindValue(":chp",    10);
    mQuery.bindValue(":ring",   QString::fromStdString(""));
    mQuery.bindValue(":mana",   0);


    mQuery.exec();

    include::cleanUp();
    std::cout << "Welcome to the legend of " << Hname           << std::endl;

    name        = Hname;
    experience  = 0;
    gold        = 0;
    level       = 1;
    hitPoints   = 10;
    strength    = 2;
    currentHP   = 10;
    ring        = "";
    mana        = 0;
    return true;
}

bool Hero::loadHero() {
    include::cleanUp();

    mQuery.exec("SELECT * FROM heroDB");

    if (!mQuery.next()) {
        std::cout << "You have no heroes"                       << std::endl;
        return false;
    }

    std::cout << "Here are all of your heroes: "                << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"     << std::endl;
    do {QString     Hname    = mQuery.value(1).toString();
        int         Hlevel   = mQuery.value(4).toInt();

        std::cout << "Hero  :" << Hname.toStdString()           << std::endl;
        std::cout << "Level :" << Hlevel                        << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    } while (mQuery.next());

    std::string Hname;
    std::cout << "Which one are you going to play :"            << std::endl;
    std::cin >> Hname;

    mQuery.prepare("SELECT * FROM heroDB WHERE name = :name");
    mQuery.bindValue(":name",   QString::fromStdString(Hname));

    if(!mQuery.exec()){
        std::cout << "Couldn't find the hero"                   << std::endl;
        std::cout << "Press enter to continue .."               << std::endl;
        std::cin.ignore();
        std::cin.get();
        return false;
    }


    mQuery.prepare("SELECT * FROM heroDB WHERE name = :name");
    mQuery.bindValue(":name",   QString::fromStdString(Hname));
    mQuery.exec();
    if (!mQuery.next()){
        include::cleanUp();
        std::cout << "Could't find a Hero of this name"         << std::endl;
        return false;
    }

    include::cleanUp();
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"     << std::endl;
    std::cout << " Welcome back to the legend of " << Hname     << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"     << std::endl;

    name        = mQuery.value(1).toString().toStdString();
    experience  = mQuery.value(2).toInt();
    gold        = mQuery.value(3).toInt();
    level       = mQuery.value(4).toInt();
    hitPoints   = mQuery.value(5).toInt();
    strength    = mQuery.value(6).toInt();
    currentHP   = mQuery.value(7).toInt();
    ring        = mQuery.value(8).toString().toStdString();
    mana        = mQuery.value(9).toInt();
    return true;
}

bool Hero::removeHero() {
    include::cleanUp();

    mQuery.exec("SELECT * FROM heroDB");

    if (!mQuery.next()) {
        std::cout << "you have no heroes"                       << std::endl;
        return false;
    }

    std::cout << "Here are all of your heroes: "                << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"     << std::endl;
    do {QString     Hname    = mQuery.value(1).toString();
        int         Hlevel   = mQuery.value(3).toInt();

        std::cout << "Hero  :" << Hname.toStdString()           << std::endl;
        std::cout << "Level :" << Hlevel                        << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    } while (mQuery.next());

    std::string Hname;
    std::cout << "Which one are you going to remove :"          << std::endl;
    std::cin >> Hname;

    mQuery.prepare("SELECT * FROM heroDB WHERE name = :name");
    mQuery.bindValue(":name",   QString::fromStdString(Hname));

    if(!mQuery.exec()){
        std::cout << "Couldn't find the hero"                   << std::endl;
        std::cout << "Press enter to continue .."               << std::endl;
        std::cin.ignore();
        std::cin.get();
        return false;
    }

    mQuery.prepare("DELETE FROM heroDB WHERE name = :name");
    mQuery.bindValue(":name",   QString::fromStdString(Hname));
    mQuery.exec();

    return true;
}

void Hero::printStats() {
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"     << std::endl;
    std::cout << "                  Stats:                "     << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"     << std::endl;
    std::cout << "Name :        " << name                       << std::endl;
    std::cout << "Experience :  " << experience                 << std::endl;
    std::cout << "gold :        " << gold                       << std::endl;
    std::cout << "Level :       " << level                      << std::endl;
    std::cout << "Hit Points :  " << hitPoints                  << std::endl;
    std::cout << "Strength :    " << strength                   << std::endl;
    if (ring != "") {
    std::cout << "Ring :        " << ring                       << std::endl;
    std::cout << "Mana :        " << mana << "/100"             << std::endl;
    }
}

void Hero::printHP() {
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"     << std::endl;
    std::cout << "HP: " << currentHP << "/" << hitPoints        << std::endl;

    switch ((currentHP *10) / hitPoints) {
        case 0:
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"     << std::endl;
    break;
        case 1:
    std::cout << "████~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"     << std::endl;
    break;
        case 2:
    std::cout << "████████~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"     << std::endl;
    break;
        case 3:
    std::cout << "████████████~~~~~~~~~~~~~~~~~~~~~~~~~~~~"     << std::endl;
    break;
        case 4:
    std::cout << "████████████████~~~~~~~~~~~~~~~~~~~~~~~~"     << std::endl;
    break;
        case 5:
    std::cout << "████████████████████~~~~~~~~~~~~~~~~~~~~"     << std::endl;
    break;
        case 6:
    std::cout << "████████████████████████~~~~~~~~~~~~~~~~"     << std::endl;
    break;
        case 7:
    std::cout << "████████████████████████████~~~~~~~~~~~~"     << std::endl;
    break;
        case 8:
    std::cout << "████████████████████████████████~~~~~~~~"     << std::endl;
    break;
        case 9:
    std::cout << "████████████████████████████████████~~~~"     << std::endl;
    break;
        case 10:
    std::cout << "████████████████████████████████████████"     << std::endl;
    break;
            }
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"     << std::endl;
}

void Hero::update() {
    if (experience >= level * 1000) {
        experience  =  0;
        level       += 1;
        hitPoints   += 2;
        strength    += 1;
    }

    mQuery.prepare("UPDATE heroDB SET xp = :xp, lvl = :lvl, hp = :hp, str = :str , chp = :chp, ring = :ring, mana = :mana WHERE name = :name");

    mQuery.bindValue(":xp", experience);
    mQuery.bindValue(":lvl", level);
    mQuery.bindValue(":hp", hitPoints);
    mQuery.bindValue(":str", strength);
    mQuery.bindValue(":chp", currentHP);
    mQuery.bindValue(":ring", QString::fromStdString(ring));
    mQuery.bindValue(":mana", mana);
    mQuery.bindValue(":name", QString::fromStdString(name));


    if (!mQuery.exec()) {
        std::cout << "didn't sucessfully update"                << std::endl;
    }
}

void Hero::rest() {
    std::random_device ranDev;
    currentHP += ranDev() % hitPoints;
    if (currentHP > hitPoints) {
        currentHP = hitPoints;
    }
}

int Hero::ringPower(std::string opponentType) {

    if (ring == "Fire"){                    //Ring type FIRE
        weak    = "Water";
        strong  = "Metal";
    }
    else if (ring == "Earth"){              //Ring type EARTH
        weak    = "Wood";
        strong  = "Water";
    }
    else if (ring == "Metal"){              //Ring tyype METAL
        weak    = "Fire";
        strong  = "Wood";
    }
    else if (ring == "Water"){              //Ring type WATER
        weak    = "Earth";
        strong  = "Fire";
    }
    else if (ring == "Wood"){               //Ring type WOOD
        weak    = "Metal";
        strong  = "Earth";
    }

    if      (opponentType == weak)      {return 10;}
    else if (opponentType == strong)    {return 40;}
    else                                {return 20;}
}

void Hero::die() {
    mQuery.prepare("DELETE FROM heroDB WHERE name = :name");
    mQuery.bindValue(":name",   QString::fromStdString(name));
    mQuery.exec();
}
