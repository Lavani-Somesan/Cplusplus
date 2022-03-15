#include "param.hpp"

/*
 * Default Constructor for Param
 * Initializing values used in Param class
 */
Param::Param() {
	inputRedirect = "NULL";
	outputRedirect = "NULL";
	argumentCount = 0;
	addingArgumentCounter = 0;
}


/*
 * Sets the InputRedirect value and
 * erases the first char in the string
 * if the char is '<'
 *
 * @param token, Char* that inputRedirect is set to
 */
void Param::setInputRedirect(char *token){
	this->inputRedirect = token;

	if(inputRedirect[0] == '<')
	{
		this->inputRedirect.erase(0, 1);
	}
}

/*
 * Sets the OutputRedirect value and
 * erases the first char in the string
 * if the char is '>'
 *
 * @param token, Char* that outputRedirect is set to
 */

void Param::setOutputRedirect(char *token) {
	this->outputRedirect = token;

	if(outputRedirect[0] == '>')
	{
		this->outputRedirect.erase(0, 1);
	}
}


/*
 * Sets the ArgumentCount value
 *
 * @param argCount, int that argumentCount is set to
 */
void Param::setArgumentCount(int argCount) {
	this->argumentCount = argCount;
}


/*
 * Adds values to the argumentVector field as long
 * as the argumentVector field is not full and updates 
 * addingArgumentCounter.
 *
 * @param token, Char* that is added to the argumentVector array
 */
void Param::addToArgumentVector(char *token) {
	if(isNumTokensNotMax()){
		argumentVector[addingArgumentCounter] = token;
		addingArgumentCounter++;
	}
}

/*
 * Check if argumentVector[0] is a valid program
 * Check if argumentVector[1] is a integer castable
 *
 * @return isGoodParams:
 * @return true, the Parameters has valid program and instnace
 * @returns false, the Parameters does not have valid program or instance or both
 *
 * @param programs, vector<string> list of programs to check
 */
bool Param::checkProgramParams() {
	
	const int MIN_ARG_NUM = 2;

	if(argumentCount < MIN_ARG_NUM){
	    return false;
    	}
    	if(isInteger(argumentVector[1])){
        	if(getNumInstances() > 0) {
			return true;
		}
    	}
    
    	return false;
}


/*
 * Gets the number of instances stored in argumentVector[1]
 *
 * @return int, argumentVector[1] as an integer
 */
int Param::getNumInstances() {
	return stoi(argumentVector[1]);
}

int Param::getArgumentCount() {
	return argumentCount;
}

/*
 * Returns the string at the specified argumentVector position
 * 
 * @return string, argumentVector[argsPositio]
 */
string Param::getArgsVector(int argsPosition) {
    return this->argumentVector[argsPosition];	
}

/*
 * @return string, inputRedirect
 */
string Param::getInputRedirect() {
    return this->inputRedirect;
}

/*
 * @return string, outputRedirect
 */
string Param::getOutputRedirect() {
    return this->outputRedirect;
}

/*
 * Checks through the string to see if its an integer
 *
 * @return true, if the string is an integer
 * @return false, if the string is not integer convertable
 */
bool Param::isInteger(string var) {
    	char* stringPart;
    	strtol(var.c_str(), &stringPart, 10);

    	return (*stringPart == 0);
}


/*
 * Checks to see if the Argument Vector is not Empty
 *
 * @return true, if arugment vector is not empty
 * @return false, if argument vector is empty
 */
bool Param::isArgVectorNotEmpty() {
	if(argumentCount > 0){
		return true;
	}

	return false;
}


/*
 * Checks to see if the argumentVector array is not full
 * and returns either true or false. 
 *
 * @return true, The argumentVector is not full
 * @return false, The argumentVector is full
 */
bool Param::isNumTokensNotMax(){
	if(addingArgumentCounter < MAXARGS){
		return true;
	} 
	else {
		return false;
	}
}


/*
 * Prints out inputRedirect, outputRedirect, argumentCount,
 * and the argumentVector only when shell is in debug mode.
 */
void Param:: printParams(){
	cout << "InputRedirect: [" << inputRedirect << "]" << endl;
	cout << "OutputRedirect: [" << outputRedirect << "]" << endl;
	cout << "ArgumentCount: [" << argumentCount << "]" << endl;

	for(int i = 0; i < argumentCount; i++)
	{
		cout << "ArgumentVector [" << i << "]: [" << argumentVector[i] << "]" << endl;
	}
}

