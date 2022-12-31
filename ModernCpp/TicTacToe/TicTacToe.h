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
	
public:
	TicTacToe() :validRow{ true }, validCol{ true },winner {}, player{ 0 }, gameEnd{ false }, row{ 0 }, col{ 0 }, playingBoard(3, std::vector<char>(3, '*')) {}
	~TicTacToe() {}
	void displayBoard();
	void playerTurn();
	void getRowAndCol();
	bool endGame();
	int getWinner();
	void updateBoard();
};

