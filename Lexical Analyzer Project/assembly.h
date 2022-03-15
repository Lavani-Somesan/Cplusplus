/***********************
 * File Name: assembly.h 
 ***********************/

#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>


void setRegEndVal(char currToken[]);
void setPostFix();
void incrementPostFix();
void addPostFixToken(char currToken[]);
void addPostFixOperator(char ch);
void generateAssemblyCode();


void writeToFile(FILE *filePtr);


#endif
