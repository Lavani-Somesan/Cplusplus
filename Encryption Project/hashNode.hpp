/***************************************************************
 *   File Name: hashNode.hpp
 *
 *   This is the header file for the class HashNode which
 *   contains and defines all functions and members for this class.
 *
 ***************************************************************/

#ifndef HASHNODE_HPP
#define HASHNODE_HPP

#include <iostream>
#include <string>
using namespace std;


class HashNode
{
	public:
		string data;
		string keyUserId;
		string password;
		HashNode *next;

		HashNode();
		HashNode(string data, string keyUserId, string password);
};

#endif
