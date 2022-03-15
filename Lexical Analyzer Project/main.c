/*********************
 * File Name: main.c

* This file is responsible for opening the file needed by
 * the parser and lexical analyzer. Then calling startParse
 * function to start analyzing the file.
 *********************/

#include "lexer.h"
#include "symbolTable.h"
#include "parser.h"
#include "assembly.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	insertIntoTbl("begin", BEGIN);
	insertIntoTbl("end", END);
	insertIntoTbl("int", INT);

	if(argc == 2) {
		printf("Compiling %s\n", argv[1]);
	} else {
		printf("Only one argument required\n");
		return -1;
	}

	filePtr = fopen(argv[1], "r");
	
	if(filePtr == NULL) {
		printf("Cannot Open File\n");
		return -1;
	}

	startParse();

	fclose(filePtr);

	if(isError() != 1) {
		char outputFile[strlen(argv[1]) + 1];
	       	strcpy(outputFile, argv[1]);

		for(int i = 0; i < strlen(outputFile); i++) {
			if(outputFile[i] == '.') {
				outputFile[i + 1] = 'o';
				outputFile[i + 2] = 'u';
				outputFile[i + 3] = 't';
				break;
			}
		}

		filePtr = fopen(outputFile, "w");

		writeToFile(filePtr);

		fclose(filePtr);		
	}

	return 0;
}




