/**
 * @author Lavani Somesan
 * @author Martin Kadzis
 * @date 10/5/2020
 *
 * This is the main program that implements the shell.
 * Prompts the user to input a string of commands which 
 * is parsed and interpreted by the program. The shell
 * checks to make sure user input is correct and then 
 * forks and executes the user's command. It will also
 * do input and output file redirection.
 */

#include "parse.hpp"
#include "param.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;


int main() {
	
	const string COMMAND_PROMPT = "$$$ ";
    	const string DEBUG_MODE = "myshell -Debug";
	const string EXIT_COMMAND = "exit";
    	const string PRIME = "prime";
    	const string TESTME = "testme";
	const string EMPTY_STRING = "";
	const int MIN_ARG = 2;

	bool running = true;
	bool debugging = false;

	do {
		string userInput;
        	
		cout << COMMAND_PROMPT;
		getline(cin, userInput);

		if(userInput.compare(EMPTY_STRING) == 0) {
			cout << "Error: Nothing Was Entered" << endl;
		}

		else if(userInput.compare(DEBUG_MODE) == 0){
			debugging = true;
        	}
	
		else if(userInput.compare(EXIT_COMMAND) != 0){
			Param paramObj;
			Parse parser(userInput, paramObj);

			if(debugging == true) {
				paramObj.printParams();
				debugging = false;
			}

        		if(paramObj.checkProgramParams()){
				//getting the argument vector from param object 
				int argsCount = paramObj.getArgumentCount();

                		string arguments[argsCount];
                		for(int i = 0; i < argsCount; ++i){
                    			arguments[i] = paramObj.getArgsVector(i);
               	 		}			
	
				char* argsv[argsCount];
				for(int i = 0; i < argsCount; ++i){
    					argsv[i] = (char*)arguments[i].c_str();
				}

				//This is where you use fork to a certain number of times
				cout << "\nFork and execute program" << endl;
				//the child, assuming we modify arguments based on how many children and split the range
				//below inserts a instance placement in the argument, when users insert ./prime 1 1000, it mods it to ./prime 1 0 1000
				//int newCount = argsCount + MIN_ARG;
				
                		vector<char*> argsvMod;
                		argsvMod.push_back(argsv[0]);
                		argsvMod.push_back(argsv[1]);
                		argsvMod.push_back(argsv[1]);
                
                		if(argsCount > MIN_ARG){
                    			for(int i = MIN_ARG; i < argsCount; ++i){
                        			argsvMod.push_back(argsv[i]);}
                		}

                		//below mods the argsvModded[2] to the instance number and executes the program
				for(int i = 0; i < stoi(argsv[1]); ++i){
                    			FILE *fp;
                    			int pid, status;
                    			pid = fork();

                    			if(pid) {
                        			wait(&status);
                    			} else {
                        			//mod this specific instance to the argument array
			           		string instance = to_string(i);
				        	argsvMod.at(MIN_ARG) = (char*)instance.c_str();

                        			//input redirect check, you want to do this here so that u have the input value to display the processed value range
                        			if(paramObj.getInputRedirect() != "NULL"){
                        
                            				vector<string> fileInput;
                            				char content[100];

                            				string file = paramObj.getInputRedirect();
                            				char* filename = (char*)file.c_str();
                            				fp = freopen(filename, "r", stdin);

                            				//reads each line into the string vector
                            				while(!feof(fp)){
                                				fgets(content, 100, fp);
                                				fileInput.push_back(content);
                            				}
                            				fclose(fp);

                            				//removes the duplicate final line
                            				fileInput.erase(fileInput.begin() + fileInput.size()-1);
                    
                            				//cleans the "\n" from fgets()
                            				for(int i = 0; i < (int)fileInput.size(); ++i){
                                				int pos = 0;
                                				while((pos = fileInput.at(i).find("\n",pos)) != string::npos){
                                    					fileInput.at(i).erase(pos,2);
                                				}
                            				}

                            				//add the inputs into the arguments
                            				for(int i = 0; i < (int)fileInput.size(); ++i){
                                				string temp = fileInput.at(i);
                                				char* tempStr = (char*)temp.c_str();
                                				argsvMod.push_back(tempStr);
                            				}
                        			}

                        			argsvMod.push_back(nullptr);

                        			//recreate the char* array
                        			char* argsvModded[argsvMod.size()];
                        			for(int i = 0; i < (int)argsvMod.size(); ++i){
                            				argsvModded[i] = argsvMod.at(i);}

                        			//print the instance and processed value range
                        			int total = stoi(argsv[1]);
                        			int range1 = (stoi(argsvModded[3])/stoi(argsvModded[1])) * i;
                        			int range2 = (stoi(argsvModded[3])/stoi(argsvModded[1])) * (i+1);
                        			cout << "[" << i << "/" << total << "]: processing values from " << range1 << " to " << range2 << endl;

                        			//output redirect check
                        			if (paramObj.getOutputRedirect() != "NULL") {
                            				string file = paramObj.getOutputRedirect() + to_string(i+1);
                            				char* filename = (char*)file.c_str();
                            				fp = freopen(filename, "w", stdout);
                        			}

                        			//execute the program
						execvp(argsvModded[0], argsvModded);
                        			fclose(fp);
                    			}
			    	}
			} 
			else {
				cout << "Error: Command Terminated Due to Incorrect Variable Type" << endl;
			}
		} 
	
		else {
			running = false;
		}
    }while(running);
	
	return 0;
}
