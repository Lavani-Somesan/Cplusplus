#include "operand.h"


Operand::Operand()
{
	operand = "0";
}



Operand::Operand(string &operand)
{
	this->operand = operand;

}



Operand::Operand(string &operand, char &operation)
{
	this->operand = operand;
	this->operation = operation;


}



void Operand::setValue(string &operand)
{
	this->operand = operand;
}



bool Operand::isNegative()
{
	if(operand.at(0) == '-')
	{
		return true;
	}

	else if(operation == '-')
	{
		return true;
	}
	
	else
	{
		return false;
	}
}



string Operand::getValue()
{
	return operand;
}



int Operand::getLengthOfString()
{
	int length = operand.length();
	
	return length;
}



void Operand::pad(int padZeros)
{
	for(int i = 0; i < padZeros; i++)
	{
		operand.insert(0, "0");
	}

}
