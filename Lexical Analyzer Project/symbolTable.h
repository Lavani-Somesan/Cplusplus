/**********************
 * File Name: symbolTable.h
 *
 * This file is responsible for being able to
 * lookup a token or insert a token into a 
 * hash table.
 *********************/


#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <stdio.h>
#include <string.h>


int insertIntoTbl(char token[], int tokenType);
int lookup(char token[]);


#endif
