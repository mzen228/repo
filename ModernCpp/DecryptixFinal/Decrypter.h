#pragma once
#include <vector> 
#include "Guess.h"
class Decrypter
{
protected:
	bool m_duplicates_allowed;
	std::vector<Guess> m_history;
	int m_rounds; 
public:
	Decrypter(bool duplicates);
	virtual ~Decrypter(); 
	void display(std::vector<char> vec)const;
	virtual bool handleFlag(char flag) = 0;
	virtual void play() = 0;
	virtual void showHelp() = 0;
	void showHistory(); 
};

