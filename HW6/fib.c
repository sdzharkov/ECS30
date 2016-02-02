#include <stdio.h>
#include <stdlib.h>
//program to print the Nth fibonacci number in the series 


int fib(int num,int a, int b);


int main(int argc, char** argv){
	int a = 0; //first number in series
	int b = 1; //second number in series 
  	
	printf("The %dth fibanocci number is %d.", atoi(argv[1]), fib(atoi(argv[1]),a,b));
  	return 0;
}

//function to compute the fibonacci number recursively
int fib(int num, int a, int b){
	if(num < 0) { //if the number is less than zero the function should return 0
		return 0;
	}
  	else if(num == 1 || num == 2){ //base cases
		return a + b; //return the sum of the bases
	} 
	else { //recursive case
		return fib(num - 1, b, a + b); //decrement the number by one, change variables
	}
}
