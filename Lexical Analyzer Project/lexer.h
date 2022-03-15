/************************
 * File Name: lexer.h

* This file is responsible for reading a file and detrmining
 * what comes next in the token stream and returning it.
 ************************/

#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#define EOS '\0'
#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define BEGIN 300
#define END 301
#define DONE 260
#define NOT_FOUND 0
#define INT 302

FILE *filePtr;
extern int lineNum;
extern int numIds;
extern char currToken[20];

struct data {
	char token[20];
};

struct data idsFound[20];


int lexan();
void showIdFound();


#endif
