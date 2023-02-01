#pragma once
class Game
{
	int howManyLetters;
	int howManyPositions;
	int minPositions;
	int maxPositions; 
	bool duplicatesAllowed;
	int round;
public:
	Game();
	~Game() {}
	void instructions();

};

