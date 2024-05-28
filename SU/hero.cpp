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
    std::string name;
    include::cleanUp();

    std::cout << "you chose New game" << std::endl;
    std::cout << "Name of Hero: ";
    std::cin >> name;

    mQuery.prepare("INSERT INTO heroDB (name, xp, level, hp, str)"
                "VALUES (:name, :xp, :level, :hp, :str)");
    mQuery.bindValue(":name",   QString::fromStdString(name));
    mQuery.bindValue(":xp",     0);
    mQuery.bindValue(":level",  1);
    mQuery.bindValue(":hp",     10);
    mQuery.bindValue(":str",    2);

    include::cleanUp();
    std::cout << "Welcome to the legend of " << name << std::endl;

    return true;
}

bool Hero::loadHero() {
    return true;
}
