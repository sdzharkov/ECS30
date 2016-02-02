#include <stdio.h>

//a quick demo of scanf, the function that gets input from a user

int main(){

	//scanf is very simlar to printf
	//its syntax is scanf(format string, address of var 1, address of var2, ...);
	//in case you forgot printf's syntax printf(format string, var1, var2, ....);
	//the only difference between the 2 is that in scanf you need a variables address
	//the & operator gives you the address of a variable
	
	
	int num1;
	double d1 = 10;
	double d2 = 99;
	
	printf("Enter a whole number: ");
	scanf("%d", &num1);
	
	printf("You entered %d\n", num1);
	
	//for scanf the format string should specify 
	//enters the format of what the user
	
	printf("Enter a number + another number: ");
	
	//this format string means we are expecting the user to enter
	//a double followed by
	//a plus sign
	//and then another double
	scanf("%lf+%lf", &d1, &d2);
	printf("%lf + %lf is %lf\n", d1, d2, d1 + d2);
	
	//if we want to allow the user to enter some white space (spaces or tabs)
	//in between the floats the + sign and the last float we have to put
	//a space in between the values
	
	printf("Enter a number + another number: ");
	scanf("%lf + %lf", &d1, &d2);
	printf("%lf + %lf is %lf\n", d1, d2, d1 + d2);
	
	

	return 0;
}
