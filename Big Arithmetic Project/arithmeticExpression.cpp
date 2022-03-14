#include "arithmeticExpression.h"
#include "operand.h"



ArithmeticExpression::ArithmeticExpression(string &operand1, string &operand2, char &operation)
{
	int operand1Length;
	int operand2Length;

	Operand o1(operand1);	
	Operand o2(operand2, operation);

	operand1Length = o1.getLengthOfString();
	operand2Length = o2.getLengthOfString();

	if(operand1Length > operand2Length)
	{
		o2.pad(operand1Length - operand2Length);
		operand2 = o2.getValue();
	}
	
	else if(operand2Length > operand1Length)
	{
		o1.pad(operand2Length - operand1Length);
		operand1 = o1.getValue();
	}

	this->operand1 = operand1;
	this->operand2 = operand2;
	this->operation = operation;

}


string ArithmeticExpression::getOp1()
{
	return operand1;
}


string ArithmeticExpression::getOp2()
{
	return operand2;
}


char ArithmeticExpression::getOperation()
{
	return operation;
}
