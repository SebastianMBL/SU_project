    #include "database.h"
    #include "hero.h"

int main()
{
    Database DB;
    Hero hero;

    int load;



//Start MENU//
    include::cleanUp();
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "   Welcome to the Story of Legends   " << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "0 -> Start a new legend" << std::endl;
    std::cout << "1 -> Load an old legend" << std::endl;
    std::cin >> load;
    std::cout << load << std::endl;

    if (load == 0) {                        //New Game//
        hero.newHero();
        hero.printStats();
    } else {                                //Load Game//
        hero.loadHero();
        hero.printStats();
    }
    return 0;
}
