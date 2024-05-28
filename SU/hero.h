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


    //CONSTRUCTOR
    Hero();

    //FUNCTIONS
    bool newHero();
    bool loadHero();
    void printStats();
    void update();

private:
    QSqlQuery mQuery;

};

#endif // HERO_H
