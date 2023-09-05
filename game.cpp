#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


Game::Game(int max)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    maxNumber = max;
    randomNumber = std::rand() % maxNumber + 1;
    numOfGuesses = 0;
}

Game::~Game()
{

}

void Game::play()
{
    int guess;
    bool correctGuess = false;

    std::cout << "Tervetuloa arvauspeliin! Arvaa numero 1 ja " << maxNumber << "valilla." << std::endl;

    while (!correctGuess) {
        std::cout << "Arvauksesi: ";
        std::cin >> guess;
        numOfGuesses++;

        if (guess < 1 || guess > maxNumber) {
            std::cout << "Arvaa numero 1 ja " << maxNumber << "valilta." << std::endl;
        } else if (guess < randomNumber) {
            std::cout << "Numero on liian pieni. Yrita uudelleen!" << std::endl;
        } else if (guess > randomNumber) {
            std::cout << "Numero on liian suuri. Yrita uudelleen!" << std::endl;
        } else {
            std::cout << "Onneksi olkoon! Arvasit oikein! (" << randomNumber << ") Sinulta kului " << numOfGuesses << " yritysta." << std::endl;
            correctGuess = true;
        }
    }
    printGameResult();
}

void Game::printGameResult()
{
    std::cout << "Peli loppui! Tuhotaan peli voit yrittaa uudelleen." << std::endl;
}
