#include <string>
#include <iostream>

void printPrimes(int n) {
	
	int nfactors{};

	std::cout << "\nPrime numbers from 1 to " << n << ": " << std::endl;

	for (size_t i{ 1 }; i <= n; ++i) {
		for (size_t j{ 1 }; j <= i; ++j) {
			if (i % j == 0)
				nfactors++;
		}

		if (nfactors == 2)
			std::cout << i << ", ";

		nfactors = 0;
	}

	std::cout << std::endl << std::endl;
}

int main() {
	std::string input;

	while (true) {
		
		std::cout << "Enter number or 'q' to quit: ";
		std::cin >> input;

		if (input == "q" || input == "Q")
			break;

		int n{ std::stoi(input) };

		printPrimes(n);
	}

	return 0;
}