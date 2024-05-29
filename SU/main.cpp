    #include "database.h"
    #include "hero.h"
    #include "opponent.h"

int main()
{
    Database DB;
    Hero hero;
    Opponent opponent;

    int input;
    int temp;


//Start MENU//

    include::cleanUp();
    include::startMenu();
    std::cin >> input;

    do {
    switch (input) {
        case 0: //NEW
            include::cleanUp();
            hero.newHero();
            hero.printStats();
            break;

        case 1: //LOAD
            include::cleanUp();
            hero.loadHero();
            hero.printStats();
            break;

        case 2: //EXIT
            std::cout << "Exiting the Story of Legends.."   << std::endl;
            return 0;

        default:
            std::cout << "Not possible, try again"          << std::endl;
    }
    } while((input != 0) && (input != 1));

//Game MENU//
    do {
        include::cleanUp();
        hero.printStats();
        hero.printHP();
        include::gameMenu();
        std::cin >> input;

        do {
            switch (input) {
                case 0:
                    include::cleanUp();
                    include::battle();
                    opponent.random();
                    opponent.printStats();
                    std::cout << "Press enter to continue.."        << std::endl;
                    std::cin.ignore();
                    std::cin.get();
                    do {
                        include::cleanUp();
                        include::battle();
                        std::cout                                   << std::endl;
                        std::cout << hero.name                      << std::endl;
                        hero.printHP();
                        std::cout                                   << std::endl;
                        std::cout << opponent.name                  << std::endl;
                        opponent.printHP();

                        opponent.currentHP -= hero.strength;
                        hero.currentHP -= opponent.strength;
                        std::this_thread::sleep_for(std::chrono::seconds(1) );


                    } while(hero.currentHP > 0 && opponent.currentHP > 0);

                    break;

                case 1:
                    hero.rest();
                    break;

                case 2: //EXIT
                    include::cleanUp();
                    std::cout << "Exiting the Story of Legends.."   << std::endl;
                    return 0;

                default:
                    std::cout << "Not possible, try again"          << std::endl;
            }
        } while(input != 0 && input != 1);
    } while(true);
    return 0;
}
