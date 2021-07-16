#include "List.h"

int List::count()
{
	int counter = 0;
	// Iterator is a pointer that can move through our list
	Node* iterator = head;
	// Loop until we point to nothing
	while (iterator != NULL)
	{
		iterator = iterator->next;// End of the list, next = NULL
		counter++;
	}
	
	return counter;
}

void List::displayList()
{
	Node* iterator = head;
	while (iterator != NULL)
	{
		cout << iterator->data << endl;// Dereference pointer and access public thing
		iterator = iterator->next;
	}

	/*while (node != NULL)
	{
		cout << " " << node->data;
		node = node->next;
	}*/
}

void List::insertAtFront(int data)
{
	Node* newNode = new Node(data);

	//make new node's next point to current head
	newNode->next = head;
	//update who is front of the list
	head = newNode;
}

void List::insertAtEnd(int data)
{
	//if list is empty, ues insert at front logic
	if (head == NULL)
	{
		insertAtFront(data);
		return; //exits this function early
	}
	Node* newNode = new Node(data);

	//set up iterator and move it to the final thing of the list
	Node* iterator = head;
	while (iterator->next != NULL)
	{
		iterator = iterator->next;
	}
	// now we are pointing to the last position
	// we now attach newNode to it
	iterator->next = newNode;
}

void List::deleteAtFront()
{
	//if list empty, there is nothing to delete
	if (head == NULL)
		return;

	Node* iterator = head;
	//move head up to the next position
	head = head->next;
	//delete old head
	delete iterator;
}

void List::deleteAtEnd()
{
	//if list empty, there is nothing to delete
	if (head == NULL)
		return;

	//get pointers to point to the last node for deletion
	//and second lat to detach last one safely
	Node* iterator = head;
	Node* previous = head;
	 
	while (iterator->next != NULL)
	{
		previous = iterator;
		iterator = iterator->next;
	}
	//detach back
	previous->next = NULL;
	//delete last element in the list
	delete iterator;
}

