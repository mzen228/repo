#pragma once
#include "Guess.h"
#include "Decrypter.h"
#include <string>
#include <vector>
#include "defvals.h"
#include "SmartStr.h"

class Game
{
	bool m_duplicates;
	void displayTime(int total_seconds);
	bool verifyComputerChoices();
public:
	static int m_how_many_letters;
	static int m_how_many_positions;
	Game();
	~Game() {}
	void instructions();
	void play();
	bool playAgain(); 
	void getNumLetters();
	void getNumPositions(); 
	char getDecrypter(); 
	void allowDuplicates(); 
	bool m_duplicates_allowed;
	std::unique_ptr<Decrypter> m_dptr; 
};

