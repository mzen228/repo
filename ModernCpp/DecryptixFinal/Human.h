#pragma once
#include "Decrypter.h"
class Human : public Decrypter
{
	int m_hint_ctr;
	std::vector<char> m_solution;
	void showHint();
	virtual void showHelp() override;
	void showSolution() const;
public:
	Human(bool duplicates); 
	virtual ~Human();
	std::vector<char> getSolution()const;
	virtual bool handleFlag(char flag) override; 
	virtual void play() override; 
	//virtual void showHelp() override; 
	bool isValid(char c)const;
	void score(std::vector<char> this_guess, int& correct, int& position);
};

