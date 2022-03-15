#include "parser.h"
#include "lexer.h"
#include "assembly.h"

int lookahead;
bool error = false;
int numIdIndex = 0;

void match(int tokenType, char *message);
void assignStmt();
void expression();
void term();
void factor();
void endMatch();
void checkIdLegal();
void checkFirstChar();
void checkLastChar();
void checkUnderscores();
bool checkIfNextIdReady();
void intDeclarations();
void checkVarDeclared();
void checkDuplicateVar();


void startParse() {
	lookahead = lexan();
	match(BEGIN, "begin");
	if(error == true) {return;}

	intDeclarations();

	if(error == true) {return;}

	while(lookahead != END && error == false) {
		assignStmt();
	}

	if(error == false) {
		match(END, "end");
	}

	if(error == false) {
		match('.', ".");
	}

	if(error == false) {
		printf("success\n");
		showIdFound();
	}
	printf("\n");
}


void assignStmt() {
	setRegEndVal(currToken);
	setPostFix();
	match(ID, "<ID>");

	checkVarDeclared();
	if(error == true) {return;}

	checkIdLegal();
	if(error == true) {return;}

	if(lookahead != '=') {
		error = true;
		printf("Error Line %d: Syntax Error, Expected '%s'\n\n", lineNum, "=");
		return;

	} else {
		match(lookahead, "=");
		if(error == true) {return;};

		expression();	
		if(error == true) {return;}

		match(';', ";");
	}
	
	generateAssemblyCode();
	incrementPostFix();
}

void expression() {
	term();
	if(error == true) {return;}

	while(lookahead == '+' || lookahead == '-') {
		char operator = (char)lookahead;
		
		match(lookahead, "+ or -");
		if(error == true) {return;}
		
		term();
		if(error == true) {return;}

		addPostFixOperator(operator);
	}
}


void term() {
	factor();
	if(error == true) {return;}

	while(lookahead == '*' || lookahead == '/') {
		char operator = (char)lookahead;
		
		match(lookahead, "* or /");
		if(error == true) {return;}

		factor();
		if(error == true) {return;}

		addPostFixOperator(operator);
	}
}


void factor() {
	if(lookahead == ID) {
		checkVarDeclared();
		if(error == true) {return;}
		
		checkIdLegal();
		if(error == true) {return;}

		addPostFixToken(currToken);
		match(ID, "id");
	}
	else if(lookahead == NUM) {
		addPostFixToken(currToken);
		match(NUM, "num");
	}
	else if(lookahead == '(') {
		match('(', "(");
		expression();
		match(')', ")");
	}
	else {
		error = true;
		printf("Error Line %d: Syntax Error, Expected '%s'\n\n", lineNum, "<ID> or <NUM>");
	}
	if(error == true) {return;};
}


void match(int tokenType, char *message) {
	if(lookahead == tokenType) {
		lookahead = lexan();
	} else {
		error = true;
		printf("Error Line %d: Syntax Error, Expected '%s'\n\n", lineNum, message);
	}
}


bool checkIfNextIdReady() {
	if(numIdIndex != numIds) {
		return true;
	}
	return false;
}

void checkIdLegal() {
		if(checkIfNextIdReady() == true) {
			checkFirstChar();
			checkLastChar();
			checkUnderscores();
			numIdIndex++;
		}
}


void checkFirstChar() {
	if(!isalpha(idsFound[numIdIndex].token[0])) {
		error = true;
		printf("Error Line %d: Identifier Cannot Start with an Underscore\n\n", lineNum);
	}
}


void checkLastChar() {
	int indexLastChar = strlen(idsFound[numIdIndex].token) - 1;

	if(idsFound[numIdIndex].token[indexLastChar] == '_') {
		error = true;
		printf("Error Line %d: Identifier Cannot End with an Underscore\n\n", lineNum);
	}
}


void checkUnderscores() {
	for(int i = 0; i < strlen(idsFound[numIdIndex].token) - 1; i++) {
		if(idsFound[numIdIndex].token[i] == '_' && idsFound[numIdIndex].token[i + 1] == '_') {
			error = true;
			printf("Error Line %d: Identifier Cannot have Consecutive Underscores\n\n", lineNum);
			break;
		}
	}
}

void checkVarDeclared() {
	bool varFound = false;
	
	for(int i = 0; i < numIdIndex; i++) {
		//printf("\n%s\n", idsFound[i].token);
		if(strcmp(idsFound[i].token, currToken) == 0) {
			varFound = true;
		}
	}
	
	if(varFound == false) {
		error = true;
		printf("Error Line %d: Variable %s is Undefined\n\n", lineNum, idsFound[numIdIndex].token);
	}
	
}

void intDeclarations() {
	//printf("%d ", lookahead);
	match(INT, "int");
	if(error == true) {return;}

	while(true) {
		//printf(" %d", lookahead);
		match(ID, "id");
		if(error == true) {break;}

		checkDuplicateVar();
		if(error == true) {break;}

		checkIdLegal();
		if(error == true) {break;}
		
		if(lookahead == ',') {
			///printf("%d", lookahead);
			match(lookahead, ",");
		}
		else if(lookahead == ';') {
			//printf("%d\n", lookahead);
			match(lookahead, ";");

			if(lookahead == INT) {
				//printf("%d", lookahead);
				match(INT, "int");
			}
			else {
				break;
			}
		}
		else {
			error = true;
			break;
		}
		if(error == true) {
			break;
		}
	}
}

void checkDuplicateVar() {
	bool varDuplicateFound = false;

	if(numIdIndex == 0) { return; }

	for(int i = 0; i < numIdIndex; i++) {
		if(strcmp(idsFound[i].token, currToken) == 0) {
			varDuplicateFound = true;
		}
	}

	if(varDuplicateFound == true) {
		error = true;
		printf("Error Line %d: Illegal Redefinition of Variable \"%s\"\n\n", lineNum, currToken);
	}
}

bool isError() {
	if(error == true) {
		return true;
	} else {
		return false;
	}
}

