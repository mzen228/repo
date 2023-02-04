#include "Game.h"
#include <iostream>

Game::Game():
	how_many_positions{ 0 },
	how_many_letters{ 0 },
	duplicates_allowed{ false },
	round{ 1 },
	alphabet{ "abcdefghijklmnopqrstuvwxyz" },
	solution{ "" },
	guess{},
	guesses{ "" },
	n_correct{},
	n_guesses{},
	display_word{ "" }
{

	const int min_letters = 2;
	const int max_letters = 10;
	const int min_positions = 3;
	const int max_positions = 10;

	//Game::instructions();

	while (true) {

		while (true) {
			std::cout << "How many letters? (";
			std::cout << min_letters << "-" << max_letters << "): ";
			std::cin >> how_many_letters;

			if (how_many_letters >= min_letters && how_many_letters <= max_letters)
				break;
		}

		while (true) {
			std::cout << "How many positions? (";
			std::cout << min_positions << "-" << max_positions << "): ";
			std::cin >> how_many_positions;

			if (how_many_positions >= min_positions && how_many_positions <= max_positions)
				break;
		}

		char choice{};
		while (choice != 'y' && choice != 'n') {
			std::cout << "Allow duplicates (y/n)? ";
			std::cin >> choice;
		}

		duplicates_allowed = (choice == 'y') ? true : false;

		if (!duplicates_allowed && how_many_positions > how_many_letters) {
			std::cout << "I can't put " << how_many_letters << " letters in " << how_many_positions
				<< " positions without duplicates!  Please try again.\n";
		}
		else {
			display_word.insert(0, how_many_positions, '_');
			break;
		}
	}

	generateSolution(); 

}

void Game::generateSolution() {
	srand((unsigned)time(NULL)); 

	for (size_t i{}; i < how_many_positions; ++i) {

		int idx = rand() % how_many_letters; 

		if (duplicates_allowed) {
			solution += alphabet[idx]; 
		}
		else {
			while(solution.find(alphabet[idx])!=std::string::npos){
				idx = rand() % how_many_letters;
			}
			solution += alphabet[idx];
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

void Game::score() {

	for (size_t i{}; i < solution.size(); ++i) {
		if (guess == solution[i]) {
			display_word[i] = guess; 
			n_correct++; 
		}
	}

}

void Game::play() {

	while (true) {

		while (true) {
			std::cout << "Enter a char: ";
			std::cin >> guess;

			if (guesses.find(guess) == std::string::npos) {
				guesses += guess;
				break;
			}
		}

		n_guesses++; 
		score();
		display(); 

		if (n_correct == solution.size()) {
			std::cout << "You win!  And it only took " << n_guesses << " guesses.\n";
			break; 
		}
	}

}

Game::~Game() {
	std::cout << "Game dtor\n";
}

void Game::display() const {
	
	for (auto c : display_word)
		std::cout << c << ' ';
	std::cout << std::endl;
}
