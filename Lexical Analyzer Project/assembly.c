#include "assembly.h"

char registerEndVal[20];
int postFixIndex = 0;
int registerCounter = 0;
int fileOutIndex = 0;

struct fileItem {
	char output[60];
};


struct postFixItem {
	char value[60];
};


struct fileItem fileOutput[100];
struct postFixItem postFix[30];

void addRegToken(char currToken[]);
void addRegOperator(char currToken[]);
void copyPostFix();


void setRegEndVal(char currToken[]) {
	memset(registerEndVal, '\0', sizeof(registerEndVal));
	strncpy(registerEndVal, currToken, strlen(currToken));
	registerCounter = 0;
}

void setPostFix() {
	memset(postFix[postFixIndex].value, '\0', sizeof(postFix[postFixIndex].value));
}


void incrementPostFix() {
	postFixIndex++;
}


void addRegToken(char currToken[]) {
	
	if(isalpha(currToken[0]) != 0 || isdigit(currToken[0]) > 0) {
		char *tempStr = fileOutput[fileOutIndex].output;

		tempStr += sprintf(tempStr, "%c%d ", 'R', registerCounter);
		tempStr += sprintf(tempStr, "%c ", '=');
		tempStr += sprintf(tempStr, "%s", currToken);

		registerCounter++;
		//printf("%s\n", fileOutput[fileOutIndex].output);
		fileOutIndex++;
	}
	else {
		addRegOperator(currToken);
	}
}


void addRegOperator(char currToken[]) {
	char *tempStr = fileOutput[fileOutIndex].output;
	
	tempStr += sprintf(tempStr, "%c%d ", 'R', registerCounter - 2);
	tempStr += sprintf(tempStr, "%c ", '=');
	tempStr += sprintf(tempStr, "%c%d", 'R', registerCounter - 2);
	tempStr += sprintf(tempStr, " %s ", currToken);
	tempStr += sprintf(tempStr, "%c%d", 'R', registerCounter - 1);
	//printf("%s\n", fileOutput[fileOutIndex].output);
	
	registerCounter--;
	fileOutIndex++;
}


void addPostFixToken(char currToken[]) {
	strcat(postFix[postFixIndex].value, currToken);
	strcat(postFix[postFixIndex].value, ",");
}


void addPostFixOperator(char op) {
	strcat(postFix[postFixIndex].value, &op);
	strcat(postFix[postFixIndex].value, ",");
}


void copyPostFix() {
	char *tempStr = fileOutput[fileOutIndex].output;

	tempStr += sprintf(tempStr, "%s", "******[");
	fileOutput[fileOutIndex].output[6] = '[';

	
	for(int i = 0; i < strlen(postFix[postFixIndex].value) - 1; i++) {
		tempStr += sprintf(tempStr, "%c", postFix[postFixIndex].value[i]);
	}
	
	tempStr += sprintf(tempStr, "%s", "]******");

	//printf("%s\n", fileOutput[fileOutIndex].output);	
	++fileOutIndex;
}


void generateAssemblyCode() {
	int length = strlen(postFix[postFixIndex].value);
	char tempArr[25];
	int count = 0;
	memset(tempArr, '\0', sizeof(tempArr));

	for(int i = 0; i < length; i++) {
		if(postFix[postFixIndex].value[i] == ',') {
			addRegToken(tempArr);
			//printf("%s\n", tempArr);
			count = 0;
			memset(tempArr, '\0', sizeof(tempArr));
		}
		else if(isalpha(postFix[postFixIndex].value[i]) != 0
			|| isdigit(postFix[postFixIndex].value[i]) > 0
			|| postFix[postFixIndex].value[i] == '_') {
			
			//printf("%c\n", tempCh);
			tempArr[count] = postFix[postFixIndex].value[i];
			count++;
			//printf("%s\n", tempArr);
		}
		else if(postFix[postFixIndex].value[i] != 0) {
			//printf("%c\n", tempCh);
			
			tempArr[count] = postFix[postFixIndex].value[i];
		}
		else {
			continue;
		}
	}

	char *tempStr = fileOutput[fileOutIndex].output;
	tempStr += sprintf(tempStr, "%s ", registerEndVal);
	tempStr += sprintf(tempStr, "%s", " = R0");
	//printf("%s\n", fileOutput[fileOutIndex].output);
	fileOutIndex++;
	
	copyPostFix();
}

void writeToFile(FILE *filePtr) {
	
	for(int i = 0; i < fileOutIndex; i++) {
		//printf("%s\n", fileOutput[i].output);
		fprintf(filePtr, "%s\n", fileOutput[i].output);
	}	
}
