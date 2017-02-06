#pragma once
#include "Phonebook.h"
#include "resource.h"
#include <iostream>
#include <string>

using namespace std;

const int Height = 8, Width = 4;
char letters[Height][Width] = { { 'a','b','c',' ' },{ 'd','e','f',' ' },{ 'g','h','i',' ' },{ 'j','k','l',' ' },{ 'm','n','o',' ' },{ 'p','q','r','s' },{ 't','u','v',' ' },{ 'w','x','y','z' } };

long total_combos = 0;
long total_checks = 0;

string *wordlist;
int  wordlist_length=0;
/*
int main(void)
{
	system("color 02");
	//Word to be generated from phone_number
	string new_word = "abcdefg", sentinel="Y";
	//*sorted* word dictionary to be used
	ifstream seven_dictionary;
	//A 7-digit phone number
	string phone_number = "5556789";

	if (!openfile(seven_dictionary, "C:/Temp/dictionary_seven_letter_words.txt"))
		return 1;
	while (sentinel == "y" || sentinel == "Y")
	{
		//Get valid phone number from user.
		cout << endl << "Enter a phone number to be checked in the format: 5556789." << endl;
		cin >> phone_number;
		while (!checkNumber(phone_number))
		{
			cout << endl << "Enter a phone number to be checked in the format: 5556789." << endl;
			cin >> phone_number;
		}

		cout << endl << "Starting time: ";
		system("echo %TIME%");
		//load a dynamic array of words within a char range
		createList(phone_number, seven_dictionary);
		//cout << endl<<"min word: "<<wordlist[0] << " max word: " << wordlist[wordlist_length - 1];
		//send off the phone number to be converted
		numberToLetter(phone_number, new_word, 0, seven_dictionary);
		//cout << endl << "Total combos: " << total_combos;
		//cout << endl << "Total checks: " << total_checks;
		cout << endl << "Ending time: ";
		system("echo %TIME%");
		cout << endl << "Would you like to test another number?(Y/N)" << endl;
		cin >> sentinel;
	}
	system("pause");
	return 0;
}



//--------------------------------------------------------------------------------------------------
// Checks for the range of letters needed and inserts all necessary words into wordlist
//--------------------------------------------------------------------------------------------------
void createList(string phone_number, ifstream& dictionary)
{
	//get the min and max possible combo 
	string min_word ="", max_word="";
	int start_pos = 0;
	dictionary.seekg(0);
	for (unsigned int pos = 0; pos < phone_number.length(); pos++)
	{
		int phone_digit= stoi(phone_number.substr(pos, 1));
		min_word += letters[phone_digit-2][0];
		if (letters[phone_digit][4] == ' ')
			max_word += letters[phone_digit-2][4];
		else
			max_word += letters[phone_digit-2][4];
	}		
	string dictionary_word = "";
	dictionary >> dictionary_word;
	while (dictionary_word < min_word)
	{
		dictionary >> dictionary_word;
	}
	start_pos=dictionary.tellg();
	start_pos -= (Allowed_Length);
	wordlist_length=1;
	while (dictionary_word < max_word&&!dictionary.eof())
	{
		dictionary >> dictionary_word;
		wordlist_length++;
	}
	wordlist = new string[wordlist_length];
	dictionary.seekg(start_pos);
	for (int pos = 0; pos < wordlist_length; pos++)
	{
		dictionary >> wordlist[pos];
	}
	return;
}


//--------------------------------------------------------------------------------------------------
// Gets the phone number at that position and goes through each of its letters and the next position
// RETURNS void
//--------------------------------------------------------------------------------------------------
void numberToLetter(string phone_number, string generated, int phone_pos, ifstream& dictionary)
{
	//the digit of the phone number being used currently
	int phone_digit = stoi(phone_number.substr(phone_pos,1));
	//loop thru each letter for phone_digit
	for (int pos = 0;pos < Width; pos++)
	{
		//cout << endl<< "I made it to pos " << pos << " inside of " << phone_pos;
		//end early if there is no 4th character for the digit
		if (letters[phone_digit-2][pos]==' ')
		{
			return;
		}
		//cout << check.substr(0, phone_pos) << letters[phone_digit-2][pos]<< check.substr(phone_pos + 1, phone_number.length() - 1 - phone_pos)<<endl;
		generated[phone_pos] =letters[phone_digit-2][pos];
		if(phone_pos==Allowed_Length-1)
		{ 
			validateWord(generated);
		}
		else
		{
			numberToLetter(phone_number, generated, phone_pos + 1, dictionary);
		}
	}
	return;
}


//--------------------------------------------------------------------------------------------------
// Check a word to see if its in the input file and print it if so
// PRINTS word if found in dictionary
//--------------------------------------------------------------------------------------------------
void validateWord(string generated)
{
	//cout << endl << "Checking " << generated;
	if (binary_search(wordlist, generated, 0, wordlist_length - 1) != -1)
	{
		cout << endl << generated << " is a potential word.";
	}
	return;
}


//--------------------------------------------------------------------------------------------------
// Looks for search from position low to high in the array string_address
//  RETURNS pos of search or -1 if not found
//--------------------------------------------------------------------------------------------------
int binary_search(string* string_address, string search, int low, int high)
{
	int const null_pos = -1;
	while (true)
	{
		int mid = (low + high) / 2;
		if (*(string_address + mid) == search)
			return mid;
		if (low == high)
			return null_pos;
		if (search < *(string_address + mid))
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
}
*/

/*
int run(int ret)
{
	if (ret = -1)
		return -1;
	//Object for validating phone number
	Checker* numChecker = new Checker();
	//String for storing user input
	string input="";

	do
	{
		do {
			//ask user
			cout << endl << "Enter a phone number to be checked in the format: 5556789."
				<< endl << "It can only contain numbers 2-9." << endl;
			
			//get input
			cin >> input;
		}
		//check if input is num 2-9
		while (!(numChecker->isValid(input)));

			//run checker and wait for return
			numChecker->runCheck(input);

		//ask to continue
			cout << endl << "Type Y to continue or a different letter to quit." << endl;
			cin >> input;
	}
	//if yes, loop continues
	while (input == "Y" || input == "y");

	delete numChecker;
	return 0;
}
*/
int main(void)
{
	Phonebook* p = new Phonebook();
	p->addFromFile("C:/Temp/dictionary_seven_letter_words.txt");
	system("pause");
}
