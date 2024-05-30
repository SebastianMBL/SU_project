#ifndef DUNGEON_H
#define DUNGEON_H

#include "include.h"


class Dungeon
{
public:
    //VARIABLES
    std::string     name;
    int             experience;
    int             gold;
    int             opponents;

    //CONSTRUCTOR
    Dungeon();
    //DESTRUCTOR
    ~Dungeon();

    //FUNCTIONS
    void load(int dungeonType);

private:
    QSqlQuery mQuery;
};

#endif // DUNGEON_H
