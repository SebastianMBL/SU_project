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
    std::string shopRing;


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

                    if (hero.ring != ""){
                        include::cleanUp();
                        include::battle();
                        opponent.printStats();

                        do {
                            std::cout << "Do you wanna youse your magic ring? (-25 mana)"   << std::endl;
                            std::cout << "0 <- Yes"                                         << std::endl;
                            std::cout << "1 <- No"                                          << std::endl;
                            std::cin >> input;
                        } while (input != 0 && input != 1);

                        if (input == 1){}
                        else if (input == 0 && hero.mana < 25){
                            std::cout << "You dont have enough mana"                    << std::endl;
                            std::cout << "Press enter to continue .."                   << std::endl;
                            std::cin.ignore();
                            std::cin.get();
                        }
                        else if (input == 0 && hero.mana > 25){
                            hero.mana -= 25;
                            opponent.currentHP -= hero.ringPower(opponent.element);
                        }
                    }

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

                        std::random_device ranDev;
                        hero.mana       += ranDev() % 11;
                        if (hero.mana > 100) {
                            hero.mana = 100;
                        }
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
                input = 0;
                break;

                case 1:
                    include::cleanUp();                                                 //Dungeon select
                    include::dungeon();
                    std::cin >> input;
                    dungeon.load(input);

                    for (int i = 0; i < dungeon.opponents; ++i) {
                        opponent.random();

                        if (hero.ring != ""){
                            include::cleanUp();
                            include::battle();
                            opponent.printStats();

                            do {
                                std::cout << "Do you wanna youse your magic ring? (-25 mana)"   << std::endl;
                                std::cout << "0 <- Yes"                                         << std::endl;
                                std::cout << "1 <- No"                                          << std::endl;
                                std::cin >> input;
                            } while (input != 0 && input != 1);

                            if (input == 1){}
                            else if (input == 0 && hero.mana < 25){
                                std::cout << "You dont have enough mana"                    << std::endl;
                                std::cout << "Press enter to continue .."                   << std::endl;
                                std::cin.ignore();
                                std::cin.get();
                            }
                            else if (input == 0 && hero.mana > 25){
                                hero.mana -= 25;
                                opponent.currentHP -= hero.ringPower(opponent.element);
                            }
                        }

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
                    }
                    hero.experience += dungeon.experience;
                    hero.gold       += dungeon.gold;
                    hero.update();
                input = 1;
                break;

                case 2:
                    include::cleanUp();
                    include::shop();
                    std::cin >> input;

                        if      (input == 0) { shopRing = "Fire";}
                        else if (input == 1) { shopRing = "Earth";}
                        else if (input == 2) { shopRing = "Metal";}
                        else if (input == 3) { shopRing = "Water";}
                        else if (input == 4) { shopRing = "Wood";}

                        if (input != 5 && hero.gold >= 10){ //Check if hero have enough gold
                            hero.ring =     shopRing;
                            hero.gold -=    10;
                            hero.update();
                            std::cout << "You have purchased a ring."          << std::endl;
                            std::cout << "Press enter to continue .."          << std::endl;
                            std::cin.ignore();
                            std::cin.get();
                        }
                        else if (input != 5) {
                            std::cout << "You dont have enough gold."          << std::endl;
                            std::cout << "Press enter to continue .."          << std::endl;
                            std::cin.ignore();
                            std::cin.get();
                        }

                input = 2;
                break;

                case 3:
                    hero.rest();
                break;

                case 4: //EXIT
                    include::cleanUp();
                    std::cout << "Exiting the Story of Legends.."   << std::endl;
                    hero.update();
                    return 0;

                default:
                    std::cout << "Not possible, press enter .."          << std::endl;
                    std::cin.ignore();
                    std::cin.get();
                break;
            }
        } while(input != 0 && input != 1 && input != 2 && input != 3);
    } while(true);
    return 0;
}
