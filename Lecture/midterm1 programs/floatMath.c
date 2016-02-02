#include <stdio.h>

//this is a quick demo of the operators defined on floats
int main(){

	//multiple variables of the same type can be declared on 1 line
	//use commas to separte the different variables
  double num1, num2, num3, num4, num5; 
  
  int integer1, integer2, integer3;
  
  num1 = 10.0 + 5.9; //you can do addition
  num2 = 100.87 - 28.21; //subtraction
  num3 = 58.54 * 62.14 * 24.99; //multiplication
  num4 = 3.0 / 4.0; //and division
  
  //the modulo operator %, is not supported on floats or doubles 

	integer2 = 10; 
	integer3 = 99;
	
	//if you combine integers and doubles in an expression the result
	//will be transformed into a double. This changing of types is called casting.
	
	printf("10 + 3.9 is %lf\n", 10 + 3.9);
	
	//The compilier does a lot of casting for you automatically.
	//This is called implicit casting.
	//The rules for implicit casting are
	  //For an arithmetic operator like + or *, if either operand is a double, 
	  //the other is automatically converted to double, and then a floating-point operation is performed.
    //For assignment =, the right side type is converted to the left side type.
    
  //converting a double to an integer causes the part after the decimal to be dropped
  
  integer1 = num1;
  
  printf("integer1 is %d and num1 is stil %lf\n", integer1, num1);
  
  //the thing that you have to be careful to watch out for is accidentally doing
  //integer divison when you wanted to do floating point division
  
  printf("integer3/integer2 is %d\n", integer3 / integer2);
  
  //to get around this you can explicitly cast the type
  //the syntax is (type to cast to) expression
  
  printf("integer3/integer2 is %lf\n", (double) integer3 / (double) integer2);
  //you don't have to cast both, it is enough to cast just 1 but being carful never hurts
  
  //but be careful as you don't want to cast the result of the expression but the elements
  //themselves
  
  printf("integer3/integer2 is %lf\n", (double) (integer3 /  integer2));


	return 0;
}
