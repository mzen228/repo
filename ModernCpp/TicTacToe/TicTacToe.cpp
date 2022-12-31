#include "TicTacToe.h"
#include <iostream>
#include <iomanip>

void TicTacToe::displayBoard() {
	std::cout << "\n";
	for (auto row : playingBoard) {
		std::cout << std::setw(40) << "";
		for (auto c : row) {
			std::cout << std::setw(5) << c << " ";
		}
		std::cout << "\n\n";
	}

}

int TicTacToe::getWinner() {
	displayBoard();
	winner = player % 2 + 1; // player 1 or 2
	std::cout << "\nPlayer " << winner << " is the winner!\n";
	return winner;
}

void TicTacToe::checkDraw() {

	for (size_t i{}; i < playingBoard.size(); ++i)
		for (size_t j{}; j < playingBoard.size(); ++j)
			if (playingBoard.at(i).at(j) == '*')
				return;
	isDraw = true;
}

bool TicTacToe::endGame() {

	checkDraw();

	if (isDraw) {
		std::cout << "\nDraw!\n";
		return true;
	}
	// all possible ways to win a tic tac toe game
	// 
	// top row
	if (playingBoard.at(0).at(0) == playingBoard.at(0).at(1) && 
		playingBoard.at(0).at(0) == playingBoard.at(0).at(2) && 
		playingBoard.at(0).at(0) != '*') {
		getWinner();
		return true;
	}
	// middle row
	else if (playingBoard.at(1).at(0) == playingBoard.at(1).at(1) && 
		playingBoard.at(1).at(0) == playingBoard.at(1).at(2) && 
		playingBoard.at(1).at(0) != '*') {
		getWinner();
		return true;
	}
	// bottom row
	else if (playingBoard.at(2).at(0) == playingBoard.at(2).at(1) && 
		playingBoard.at(2).at(0) == playingBoard.at(2).at(2) && 
		playingBoard.at(2).at(0) != '*') {
		getWinner();
		return true;
	}
	// left column
	else if (playingBoard.at(0).at(0) == playingBoard.at(1).at(0) && 
		playingBoard.at(0).at(0) == playingBoard.at(2).at(0) && 
		playingBoard.at(0).at(0) != '*') {
		getWinner();
		return true;
	}
	// middle column
	else if (playingBoard.at(0).at(1) == playingBoard.at(1).at(1) && 
		playingBoard.at(0).at(1) == playingBoard.at(2).at(1) && 
		playingBoard.at(0).at(1) != '*') {
		getWinner();
		return true;
	}
	// right column
	else if (playingBoard.at(0).at(2) == playingBoard.at(1).at(2) && 
		playingBoard.at(0).at(2) == playingBoard.at(2).at(2) && 
		playingBoard.at(0).at(2) != '*') {
		getWinner();
		return true;
	}
	// diagonal
	else if (playingBoard.at(0).at(0) == playingBoard.at(1).at(1) &&
		playingBoard.at(0).at(0) == playingBoard.at(2).at(2) &&
		playingBoard.at(0).at(0) != '*') {
		getWinner();
		return true;
	}
	// diagonal
	else if (playingBoard.at(2).at(0) == playingBoard.at(1).at(1) &&
		playingBoard.at(2).at(0) == playingBoard.at(0).at(2) &&
		playingBoard.at(2).at(0) != '*') {
		getWinner();
		return true;
	}
	player++;
	return 0;
}

void TicTacToe::getRowAndCol() {
	do {
		std::cout << "Enter the row and col separated by spaces: ";
		std::cin >> row >> col;

		if (row > 2 || row < 0) {
			std::cout << "Invalid row entry.\n";
		}

		if (col > 2 || col < 0) {
			std::cout << "Invalid col entry.\n";
		}

		if (playingBoard[row][col] != '*')
			std::cout << "Invalid.\n";

	} while (row > 2 || row < 0 || col>2 || col < 0 || playingBoard[row][col] != '*');
}

void TicTacToe::playerTurn() {
	if (player % 2 == 0) {
		std::cout << "Player 1's turn\n";
	}
	else {
		std::cout << "Player 2's turn\n";
	}

	getRowAndCol();

	updateBoard();
}

void TicTacToe::updateBoard() {
	if (player % 2 == 0) {
		playingBoard.at(row).at(col) = 'X';
	}
	else {
		playingBoard.at(row).at(col) = 'O';
	}
}