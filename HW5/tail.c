#include <stdio.h>
#include <stdlib.h>
//program that asks the user for a file and how many last lines of the file they would like to see printed

void tail(FILE* inFile, FILE* inFile2, int numLine);

//function to read through the file and print the last numLine lines of the file
void tail(FILE* inFile, FILE* inFile2, int numLine){
	int linecount = 0;
	int second_count = 0;
	char lines[100]; //for the first time we read the file to solely determine number of lines
	char result[100];
	

	//open the file one time to determine how many lines are in the file
	while (fgets(lines, 100, inFile) != NULL) { //read in each string one at a time
		linecount += 1; //for each line add one to the line count
	}

	if (numLine > linecount) { //if the user asked for more lines than there are in the file, print all the lines
		while(fgets(result, 100, inFile2) != NULL) { //read in all the strings and print each one
			printf("%s", result);
		}
		return; //the printing is over so we can exit the function
			
	}
	else {
		while (fgets(result, 100, inFile2) != NULL) { //read in one string at a time
			second_count += 1; //add one to this line count to reach our desired starting point
			if (second_count < linecount - numLine + 1) { //second count must be equal to how many lines the user wants printed
				continue; //go to the next iteration
			}
			else {
				printf("%s", result); //print each line that is greater than or equal to the starting point
			}
			
		}
	}
	
return;
}

int main(int argc, char* argv[]) {
	
	FILE* inFile = fopen(argv[1],"r"); //open file first time
	FILE* inFile2 = fopen(argv[1], "r"); //open it again to print results
	int numLine = atoi(argv[2]); //how many lines the user wants printed 
	tail(inFile, inFile2, numLine);
	fclose(inFile); //need to close all files that have been opened
	fclose(inFile2);

	return 0;
}

