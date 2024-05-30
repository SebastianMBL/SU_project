#ifndef OPPONENT_H
#define OPPONENT_H

#include "include.h"

class Opponent
{
public:
    //VARIABLES
    std::string name;
    int         experience;
    int         hitPoints;
    int         strength;
    std::string  element;

    int         currentHP;

    //CONSTRUCTOR
    Opponent();
    //DESTRUCTOR
    ~Opponent();

    //FUNCTIONS
    void random();
    void printStats();
    void printHP();
    void load(std::string oponentName);

private:
    QSqlQuery mQuery;

};

#endif // OPPONENT_H
