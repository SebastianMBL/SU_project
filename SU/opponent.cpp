#include "opponent.h"

Opponent::Opponent() {
    mQuery.exec("CREATE TABLE opponentDB ("
                "id         INT PRIMARY KEY AUTO_INCREMENT,"
                "name       CHAR(100),"
                "xp         INT,"
                "hp         INT,"
                "str        INT)");

    mQuery.exec("INSERT INTO opponentDB (name, xp, hp, str) VALUES "
                "('Golem', 800, 10, 1), "
                "('Phoenix', 600, 5, 1), "
                "('Hydra', 1000, 7, 2), "
                "('Harpy', 400, 4, 1)");
}

Opponent::~Opponent() {
    mQuery.exec("DROP TABLE opponentDB");
}
