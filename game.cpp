#include "game.h"
#include <ctime>


Game::Game(int maxValue)
{
    maxNumber = maxValue;
    std::cout << "GAME CONSTRUCTOR: Valitsi numeron " << maxNumber << " isoimmaksi mahdolliseksi." << std::endl;
}

Game::~Game()
{
    std::cout << "GAME DESTRUCTOR: Peli poistettu muistista!" << std::endl;
}

void Game::play()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    randomNumber = std::rand() % maxNumber + 1;
    numOfGuesses = 0;
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
            std::cout << "Onneksi olkoon! Arvasit oikein! (" << randomNumber << ")" << std::endl;
            correctGuess = true;
        printGameResult();
        }
      }
  }

void Game::printGameResult()
{
    std::cout << "Peli loppui! Sinulta kului " << numOfGuesses << " yritysta." << std::endl;
}
