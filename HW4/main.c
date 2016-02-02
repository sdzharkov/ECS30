#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "connectn.h"
#include <ctype.h>


//main function that starts the program
//program to execute the game of Connect-4, except the user can define the size of the board and how many pieces are needed to win
int main(int argc, char** argv){
	int num_rows = 0; //initialize variables that will be entered by the user
	int num_columns = 0;
	int plays_to_win = 0;
	int turn_count = 1;


	read_args(argc, argv, &num_rows, &num_columns, &plays_to_win); //pass the variables as pointers so that their values can be updated
	char** board = create_board(num_rows, num_columns);
	execute_game(board, num_rows, num_columns, plays_to_win, turn_count); 
	destroy_board(board, num_rows); //when the game is over, the board can be destroyed


	return 0;
}