/*************************
 * File Name: parser.h

* This class is responsible for making sure if the token
 * that is passed from the lexical analyzer is okay or legal.
 * Reports errors such as syntax errors or illegal identifiers.
 *************************/

#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>


void startParse();
bool isError();

#endif
