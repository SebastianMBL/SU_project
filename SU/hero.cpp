#include "hero.h"

Hero::Hero() {
    mQuery.exec("CREATE TABLE heroDB ("
                "id         INT PRIMARY KEY AUTO_INCREMENT,"
                "name       CHAR(100),"
                "xp         INT,"
                "level      INT,"
                "hp         INT,"
                "str        INT)");
}

bool Hero::newHero() {
    std::string Hname;
    include::cleanUp();

    std::cout << "you chose New game"                   << std::endl;
    std::cout << "Name your new Hero: "                 << std::endl;
    std::cin >> Hname;

    mQuery.prepare("INSERT INTO heroDB (name, xp, level, hp, str)"
                   "VALUES (:name, :xp, :level, :hp, :str)");
    mQuery.bindValue(":name",   QString::fromStdString(Hname));
    mQuery.bindValue(":xp",     0);
    mQuery.bindValue(":level",  1);
    mQuery.bindValue(":hp",     10);
    mQuery.bindValue(":str",    2);

    mQuery.exec();

    include::cleanUp();
    std::cout << "Welcome to the legend of " << Hname    << std::endl;

    name        = Hname;
    experience  = 0;
    level       = 1;
    hitPoints   = 10;
    strength    = 2;

    return true;
}

bool Hero::loadHero() {
    include::cleanUp();

    mQuery.exec("SELECT * FROM heroDB");

    if (!mQuery.next()) {
        std::cout << "you have no heroes"               << std::endl;
        return false;
    }

    std::cout << "Here are all of your heroes: "        << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<  "        << std::endl;
    do {QString     Hname    = mQuery.value(1).toString();
        int         Hlevel   = mQuery.value(3).toInt();

        std::cout << "Hero  :" << Hname.toStdString()   << std::endl;
        std::cout << "Level :" << Hlevel                << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~"      << std::endl;
    } while (mQuery.next());

    std::string Hname;
    std::cout << "Which one are you going to play :"    << std::endl;
    std::cin >> Hname;

    mQuery.prepare("SELECT * FROM heroDB WHERE name = :name");
    mQuery.bindValue(":name",   QString::fromStdString(Hname));

    if(!mQuery.exec()){
        std::cout << "Couldn't find the hero"           << std::endl;
        std::cout << "Press enter to continue"          << std::endl;
        return false;
    }

    include::cleanUp();
    std::cout << "Welcome back"                         << std::endl;
    std::cout << "to the legend of " << Hname           << std::endl;

    mQuery.prepare("SELECT * FROM heroDB WHERE name = :name");
    mQuery.bindValue(":name",   QString::fromStdString(Hname));
    mQuery.exec();
    if (!mQuery.next()){
        std::cout << "Could't find the Hero you were looking for" << std::endl;
        return false;
    }

    name        = mQuery.value(1).toString().toStdString();
    experience  = mQuery.value(2).toInt();
    level       = mQuery.value(3).toInt();
    hitPoints   = mQuery.value(4).toInt();
    strength    = mQuery.value(5).toInt();


    return true;
}

void Hero::printStats() {
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "               Stats:               " << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "Name :        " << name               << std::endl;
    std::cout << "Experience :  " << experience         << std::endl;
    std::cout << "Level :       " << level              << std::endl;
    std::cout << "Hit Points :  " << hitPoints          << std::endl;
    std::cout << "Strength :    " << strength           << std::endl;
}

void Hero::update() {
    mQuery.prepare("UPDATE heroDB SET xp = :experience, level = :level, hp = :hitPoints, str = :strength WHERE name = :name");

    mQuery.bindValue(":experience", experience);
    mQuery.bindValue(":level", level);
    mQuery.bindValue(":hitPoints", hitPoints);
    mQuery.bindValue(":strength", strength);
    mQuery.bindValue(":name", QString::fromStdString(name));

    if (!mQuery.exec()) {
        std::cout << "didn't sucessfully update" << std::endl;
    }
}
