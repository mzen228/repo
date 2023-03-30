#include "Decrypter.h"
Decrypter::Decrypter(bool has_duplicates) :
	m_duplicates_allowed{ has_duplicates },
	m_rounds{ 1 }
{}

Decrypter::~Decrypter() {}

void Decrypter::display(std::vector<char> vec)const {
	std::copy(vec.begin(), vec.end(), 
		std::ostream_iterator<char>(std::cout, " "));
	//std::cout << std::endl; 
}

void Decrypter::showHistory() {
	for (auto& guess : m_history)
		std::cout << guess << std::endl; 
}