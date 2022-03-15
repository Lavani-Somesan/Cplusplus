#include "parse.hpp"

/*
 * Constructor for Parse class
 *
 * @param argument, String input to be parsed
 * @param paramObj, Param object to store parsed values
 *
 */
Parse::Parse(string argument, Param &paramObj) {
	tokenizer(argument, paramObj);
}


/*
 * Tokenizes user entered string that is delimited by
 * spaces, tabs, and new lines. Sets the tokens
 * to the correct paramObj field to be stored.
 *
 * @param string, String input to be parsed
 * @param paramObj, Param object to store parsed values
 */
void Parse::tokenizer(string argument, Param &paramObj) 
{
	const char INPUT_CHAR = '<';
	const char OUTPUT_CHAR = '>';

	char delimiter[]=" \t\n";
	int argVecCounter = 0;

	char userCharArr[argument.length() + 1];
	strcpy(userCharArr, argument.c_str());

	char *tokens;
	tokens = strtok(userCharArr, delimiter);
	
	while(tokens != NULL) 
	{
		if(tokens[0] == INPUT_CHAR) {
			paramObj.setInputRedirect(tokens);
			tokens = strtok(NULL, delimiter);		
		}
		else if(tokens[0] == OUTPUT_CHAR) {
			paramObj.setOutputRedirect(tokens);
			tokens = strtok(NULL, delimiter);
		}
		else {
		paramObj.addToArgumentVector(tokens);
		argVecCounter++;
		tokens = strtok(NULL, delimiter);
		}
	}

	paramObj.setArgumentCount(argVecCounter);
}


