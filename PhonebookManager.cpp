#include "PhonebookManager.h"



PhonebookManager::PhonebookManager()
{

}


PhonebookManager::~PhonebookManager()
{
	delete master;
}


//------------------------------------------------------------------------
// Takes strings from a specified file and adds them to a phonebook
// Takes bool param to determine if word mutations should be made too
// Returns false if file fails to open
bool PhonebookManager::addFromFile(string loc, bool mutate)
{
	ifstream stream;
	if (!openfile(stream, loc))
		return false;
	string in;
	while (!stream.eof())
	{
		stream >> in;
		addWord(in, mutate);
	}
	stream.close();
	return true;
}

//------------------------------------------------------------------------
// Finds a phonebook to add word to
// Returns true if word is added
void PhonebookManager::addWord(string word, bool mutate)
{
	int length = word.length();
	//if outside of limits, return
	if (length > MAX || length < MIN)
		return;
	//This will be used to remember the phonebook location
	int accessPos;

	//If empty master, create a new phonebook
	if (master->size() == 0)
	{
		accessPos = 0;
		Phonebook* newEntry = new Phonebook(length);
		master->push_back(newEntry);
	}
	else {
		accessPos = findBook(word);

		//if not found, create number at mid from binary search
		if (accessPos<0)
		{
			accessPos = (-1 * accessPos) - 1;
			//Number goes in front of mid
			if (length < master->at(accessPos)->getLength())
			{
				vector<Phonebook*>::iterator ite = master->begin() + accessPos;
				master->insert(ite, new Phonebook(length));
			}
			//Number goes behind mid
			else
			{
				vector<Phonebook*>::iterator ite = master->begin() + accessPos + 1;
				master->insert(ite, new Phonebook(length));
				accessPos += 1;
			}
		}
	}
	//Add plain word or mutated words
	if (mutate)
		master->at(accessPos)->generateWords(word,0);
	else
		master->at(accessPos)->addWord(word);

	return;
}

//------------------------------------------------------------------------
// Searches for a word in the phonebooks
// Returns true if word is found
bool PhonebookManager::findWord(string word)
{
	int accessPos = findBook(word);
	if (accessPos < 0)
		return false;
	else
		return master->at(accessPos-1)->findWord(word);
		
}

bool PhonebookManager::printAllFor(string num)
{
	int length;
	//The length of num is greater than MAX
	if (num.length()>MAX)
	{
		length = MAX;
	}
	//Length of num is too small to print any Phonewords for
	else if(num.length()<MIN)
	{
		cout << num << " is less than the minimum of " << MIN << "." << endl;
		return;
	}
	//The length of num is between MIN and MAX
	else
	{
		length = num.length();
	}
	while (length >= MIN)
	{
		for (int pos = 0; pos + length <= num.length(); pos++)
		{
			int accessPos = findBook(num.substr(pos, length));
			if (accessPos > 0)
			{
				master->at(accessPos - 1)->printAllFor(num.substr(pos, length));
			}
		}
		length--;
	}
}

//------------------------------------------------------------------------
// Searches for the correct phonebook location for a word
// Returns a int +(index+1) for the location of the phonebook if found
// Returns a int -(index+1) for where binary serach stopped otherwise
int PhonebookManager::findBook(string word)
{
	{
		int high = master->size() - 1, mid = 0, low = 0;
		int length = word.length();
		while (low <= high)
		{
			mid = (low + high) / 2;
			//if mid is target number
			if (length == master->at(mid)->getLength())
			{
				return mid+1;
			}
			//if search is less than mid
			else if (length < master->at(mid)->getLength())
			{
				high = mid - 1;
			}
			//if mid is greater than target number
			else
			{
				low = mid + 1;
			}
		}
		return -1*(mid+1);
	}
}

//------------------------------------------------------------------------
// Searches for a word in the phonebooks to delete
// Returns true if word is found and deleted
bool PhonebookManager::delWord(string word)
{
	int accessPos = findBook(word);
	if (accessPos < 0)
		return false;
	else
		return master->at(accessPos-1)->delWord(word);
}

//------------------------------------------------------------------------
// Verifies that a string only contains numbers.
// Returns true if only numbers are in the string, false otherwise.
bool PhonebookManager::verifyIntString(string num)
{
	for (unsigned int c = 0; c < num.length(); c++)
	{
		if (num.at(c) <= '0' || num.at(c) >= '9')
			return false;
	}
	return true;
}

//------------------------------------------------------------------------
// Access the total number of entries across the phonebooks
// Returns the total number of words
int PhonebookManager::getTotal()
{
	int return_val = 0;
	for (int pos = 0; pos < master->size(); pos++)
	{
		return_val += master->at(pos)->getCount();
	}
	return return_val;
}