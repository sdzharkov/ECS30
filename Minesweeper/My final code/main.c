#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "board.h" //include header files 
#include "play.h"

//program to implement the game of minesweeper
//user enters the name of the executable, the row and column dimensions, number of mines, and optionally a seed for random number generator 
int main(int argc, char** argv){
	
	Board board; //intitialize the board with struct type Board
	
  	int row = 0; //intialize the number of rows
  	int column = 0; //initialize the number of columns
  	int mine = 0; //intiialize the number of mines
  	read_args(argc, argv, &row, &column, &mine);
  	board.row = row;
  	board.col = column;
  	board.mine = mine;


	board.seed = generate_seed(argv);
	board.tile = create_board(board); //create the board
	mine_location_generator(board);
	print_board(board);
	play_is_valid(board);



	destroy_board(board); //when the game is over destroy the board

  return 0;
}