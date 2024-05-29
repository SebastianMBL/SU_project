#ifndef INCLUDE_H
#define INCLUDE_H

#include <QtSql>
#include <QSqlDatabase>
#include <QString>
#include <math.h>
#include <chrono>
#include <thread>
#include <random>
#include <iostream>
#include <string>


class include
{
public:

    //FUNCTIONS
    static void cleanUp();

    //MENUS
    static void startMenu();
    static void gameMenu();
    static void battle();
    static void win();
    static void die();
};

#endif // INCLUDE_H
