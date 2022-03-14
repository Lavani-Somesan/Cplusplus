#ifndef EXPRESSIONREADER_H
#define EXPRESSIONREADER_H

#include "arithmeticExpression.h"
#include "bigIntegerArithmetic.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class ExpressionReader {

	public:
		ExpressionReader(string filename);
		
		void readExpressions(string filename);
	

};


#endif
