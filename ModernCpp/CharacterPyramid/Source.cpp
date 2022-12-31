#include <string>
#include <iostream>

void createCharacterPyramid(const std::string& str) {
	size_t strLength{ str.size() };
	size_t charPyrLength{ 2 * str.size() - 1 };
	std::string charPyramid(charPyrLength, ' ');
	size_t midIdx{ charPyrLength / 2 };

	std::cout << std::endl;
	for (size_t i{}; i < strLength; ++i) {
		charPyramid[midIdx - i] = str[i];
		charPyramid[midIdx + i] = str[i];
		std::cout << charPyramid << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	std::string s{};

	while (true) {
		std::cout << "Enter string or 'q' to quit: ";
		std::getline(std::cin, s);
		if (s == "q" || s == "Q")
			break;

		createCharacterPyramid(s);
	}

	return 0;
}