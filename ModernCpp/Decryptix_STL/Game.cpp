#include "Game.h"
#include <iostream>

Game::Game():
	m_how_many_positions{  },
	m_how_many_letters{  },
	m_duplicates_allowed{ },
	m_round{ 1 },
	m_alphabet{ "abcdefghijklmnopqrstuvwxyz" },
	m_solution{ },
	m_guess{},
	m_n_correct{},
	m_hint_cnt{ 1 }
{
	
	const int MIN_LETTERS = 2;
	const int MAX_LETTERS = 26;
	const int MIN_POSITIONS = 3;
	const int MAX_POSITIONS = 10;

	//Game::instructions();

	while (true) {

		while (true) {
			std::cout << "How many letters? (";
			std::cout << MIN_LETTERS << "-" << MAX_LETTERS << "): ";
			std::cin >> m_how_many_letters;

			if (m_how_many_letters >= MIN_LETTERS && m_how_many_letters <= MAX_LETTERS)
				break;
		}

		while (true) {
			std::cout << "How many positions? (";
			std::cout << MIN_POSITIONS << "-" << MAX_POSITIONS << "): ";
			std::cin >> m_how_many_positions;

			if (m_how_many_positions >= MIN_POSITIONS && m_how_many_positions <= MAX_POSITIONS) {
				m_guess.resize(m_how_many_positions);
				break;
			}
		}

		char choice{};
		while (choice != 'y' && choice != 'n') {
			std::cout << "Allow duplicates (y/n)? ";
			std::cin >> choice;
		}

		m_duplicates_allowed = (choice == 'y') ? true : false;

		if (!m_duplicates_allowed && m_how_many_positions > m_how_many_letters) {
			std::cout << "I can't put " << m_how_many_letters << " letters in " << m_how_many_positions
				<< " positions without duplicates!  Please try again.\n";
		}
		else {
			break;
		}
	}

	generateSolution(); 

}

// the add member function should already checks for duplicates, so there's 
// no need to check for duplicates again in generateSolution() 
void Game::generateSolution() {
	srand((unsigned)time(NULL)); 

	for (size_t i{}; i < m_how_many_positions;) {

		int idx = rand() % m_how_many_letters; 
		char c = m_alphabet[idx]; 

		if (m_duplicates_allowed) {
			m_solution.push_back(c);
			i++;
		}
		else {
			if (std::find(m_solution.begin(), m_solution.end(), c) == m_solution.end())
			{
				m_solution.push_back(c); 
				i++;
			}
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

	m_n_correct = 0;
	m_n_in_position = 0;
	std::vector<char> solution{m_solution};

	for (int i{}; i < m_guess.size(); ++i) {
		if (m_guess[i] == solution[i])
			m_n_in_position++; 
	}

	for (int i{}; i < m_guess.size(); ++i) {

		auto it = std::find(solution.begin(), solution.end(), m_guess[i]);

		if (it != solution.end()) {
			m_n_correct++;
			solution.erase(it);
		}
	}
}

void Game::handleFlag(char c) {
	if (c == 'h')
		showHint();
	else if (c == 's')
		showHistory();
	else if (c == '?')
		showHelp();
	else if (c == 'q')
		return;		// quit 
}

void Game::showHistory() {
	for (auto& guess : m_guess_history){
		for (auto& c : guess)
			std::cout << c << ", ";
		std::cout << std::endl;
	}
}

void Game::showHelp() {
	std::cout << "-h Hint\n";
	std::cout << "-s Show history\n";
	std::cout << "-? Help\n";
	std::cout << "-q quit\n";
}

bool Game::isValid(const std::string& str) {

	if (str.size() != m_how_many_positions)
		return false;

	for (auto& c : str) {
		int ascii_c = c - 'a';

		if (ascii_c >= m_how_many_letters) {
			return false;
		}
	}


	return true;
}

void Game::play() {

	std::string new_guess{};

	while (true) {

		while (true) {
			std::cout << "Round " << m_round << ". Enter -? or "
				<< m_how_many_positions << " letters between " <<
				m_alphabet[0] << " and " << m_alphabet[m_how_many_letters - 1] << ": ";

			std::cin >> new_guess;

			if (new_guess[0] == '-') {
				handleFlag(new_guess[1]);
				continue;
			}
			
			if (isValid(new_guess))
				break;

		}

		for (int i{}; i < new_guess.size(); ++i)
			m_guess[i] = new_guess[i];

		score();
		display();
		m_guess_history.push_back(m_guess);

		if(m_n_in_position == m_solution.size()){
			std::cout << "You win!  And it ";

			if (m_round <= 6)
				std::cout << "only ";

			std::cout << "took you " << m_round << " guesses.\n";
			break; 
		}
		m_round++;
	}

}

void Game::display()const{
		std::cout << "Your guess: ";
		for (auto& c : m_guess)
			std::cout << c << ' ';
		std::cout << '\t' << m_n_correct << " correct, " << m_n_in_position << " in position.\n";
}

void Game::showHint() {
	std::cout << "hint: ";

	for (int i{}; i < m_hint_cnt && i < m_solution.size(); ++i)
		std::cout << m_solution[i] << ", ";
	std::cout << std::endl; 

	m_hint_cnt++;
}

Game::~Game() {}
