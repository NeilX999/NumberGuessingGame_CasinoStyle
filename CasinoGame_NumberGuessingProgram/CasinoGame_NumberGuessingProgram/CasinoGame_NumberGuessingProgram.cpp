#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

void GuessingGame()
{
	int money = 100;
	std::cout << "\nYou have " << money << " points by default.\nYou lose them if you guess the wrong number.";
	std::cout << "\n\nI am thinking of a number. Can you guess it?\nIf you do then you will get 150% percent (added) the amount of points.\n" << std::endl;
	srand(time(NULL));
	int secret_number = rand() % 101;
	while (true)
	{
		std::cout << "Enter a number: ";
		int input_number;
		std::cin >> input_number;
		if (input_number > secret_number)
		{
			std::cout << "The secret number is lower\n" << std::endl;
			money -= 10;
			continue;
		}
		else if (input_number < secret_number)
		{
			std::cout << "The secret number is higher\n" << std::endl;
			money -= 10;
			continue;
		}
		else
		{
			std::cout << "You guessed the number\n" << std::endl;
			std::cout << "You had " << 1.5 * money << " points at the end of the round" << std::endl;
			break;
		}
	}
}

void hand()
{
	std::string input;
	while (true)
	{
		std::cout << ">>>";
		std::cin >> input;
		if (input == "game") { GuessingGame(); }
		else if (input == "exit") { break; }
		else { std::cout << input << " is not an acceptable command" << std::endl; }
	}
}

int main()
{
	hand();
	std::cin.get();
}