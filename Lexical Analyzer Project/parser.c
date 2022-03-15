#include "parser.h"
#include "lexer.h"

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


void startParse() {
	lookahead = lexan();
	match(BEGIN, "begin");

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
	match(ID, "<ID>");
	checkIdLegal();

	if(error == true) {
		return;
	}

	if(lookahead != '=') {
		error = 1;
		printf("Line %d: syntax error expected '%s'\n", lineNum, "=");

	} else {
		match(lookahead, "lookahead");
		expression();
		
		if(error == 1) {
			return;
		}

		match(';', ";");
	}
}

void expression() {
	term();
	if(error == 1) {
		return;
	}

	while(lookahead == '+' || lookahead == '-') {
		match(lookahead, "+ or -");
		term();

		if(error == 1) {
			return;
		}
	}
}


void term() {
	factor();
	if(error == 1) {
		return;
	}

	while(lookahead == '*' || lookahead == '/') {
		match(lookahead, "* or /");
		factor();

		if(error == 1) {
			return;
		}
	}
}


void factor() {
	if(lookahead == ID) {
		checkIdLegal();
		match(ID, "id");
	}
	else if(lookahead == NUM) {
		match(NUM, "num");
	}
	else if(lookahead == '(') {
		match('(', "(");
		expression();
		match(')', ")");
	}
	else {
		error = 1;
		printf("Line %d: syntax error expected '%s'\n", lineNum, "<ID> or <NUM>");
	}
}


void match(int tokenType, char *message) {
	if(lookahead == tokenType) {
		lookahead = lexan();
	} else {
		error = 1;
		printf("Line %d: syntax error expected '%s'\n", lineNum, message);
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
		printf("Line %d: Identifier Cannot Start with an Underscore\n", lineNum);
	}
}


void checkLastChar() {
	int indexLastChar = strlen(idsFound[numIdIndex].token) - 1;

	if(idsFound[numIdIndex].token[indexLastChar] == '_') {
		error = true;
		printf("Line %d: Identifier Cannot End with an Underscore\n", lineNum);
	}
}


void checkUnderscores() {
	for(int i = 0; i < strlen(idsFound[numIdIndex].token) - 1; i++) {
		if(idsFound[numIdIndex].token[i] == '_' && idsFound[numIdIndex].token[i + 1] == '_') {
			error = true;
			printf("Line %d: Identifier Cannot have Consecutive Underscores\n", lineNum);
			break;
		}
	}
}
