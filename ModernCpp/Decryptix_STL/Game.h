#pragma once
#include <string>
#include <vector>

class Game
{
	int m_how_many_letters;
	int m_how_many_positions;
	bool m_duplicates_allowed;
	int m_round;
	std::vector<char> m_solution; 
	std::string m_alphabet;
	std::vector<char> m_guess; 
	std::vector<std::vector<char>> m_guess_history; 
	int m_n_correct; 
	int m_n_in_position; 
	int m_hint_cnt;
public:
	Game();
	~Game();
	void instructions();
	void play(); 
	void generateSolution();
	std::vector<char> getSolution()const { return m_solution; }
	void display()const;
	void handleFlag(char);
	void score(); 
	void showHint();
	void showHistory();
	void showHelp();
};

