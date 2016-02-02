#include <stdio.h>
//program that adds two fractions together without simplifying them

int main() {

	int frac1_num, frac1_denom; //initialize numerator and denominator for first fraction
	int frac2_num, frac2_denom; //intitialize numerator and denominator for second fraction
	int final_num, final_denom; //initialize numerator and denominator for resulting fraction

	printf("Please enter the first fraction to be added: ");
	scanf("%d / %d", &frac1_num, &frac1_denom); //read in values and assign them to the first fraction
	printf("Please enter the second fraction to be added: ");
	scanf("%d / %d", &frac2_num, &frac2_denom); //read in values and assign them to the second fraction
	//any amount of whitespace will be considered acceptable input 

	final_num = (frac1_num * frac2_denom) + (frac2_num * frac1_denom); 
	//numerator of the first fraction multiplied by the denominator of the second fraction
	//plus the numerator of the second fraction multiplied by the denominator of the first fraction
	final_denom = frac1_denom * frac2_denom; //multiply denominators together for common denominator

	printf("%d/%d + %d/%d = %d/%d\n", frac1_num, frac1_denom, frac2_num, frac2_denom, final_num, final_denom);

	return 0;

}