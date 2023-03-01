#include "Guess.h"

Guess::Guess(
	std::vector<char> guess,
	int how_many_right,
	int how_many_in_position
) :
	m_score{ how_many_right,how_many_in_position },
	m_string{guess}
{
}

Guess::Guess(const Guess& rhs) :
	m_score{ rhs.m_score },
	m_string{ rhs.m_string }
{
}

Guess::Guess() :m_string{},
m_score{} 
{}

Guess::~Guess() {
}

bool Guess::operator==(const Guess& rhs)const {
	return (m_string == rhs.m_string) && (m_score == rhs.m_score);
}

Guess& Guess::operator=(const Guess& rhs) {

	if (this != &rhs) {
		m_score = rhs.m_score;
		m_string = rhs.m_string; 
	}

	return *this; 
}

std::ostream& operator<<(std::ostream& ostr, const Guess& m_guess) {
	return ostr;
}
