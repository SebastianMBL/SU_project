#ifndef OPPONENT_H
#define OPPONENT_H

#include "include.h"

class Opponent
{
public:
    //VARIABLES
    std::string name;
    int         xp;
    int         hp;
    int         str;

    //CONSTRUCTOR
    Opponent();
    //DESTRUCTOR
    ~Opponent();

private:
    QSqlQuery mQuery;

};

#endif // OPPONENT_H
