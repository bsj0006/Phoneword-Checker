#pragma once
#include <vector>
#include "Phonebook.h"

using namespace std;

class PhonebookManager
{
public:
	PhonebookManager();
	~PhonebookManager();
	bool addFromFile(string, bool);
	void addWord(string, bool);
	bool delWord(string);
	bool findWord(string);
	int findBook(string);
	bool printAllFor(string);
	bool verifyIntString(string);
	int getTotal();
private:
	const int MIN = 4;
	const int MAX = 10;
	vector<Phonebook*>* master;
};

