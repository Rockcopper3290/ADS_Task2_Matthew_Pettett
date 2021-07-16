#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

class List
{
public:
	//points to the front of the linked list
	Node* head = NULL;

	int count();
	void displayList();

	void insertAtFront(int data);
	void insertAtEnd(int data);

	void deleteAtFront();
	void deleteAtEnd();

};
