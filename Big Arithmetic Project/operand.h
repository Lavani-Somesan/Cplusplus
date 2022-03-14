#ifndef OPERAND_H
#define OPERAND_H


#include <iostream>
#include <string>
#include <string.h>
using namespace std;


class Operand {

	public:
		Operand();
		Operand(string &operand);
		Operand(string &operand, char &operation);

		bool isNegative();
		string getValue();
		int getLengthOfString();
		void pad(int padZeros);
		void setValue(string &operand);

	private:
		string operand;
		char operation;

};


#endif
