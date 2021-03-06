#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "board.h"

//file to contain all functions pertaining to the board and creating it
//function to create the board
//board holds a 2-D array of the tiles
tiles** create_board(Board board) {
	int i, j;
	tiles** size;
	size = (tiles**)malloc((board.row)*sizeof(tiles*)); //allocate memory for each column on the board
  	for(i = 0; i < board.row; i++){
    	size[i] = (tiles*)malloc((board.col)*sizeof(tiles)); //allocate memory for each row on the board
  	}
	for(i = 0; i < board.row; i++){
		for(j = 0; j < board.col; j++){
			(size[i][j]).revealed = '#';
			(size[i][j]).concealed = ' ';
			(size[i][j]).marked = ' ';
		}
	}
	return size;
}
//function to print out the board
void print_board(Board board) {
	int i, j;
	int row_count = board.row - 1; //prints the number of the rows on the left of each row
	for (i = 0; i < board.row; i++) {
		printf("%d ", row_count);
		for (j = 0; j < board.col; j++) {
			printf("%c ", (board.tile[i][j]).revealed);
		}
		printf("\n");
		row_count--;	
	}
	printf("  ");
	for (j = 0; j < board.col; j++) {
			printf("%d ", j);
	}
	printf("\n");	
	return;
}
//function to destroy the board once the game is over
void destroy_board(Board board) {
	int i;
	for(i =0; i < board.row; i++){ //first free the space for each column
    free(board.tile[i]);
  }
	//then free the space for ever row 
  free(board.tile);
	return;
}

//function to read the user's arguments
void read_args(int argc, char** argv, int* row, int* column, int* mine) {
	if (argc < 4) {
		printf("Not enough arguments. Usage:\n");
		printf("./mine_sweeper.out num_rows num_cols num_mines [seed])\n");
		exit (0);
	}
	else if (argc > 5) {
		printf("Too many arguments. Usage:\n");
		printf("./mine_sweeper.out num_rows num_cols num_mines [seed])\n");
		exit (0);
	}
	else {
		*row = atoi(argv[1]); //dereference the pointer and store the integer value of the arguments
		*column = atoi(argv[2]);
		*mine = atoi(argv[3]);
	}
	return;
}


