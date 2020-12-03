#include <iostream>
#include <vector>
#include <queue>

class Node{
	int data;
	Node *next;
}

class Queue
{
	int end;
	int start;


public:
	Queue() : start(-1), end(-1) {}
	bool push(int value);
	int pop();
	int peek();
	int front();
	int back();
	int size();
	bool isFull();
	bool isEmpty();
};

bool Queue::push(int value)
{

}

int Queue::pop()
{

}

int Queue::peek()
{

}

bool Queue::isFull()
{

}

bool Queue::isEmpty()
{

}

int main(void)
{
	class Queue s = Queue(100);
	std::queue<int> s;

	return (0);
}
