#pragma once
#include <string>

class Game
{
	int how_many_letters;
	int how_many_positions;
	int minPositions;
	int maxPositions; 
	bool duplicates_allowed;
	int round;
	std::string solution; 
	std::string alphabet;
	char guess;
	std::string guesses; 
	int n_guesses; 
	int n_correct; 
	std::string display_word;
public:
	Game();
	~Game();
	void instructions();
	void play(); 
	void generateSolution();
	std::string getSolution()const{ return solution; } 
	void display()const;
	void score(); 

};

