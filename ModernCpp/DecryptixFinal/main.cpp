#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include "Game.h"
#include "Guess.h"
#include "defvals.h"
#include <random>
#include <time.h>
#include <chrono>

int main() {
	
	bool play_again{ true };

	while (play_again) {
		auto game = std::make_unique<Game>();
		game->play(); 
		play_again = game->playAgain(); 
	}

	return 0;
}