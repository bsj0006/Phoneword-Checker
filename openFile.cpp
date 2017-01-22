#include "openFile.h"

using namespace std;

//--------------------------------------------------------------
// OPEN INPUT FILES
// RETURN TRUE IF OPENED
//--------------------------------------------------------------
bool openfile(ifstream& file, string location)//infile variant
{
	file.open(location);
	if (!file)
	{
		cout << "Unable to open file at " << location << endl;
		system("pause");
		return false;
	}
	else
	{
		cout << "File opened at " << location << endl;
		return true;
	}
}


//--------------------------------------------------------------
// OPEN OUTPUT FILES
// RETURN TRUE IF OPENED
//--------------------------------------------------------------
bool openfile(ofstream& file, string location)
{
	file.open(location);
	if (!file)
	{
		cout << "Unable to open file at " << location << endl;
		system("pause");
		return false;
	}
	else
	{
		cout << "File opened at " << location << endl;
		return true;
	}
}
