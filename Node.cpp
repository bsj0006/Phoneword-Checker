#include "Node.h"

using namespace std;

template <class Type>
Node<Type>::Node(Type val)
{
	value = val;
	next = NULL;
}

template <class Type>
Node<Type>::~Node()
{
	if (next != NULL)
		delete next;
	next = NULL;
}

template <class Type>
void Node<Type>::add_node(Node* node)
{
	next = node;
}

template <class Type>
Type Node<Type>::getValue()
{
	return value;
}

template <class Type>
void Node<Type>::setValue(Type val)
{
	value = val;
}

template class Node<int>;
template class Node<string>;