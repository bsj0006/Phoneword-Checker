#include "PhoneNumber.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <fstream>

class Checker
{
private:
	PhoneNumber* pnum;

public:
	Checker();
	~Checker();
	bool isValid(string number);
	int runCheck(string number);	
};

