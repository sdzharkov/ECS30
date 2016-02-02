#include <stdio.h>
//gedit

int main(){
	//integers are used to represent whole numbers like ..., -2, -1, 0, 1,2,3,4...
	int num = 7;
	int num2;
	int num3;
	//a - z, 0 -9, _
	//if , for , while, int ,float, double, char, unsigned, const,
	//return, switch, long, break, continue, else
	
	//unsigned intergers are used to represent only positive whole numbers
	//you have to be extremly careful if you choose to work with them
	//as negative numbers cannot be represented with an unsigned interger
	//so if you do subtraction and subtract a larger number from a smaller number
	//you will get a weird result
	unsigned int positive = 10;
	unsigned int mystery;
	
	//floating point numbers are used to represent numbers that have a decimal part
	float frac = 89.73;
	float frac2;
	float frac3;
	
	//doubles are also used to represent numbers that have a decimal part
	//but they have more precision and can represent a wider range of numbers than floats
	//In order to get this increased precesion doubles take up twice as much space as a float
	//but you should favor using doubles over floats
	double better_frac = 80073.5726;
	double better_frac2;
	double better_frac3;
	
	//chars are used to represent charcters. Each char can only hold 1 character
	//character literals are written inside ''
	char character = 'h';
	char character2;
	char character3;
	
	//variables have to be defined at the beginning of a function in C.
	//As you can see above you can intialize a variable's value when you define it
	//or you can leave it undefined. If you do not intialize a variable's value,
	//it can be anything
	
	//variables are assinged values using = 
	//the value on the right hand side of = will be stored into the variable on the left of the equal
	//don't read = as equals but instead read it as assigned
	
	num2 = 12; //num2 is assigned the value 12 and NOT num2 is equal to 12
	frac2 = 37;
	better_frac2 = 12.39;
	character2 = 'i';
	mystery = -5;
	
	//variables can be used in expressions just like other values
	//everywhere the variable occurs its value is substitued in its place
	
	num3 = num + num2; //num 2 will have the value 7 + 12 which is 19
	
	//literals can also show up in the same expression with variables
	
	frac3 = frac2 + frac + 100  - 12;
	better_frac3 = better_frac2 / better_frac * 5;
	
	//adding to a chacter basically moves you through the alphabet
	//characters are actually represented using their ascii values
	//go to this website to see them: http://www.asciitable.com/
	character3 = character2 + 1;
	
	//you can overwrite a variable with a new value
	//if you do so the old value is replaced with the new one
	
	num = -6;
	
	//you can also update a variable based on its old value
	num2 = num2 + 1;
	
	//in addition to using printf to dispay regular strings
	//we can also use it to display variables. To do so we have to include
	//special format specifiers saying where the variable should be displayed at
	//format specifiers start with %. For every specifier you have in the format string
	//you have to have a variable
	
	//the syntax for printf is printf(format string, var1, var2, var3, ...)
	
	//%d is the format specifier for integers
	//I believe they choose d decimal starts with a d
	printf("num is %d\n", num);
	printf("num2 is %d\n", num2);
	printf("num3 is %d\n", num3);
	
	//%u is for unsigned integers
	printf("positive is %u\n", positive);
	printf("mystery is %u \n", mystery);
	
	//%f for floats
	printf("frac is %f\n", frac);
	printf("frac2 is %f\n", frac2);
	printf("frac3 is %f\n", frac3);
	
	//%lf for doubles
	printf("better_frac is %lf\n", better_frac);
	printf("better_frac2 is %lf\n", better_frac2);
	printf("better_frac3 is %lf\n", better_frac3);
	
	//%c for charcters
	printf("character is %c\n", character);
	printf("character2 is %c\n", character2);
	printf("characte3 is %c\n", character3);
	
	
	//you can have more than 1 variable per printf. 
	//In fact you can have as many as you want. Just make sure that you have
	//the same number of variables as you do format specifiers
	
	printf("The original crew %d %f %lf %c\n", num, frac, better_frac, character);
	
	//there are also many options to control how the variables are displayed
	//as an example for floats and doubles we can control how many digits
	//after the decimal point are displayed
	
	printf("frac3: %.2f and better_frac2: %.1lf\n", frac3, better_frac2);
	
	//you can tell the computer to display variables however you want
	//even if the types don't match. Generally you don't want to do this
	//but there are a few rare instances where you do
	
	printf("num interpreted as an unsinged interger is %u\n", num);
	
	//There are lot more things you can do with printf than just this
	//In fact I would say it is one of the most powerful and complicated
	//of the functions in the C standard library
	//see http://www.cplusplus.com/reference/cstdio/printf/
	//for everything you can do
	
	return 0;
}
