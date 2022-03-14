
#include "expressionReader.h"
#include "arithmeticExpression.h"
#include "operand.h"
#include "bigIntegerArithmetic.h"
#include "stack.h"
#include "node.h"

#include <iostream>
#include <string>
using namespace std;



int main()
{
	string filename = "expressions.txt";
	
	ExpressionReader er(filename);
	

	return 0;
}
