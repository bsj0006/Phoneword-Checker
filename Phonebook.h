#pragma once
#include "PhoneNumber.h"
#include "openFile.h"
#include <vector>

class Phonebook
{
public:
	Phonebook();
	~Phonebook();

	bool addFromFile(string,bool);
	bool addWord(string);
	bool findWord(string);
	bool delWord(string);

	bool verifyStr(string);
	string wordToNum(string);

	bool printAllFor(string);
	Node<PhoneNumber>* getWordList(string);
	void printD();

private:
	vector<PhoneNumber*>* book;
	void generateWords(string, int);
	int debug;
};

