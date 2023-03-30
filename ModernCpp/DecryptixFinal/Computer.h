#pragma once
#include "Decrypter.h"
class Computer : public Decrypter
{
public:
	Computer(bool);
	virtual bool handleFlag(char flag) override;
	virtual void play() override;
	virtual void showHelp() override;
};

