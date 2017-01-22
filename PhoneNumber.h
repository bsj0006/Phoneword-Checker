#pragma once
#include <string>

class PhoneNumber
{
public:
	PhoneNumber(string number);
	~PhoneNumber();

	void setNum(string number);
	string getNum(string number);

	string getMaxWord();
	string getMinWord();
	string getWord(int);
	int getComboCount();

};

