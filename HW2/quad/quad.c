//program to solve for x by using the quadratic formula
#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c; //intialize coefficients for equation entered by the user

	double inner_expression; //expression inside the square root
	double root1, root2; //answer can have either zero, one or two real roots 

	printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
	printf("Please enter a: "); //ask user for input of coefficients
	scanf("%lf", &a);
	printf("Please enter b: ");
	scanf("%lf", &b);
	printf("Please enter c: ");
	scanf("%lf", &c);

	inner_expression = (b * b) - (4 * a * c); //expression evaluated inside the square root

	if (inner_expression > 0) { //if we are taking the square root of a positive number
		root1 = (-b + sqrt(inner_expression))/(2 * a); //need to do both cases
		root2 = (-b - sqrt(inner_expression))/(2 * a); //two real solutions 
		printf("There are 2 real solutions\n");
		printf("Solution 1: %.2lf\n", root1); //display answer with two decimal places
		printf("Solution 2: %.2lf\n", root2);
	}
	else if (inner_expression == 0) { //if expression inside square root will be 0 we can ignore it
		root1 = (-b / (2 * a)); //only one real solution because there is nothing to add or subtract
		printf("There is one real solution: %.2lf\n", root1);
	}
	else if (inner_expression < 0) { //if we are taking the square root of a negative number
		printf("There are no real solutions\n"); //answer would include imaginary numbers
	}

	return 0;
}