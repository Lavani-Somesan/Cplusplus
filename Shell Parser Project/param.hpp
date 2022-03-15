/*
 * @author Lavani Somesan
 * @author Martin Kadzis
 * @date 10/5/2020
 *
 * The Param class stores the string of commands parsed
 * from the Parse class to the correlating fields. Has 
 * ability to print the fields when in debug mode.
 */



#ifndef PARAM_HPP
#define PARAM_HPP

#define MAXARGS 32
#include <iostream>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;


class Param {

	private:
		string argumentVector[MAXARGS];
		string inputRedirect;
		string outputRedirect;
		int argumentCount;
		int addingArgumentCounter;

		bool isArgVectorNotEmpty();
		bool isNumTokensNotMax();
		bool isInteger(string);
	
	public:
		Param();
		
		void setInputRedirect(char *);
		void setOutputRedirect(char *);
		void setArgumentCount(int);
		void addToArgumentVector(char *);

       		bool checkProgramParams();        
        	int getNumInstances();
		int getArgumentCount();
		string getArgsVector(int);
        	string getInputRedirect();
        	string getOutputRedirect();

		void printParams();
};

#endif

