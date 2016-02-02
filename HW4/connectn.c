#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "connectn.h"
#include <ctype.h>


//function to read in the command line arguments
void read_args(int argc, char** argv, int* num_rows, int* num_columns, int* plays_to_win) {

//first argument is the name of the executable, followed by 3 more for rows, columns, and plays to win
	if (argc < 4) { //if the number of arguments is less than 4, there are too few
		printf("Not enough arguments entered\nUsage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0); //terminate the program
	}
	else if (argc > 4) { //if the number of arguments is more than 4 there are too many
		printf("Too many arguments entered\nUsage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0); //terminate the program
	}
	else {
		*num_rows = atoi(argv[1]); //convert arguments into integers
		*num_columns = atoi(argv[2]);
		*plays_to_win = atoi(argv[3]);
	}
 
}

//function to dynamically allocate space for the board based on user defined sizes
char** create_board(int num_rows, int num_columns) { //function is a double pointer so we can return the board
	int i, j, k;

	char** board = (char**)malloc(num_rows * sizeof(char*)); //space for each row
	for (i= 0; i < num_rows; i++) {
		board[i] = (char*)malloc(num_columns * sizeof(char)); //space for each column
	}
	for (j = 0; j < num_rows; j++) {
		for (k = 0; k < num_columns; k++) {
			board[j][k] = '*'; //with the space we allocated, put a star in each element of the array
		}
	}

	return board;
}

//function to free all the space allocated for the board if the game is over
void destroy_board(char** board, int num_rows) {
	int i;
	for (i = 0; i < num_rows; i++) {
		free(board[i]); //free the space we allocated for the board for each column
	}
	free(board); //frees each row that we allocated memory for 

	return;
}

//function to print the board for the user to see after every turn
void print_board(char** board, int num_rows, int num_columns) {
	int i, j;
	int count = num_rows-1; //print out the row numbers before each row
	for (i = 0; i < num_rows ; i++){
		printf("%d ", count);
		for (j = 0; j < num_columns; j++) {
			printf("%c ", board[i][j]); //go through each row and each column and print a '*'
		}
		printf("\n");
		count--; //decrement the count for each row
	}
	printf("  ");
	j = 0;
	for (j = 0; j < num_columns; j++) {
		printf("%d ", j); //print the column numbers at the bottom of the board
	}
	printf("\n");

	return;
}

//function to ask the user what column they would like to play in
void get_play(int num_columns, int num_rows, char** board, int turn_count) {
	int column_play = 0;

	printf("Enter a column between 0 and %d to play in: ", num_columns-1); //ask the user for input
	scanf("%d", &column_play);

	while (!(play_is_valid(num_rows, num_columns, column_play, board))) { //while the play isnt valid keep asking user for input
		printf("Enter a column between 0 and %d to play in: ", num_columns-1);
		scanf("%d", &column_play);
	}
	if (play_is_valid(num_rows, num_columns, column_play, board)) { //if the play is valid
		play_game(board, turn_count, num_rows, column_play); //play game to update the board
	}

	return;
}

//function to update the board
void play_game(char** board, int turn_count, int num_rows, int column_play) {
	int i;
	for (i = num_rows-1; i >= 0; i--) {
		if (board[i][column_play] != '*') { //if the column in the bottom row already has a piece played in it
			continue; //skip it and go to one row higher 
		}
		else  {
			if ((turn_count % 2) != 0) { //determine whose turn it is
				board[i][column_play] = 'O';
				break;
			}
			else {
				board[i][column_play] = 'X';
				break;
			}
		}
	}

}

//function to check if the column entered is valid
bool play_is_valid(int num_rows, int num_columns, int column_play, char** board) {

	if ((column_play > (num_columns-1)) || (column_play < 0)) { //if the entered column is out of range
		return false;
	}
	else if(board[0][column_play]!='*'){ //if the column is full
		return false;
	}
	return true;
}

//function to check if there is a win in the row 
bool row_win(char** board, int num_rows, int num_columns, int plays_to_win) {
	int i, j, k;
	for (i = 0; i < num_rows; i++) { //for every row starting at the first row
		int num_in_a_row = 1;
		for (j = 0; j <= num_columns - plays_to_win; j++) { //for ever column that won't go out of range
			if(board[i][j] == '*') { //if the spot is still unused skip it and go to the next iteration
				continue;
			}
			num_in_a_row = 1;
			for (k = 1; k < plays_to_win; k++) {
				if (board[i][j] == board[i][j+k]) { //if there is a match
					num_in_a_row += 1;
					if (num_in_a_row == plays_to_win) { //check to see if the increment counter is same as pieces needed to win
						return true;
					}	
				}
				else {
					break;
				}
			}
			
		}
	}
	return false;
}

//function to check if there is a win in the column
bool col_win(char** board, int num_rows, int num_columns, int plays_to_win) {
	int i, j, k;
	for (j = 0; j < num_columns; j++) { //starting at the first column
		int num_in_a_row = 1;
		for (i = 0; i <= num_rows- plays_to_win; i++) { //go through every row that will have a possibility 
			if(board[i][j] == '*') { //if the spot is unused skip it and go to the next iteration
				continue;
			}
			num_in_a_row = 1;
			for (k = 1; k < plays_to_win; k++) { //loop through as many times as pieces you need to win
				if (board[i][j] == board[i+k][j]) { //if there is a match in the column
					num_in_a_row += 1;
					if (num_in_a_row == plays_to_win) { //check if the increment is same as pieces needed to win
						return true;
					}
				}
				else {
					num_in_a_row = 1; //otherwise go to next iteration and set counter back to 1
					break;
				}
			}
			
		}
	}
	return false;
}

//function to check win from bottom left to top right
bool right_diag_win(char** board, int num_rows, int num_columns, int plays_to_win) {
	int i, j, k;
	for (i = num_rows - 1; i > num_rows- plays_to_win; i--) { //start at the bottom row
		int num_in_a_row = 1;
		for (j = 0; j < num_columns - plays_to_win; j++) { //start at the first column
			if(board[i][j] == '*') { //if the spot is still unused skip it and go to the next iteration
				continue;
			}
				for (k = 1; k < plays_to_win; k++) {
					if (board[i][j] == board[i-k][j+k]) { //if there is a match
						num_in_a_row += 1; //add one to the increment counter
						if (num_in_a_row == plays_to_win) { //check if the increment is the number of pieces needed to win
							return true;
						}
					}

					else {
						num_in_a_row = 1; //if there isn't a match, set the counter back to 1
						break;
					}
			
				}
			}
		}
	return false;

}

//function to check win from top left to bottom right
bool left_diag_win(char** board, int num_rows, int num_columns, int plays_to_win) {
	int i, j, k;
	for (i = 0; i <= num_rows- plays_to_win; i++) { //starting at the first row
		int num_in_a_row = 1; //start the number of pieces in a row at 1
		for (j = 0; j <= num_columns- plays_to_win; j++) { //starting at the first column
			if (board[i][j] == '*') { //if the board at that element is still unused
				continue; //skip it and go to the next spot
			}
				for (k = 1; k < plays_to_win; k++) {
					if (board[i][j] == board[i+k][j+k]) { //if there is a match in the diagonal
						num_in_a_row += 1; //add one to the increment counter
						if (num_in_a_row == plays_to_win) { //check if the increment is how many in a row you need to win
							return true; //return true to end the game
						}
					}
					else {
						num_in_a_row = 1; //otherwise, set the counter back to one and break back to the second for loop
						break;
					}
				}
		}
			
	}
	return false;
}

void execute_game(char** board, int num_rows, int num_columns, int plays_to_win, int turn_count) {
	turn_count = 0;
	while ((game_won(board, num_rows, num_columns, plays_to_win) == false) && 
			(game_over(board, num_rows, num_columns) == false)) { //while there isnt a win and it isn't a tie game yet
		print_board(board, num_rows, num_columns); //print the board
		get_play(num_columns, num_rows, board, turn_count); //ask the user for their play and update the board
		turn_count++; //increment the amount of turns that have been played
	}
	if (game_won(board, num_rows, num_columns, plays_to_win)) { //if somebody has won the game
		//determine which player is the winner
		int player = 0;
			if (turn_count % 2 == 0) { //player two has the even numbers on turn_count increment
				player = 2;
			}
			else {
				player = 1;
			}
			print_board(board, num_rows, num_columns); //print the board and declare the winner
			printf("Player %d Won!\n", player);	
		}
	else if (game_over(board, num_rows, num_columns)) { //if the game is a tie
		print_board(board, num_rows, num_columns); //print the board and declare a tie
		printf("Tie game!\n");
	}


	return;
}

//function to determine if a player has won the game 
bool game_won(char** board, int num_rows, int num_columns, int plays_to_win) {

	if (col_win(board, num_rows, num_columns, plays_to_win) //if there is a win in the column
		|| row_win(board, num_rows, num_columns, plays_to_win) //if there is a win in the row
		|| right_diag_win(board, num_rows, num_columns, plays_to_win) //if there is a win in the right diagonal
		|| left_diag_win(board, num_rows, num_columns, plays_to_win)) { //if there is a win in the left diagonal
 
		return true;
	}

	return false;

}
//function to determine if it is a tie game
bool game_over(char** board, int num_rows, int num_columns) {
	int i;
	for (i = 0; i < num_columns; i++) {
		if (board[0][i] == '*') { //if an element in the board is still a star, more moves can be played
			return false;
		}
	}
	return true;
}


