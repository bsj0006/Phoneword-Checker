#include "Phonebook.h"

Phonebook::Phonebook(int len)
{
	book = new vector<PhoneNumber*>(0);
	length = len;
	count = 0;
}

Phonebook::~Phonebook()
{
	delete book;
}

//------------------------------------------------------------------------
// Adds mainWord to the dictionary
// Returns true if word is added
bool Phonebook::addWord(string mainWord)
{
	//Generate phonenumber for word
	string mainNumber = wordToNum(mainWord);
	//This will be used to remember the phonenumber location
	int accessPos; 
	int low = 0;
	int high = book->size() - 1;
	int mid = 0;
	//Try to find number in phonebook
	bool found = false;


	//If empty phonebook, add number
	if (book->empty())
	{
		accessPos = 0;
		PhoneNumber* newEntry = new PhoneNumber(mainNumber);
		book->push_back(newEntry);
	}
	else {
		while (low <= high)
		{
			mid = (low + high) / 2;
			//if mid is target number
			if (mainNumber.compare(book->at(mid)->getNumber()) == 0)
			{
				//cout << mainNumber << " already exist." << endl;
				found = true;
				accessPos = mid;
				break;
			}
			//if search is less than mid
			else if (mainNumber.compare(book->at(mid)->getNumber()) == -1)
			{
				high = mid - 1;
			}
			//if mid is greater than target number
			//if search is greater than mid
			else
			{
				low = mid + 1;
			}
		}

		//if not found, create number at mid from binary search
		if (!found)
		{
			//Number goes in front of mid
			if (mainNumber.compare(book->at(mid)->getNumber()) == -1)
			{
				vector<PhoneNumber*>::iterator ite = book->begin() + mid;
				book->insert(ite, new PhoneNumber(mainNumber));
				accessPos = mid;
			}
			//Number goes behind mid
			else
			{
				vector<PhoneNumber*>::iterator ite = book->begin() + mid + 1;
				book->insert(ite, new PhoneNumber(mainNumber));
				accessPos = mid + 1;
			}
		}
	}

	cout << mainWord << endl;
	if (book->at(accessPos)->addWord(mainWord))
	{
		count++;
		return true;
	}
	return false;
}

//------------------------------------------------------------------------
// Finds mainWord inside book
// Returns true if found, false otherwise
bool Phonebook::findWord(string mainWord)
{
	int high = book->size()-1, mid = 0, low = 0;
	string mainNumber = wordToNum(mainWord);
	while (low <= high)
	{
		mid = (low + high) / 2;
		//if mid is target number
		if (mainNumber.compare(book->at(mid)->getNumber()) == 0)
		{
			if (book->at(mid)->findWord(mainWord))
				return true;
			else
				return false;
		}
		//if search is less than mid
		else if (mainNumber.compare(book->at(mid)->getNumber()) == -1)
		{
			high = mid - 1;
		}
		//if mid is greater than target number
		else
		{
			low = mid + 1;
		}
	}
	return false;
}

//------------------------------------------------------------------------
// Deletes mainWord fom book.
// Returns true if word is deleted, false otherwise.
bool Phonebook::delWord(string mainWord)
{
	int high = book->size() - 1, mid = 0, low = 0;
	string mainNumber = wordToNum(mainWord);
	while (low <= high)
	{
		mid = (low + high) / 2;
		//if mid is target number
		if (mainNumber.compare(book->at(mid)->getNumber()) == 0)
		{
			if (book->at(mid)->delWord(mainWord))
				return true;
			else
				return false;
		}
		//if search is less than mid
		else if (mainNumber.compare(book->at(mid)->getNumber()) == -1)
		{
			high = mid - 1;
		}
		//if search is greater than mid
		else
		{
			low = mid + 1;
		}
	}
	return false;
}

//------------------------------------------------------------------------
// Converts each letter in word to a corresponding number
// Returns the converted string
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

//
bool Phonebook::printAllFor(string mainNumber)
{
	int high = book->size() - 1, mid = 0, low = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		//if mid is target number
		if (mainNumber.compare(book->at(mid)->getNumber()) == 0)
		{
			//print out all at mid
			book->at(mid)->printWords();
			return true;
		}
		//if search is less than mid
		else if (mainNumber.compare(book->at(mid)->getNumber()) == -1)
		{
			high = mid - 1;
		}
		//if mid is greater than target number
		//if search is greater than mid
		else
		{
			low = mid + 1;
		}
	}
	return false;
}

//------------------------------------------------------------------------
//  Returns a count of the total number of words within this book
//
int Phonebook::getCount()
{
	return count;
}

int Phonebook::getLength()
{
	return length;
}

//------------------------------------------------------------------------
// Used to recursively create mutated words by changing letters to numbers
// 
void Phonebook::generateWords(string word, int pos)
{
	//8=B 5=S 3=E 1=L 7=T 0=O
	if (pos == word.size())
	{
		addWord(word);
		return;
	}
	//converts word to uppercase
	word.at(pos) = toupper(word.at(pos));
	if (word.at(pos) == 'B')
	{
		generateWords(word, pos + 1);
		word.at(pos) = '8';
		generateWords(word, pos + 1);
		return;
	}

	if (word.at(pos) == 'T')
	{
		generateWords(word, pos + 1);
		word.at(pos) = '7';
		generateWords(word, pos + 1);
		return;
	}

	if (word.at(pos) == 'S')
	{
		generateWords(word, pos + 1);
		word.at(pos) = '5';
		generateWords(word, pos + 1);
		return;
	}

	if (word.at(pos) == 'E')
	{
		generateWords(word, pos + 1);
		word.at(pos) = '3';
		generateWords(word, pos + 1);
		return;
	}

	if (word.at(pos) == 'L')
	{
		generateWords(word, pos + 1);
		word.at(pos) = '1';
		generateWords(word, pos + 1);
		return;
	}

	if (word.at(pos) == 'O')
	{
		generateWords(word, pos + 1);
		word.at(pos) = '0';
		generateWords(word, pos + 1);
		return;
	}
	generateWords(word, pos + 1);
	return;
}
