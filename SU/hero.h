#ifndef HERO_H
#define HERO_H

#include "include.h"

class Hero
{
public:
    //CONSTRUCTOR
    Hero();

    //FUNCTIONS
    bool newHero();
    bool loadHero();

private:
    QSqlQuery mQuery;

};

#endif // HERO_H
