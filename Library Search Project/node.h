#ifndef NODE_H
#define NODE_H


#include <iostream>
#include <string>
using namespace std;


class Node {

	public:

		string data;
		Node* right;
		Node* left;

		Node();
		Node(string data);
	
};

#endif

