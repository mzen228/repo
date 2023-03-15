#pragma once
#include <iostream>
#include <vector>
class Guess
{
	std::vector<char> m_string;
	std::pair<int,int> m_score;
public:

	Guess() :m_string{  }, m_score(0,0){ }
	Guess(std::vector<char> guess, int how_many_right, int how_many_position);
	Guess(const Guess& rhs);
	~Guess();
	std::pair<int, int> getScore()const { return m_score; }
	std::vector<char> getString()const { return m_string; }
	void setNumPosition(int num) { m_score.first = num; }
	void setNumCorrect(int num) { m_score.second = num; }
	void setString(std::string s) { m_string = { s.begin(),s.end() }; }
	friend std::ostream& operator<<(std::ostream& ostr, const Guess& m_guess);
	bool operator==(const Guess& rhs)const;
	Guess& operator=(const Guess& rhs);
};

