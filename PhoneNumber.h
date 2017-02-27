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
	
	void forceWord(string);
	void forceWord(string, string);
	bool addWord(string);
	bool addWord(string, string);
	bool findWord(string);
	bool delWord(string);

	bool printWords();

private:
	string number;
	Node<string>* head;

};

