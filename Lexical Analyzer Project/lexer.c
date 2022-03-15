#include "lexer.h"
#include "symbolTable.h"

char ch;
int lineNum = 1;
int tokenType;

char idLexeme[20];
char numLexeme[20];
int LEX_SIZE = 20;
int numIds = 0;

void addToIdArr(int count); 


int lexan() {
	while(1) {
		ch = fgetc(filePtr);		

		if(ch == ' '|| ch == '\t') {}

		else if(ch == '\n') {
			++lineNum;
		}	

		else if(ch == '~') {
			while(ch != '\n') {
				ch = fgetc(filePtr);
			}
			++lineNum;
		}

		else if(isdigit(ch)) {
			int count = 0;

			for(int i = 0; i < LEX_SIZE; i++) {
				numLexeme[i] = ' ';
			}
			numLexeme[count] = ch;
			count++;

			while(1) {
				ch = fgetc(filePtr);
				if(isdigit(ch)) {
					numLexeme[count] = ch;
					count++;
				} else {
					ungetc(ch, filePtr);
					break;
				}
			}
			//Debugging
			/*
			for(int i = 0; i < count; i++) {
				printf("%c", numLexeme[i]);
			}
			printf("\n");
			*/

			return NUM;
		}

		else if(isalpha(ch)) {
			int count = 0;
		
			for(int i = 0; i < LEX_SIZE; i++) {
				idLexeme[i] = ' ';
			}
			idLexeme[count] = ch;
			count++;

			while(1) {
				ch = fgetc(filePtr);
				
				if(ch == '_' || isalpha(ch) || isdigit(ch)) {
					idLexeme[count] = ch;
					count++;
				} else {
					ungetc(ch, filePtr);
					break;
				}
			}

			//Debugging
			/*
			for(int i = 0; i < count; i++) {
				printf("%c", idLexeme[i]);
			}
			printf("\n");
			*/

			tokenType = lookup(idLexeme);

			//Debugging
			//printf("Token TYpe: %d\n", tokenType);

			if(tokenType == NOT_FOUND) {
				strncpy(idsFound[numIds].token, idLexeme, count);
				numIds++;
				
				insertIntoTbl(idLexeme, ID);
				return ID;
			} else {
				return tokenType;
			}
		}

		else if(ch == EOF) {
			return DONE;
		}

		else {
			return ch;
		}
	}
}

void showIdFound() {
	printf("Identifiers: ");
	for(int i = 0; i < numIds; i++) {
		if(i == numIds - 1) {
			printf("%s ", idsFound[i].token);
		} else {
			printf("%s, ", idsFound[i].token);
		}
	}
	printf("\n");
}

