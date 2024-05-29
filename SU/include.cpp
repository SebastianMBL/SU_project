#include "include.h"

void include::cleanUp() {
    std::system("clear");

}

void include::startMenu() {

    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "     Welcome to the Story of Legends    " << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "0 -> Start a new legend"                  << std::endl;
    std::cout << "1 -> Load an old legend"                  << std::endl;
    std::cout << "2 -> Remove an old legend"                << std::endl;
    std::cout << "3 -> Exit the Story of Legends"           << std::endl;

}

void include::gameMenu() {

    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "      What are you gonna do today?      " << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "0 -> Let your Hero face an opponent"      << std::endl;
    std::cout << "1 -> Let your Hero rest"                  << std::endl;
    std::cout << "2 -> Exit the Story of Legends"           << std::endl;

}

void include::battle() {

    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "             TIME FOR A DUAL            " << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;

}

void include::win() {

    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "                YOU WON                 " << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;

}

void include::die() {

    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "          Your legend is over           " << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "You have tragically lost the battle, and" << std::endl;
    std::cout << "have therefore sadly passed away.       " << std::endl;
    std::cout << "This legend has now found its very end. " << std::endl;

}
