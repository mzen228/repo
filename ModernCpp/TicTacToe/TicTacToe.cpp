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

void TicTacToe::getWinner() {
	displayBoard();

	if (player % 2 == 1)
		std::cout << "\nPlayer 1 is the winner!\n";
	else
		std::cout << "\nPlayer 2 is the winner!\n";
}

bool TicTacToe::checkDraw() {

	for (size_t i{}; i < playingBoard.size(); ++i)
		for (size_t j{}; j < playingBoard.size(); ++j)
			if (playingBoard.at(i).at(j) == '*')
				return 0;
	std::cout << "\nDraw!\n";
	return true; 
}

bool TicTacToe::endGame() {

	// all possible ways to win a tic tac toe game
	
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

	return checkDraw();
}

void TicTacToe::getRowAndCol() {
	do {
		std::cout << "Enter the row and col separated by spaces: ";
		std::cin >> row >> col;

		validCol = true;
		validRow = true;

		if (row > 2 || row < 0) {
			std::cout << "Invalid row entry.\n";
			validRow = false;
		}

		if (col > 2 || col < 0) {
			std::cout << "Invalid col entry.\n";
			validCol = false;
		}

	} while (!validRow || !validCol);
}

void TicTacToe::uniqueMove() {
	while (playingBoard.at(row).at(col) != '*') {
		std::cout << "Invalid move.\n";
		getRowAndCol();
	}
}

void TicTacToe::playerTurn() {
	if (player % 2 == 0) {
		std::cout << "Player 1's (X) turn\n";
	}
	else {
		std::cout << "Player 2's (O) turn\n";
	}

	getRowAndCol();
	uniqueMove();
	updateBoard();
	player++;
}

void TicTacToe::updateBoard() {
	if (player % 2 == 0) {
		playingBoard.at(row).at(col) = 'X';
	}
	else {
		playingBoard.at(row).at(col) = '0';
	}
}