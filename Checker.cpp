#include "Checker.h"
  
using namespace std;

const int ALLOWED_LENGTH = 7;

Checker::Checker()
{
	//DEBUG
	cout << "Checker created: " << this << endl;
}

Checker::~Checker()
{
	//DEBUG
	cout << "Checker deleted: " << this << endl;
}

//-------------------------------------------------------------
// Checks if the number is usable
//
// Returns true when number is a valid 7 digit phone number
//-------------------------------------------------------------
bool Checker::isValid(string number)
{
	//Return false if the phone number isnt 7 long
	if (number.size() != ALLOWED_LENGTH)
		return false;
	//Return false if it contains a 1 or 0
	for (unsigned int pos = 0;pos < number.size();pos++)
	{
		if (number[pos] == '0' || number[pos] == '1')
		{
			cout << "Try a phone number without a 1 or a 0 in it." << endl;
			return false;
		}
		//Return false if it contains something other than a number
		if (number[pos] < '2' || number[pos] > '9')
		{
			cout << "Enter numbers only." << endl;
			return false;
		}
	}
	//Returns true when it is valid
	return true;
}

int Checker::runCheck(string number)
{
	return 0;
}

