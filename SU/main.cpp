#include <iostream>

int main()
{
    int load;
    std::cout << "Welcome to the game" << std::endl;
    std::cout << "(0)New game (1)Load game: " << std::endl;
    std::cin >> load;
    std::cout << load << std::endl;
    if (load == 1) {
        std::cout << "you chose load";
    } else {
        std::cout << "you chose new game";
    }
    return 0;
}
