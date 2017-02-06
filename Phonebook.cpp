#include "Phonebook.h"



Phonebook::Phonebook()
{
	book = new vector<PhoneNumber>;
}


Phonebook::~Phonebook()
{
	delete book;
}

bool Phonebook::addFromFile(string loc)
{
	ifstream stream;
	if (!openfile(stream, loc))
		return false;
	string in;
	while (!stream.eof())
	{
		cout << in << endl;
		stream >> in;
		addWord(in);
	}
	return true;	
}

bool Phonebook::addWord(string mainWord)
{
	//Generate phonenumber for word
	string mainNumber = wordToNum(mainWord);
	//Binary search for phonenumber

	int mid; //This will be used to remember the phonenumber location
	if (book->size() == 0)
	{
		mid = 0;
		book->push_back(PhoneNumber(mainNumber));
	}
	int low = 0;
	int high = book->size()-1;
	bool found;

	while (true)
	{
		mid = (low + high) / 2;
		if ((book->at(mid).getNumber()).compare(mainNumber) == 0)
		{
			//Number is at mid
			found = true;
			break;
		}
		if (low == high)//Number not found, create new
		{
			found = false;
			if ((book->at(mid).getNumber()).compare(mainNumber) == -1)//Phonenumber is placed behind mid
			{
				vector<PhoneNumber>::iterator it = book->begin() + mid;
				book->insert(it, PhoneNumber(mainNumber));
				mid++;
			}
			else //PhoneNumber is in front of mid
			{
				vector<PhoneNumber>::iterator it = book->begin() + mid - 1;
				book->insert(it, PhoneNumber(mainNumber));
			}
		}
		if ((book->at(mid).getNumber()).compare(mainNumber) == -1)
		{
			low = mid + 1;			
		}
		else
		{
			high = mid - 1;
		}
	}
	//if not found, create number at mid from binary search

	//iterate through posible "hybrids of word" Ex. numeral,num3ral,num3r4l,
	//add each to found phonenumber(Do not need to findWord() for each if new phonenumber)
	if (!(book->at(mid)).findWord(mainNumber))
		(book->at(mid)).addWord(mainNumber);
	return true;
}

bool Phonebook::verifyStr(string num)
{
	for (unsigned int c = 0; c < num.length(); c++)
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
	for (unsigned int c = 0; c < word.length(); c++)
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
