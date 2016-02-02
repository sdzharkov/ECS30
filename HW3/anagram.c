//program to see whether two words are are anagrams 
#include <stdio.h>
#include <string.h>
#include <ctype.h> //this library allows us to use the tolower function to alter characters

//declare all functions at the beginning of the program
void compare_strings(char first[], char second[]);
int anagram_check(char first[], char second[]);

//function that checks if the two words are anagrams of each other after converting the words to all lowercase
int anagram_check(char first[], char second[]) {

	int i, j;
	int counter1 = 0; //initialize the numbercounter for the first word
	int counter2 = 0; //initialize the number counter for the second word
	for (i = 0; i < strlen(first); i++) {
		counter1 += (int)(first[i]); //change each chracter to an integer and add it to its counter
		//will hold the total ascii values in counter1
	}
	for (j = 0; j < strlen(second); j++) {
		counter2 += (int)(second[j]); //change each character of the second word to an integer and add to its counter
	}

	if (counter1 != counter2) //if both counters do nothold the same value the words don't contain the same letters
		return 1; //return a positive number

	return 0; //return 0 if it is successful and the words are anagrams

}

//function that compares the strings by length, changes the characters to all lowercase
//also determines if the words are anagrams of one another
//return type void because has print statements to execute wanted results
void compare_strings(char first[], char second[]) {
	int i; 
	int j;
	char original_first[20];
	char original_second[20];

	strcpy(original_first, first); //store a copy of the first word into the placeholder variable
	//allows us to alter the first array while still knowing its original value 
	strcpy(original_second, second); //store a copy of second word into this placeholder variable

	if (strlen(first) != strlen(second)) { //if the lengths of the two strings aren't the same we can immediately exit
		printf("%s is NOT an anagram of %s", first, second);
		return;
	}
	for (i = 0; i < strlen(first); i++) {
		first[i] = tolower(first[i]); //change each character to lowercase if it already isn't
	}

	for (j = 0; j < strlen(second); j++) {
		second[j] = tolower(second[j]); //change each character to lowercase if it already isn't
	}



	if (anagram_check(first,second) == 0) { //call function to check if words are anagrams
		//we get 0 back from the function if it is successful, so that is our if statement condition
		printf("%s is an anagram of %s", original_first, original_second);
	}
	else {
		printf("%s is NOT an anagram of %s", original_first, original_second);
	}
	return;

}



int main() {

	char first[20]; //initialize the words to be entered
	char second[20]; //create space for a maximum of 20 characters 

	printf("Please enter the first word: "); //read in the first word and assign it to variable first
	scanf("%s", first);
	printf("Please enter the second word: "); //read in the second word and assign it to variable second
	scanf("%s", second);

	compare_strings(first, second); //call the function that executes the string comparisons


	return 0;
}