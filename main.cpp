#include <iostream>
#include "game.h"

int main() {
    int maxNumber;

    std::cout << "Aseta isoin arvattava luku: ";
    std::cin >> maxNumber;

    Game game(maxNumber);
    game.play();

    return 0;
}
