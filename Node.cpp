#include "Node.h"

using namespace std;

template <class Type>
Node<Type>::Node(Type prim)
{
	primary = prim;
	next = NULL;
}

template <class Type>
Node<Type>::Node(Type prim, Type sec)
{
	primary =  prim;
	secondary = sec;
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
Type Node<Type>::getPrimary()
{
	return primary;
}

template <class Type>
void Node<Type>::setValue(Type prim)
{
	primary = prim;
}

template<class Type>
void Node<Type>::setValue(Type prim, Type sec)
{
	primary = prim;
	secondary = sec;
}

template class Node<int>;
template class Node<string>;