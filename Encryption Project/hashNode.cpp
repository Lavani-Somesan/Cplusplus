/***************************************************************
 *   File Name: hashNode.cpp
 *
 *   This is the class HashNode's function declarations which
 *   will be used to help externally chain our hash table.
 *
 ***************************************************************/

#include "hashNode.hpp"


/*HashNode Constructor
 *
 * Initializes the data, keyUserId, and password members of this class
 *
 */
HashNode::HashNode()
{
	string data = " ";
	string keyUserId = " ";
	string password = " ";
}


/*HashNode Parameterized Constructor
 * @param data holds the userId and password stringed together
 * @param keyUserId holds the userIds
 * @param passowrd holds the passwords
 *
 * Initializes the data, keyUserId, and password members and assignes the
 * next pointer to NULL.
 *
 */
HashNode::HashNode(string data, string keyUserId, string password)
{
	this->keyUserId = keyUserId;
	this->data = data;
	this->password = password;
	next = NULL;
}
