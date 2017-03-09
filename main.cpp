#pragma once
#include "PhonebookManager.h"
#include "resource.h"
#include <iostream>
#include <string>

using namespace std;

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
	string input="";
	PhonebookManager* phoneDict = new PhonebookManager();
	phoneDict->addFromFile("C:/Temp/dictionary_seven_letter_words.txt", false);
	cout << "Entries created: " << phoneDict->getTotal() << endl;
	cout << "\nFinished.\n" << endl;
	cin >> input;
	while (p->verifyStr(input)&&input.length()==7)
	{
		if (!p->printAllFor("input"))
		{
			cout << "None found/n" << endl;
		}
		cin >> input;
	}
	
	system("pause");
}
