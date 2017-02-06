#pragma once
#include <string>

using namespace std;

template <class Type> class Node
{

public:
	Node* next;

	Node(Type);
	Node(Type,Type);
	~Node();

	void add_node(Node*);
	Type getPrimary();
	void setValue(Type);
	void setValue(Type,Type);
	
private:
	Type primary;
	Type secondary;

};

