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
	//local variables
	int bookID, softwareBooks = 0, hardwareBooks = 0, otherBooks = 0;

	cout << "Set size of stack: ";
	int sizeOfStack;
	cin >> sizeOfStack;

	StackArray s(sizeOfStack);

	cout << "How many books you want to add into stack: ";
	int noOfBooks;
	cin >> noOfBooks;

	for (int i = 0; i < noOfBooks; i++)
	{
		if (!s.isFull())
		{
			cout << "\nEnter Book identity number that you want to insert into stack: ";
			cin >> bookID;

			if (bookID % 8 == 0)
			{
				s.push(bookID);
				softwareBooks++;
			}

			else if (bookID % 5 == 0)
			{
				s.push(bookID);
				hardwareBooks++;
			}

			else
			{
				s.push(bookID);
				otherBooks++;
			}
		}
	}

	cout << "\n\nTotal Software Book/Books = " << softwareBooks;
	cout << "\n\nTotal Hardware Book/Books = " << softwareBooks;
	cout << "\n\nTotal Other Book/Books = " << softwareBooks;


}