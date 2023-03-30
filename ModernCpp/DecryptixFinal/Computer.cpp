#include "Computer.h"

Computer::Computer(bool duplicates):Decrypter(duplicates) {
	
}

bool Computer::handleFlag(char flag) {
	return true;
}
void Computer::play() {
	std::cout << "Computer guesses...\n";
}

void Computer::showHelp() {

}