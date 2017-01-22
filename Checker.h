#pragma once
#include "PhoneNumber.h"
#include "Node.h"
#include <iostream>
#include <fstream>

using namespace std;

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

