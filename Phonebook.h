#pragma once
#include "PhoneNumber.h"
#include "openFile.h"
#include <vector>

class Phonebook
{
public:
	Phonebook(int);
	~Phonebook();

	bool addWord(string);
	bool findWord(string);
	bool delWord(string);

	string wordToNum(string);

	bool printAllFor(string);
	Node<PhoneNumber>* getWordList(string);
	int getCount();
	int getLength();
	void generateWords(string, int);

private:
	vector<PhoneNumber*>* book;
	int length;
	int count;
};

