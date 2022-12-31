#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


std::string shiftMessage(const std::string& str, int shift, char type) {

	std::string shiftedStr{};
	std::string alphabet{ "abcdefghijklmnopqrstuvwxyz" };
	int idx{};

	std::string rotAlphabet{ alphabet };

	if(type == 'd' || type == 'D')
		std::rotate(rotAlphabet.rbegin(), rotAlphabet.rbegin() + shift, rotAlphabet.rend());
	else if(type == 'e' || type == 'e')
		std::rotate(rotAlphabet.begin(), rotAlphabet.begin() + shift, rotAlphabet.end());

	alphabet += alphabet;
	rotAlphabet += rotAlphabet;

	std::transform(alphabet.begin() + 26, alphabet.end(), alphabet.begin() + 26, ::toupper);
	std::transform(rotAlphabet.begin() + 26, rotAlphabet.end(), rotAlphabet.begin() + 26, ::toupper);

	for (auto c : str) {
		if (std::isalpha(c)) {
			idx = alphabet.find(c);
			shiftedStr += rotAlphabet.at(idx);
		}
		else {
			shiftedStr += c;
		}
	}

	return shiftedStr;
}

int main() {
	std::string message{}, shiftedMessage{};
	int offset{};
	char c{};

	while (true) {
		std::cout << "Enter 'e' to encrypt, 'd' to decrypt, or 'q' to quit: ";
		std::cin >> c;

		if (c == 'q' || c=='Q')
			break;

		std::getline(std::cin, message);
		std::cout << "Enter message: ";
		std::getline(std::cin, message);

		std::cout << "Enter offset: ";
		std::cin >> offset;

		shiftedMessage = shiftMessage(message, offset, c);

		if (c == 'e') {
			std::cout << "Encrypted message: " << shiftedMessage << std::endl;

		}
		else if (c == 'd') {
			std::cout << "Decrypted message: " << shiftedMessage << std::endl;
		}
	}

	return 0;
}