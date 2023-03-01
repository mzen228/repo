#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include "Game.h"
#include "Guess.h"

int main() {

	
	while (true) {
		
		Game game;
		game.getHint();
		game.play();

		char choice{};
		std::cout << "Play again? (y/n): ";
		std::cin >> choice;

		if (choice == 'y' || choice == 'Y')
			continue;
		else if (choice == 'n' || choice == 'N') 
			break;
		else {
			std::cout << "I'll just assume you meant to enter a 'y'...";
			continue; 
		}
	}

	return 0;
}