#include <stdio.h>
#include <string.h>
//program to complete a binary string entered by a user 


//function that prints the binary string using recursion
void complete_binary(char* list, char* result) {
	//list holds the list being changed
	//result holds the final list we want to print

	if (*list == '\0') { //if we reached the end of the string, we should print out the string
		printf("%s\n", result);
		return; //done with the function
	}

	else if (*list == '1') { //if the element is a 1, do the rest
		complete_binary(list+1, result); //recursive call for the rest
	}
	else if (*list == '0') { //if the element is a 0, do the rest
		complete_binary(list+1, result);
	}

	else if(*list == 'x'){ //recursive case
		*list = '0'; //set the value to 0
		complete_binary(list+1, result);
		*list = '1'; //set the value to 1
		complete_binary(list+1, result);
		*list = 'x'; //after both cases have been executed, set the string back to an x
	}

	return;
}



// main function
int main(int argc, char** argv) {
	
	complete_binary(argv[1], argv[1]); //pass the same string twice


	return 0; 
}