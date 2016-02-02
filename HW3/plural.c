//program that asks the user for a noun and prints out its plural form

#include <stdio.h>
#include <string.h>

//function to check the endings of the entered word, and to modify that word to the plural version
//void function because just alters the word in place
void plural(char word[]){ 
	int length; 
	length = strlen(word); //length of the word entered by the user

	if ((word[length-2] == 'c' && word[length-1] == 'h') || //if word ends in ch
		(word[length-2] == 's' && word[length-1] == 'h') ||  //if word ends in sh
		word[length-1] == 's' || word[length-1] == 'x' || word[length-1] == 'z'){ //if word ends in s, x, or z
		strcat(word, "es"); //concatenate 'es' to the end of the string
	}
	else if ((word[length-2] == 'a' || word[length-2] == 'e' || word[length-2] == 'i'
			|| word[length-2] == 'o' || word[length-2] == 'u') && word[length-1] == 'y') { //if the word ends in a vowel and y
		strcat(word, "s"); //concatenate s to the end of the string
	}
	else if (word[length-1] == 'y') { //if the word ends in a consonant and a y
		word[length-1] = 'i'; //add 'ies' to the end of the string
		word[length] = 'e';
		word[length+1] = 's';
		word[length+2] = '\0'; //have to put the null character back in at the end of the string
	}
	else if (word[length-1] == 'f' ) { //if the word ends in an 'f'
		word[length-1] = 'v'; //add ies to the end of the string
		word[length] = 'e';
		word[length+1] = 's';
		word[length+2] = '\0';
	}
	else if (word[length-2] == 'f' && word[length-1] == 'e') { //if the word ends in 'fe'
		word[length-2] = 'v'; //add 'ves' to the end of the string
		word[length-1] = 'e';
		word[length] = 's';
		word[length+1] = '\0';
	}
	else {
		strcat(word, "s"); //otherwise add an 's' to the end of the string
	}

	return;
}


int main() {
	int max_size = 10; //maximum size of the word will be ten characters
	char word[max_size]; //
	char original_word[max_size];

	printf("Please enter a word: ");
	scanf("%s", word);

	strcpy(original_word, word);

	plural(word);
	printf("The plural from of %s is %s.", original_word, word);



	return 0;
}
