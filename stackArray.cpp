#include <iostream>
using namespace std;

class StackArray
{
public:
	StackArray(int stackSize);
	int isFull();
	int isEmpty();
	int top();
	void push(int data);
	int pop();
	~StackArray();

private:
	int* stackArray;
	int stackSize;
	int current;
};

StackArray::StackArray(int stackSize)
{
	this->stackSize = stackSize;
	stackArray = new int[stackSize];
	current = -1;
}

int StackArray::isFull()
{
	if (current == stackSize - 1)
		return 1;
	return 0;
}

int StackArray::isEmpty()
{
	if (current == -1)
		return 1;
	return 0;
}

int StackArray::top()
{
	return current;
}

void StackArray::push(int data)
{
	stackArray[++current] = data;
}

int StackArray::pop()
{
	return stackArray[current--];
}

StackArray::~StackArray()
{
	delete[]stackArray;
}

void displayStack(StackArray s)
{
	while (!s.isEmpty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}
int main()
{
	
}
