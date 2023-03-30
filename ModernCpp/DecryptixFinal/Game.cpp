#include <chrono>
#include "Computer.h"
#include "SmartStr.h"
#include "Decrypter.h"
#include "Human.h"
#include "Game.h"
#include <iostream>
#include <time.h>

int Game::m_how_many_letters{};
int Game::m_how_many_positions{}; 

Game::Game()
{

	//instructions(); 

	while (true) {

		while (true) {
			std::cout << "How many letters? (";
			std::cout << MIN_LETTERS << "-" << MAX_LETTERS << "): ";
			std::cin >> m_how_many_letters;

			if (m_how_many_letters >= MIN_LETTERS && m_how_many_letters <= MAX_LETTERS)
				break;
			else {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		while (true) {
			std::cout << "How many positions? (";
			std::cout << MIN_LETTERS << "-" << MAX_POSITIONS << "): ";
			std::cin >> m_how_many_positions;

			if (m_how_many_positions >= MIN_POSITIONS && m_how_many_positions <= MAX_POSITIONS) {
				break;
			}
			else {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		char choice{}; 
		while (true) {

			std::cout << "Allow duplicates (y/n)? ";
			std::cin >> choice;

			if (choice == 'y' || choice == 'n')
				break;
		}

		m_duplicates_allowed = (choice == 'y') ? true : false;

		if (!m_duplicates_allowed && m_how_many_positions > m_how_many_letters) {
			std::cout << "I can't put " << m_how_many_letters << " letters in " << m_how_many_positions
				<< " positions without duplicates!  Please try again.\n";
			continue;
		}

		while (true) {

			std::cout << "Who guesses.  (H)uman or (C)omputer? (h/c)? ";
			std::cin >> choice;

			if (choice == 'h' || choice == 'c')
				break;
		}

		bool ok = (choice == 'h') ? true : verifyComputerChoices();

		if (ok) {
			if (choice == 'h') {
				m_dptr = std::make_unique<Human>(m_duplicates_allowed);
			}
			else {
				m_dptr = std::make_unique<Computer>(m_duplicates_allowed);
			}
			break;
		}
	}
}

void Game::play() {
	auto start = std::chrono::steady_clock::now();
	m_dptr->play();
	auto end = std::chrono::steady_clock::now();
	int total_seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
	displayTime(total_seconds); 
}

void Game::displayTime(int total_seconds) {

	int total_days = total_seconds / SECONDS_IN_A_DAY;
	int total_hours = total_seconds / SECONDS_IN_HOUR;
	int total_minutes = total_seconds / SECONDS_IN_MINUTE;

	if (total_days)
		std::cout << total_days << " days!\n";
	else if (total_hours)
		std::cout << total_hours << " hours!\n";
	else if (total_minutes)
		std::cout << total_minutes << " minutes!\n";
	else
		std::cout << total_seconds << " seconds!\n";
}

bool Game::verifyComputerChoices() {

	int total_guesses{ 1 };

	if (m_duplicates_allowed) {
		total_guesses = pow(m_how_many_letters, m_how_many_positions);
	}
	else {
		for (int i{ m_how_many_letters }; i > m_how_many_letters - m_how_many_positions; --i) {
			total_guesses *= i;
		}
	}

	int total_seconds{ total_guesses / GUESSES_PER_SECOND };

	if (total_seconds > 2) {
		std::cout << "\nYou are asking me to guess from a possible " << total_guesses << " combinations.";
		std::cout << "\nI can get through about " << GUESSES_PER_SECOND << " guesses per second.  ";
		std::cout << "If the puzzle is tough,\na single gues could take more than ";

		displayTime(total_seconds);


		char confirm{};

		while (true) {
			std::cout << "Are you sure (y/n)? ";
			std::cin >> confirm;

			if (confirm == 'y' || confirm == 'Y')
				return true;
			else if (confirm == 'n' || confirm == 'N')
				return false;
		}
	}
	else {
		std::cout << "Choosing among " << total_guesses << " possible combinations...\n";
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


bool Game::playAgain() {
	std::cout << "Play again? (y/n): ";
	char choice{};
	std::cin >> choice;

	if (choice == 'y' || choice == 'Y')
		return true;
	else if (choice == 'n' || choice == 'N')
		return false;
	else {
		std::cout << "I'll just assume you meant to enter a 'y'...";
		return true;
	}
}
