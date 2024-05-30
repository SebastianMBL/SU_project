#include "opponent.h"
#include "hero.h"

Opponent::Opponent() {
    mQuery.exec("CREATE TABLE opponentDB ("
                "id         INT PRIMARY KEY AUTO_INCREMENT,"
                "name       CHAR(100),"
                "xp         INT,"
                "hp         INT,"
                "str        INT,"
                "elem       CHAR(100))");

    mQuery.exec("INSERT INTO opponentDB (name, xp, hp, str, elem) VALUES "
                "('Fire Golem',     600,    10,     2,      'Fire'), "
                "('Phoenix',        900,    11,     4,      'Fire'), "
                "('Dragon',         3000,   111,    6,      'Fire'), "
                "('Earth Golem',    600,    20,     1,      'Earth'),"
                "('Gargoyle',       800,    39,     2,      'Earth'),"
                "('Giant',          1700,   82,     4,      'Earth'),"
                "('Metal Golem',    600,    17,     1,      'Metal'),"
                "('Alicanto',       1100,   22,     3,      'Metal'),"
                "('Tombstone',      1800,   37,     7,      'Metal'),"
                "('Water Golem',    600,    8,      2,      'Water'),"
                "('Hydra',          1000,   18,     3,      'Water'),"
                "('Kraken',         2100,   72,     5,      'Water'),"
                "('Wood Golem',     600,    7,      2,      'Wood'),"
                "('Troll',          1000,   44,     2,      'Wood'),"
                "('Ent',            2600,   96,     5,      'Wood')");
}

Opponent::~Opponent() {
    mQuery.exec("DROP TABLE opponentDB");
}

void Opponent::random() {
    std::string opponentNames[15] = {"Fire Golem",   "Phoenix",  "Dragon",
                                    "Earth Golem",  "Gargoyle", "Giant",
                                    "Metal Golem",  "Alicanto", "Tombstone",
                                    "Water Golem",  "Hydra",    "Kraken",
                                    "Wood Golem",   "Troll",    "Ent"};
    std::random_device ranDev;
    int opponentNr = ranDev() % 15; // 15 being the number of opponents possible, nr = [0 ..14]

    mQuery.prepare("SELECT * FROM opponentDB WHERE name = :name");
    mQuery.bindValue(":name",   QString::fromStdString(opponentNames[opponentNr]));
    mQuery.exec();
    mQuery.next();

    name        = mQuery.value(1).toString().toStdString();
    experience  = mQuery.value(2).toInt();
    hitPoints   = mQuery.value(3).toInt();
    strength    = mQuery.value(4).toInt();
    element     = mQuery.value(5).toString().toStdString();

    currentHP   = hitPoints;
}

void Opponent::load(std::string opponentName) {
    mQuery.prepare("SELECT * FROM opponentDB WHERE name = :name");
    mQuery.bindValue(":name",   QString::fromStdString(opponentName));
    mQuery.exec();
    mQuery.next();

    name        = mQuery.value(1).toString().toStdString();
    experience  = mQuery.value(2).toInt();
    hitPoints   = mQuery.value(3).toInt();
    strength    = mQuery.value(4).toInt();
    element     = mQuery.value(5).toString().toStdString();

    currentHP   = hitPoints;
}

void Opponent::printStats(){
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "               Opponent:                " << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "Name :        " << name                   << std::endl;
    std::cout << "Experience :  " << experience             << std::endl;
    std::cout << "Hit Points :  " << hitPoints              << std::endl;
    std::cout << "Strength :    " << strength               << std::endl;
    std::cout << "Element :     " << element                << std::endl;
}

void Opponent::printHP() {
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "HP: " << currentHP << "/" << hitPoints << std::endl;
    //int amount = rint(;

    switch ((currentHP *10) / hitPoints) {
        case 0:
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    break;
        case 1:
    std::cout << "████~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    break;
        case 2:
    std::cout << "████████~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    break;
        case 3:
    std::cout << "████████████~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    break;
        case 4:
    std::cout << "████████████████~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    break;
        case 5:
    std::cout << "████████████████████~~~~~~~~~~~~~~~~~~~~" << std::endl;
    break;
        case 6:
    std::cout << "████████████████████████~~~~~~~~~~~~~~~~" << std::endl;
    break;
        case 7:
    std::cout << "████████████████████████████~~~~~~~~~~~~" << std::endl;
    break;
        case 8:
    std::cout << "████████████████████████████████~~~~~~~~" << std::endl;
    break;
        case 9:
    std::cout << "████████████████████████████████████~~~~" << std::endl;
    break;
        case 10:
    std::cout << "████████████████████████████████████████" << std::endl;
    break;
            }
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}
