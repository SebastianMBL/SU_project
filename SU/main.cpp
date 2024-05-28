#include <iostream>

#include <QtSql>
#include <QSqlDatabase>

int main()
{
    int load;
    std::string hero_name;

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost"); // Currently set to localhost
    db.setDatabaseName("Game"); // Change to desired schema DEN REELLE DATABASE
    db.setUserName("sammy"); // Change to username
    db.setPassword("password"); // Change to password
    db.open();

//Start MENU//
    std::cout << "Welcome to the game" << std::endl;
    std::cout << "(0)New game (1)Load game: " << std::endl;
    std::cin >> load;
    std::cout << load << std::endl;

    if (load == 1) {                        //Load Game//
        std::cout << "you chose Load game";
        std::cout << "Name of Hero:";
        std::cin >> hero_name;
    } else {                                //New Game//
        std::cout << "you chose New game" << std::endl;
        std::cout << "Name of Hero: ";
        std::cin >> hero_name;
        std::cout << "Welcome to the legend of " << hero_name << std::endl;
    }
    return 0;
}
