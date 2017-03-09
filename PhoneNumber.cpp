#include "PhoneNumber.h"
#include <iostream>
#include <string>

using namespace std;

PhoneNumber::PhoneNumber(string num)
{
	number = num;
	head = NULL;
}

PhoneNumber::~PhoneNumber()
{
	if (head != NULL)
		delete head;
}

string PhoneNumber::getNumber()
{
	return number;
}

//Adds a word to this number
//Returns true if word is added, false otherwise.
bool PhoneNumber::addWord(string word)
{
	if (findWord(word))
	{
		return false;
	}
	Node<string>* newHead = new Node<string>(word);
	newHead->add_node(head);
	head = newHead;
	return true;
}

//Adds a word and argument to this number
//Returns true if word is added, false otherwise.
bool PhoneNumber::addWord(string word, string args)
{
	if (findWord(word))
	{
		return false;
	}
	Node<string>* newHead = new Node<string>(word,args);
	newHead->add_node(head);
	head = newHead;
	return true;
}

bool PhoneNumber::findWord(string word)
{
	Node<string>* current = head;
	while (current != NULL)
	{
		word.compare("1112222");
		if (word.compare(current->getPrimary()) == 0)
			return true;
		current = current->next;
	}
	return false;
}

bool PhoneNumber::delWord(string word)
{
	Node<string>* current = head;
	if (head == NULL)
		return false;
	if (word.compare(current->getPrimary()) == 0)
	{
		head = current->next;
		current->next=NULL;
		delete current;
		return true;
	}
	while (current->next != NULL)
	{
		if (word.compare(current->next->getPrimary()) == 0)
		{
			Node<string>* found = current->next;
			current->next = found->next;
			found->next = NULL;
			delete found;
			return true;
		}
		current = current->next;
	}
	return false;
}

bool PhoneNumber::printWords()
{
	if (head != NULL)
	{
		Node<string>* current = head;
		while (current != NULL)
		{
			cout << current->getPrimary() << endl;
			current = current->next;
		}
		return true;
	}
	return false;
}
