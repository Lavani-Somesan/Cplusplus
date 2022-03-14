#include "expressionReader.h"
#include "arithmeticExpression.h"
#include "bigIntegerArithmetic.h"


ExpressionReader::ExpressionReader(string filename)
{

	readExpressions(filename);
}



void ExpressionReader::readExpressions(string filename)
{
	ifstream inFS;
	string operand1;
	string operand2;
	char operation;
	bool isfileOpen = true;


	inFS.open(filename.c_str());
	
   	if (!inFS.is_open()) 
	{
      		cout << "Could not open file" << endl;
		isfileOpen = false;
   	}


	if(isfileOpen == true)
	{
		cout << "Arithmetic Operations: " << endl;

		while(inFS >> operand1 >> operation >> operand2)
		{	
			ArithmeticExpression ae(operand1, operand2, operation);

			BigIntegerArithmetic bia(ae);
			bia.setUp();
			
			if(operation == '+')
			{
				bia.add();
			}
			else
			{
				bia.subtract();
			}

			bia.showResults();			
		}
	}
	

	inFS.close();

}
