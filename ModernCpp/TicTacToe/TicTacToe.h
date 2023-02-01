#pragma once
#include <vector>
#include "TicTacToe.h"

class TicTacToe
{
	std::vector<std::vector<char>> playingBoard;
	int row;
	int col;
	bool gameEnd;
	int player;
	int winner;
	bool validRow;
	bool validCol;
	int nGames;
	int nDraws; 
	int firstPlayerWins;
	int secondPlayerWins;
	
public:
	TicTacToe();
	~TicTacToe() {}
	void displayBoard();
	void playerTurn();
	void getRowAndCol();
	bool endGame();
	void getWinner();
	void draw();
	bool checkDraw();
	void updateBoard();
	void uniqueMove();
	void whosTurn();
	bool playAgain();
	void resetBoard(); 
	void displayStats();
};

