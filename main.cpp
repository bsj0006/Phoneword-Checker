#pragma once
#include "PhonebookManager.h"
#include "resource.h"
#include <iostream>
#include <string>

using namespace std;


int main(void)
{
	//Object for validating phone number
	PhonebookManager* dict = new PhonebookManager();
	dict->addFromFile("C:/Temp/dictionary_four_letter_words.txt", true);
	dict->addFromFile("C:/Temp/dictionary_five_letter_words.txt", true);
	dict->addFromFile("C:/Temp/dictionary_six_letter_words.txt", true);
	dict->addFromFile("C:/Temp/dictionary_seven_letter_words.txt", true);
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
		while (!(dict->verifyIntString(input)));

		//run checker and wait for return
		cout << "In:" << input << endl;

		//ask to continue
		cout << endl << "Type Y to continue or a different letter to quit." << endl;
		cin >> input;
	}
	//if yes, loop continues
	while (input == "Y\0" || input == "y\0");

	delete dict;
	system("pause");
	return 1;
}