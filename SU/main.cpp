    #include "database.h"
    #include "hero.h"
    #include "opponent.h"
    #include "dungeon.h"

int main()
{
    Database DB;
    Hero hero;
    Opponent opponent;
    Dungeon dungeon;

    int input;
    int temp;


//Start MENU//
    do {
    include::cleanUp();
    include::startMenu();
    std::cin >> input;

    switch (input) {
        case 0: //NEW
            include::cleanUp();
            hero.newHero();
            hero.printStats();
            break;

        case 1: //LOAD
            include::cleanUp();
            if (!hero.loadHero()){
                input = 4;
                std::cout << "Press enter to return to menu.."        << std::endl;
                std::cin.ignore();
                std::cin.get();
            }
            else {
                hero.printStats();
            }
            break;

        case 2: //EXIT
            include::cleanUp();
            hero.removeHero();
            break;

        case 3:
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
                    do {
                        include::cleanUp();
                        include::battle();
                        opponent.random();
                        opponent.printStats();
                        std::cout << "0 -> Face this opponent"      << std::endl;
                        std::cout << "1 -> Look for another opponent" << std::endl;
                        std::cin >> input;
                    } while(input != 0);

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
                        std::this_thread::sleep_for(std::chrono::seconds(1) );
                        include::cleanUp();
                        include::battle();
                        std::cout                                   << std::endl;
                        std::cout << hero.name                      << std::endl;
                        hero.printHP();
                        std::cout                                   << std::endl;
                        std::cout << opponent.name                  << std::endl;
                        opponent.printHP();

                        if (opponent.currentHP > 0) {
                            hero.currentHP -= opponent.strength;
                            std::this_thread::sleep_for(std::chrono::seconds(1) );
                        }
                    } while(hero.currentHP > 0 && opponent.currentHP > 0);

                    if (opponent.currentHP <= 0) {
                        hero.experience += opponent.experience;
                        hero.update();

                    }
                    if (hero.currentHP <= 0) {
                        include::die();
                        hero.die();
                        std::cout << "Press enter to exit.."        << std::endl;
                        std::cin.ignore();
                        std::cin.get();
                        return 0;
                    }
                    break;

                case 1:
                    include::cleanUp();
                    include::dungeon();
                    std::cin >> input;
                    dungeon.load(input);

                    for (int i = 0; i < dungeon.opponents; ++i) {
                        opponent.random();
                        do {
                            include::cleanUp();
                            include::dungeon();
                            std::cout                                   << std::endl;
                            std::cout << hero.name                      << std::endl;
                            hero.printHP();
                            std::cout                                   << std::endl;
                            std::cout << opponent.name                  << std::endl;
                            opponent.printHP();

                            opponent.currentHP -= hero.strength;
                            std::this_thread::sleep_for(std::chrono::seconds(1) );
                            include::cleanUp();
                            include::dungeon();
                            std::cout                                   << std::endl;
                            std::cout << hero.name                      << std::endl;
                            hero.printHP();
                            std::cout                                   << std::endl;
                            std::cout << opponent.name                  << std::endl;
                            opponent.printHP();

                            if (opponent.currentHP > 0) {
                                hero.currentHP -= opponent.strength;
                                std::this_thread::sleep_for(std::chrono::seconds(1) );
                            }
                        } while(hero.currentHP > 0 && opponent.currentHP > 0);

                        if (opponent.currentHP <= 0) {
                            hero.experience += opponent.experience;
                            hero.update();
                        }

                        if (hero.currentHP <= 0) {
                            include::die();
                            hero.die();
                            std::cout << "Press enter to exit.."        << std::endl;
                            std::cin.ignore();
                            std::cin.get();
                            return 0;
                        }
                    }
                    hero.experience += dungeon.experience;
                    hero.update();
                    break;

                case 2:
                    hero.rest();
                    break;

                case 3: //EXIT
                    include::cleanUp();
                    std::cout << "Exiting the Story of Legends.."   << std::endl;
                    return 0;

                default:
                    std::cout << "Not possible, try again"          << std::endl;
            }
        } while(input != 0 && input != 1 && input != 2);
    } while(true);
    return 0;
}
