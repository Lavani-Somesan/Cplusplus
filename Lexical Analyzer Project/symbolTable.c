#include "symbolTable.h"

#define SYM_TBL_SIZE 900

struct dataItem {
	char *lexPtr;
	int tokenType;
};

struct dataItem symbolTbl[SYM_TBL_SIZE];

int hashCode(char key[]);


int insertIntoTbl(char lexeme[], int data) {
	
	int hashIndex = hashCode(lexeme);

	while(symbolTbl[hashIndex].lexPtr != NULL) {
 		++hashIndex;
		hashIndex = hashIndex % SYM_TBL_SIZE;
	}

	symbolTbl[hashIndex].lexPtr = lexeme;
	symbolTbl[hashIndex].tokenType = data;

	return symbolTbl[hashIndex].tokenType;
}


int lookup(char lexeme[]) {
	int hashIndex = hashCode(lexeme);
	
	//Debugging
	//printf("Hash code: %d\n", hashIndex);

	return symbolTbl[hashIndex].tokenType;
}



int hashCode(char key[]) {
	int keyLength = 0;
	int hashVal = 0;

	while(key[keyLength] != ' ' && key[keyLength] != '\0') keyLength++;

	//Debugging
	//printf("Key length: %d\n", keyLength);

	if(keyLength == 1) {
		hashVal = key[0];
		return hashVal % SYM_TBL_SIZE;
	} else {
		for(int i = 0; i < keyLength; i++) {
			hashVal += key[i];
			
			if(i == 1 && keyLength == 2) {
				return (hashVal * 2) % SYM_TBL_SIZE;
			}
			else if(i == 2 && keyLength == 3) {
				return hashVal % SYM_TBL_SIZE;
			}
			else if(i == 3 && keyLength == 4) {
				return hashVal % SYM_TBL_SIZE;
			}
			else if(i == 4 && keyLength > 4) {
				return hashVal % SYM_TBL_SIZE;
			}
			else {
				continue;
			}
		}
	}
	return 0;
}
