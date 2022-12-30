#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <Windows.h>
#include <algorithm>

std::string reverseWordOrder(std::string& str) {
	std::stringstream ss{ str };
	std::stack<std::string> st{};
	std::string word{}, revStr{};

	while (ss >> word)
		st.push(word);

	while (!st.empty()) {
		if (revStr.empty()) {
			revStr += st.top();
			st.pop();
		}
		else {
			revStr += ' ' + st.top();
			st.pop();
		}
	}

	//std::cout << "reversed message: " << revStr << std::endl;

	return revStr;
}

std::string shiftMessageEnc(std::string& str, int shift) {
	std::string alphabet{ "abcdefghijklmnopqrstuvwxyz" };

	std::string rotAlphabet{ alphabet };
	std::rotate(rotAlphabet.begin(), rotAlphabet.begin() + shift, rotAlphabet.end());

	alphabet += alphabet;
	rotAlphabet += rotAlphabet;

	std::transform(alphabet.begin() + 26, alphabet.end(), alphabet.begin() + 26, ::toupper);
	std::transform(rotAlphabet.begin() + 26, rotAlphabet.end(), rotAlphabet.begin() + 26, ::toupper);

	std::string shiftedStr{};

	int idx{};

	//std::cout << alphabet << std::endl;
	//std::cout << rotAlphabet << std::endl;

	for (auto c : str) {
		if (std::isalpha(c)) {
			idx = alphabet.find(c);
			shiftedStr += rotAlphabet.at(idx);
		}
		else {
			shiftedStr += c;
		}
	}

	//std::cout << "shifted message: " << shiftedStr << std::endl;

	return shiftedStr;
}

std::string shiftMessageDec(std::string& str, int shift) {
	std::string alphabet{ "abcdefghijklmnopqrstuvwxyz" };

	std::string rotAlphabet{ alphabet };
	std::rotate(rotAlphabet.begin(), rotAlphabet.begin() + shift, rotAlphabet.end());

	alphabet += alphabet;
	rotAlphabet += rotAlphabet;

	std::transform(alphabet.begin() + 26, alphabet.end(), alphabet.begin() + 26, ::toupper);
	std::transform(rotAlphabet.begin() + 26, rotAlphabet.end(), rotAlphabet.begin() + 26, ::toupper);


	std::string shiftedStr{};

	//std::cout << alphabet << std::endl;
	//std::cout << rotAlphabet << std::endl;

	int idx{};

	for (auto c : str) {
		if (std::isalpha(c)) {
			idx = rotAlphabet.find(c);
			shiftedStr += alphabet.at(idx);
		}
		else {
			shiftedStr += c;
		}
	}

	//std::cout << "shifted message: " << shiftedStr << std::endl;

	return shiftedStr;
}

std::string encryptMessage(std::string& str, int shift) {
	std::string tmp{};
	tmp = shiftMessageEnc(str, shift);
	tmp = reverseWordOrder(tmp);
	std::cout << "encrypted message: " << tmp << std::endl;
	return tmp;
}

std::string decryptMessage(std::string& str, int shift) {
	std::string tmp{};
	tmp = reverseWordOrder(str);
	tmp = shiftMessageDec(tmp, shift);
	std::cout << "decrypted message: " << tmp << std::endl;

	return tmp;
}

void concealMessage() = delete;// {
//	for (size_t i{}; i < 200; ++i)
//		std::cout << std::endl;
//}

int main() {
	std::string message{}, encryptedMessage{}, decryptedMessage{};
	int offset{};
	char c{};

	while(true){
		std::cout << "Enter 'e' to encrypt, 'd' to decrypt, or 'q' to quit: ";
		std::cin >> c;

		if (c == 'q')
			break;

		std::getline(std::cin, message); // need to consume the \n from the cin 

		if (c == 'e') {


			HANDLE hStdInput = GetStdHandle(STD_INPUT_HANDLE);
			DWORD mode = 0;

			GetConsoleMode(hStdInput, &mode);

			SetConsoleMode(hStdInput, mode & (~ENABLE_ECHO_INPUT));

			std::cout << "Enter message: ";
			//std::getline(std::cin, message);
			std::getline(std::cin, message);

			std::cout << std::endl;

			SetConsoleMode(hStdInput, mode);
		}
		else if (c == 'd') {
			std::cout << "Enter message: ";
			std::getline(std::cin, message);
		}

		//return message;

		//std::cout << "message: " << message << std::endl;
		
		std::cout << "Enter offset: ";
		std::cin >> offset;

		//concealMessage();

		if (c == 'e') {
			encryptedMessage = encryptMessage(message, offset);
			//encryptedMessage = encryptMessage(encryptedMessage, offset);

			// crack the encryption by rotating the encrypted message 26 times 
			for (size_t i{1}; i <= 26; i++) 
				decryptedMessage = decryptMessage(encryptedMessage, i);

		}
		else if (c == 'd')
			decryptedMessage = decryptMessage(message, offset);
	} 

}