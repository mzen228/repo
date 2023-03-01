#pragma once
#include <iostream>
#include <vector>
class Guess
{
	std::vector<char> m_string;
	std::pair<int,int> m_score;
public:

	Guess();
	Guess(std::vector<char> guess, int how_many_right, int how_many_position);
	Guess(const Guess& rhs);
	~Guess();
	std::pair<int, int> getScore()const { return m_score; }
	std::vector<char> getString()const { return m_string; }
	friend std::ostream& operator<<(std::ostream& ostr, const Guess& m_guess);
	bool operator==(const Guess& rhs)const;
	Guess& operator=(const Guess& rhs);
};

