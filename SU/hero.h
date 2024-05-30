#ifndef HERO_H
#define HERO_H

#include "include.h"

class Hero
{
public:
    //VARIABLES
    std::string name;
    int         experience;
    int         gold;
    int         level;
    int         hitPoints;
    int         strength;
    int         currentHP;
    std::string ring;
    int         mana;

    std::string weak;
    std::string strong;


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
    int ringPower(std::string opponentType);
    void die();

private:
    QSqlQuery mQuery;

};

#endif // HERO_H
