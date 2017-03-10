#pragma once
#include "Node.h"
#include <string>

using namespace std;

class PhoneNumber
{
public:
	PhoneNumber(string);
	~PhoneNumber();

	string getNumber();
	
	bool addWord(string);
	bool addWord(string, string);
	bool findWord(string);
	bool delWord(string);

	bool printWords();

	bool isEmpty();

private:
	string number;
	Node<string>* head;

};

