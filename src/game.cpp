#include "game.h"

#include <iostream>

void playGame()
{
    std::cout << "=== GUESSQUEST ===\n";
    std::cout << "Select difficulty:\n"
              << "1. Easy (1-10)\n"
              << "2. Medium (1-20)\n"
              << "3. Hard (1-100)\n";

    int choice = 0;
    int maximum = 20;
    while (true)
    {
        std::cout << "Enter choice (1-3): ";
        if (!(std::cin >> choice))
        {
            std::cout << "\nNo integer read. Ending the game.\n";
            return;
        }

        if (choice == 1)
        {
            maximum = 10;
            break;
        }
        else if (choice == 2)
        {
            maximum = 20;
            break;
        }
        else if (choice == 3)
        {
            maximum = 100;
            break;
        }
        else
        {
            std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    }

    const int minimum = 1;
    const int target = randomNumber(minimum, maximum);

    std::cout << "\nI'm thinking of a number between " << minimum
              << " and " << maximum << ".\n\n";

    int attemptsRemaining = 5;
    while (true)
    {
        std::cout << "Attempts remaining: " << attemptsRemaining << '\n';
        std::cout << "Your guess: ";
        int guess;
        if (!(std::cin >> guess))
        {
            std::cout << "\nNo integer read. Ending the game.\n";
            return;
        }

        if (guess == target)
        {
            std::cout << "You win!\n";
            return;
        }

        --attemptsRemaining;
        if (attemptsRemaining == 0)
        {
            std::cout << "You lose! The number was " << target << ".\n";
            return;
        }

        if (guess < target)
        {
            std::cout << "Too low!\n\n";
        }
        else
        {
            std::cout << "Too high!\n\n";
        }
    }
}