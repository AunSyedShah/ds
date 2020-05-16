#include <iostream>
#include <stdlib.h>
using namespace std;
/* The Node class */
class Node
{
public:
	int get() { return object; };
	void set(int object) { this->object = object; };
	Node* getNext() { return nextNode; };
	void setNext(Node* nextNode) { this->nextNode = nextNode; };
private:
	int object;
	Node* nextNode;
};
/* The List class */
class List
{
public:
	List();
	void add(int addObject);
	friend void traverse(List list);
private:
	int size;
	Node* headNode;
	Node* currentNode;
	Node* lastCurrentNode;
	// methods
	int get();
	bool next();
};
/* Constructor */
List::List()
{
	headNode = new Node();
	headNode->setNext(NULL);
	currentNode = NULL;
	lastCurrentNode = NULL;
	size = 0;
}

/* add() class method */
void List::add(int addObject)
{
	Node* newNode = new Node();
	newNode->set(addObject);
	if (currentNode != NULL)
	{
		newNode->setNext(currentNode->getNext());
		currentNode->setNext(newNode);
		lastCurrentNode = currentNode;
		currentNode = newNode;
	}
	else
	{
		newNode->setNext(NULL);
		headNode->setNext(newNode);
		lastCurrentNode = headNode;
		currentNode = newNode;
	}
	size++;
}

/* get() class method */
int List::get()
{
	if (currentNode != NULL)
		return currentNode->get();
}
/* next() class method */
bool List::next()
{
	if (currentNode == NULL) return false;
	lastCurrentNode = currentNode;
	currentNode = currentNode->getNext();
	if (currentNode == NULL || size == 0)
		return false;
	else
		return true;
}
/* Friend function to traverse linked list */
void traverse(List list)
{
	Node* savedCurrentNode = list.currentNode;
	list.currentNode = list.headNode;

	for (int i = 1; list.next(); i++)
	{
		cout << "Element " << i << " " << list.get() << endl;
	}
	list.currentNode = savedCurrentNode;
}

int main()
{
	List l;
	l.add(5);
	l.add(6);
	l.add(3);
	traverse(l);
}
