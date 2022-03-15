/*
 * @author Lavani Somesan
 * @author Martin Kadzis
 * @date 10/5/2020
 *
 * The Parse class takes in a string of commands and a Param
 * object from the main program. It parses the string
 * of commands and sets them to the coressponing fields
 * in the Param object. 
 */



#ifndef PARSE_HPP
#define PARSE_HPP

#include "param.hpp"
#include <iostream>
#include <string.h>

using namespace std;


class Parse {

	private:
        	void tokenizer(string, Param &paramObj);
	public:
        	Parse(string, Param &paramObj);
};

#endif
