#include <random>
#include "Human.h"
#include "Game.h"
#include <string>

Human::Human(bool duplicates) : 
	Decrypter(duplicates),
	m_hint_ctr{}
{

}

Human::~Human() {} 

std::vector<char> Human::getSolution()const {
	return m_solution;
}

/// <summary>
/// Handle any flag from user (-?,-q,etc.) 
/// </summary>
/// <param name="flag"></param>
/// <returns></returns>
bool Human::handleFlag(char flag) {
	bool quit{};

	switch (flag) {
	case 'h':
		showHint();
		break;
	case '?':
		showHelp();
		break; 
	case '!':
		showSolution(); 
		break; 
	case 's':
		showHistory();
		break; 
	case 'q':
		quit = true;
		break; 
	default:
		std::cout << "\nUnknown flag. Ignored.\n";
		break;
	}

	return quit; 
}

void Human::showSolution()const {
	std::cout << "Solution: ";
	display(getSolution());
	std::cout << std::endl;
}

/// <summary>
/// Tell us if the charact is valid
/// </summary>
/// <param name="c"></param>
/// <returns></returns>
bool Human::isValid(char c)const {
	if (alpha.find(c) < Game::m_how_many_letters)
		return true;
	return false;
}

void Human::play() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> idist(0, Game::m_how_many_letters - 1); 

	for (int i{}; i < Game::m_how_many_positions;) {
		char random_letter{ alpha[idist(mt)] }; 
		
		if (!m_duplicates_allowed && i>0) {
			if (std::find(m_solution.begin(), m_solution.end(), random_letter) != m_solution.end()) {
				continue; 
			}
		}
		m_solution.push_back(random_letter);
		i++; 
	}

	int num_position{}, num_correct{};
	std::vector<char> current_guess{}; 
	bool quit{};

	while (num_position < Game::m_how_many_positions) {

		current_guess.clear(); 
		std::string new_guess{}; 

		std::cout << "Round " << m_rounds << ". ";
		std::cout << "Enter -? or " << Game::m_how_many_positions << " letters between ";
		std::cout << alpha[0] << " and " << alpha[Game::m_how_many_letters - 1] << ": ";

		std::cin >> new_guess; 

		if (new_guess.front() == '-') {
			quit = handleFlag(new_guess[1]); 
			if (quit)
				break; 
			continue; 
		}

		if (new_guess.size() != Game::m_how_many_positions)
			continue; 

		bool valid_guess{ true }; 

		for (auto& c : new_guess) {
			if (!isValid(c)) {
				valid_guess = false;
				break;
			}
			else
				current_guess.push_back(c); 
		}

		if (!valid_guess)
			continue;

		m_rounds++; 
		std::cout << "Your guess: ";
		display(current_guess); 
		score(current_guess, num_correct, num_position); 
		std::cout << "\t\t" << num_correct << " correct in " << num_position << " positions.\n";
		Guess guess_obj(current_guess, num_correct, num_position);
		m_history.push_back(guess_obj);
	}

	if (!quit) {
		//std::cout << "The answer: ";
		//display(getSolution());
		std::cout << "\nCongratulations!  It took you ";

		if (m_rounds < 6)
			std::cout << "only ";

		std::cout << --m_rounds << " rounds!\n"; 
	}
}

void Human::score(std::vector<char> this_guess, int& correct, int& position) {

	auto sln_copy{ m_solution }; 
	auto n{ this_guess.size() }; 

	correct = 0;
	position = 0;

	// find the number of correct
	for (int i{}; i < n; ++i) {

		char c{ this_guess[i] }; 

		auto it = std::find(sln_copy.begin(), sln_copy.end(),c); 

		if (it != sln_copy.end()) {
			correct++;
			sln_copy[std::distance(sln_copy.begin(), it)] = '\0'; 
		}
	}

	// find the number of correct in the correct position 
	for (int i{}; i < this_guess.size(); ++i) {
		if (this_guess[i] == m_solution[i])
			position++;
	}
}

void Human::showHelp() {
	std::cout << "\t-h Hint\n";
	std::cout << "\t-s Show history\n";
	std::cout << "\t-? Help\n";
	std::cout << "\t-! Show solution\n";
	std::cout << "\t-q quit\n";
}

void Human::showHint() {
	
	if(m_hint_ctr<Game::m_how_many_positions)
		m_hint_ctr++;

	std::cout << "Hint: ";
	for (int i{}; i < m_hint_ctr; ++i) {
		std::cout << m_solution[i];
		if (i != m_hint_ctr - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}