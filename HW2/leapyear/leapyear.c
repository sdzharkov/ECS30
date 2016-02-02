//program to calculate whether an inputted year is a leap year or not
//a year is a leap year if it is evenly divisible by 4, except when it is divisible by 100
//if the year is divisible by 4 and also by 400 then it is a leap year
#include <stdio.h>

int main() {

	int user_input; //initialize variable that will be assigned to the year the user enters

	printf("Please enter a year: ");
	scanf("%d", &user_input); //assign input to variable

	if (user_input % 4 == 0) { //if the year is evenly divisible by 4
		if (user_input % 100 != 0) { //as long as the year is not evenly divisible by 100 it is leap year
			printf("%d is a leap year.\n", user_input);
		}
		else if (user_input % 400 == 0) { //if the year is evenly divisible by 400 it is leap year
			printf("%d is a leap year.\n", user_input);
		}
		else { //otherwise it is not a leap year
			printf("%d is not leap year.\n", user_input);
		}
	} 
	else { //if the year is not evenly divisible by 4 it is not a leap year
		printf("%d is not leap year.\n", user_input);
	}



	return 0;
}