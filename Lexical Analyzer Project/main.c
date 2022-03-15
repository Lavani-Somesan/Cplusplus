/*********************
 * File Name: main.c
 *
 * This file is responsible for opening the file needed by
 * the parser and lexical analyzer. Then calling startParse
 * function to start analyzing the file.
 *********************/

#include "lexer.h"
#include "symbolTable.h"
#include "parser.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

	insertIntoTbl("begin", BEGIN);
	insertIntoTbl("end", END);

	if(argc == 2) {
		printf("Compiling %s\n", argv[1]);
	} else {
		printf("Only one argument required\n");
		return 0;
	}

	filePtr = fopen(argv[1], "r");

	startParse();

	fclose(filePtr);

	return 0;
}




