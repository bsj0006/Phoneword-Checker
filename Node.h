#pragma once
#include <string>

using namespace std;

template <class Type> class Node
{

public:
	Node* next;

	Node(Type);
	~Node();

	void add_node(Node*);
	Type getValue();
	void setValue(Type);
	
private:
	Type value;

};

