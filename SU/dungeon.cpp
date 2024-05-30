#include "dungeon.h"

Dungeon::Dungeon() {
    mQuery.exec("CREATE TABLE dungeonDB ("
                "id         INT PRIMARY KEY AUTO_INCREMENT,"
                "name       CHAR(100),"
                "xp         INT,"
                "gold       INT,"
                "opp        INT)");

    mQuery.exec("INSERT INTO dungeonDB (name, xp, gold, opp) VALUES "
                "('Easy',   3000,   2,      3), "
                "('Medium', 6000,   5,      6), "
                "('Hard',   10000,  10,     9)" );
}

Dungeon::~Dungeon() {
    mQuery.exec("DROP TABLE dungeonDB");
}

void Dungeon::load(int dungeonType) {
    std::string dungeonName;
    switch (dungeonType) {
    case 0:
        dungeonName = "Easy";
        break;
    case 1:
        dungeonName = "Medium";
        break;
    case 2:
        dungeonName = "Hard";
    }

    mQuery.prepare("SELECT * FROM dungeonDB WHERE name = :name");
    mQuery.bindValue(":name",   QString::fromStdString(dungeonName));
    mQuery.exec();
    mQuery.next();

    name        = mQuery.value(1).toString().toStdString();
    experience  = mQuery.value(2).toInt();
    gold        = mQuery.value(3).toInt();
    opponents   = mQuery.value(4).toInt();
}
