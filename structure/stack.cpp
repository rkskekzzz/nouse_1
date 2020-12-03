#include <iostream>
#include <vector>

class Stack
{
	int MAX;
	int top;

public:
	std::vector<int> array = std::vector<int>(MAX);
	Stack(int max) : MAX(max), top(-1) {}
	bool push(int value);
	int pop();
	int peek();
	bool isFull();
	bool isEmpty();
};

bool Stack::push(int value)
{
	if (isFull())
		return false;

	array[++top] = value;
	return true;
}

int Stack::pop()
{
	if (isEmpty())
		return false;

	int tmp = array[top--];
	return tmp;
}

int Stack::peek()
{
	if (isEmpty())
		return false;

	return array[top];
}

bool Stack::isFull()
{
	return (top == MAX - 1) ? 1 : 0;
}

bool Stack::isEmpty()
{
	return (top == -1) ? 1 : 0;
}

int main(void)
{
	class Stack s = Stack(100);
	s.push(1009);
	std::cout << s.peek();
	return (0);
}
