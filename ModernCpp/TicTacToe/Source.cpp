/*Tic tac toe

Display the tic tac toe board 

Player 1 and Player 2 alternate turns until one of the wins or there is a draw*/
#include "TicTacToe.h"
#include <iostream>
#include <vector>

int main() {

	TicTacToe game;

	while(!game.endGame())
		game.playerTurn();

	return 0;
}