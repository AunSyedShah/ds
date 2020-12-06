#include <iostream>
using namespace std;

class StackArray
{
private:
	int _current;
	int noOfElements;
	int _capacity;
	int *s;

public:
	StackArray(int capacity);
	bool isEmpty();
	bool isFull();
	void push(int value);
	void pop();
	int top();
};

StackArray::StackArray(int capacity)
{
	s = new int[capacity];
	_capacity = capacity;
	noOfElements = 0;
	_current = -1;
}
bool StackArray::isEmpty()
{
	if (_current == -1)
	{
		return true;
	}
	return false;
}

bool StackArray::isFull()
{
	if (_current == _capacity - 1)
	{
		return true;
	}
	return false;
}

void StackArray::push(int value)
{
	s[++_current] = value;
	noOfElements++;
}

void StackArray::pop()
{
	s[_current--];
	noOfElements--;
}
int StackArray::top()
{
	return s[_current];
}
void displayStack(StackArray s)
{
	while (!s.isEmpty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}
int main(int argc, char const *argv[])
{
		
	return 0;
}
