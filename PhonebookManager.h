#pragma once
#include <vector>
#include "Phonebook.h"

using namespace std;

#define MAX 10
#define MIN 4

class PhonebookManager
{
public:
	PhonebookManager();
	~PhonebookManager();
	bool addFromFile(string, bool);
	void addWord(string, bool);
	bool delWord(string);
	bool findWord(string);
	bool printAllFor(string);
	bool verifyIntString(string);
	int getTotal();
	bool test();
	vector<Phonebook*>* master;
private:
	int findBook(string);
};