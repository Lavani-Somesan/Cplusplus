#include "stack.h"
#include "node.h"


void Stack::push(int data)
{
	Node *currNodePtr = new Node(data);

	currNodePtr->next = top;

	top = currNodePtr;

}


void Stack::pop()
{
	if(!isEmpty())
	{
		Node *currNodePtr = top;

		top = top->next;
		currNodePtr->next = NULL;
	}
}



bool Stack::isEmpty()
{
	if(top == NULL)
	{
		return true;
	}

	else
	{
		return false;
	}

}



int Stack::getTop()
{
	Node* currNodePtr = top;
	return currNodePtr->data;
}



void Stack::display()
{
	if(!isEmpty())
	{
	Node* currNodePtr = top;
	
	while(currNodePtr->next != NULL)
	{
		cout <<  currNodePtr->data;
		currNodePtr = currNodePtr->next;
	}
	 cout << currNodePtr->data << endl << endl;
	
	}

}




