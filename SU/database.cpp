#include "database.h"

Database::Database()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost"); // Currently set to localhost
    db.setDatabaseName("Game"); // Change to desired schema DEN REELLE DATABASE
    db.setUserName("sammy"); // Change to username
    db.setPassword("password"); // Change to password
    db.open();
}
