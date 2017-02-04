#include "Phonebook.h"



Phonebook::Phonebook()
{
	book = new vector<PhoneNumber>;
}


Phonebook::~Phonebook()
{
	delete book;
}

bool Phonebook::addWord(string)
{
	return false;
}

bool Phonebook::verifyStr(string num)
{
	for (int c = 0; c < num.length(); c++)
	{
		if (num.at(c) <= '0' || num.at(c) >= '9')
			return false;
	}
	return true;
}

//Converts each letter in word to a corresponding number
string Phonebook::wordToNum(string word)
{
	string ret = "";
	char b = ' ';
	for (int c = 0; c < word.length(); c++)
	{
		b = word.at(c);
		if ((b >= 'a' && b <= 'c') || (b >= 'A' && b <= 'C'))//A-C: 2
		{
			ret += '2';
		}else if ((b >= 'd' && b <= 'f') || (b >= 'D' && b <= 'F'))//D-F: 3
		{
			ret += '3';
		}
		else if ((b >= 'g' && b <= 'i') || (b >= 'G' && b <= 'I'))//G-I: 4
		{
			ret += '4';
		}
		else if ((b >= 'j' && b <= 'l') || (b >= 'J' && b <= 'L'))//J-L: 5
		{
			ret += '5';
		}
		else if ((b >= 'm' && b <= 'o') || (b >= 'M' && b <= 'O'))//M-O: 6
		{
			ret += '6';
		}
		else if ((b >= 'p' && b <= 's') || (b >= 'P' && b <= 'S'))//P-S: 7
		{
			ret += '7';
		}
		else if ((b >= 't' && b <= 'v') || (b >= 'T' && b <= 'V'))//T-V: 8
		{
			ret += '8';
		}
		else if ((b >= 'w' && b <= 'z') || (b >= 'W' && b <= 'Z'))//W-Z: 9
		{
			ret += '9';
		}
		else ret += b; //Re-add char if it isnt A-Z Ex. T0NS1LS = 8067157
	}
	return ret;
}
