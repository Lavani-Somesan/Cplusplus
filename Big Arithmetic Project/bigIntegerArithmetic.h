#ifndef BIGINTEGERARITHMETIC_H
#define BIGINTEGERARITHMETIC_H

#include "arithmeticExpression.h"
#include "stack.h"
#include "node.h"

#include <iostream>
#include <string>
using namespace std;



class BigIntegerArithmetic {

	public:
		BigIntegerArithmetic(ArithmeticExpression aeObj);
		
		void setUp();
		void add();
		void subtract();
		void showResults();
		bool isOp1Bigger();
		bool isOp2Bigger();

		private:
		string operand1;
		string operand2;
		char operation;
		Stack op1Stack;
		Stack op2Stack;
		Stack result;

};


#endif

