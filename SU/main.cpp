    #include "database.h"
    #include "hero.h"

int main()
{
    Database DB;
    Hero hero;


    int load;
    std::string hero_name;



//Start MENU//
    std::cout << "Welcome to the game" << std::endl;
    std::cout << "(0)New game (1)Load game: " << std::endl;
    std::cin >> load;
    std::cout << load << std::endl;

    if (load == 1) {                        //Load Game//
        std::cout << "you chose Load game";
        std::cout << "Name of Hero: ";
        std::cin >> hero_name;
    } else {                                //New Game//
        hero.newHero();
    }
    return 0;
}
