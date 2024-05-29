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

void Opponent::random() {
    std::string opponentNames[4] = {"Golem", "Phoenix", "Hydra", "Harpy"};
    std::random_device ranDev;
    int opponentNr = ranDev() % 4; // 4 being the number of opponents possible, nr = [0 ..3]

    mQuery.prepare("SELECT * FROM opponentDB WHERE name = :name");
    mQuery.bindValue(":name",   QString::fromStdString(opponentNames[opponentNr]));
    mQuery.exec();
    mQuery.next();

    name        = mQuery.value(1).toString().toStdString();
    experience  = mQuery.value(2).toInt();
    hitPoints   = mQuery.value(3).toInt();
    strength    = mQuery.value(4).toInt();

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
