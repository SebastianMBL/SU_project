#ifndef HERO_H
#define HERO_H

#include "include.h"

class Hero
{
public:
    //VARIABLES
    std::string name;
    int         experience;
    int         level;
    int         hitPoints;
    int         strength;
    int         currentHP;


    //CONSTRUCTOR
    Hero();

    //FUNCTIONS
    bool newHero();
    bool loadHero();
    bool removeHero();
    void printStats();
    void printHP();
    void update();
    void rest();
    void die();

private:
    QSqlQuery mQuery;

};

#endif // HERO_H
