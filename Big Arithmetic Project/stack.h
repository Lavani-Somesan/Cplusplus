#ifndef STACK_H
#define STACK_H

#include "node.h"

#include <iostream>
#include <string>
using namespace std;


class Stack {
	
	Node* top = NULL;

	public:
		Stack()
		{
		}
		void push(int data);
		void display();
		void pop();
		bool isEmpty();
		int getTop();
};


#endif

