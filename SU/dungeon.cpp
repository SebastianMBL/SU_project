#include "dungeon.h"

Dungeon::Dungeon() {
    mQuery.exec("CREATE TABLE dungeonDB ("
                "id         INT PRIMARY KEY AUTO_INCREMENT,"
                "name       CHAR(100),"
                "xp         INT,"
                "opp        INT)");

    mQuery.exec("INSERT INTO dungeonDB (name, xp, opp) VALUES "
                "('Easy',   5000,   3), "
                "('Medium', 10000,  6), "
                "('Hard',   15000,  9)" );
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
    opponents   = mQuery.value(3).toInt();
}
