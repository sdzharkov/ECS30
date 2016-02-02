//program to print out pascal's triangle up to the level specified by the user's input
#include <stdio.h>

//declare all functions at the beginning of the program
void pascalfunc(int pascalNum);

	
void pascalfunc(int pascalNum){ //return type is void because it prints out the desired results

	int row = 0; //intitialize all of the components of the triangle
	int num = 0;
	int col = 0;
	
	
	for (row=0; row < pascalNum; ++row){ //for ever row up to the specified number of levels
		num = 1; //first number in pascal's triangle is one
		for (col = 0; col <= row; ++col){
			printf("%d ",num); 
			num = num * (row-col) / (col + 1); //formula for the additional numbers
		}
		printf("\n");
	}
			
	return;
	
	}

int main(){
	int pascalNum = 0;
	
	printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
	scanf("%d", &pascalNum); //number of levels the user wants printed
	
	pascalfunc(pascalNum); //call the function that will display Pascal's Triangle 
	
	return 0;
	}
			
