#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Generate a random number between 1 and 10
    int numberToGuess = std::rand() % 10 + 1;  // Range is now 1 to 10
    int playerGuess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 10." << std::endl;

    // Game loop
    do {
        std::cout << "Enter your guess: ";
        std::cin >> playerGuess;
        attempts++;

        if (playerGuess > numberToGuess) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (playerGuess < numberToGuess) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the number " << numberToGuess << " in " << attempts << " attempts!" << std::endl;
        }
    } while (playerGuess != numberToGuess);

    return 0;
}

