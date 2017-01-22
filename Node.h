#pragma once
#include <string>

using namespace std;

class Node
{

public:
	Node* next;

	Node(string val);
	~Node();

	void add_node();
	void delete_all();
	void print();
	
private:
	string value;

};

