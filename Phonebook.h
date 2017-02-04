#pragma once
#include "PhoneNumber.h"
#include "openFile.h"
#include <vector>

class Phonebook
{
public:
	Phonebook();
	~Phonebook();

	bool addFromFile(string);
	bool addWord(string);
	bool findWord(string);
	bool delWord(string);

	bool verifyStr(string);
	string wordToNum(string);

	bool printAllFor(string);
	bool printFullFor(string);
	bool printPartialFor(string);

private:
	vector<PhoneNumber>* book;
};

