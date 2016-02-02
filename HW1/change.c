// program to calculate amount of change in dollar bills
#include <stdio.h>
int main(void) {
	int money_amount; //initialize value read through input
	int hundreds, fifties, twenties, tens, fives, ones; //initialize bill amounts

	printf("Please enter the amount of money you wish to withdraw: ");
	scanf("%d", &money_amount); //assign amount to variable

	hundreds = money_amount/100; //divide the money amount evenly by 100 and decimal is dropped
	fifties = (money_amount%100)/50; //take the raminder of money_amount/100 and divide it evenly by 50
	twenties = (money_amount%50)/20;
	tens = (money_amount%50 - twenties*20)/10;
	fives = (money_amount%10)/5;
	ones = money_amount%5;

	//print statements displaying specific bills the user will be receiving
	printf("You received %d hundred(s)\n", hundreds); 
	printf("You received %d fifty(s)\n", fifties);
	printf("You received %d twenty(s)\n", twenties);
	printf("You received %d ten(s)\n", tens);
	printf("You received %d five(s)\n", fives);
	printf("You received %d one(s)\n", ones);

	return 0;


}