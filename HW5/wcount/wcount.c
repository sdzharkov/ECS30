#include <stdio.h>
#include <stdlib.h>

void wordcount(FILE* inFile); //This function counts the number of words 

int main(int argc, char* argv[]) {  //This is the main function
	FILE* inFile = fopen(argv[1],"r");  // this opens the file called in the command line 
	wordcount(inFile); // this calls wordcount with the file as a parameter
	fclose(inFile);  // this closes the file
	return 0;
}

void wordcount(FILE* inFile){  // this function counts the number of words
	int count = 0;
	char fileName[1000]; //declaring a file name
	if (inFile == NULL){ //if there is nothing in the file then print "error"
		printf("Error");
	}
	while (fscanf(inFile,"%s",fileName) != EOF){  //while scanning every word until no words left
			count ++; //update count
		}
	
	printf("There are %d word(s).",count); //print number of words
}


