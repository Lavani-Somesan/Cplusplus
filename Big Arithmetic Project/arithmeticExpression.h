#ifndef ARITHMETICEXPRESSION_H
#define ARITHMETICEXPRESSION_H

#include "operand.h"

#include <iostream>
#include <string>
using namespace std;



class ArithmeticExpression {

	public:
		ArithmeticExpression(string &operand1, string &operand2, char &operation);

		string getOp1();
		string getOp2();
		char getOperation();
	

	private:
		string operand1;
		string operand2;
		char operation;

};


#endif
