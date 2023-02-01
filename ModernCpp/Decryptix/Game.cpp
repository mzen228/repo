#include "Game.h"
#include <iostream>

Game::Game():
	howManyPositions{ 0 },
	howManyLetters{ 0 },
	duplicatesAllowed{ false },
	round{ 1 } 
{

	const int minLetters = 2;
	const int maxLetters = 10;
	const int minPositions = 3;
	const int maxPositions = 10;

	Game::instructions();

	while (true) {

		while (true) {
			std::cout << "How many letters? (";
			std::cout << minLetters << "-" << maxLetters << "): ";
			std::cin >> howManyLetters;

			if (howManyLetters >= minLetters && howManyLetters <= maxLetters)
				break;
		}

		while (true) {
			std::cout << "How many positions? (";
			std::cout << minPositions << "-" << maxPositions << "): ";
			std::cin >> howManyPositions;

			if (howManyPositions >= minPositions && howManyPositions <= maxPositions)
				break;
		}

		char choice{};
		while (choice != 'y' && choice != 'n') {
			std::cout << "Allow duplicates (y/n)? ";
			std::cin >> choice;
		}

		duplicatesAllowed = (choice == 'y') ? true : false;

		if (!duplicatesAllowed && howManyPositions > howManyLetters) {
			std::cout << "I can't put " << howManyLetters << " letters in " << howManyPositions
				<< " positions without duplicates!  Please try again.\n";
		}
		else {
			break;
		}
	}
}

void Game::instructions() {
	std::cout << "Decryptix. (c)Copyright 1999 Liberty ";
	std::cout << "Associates, Inc. Version 0.2\n" << std::endl;
	std::cout << "There are two ways to play decryptix: ";
	std::cout << " either you can guess a pattern I create, ";
	std::cout << "or I can guess your pattern.\n\n";

	std::cout << "If you are guessing, I will think of a\n";
	std::cout << "pattern of letters (e.g., abcde).\n\n";

	std::cout << "On each turn, you guess the pattern and\n";
	std::cout << " I will tell you how many letters you\n";
	std::cout << "got right, and how many of the correct\n";
	std::cout << " letters were in the correct position.\n\n";

	std::cout << "The goal is to decode the puzzle as quckly\n";
	std::cout << "as possible.  You control how many letters \n";
	std::cout << "can be used and how many positions\n";
	std::cout << " (e.g., 5 possible letters in 4 positions)\n";
	std::cout << "as well as whether or not the pattern might\n";
	std::cout << " contain duplicate letters (e.g., aabcd).\n\n";

	std::cout << "If I'm guessing, you think of a pattern\n";
	std::cout << "and score each of my answers.\n\n" << std::endl;
}

