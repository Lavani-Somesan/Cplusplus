#ifndef FILEREADER_H
#define FILEREADER_H

#include "book.h"
#include "library.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class FileReader {

	public:
		FileReader(string filename);
		
		void readFile(string filename);
	
};


#endif

