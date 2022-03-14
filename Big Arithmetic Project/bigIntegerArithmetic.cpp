#include "bigIntegerArithmetic.h"
#include "arithmeticExpression.h"
#include "stack.h"
#include "node.h"

BigIntegerArithmetic::BigIntegerArithmetic(ArithmeticExpression aeObj)
{
	operand1 = aeObj.getOp1();
	operand2 = aeObj.getOp2();
	operation = aeObj.getOperation();	


}


void BigIntegerArithmetic::setUp()
{
	Stack op1Stack;
	Stack op2Stack;


	for(unsigned i = 0; i < operand1.length(); i++)
        {
                op1Stack.push((int)(operand1.at(i) - '0'));
                op2Stack.push((int)(operand2.at(i) - '0'));
        }
	
	this->op1Stack = op1Stack;
	this->op2Stack = op2Stack;
}





void BigIntegerArithmetic::add()
{
	Stack result;
	const int MAX_INT = 10;
	int carry = 0;
	int remainder = 0;
	int resultVal;


	if(operation == '+')
	{
	for(unsigned i = 0; i < operand1.length(); i++)
	{
		resultVal = op1Stack.getTop() + op2Stack.getTop();

		if(resultVal < MAX_INT)
		{
			if(resultVal + carry == MAX_INT)
			{
				result.push(0);
				op1Stack.pop();
				op2Stack.pop();
				carry = 1;
				
			}
			else
			{
				result.push(resultVal + carry);
				op1Stack.pop();
				op2Stack.pop();
				carry = 0;
			}
		}
	
		else if( resultVal >= MAX_INT)
		{
			remainder = resultVal % 10;
			result.push(remainder + carry);
			op1Stack.pop();
			op2Stack.pop();
			carry = 1;	
		}		
	}
	}

	if(carry == 1)
	{
		result.push(carry);
	}

	this->result = result;
}



void BigIntegerArithmetic::subtract()
{
	Stack result;
	Stack temp;
	const int MAX_INT = 10;
        int carry = 0;
        int resultVal;
	

	if(isOp2Bigger() == true)
	{
		temp = op1Stack;
		op1Stack = op2Stack;
		op2Stack = temp;
	}


	for(unsigned i = 0; i < operand1.length(); i++)
        {	
	if(operation == '-')
	{
		if(op1Stack.getTop() >= op2Stack.getTop())
		{
			if(op1Stack.getTop() == 0 && op2Stack.getTop() == 0)
			{
				resultVal = (op1Stack.getTop() + MAX_INT) - op2Stack.getTop();
				result.push(resultVal - carry);
				op1Stack.pop();
				op2Stack.pop();
				carry = 1;
			}
			else
			{
				resultVal = op1Stack.getTop() - op2Stack.getTop();
				result.push(resultVal - carry);
				op1Stack.pop();
				op2Stack.pop();
				carry = 0;
			}
		}

		else if(op1Stack.getTop() < op2Stack.getTop())
		{
			resultVal = (op1Stack.getTop() + MAX_INT) - op2Stack.getTop();
			result.push(resultVal - carry);
			op1Stack.pop();
			op2Stack.pop();
			carry = 1;
		}
	}
	}

	this->result = result;

}



bool BigIntegerArithmetic::isOp1Bigger()
{
	int op1 = (operand1.at(0) - '0');
        int op2 = (operand2.at(0) - '0');

	if(op1 > op2)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}


bool BigIntegerArithmetic::isOp2Bigger()
{
	int op1 = (operand1.at(0) - '0');
	int op2 = (operand2.at(0) - '0');


        if(op2 > op1)
        {
                return true;
        }

        else
        {
                return false;
        }
}



void BigIntegerArithmetic::showResults()
{


	if(isOp1Bigger() == true && operation == '+')
	{
	cout << " " << operand1 << endl;
	cout << operation << operand2 << endl;
	cout << " ";
	result.display();
	cout << endl;
	}

	else if(isOp1Bigger() == true && operation == '-')
	{
		cout << " " << operand1 << endl;
        	cout << operation << operand2 << endl;
        	cout << " ";
		result.display();
        	cout << endl;
	}

	else if(isOp2Bigger() == true && operation == '+')
	{
		cout << " " << operand1 << endl;
                cout << operation << operand2 << endl;
                cout << " ";
		result.display();
                cout << endl;
	}

	else if(isOp2Bigger() == true && operation == '-')
	{
		cout << " " << operand1 << endl;
                cout << operation << operand2 << endl;
                cout << "-";
		result.display();
                cout << endl;


	}
}
