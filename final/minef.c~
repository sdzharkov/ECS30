#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


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



//function to give a seed to the random number generator
int generate_seed(char** argv){
	int location_of_seed;
	if (argv[4] != NULL) {
		location_of_seed = atoi(argv[4]); //if the user entered a fifth argument
	}
	else {
		location_of_seed = ((int)time(0)); //seed with the current time
	}
	return location_of_seed;
}

//function to keep playing the game while nobody has won
void play_is_valid(Board board) {
	while(1){
		play_game(board); //call the function to get a play from the user and print how many mines are left
	}
	return;
}

//function to print the board and say how many mines are left 
void play_game(Board board) {
	get_play(board);
	printf("There are %d mines left\n", board.mine - marked_mines(board)); //print how many  mines are left
	print_board(board);
	return;
}

//ask the user for a play
void get_play(Board board) {
	int enter_row, enter_col;
	while(1){ //while still true, keep going through this loop
		printf("Enter row a row between 0-%d and a column between 0-%d: ", board.row - 1, board.col - 1);
		scanf("%d %d", &enter_row, &enter_col);
		enter_row = board.row - enter_row - 1;
		if (in_bounds(board, enter_row, enter_col)) {
			if (board.tile[enter_row][enter_col].revealed == '!') {
				if (option_2(board, enter_row, enter_col)) {
					break;
				}
				else {
					continue;
				}
			}
			else if (board.tile[enter_row][enter_col].revealed == '?') {
				if (option_3(board, enter_row, enter_col)) {
					break;
				}
				else {
					continue;
				}
			}
			else if (board.tile[enter_row][enter_col].revealed == '#') {
				if (option_1(board, enter_row, enter_col)) {
					reveal_board(board, enter_row, enter_col, 0); 
					break;
				}
				else {
					continue;
				}
			}
			else {
				printf("This tile is already revealed.\n");
				continue;
			}
		}
		else {
			continue;
		}
	}
	if (check_win(board)) {
			print_board(board);
			printf("You Won!!\n");
			exit (0); //end the program because the game is over and the user has lost 
	}

	if (isgameover(board)) {
			print_board(board);
			printf("You Lost :(\n");
			exit(0); //end the program because the game is over and the user has lost
	}
	return;
}

//function to ask the user what they want to do with their entered coordinates
int option_1(Board board, int row, int col) {
	int entered_option;
	printf("Enter Action\n0. Reveal\n1. Question\n2. Mark\n3. Cancel\nAction: "); //present options to user 
	scanf("%d", &entered_option);
	if (entered_option == 0) { //to reveal 
		board.tile[row][col].revealed = board.tile[row][col].concealed;
		return 1;
	}
	else if (entered_option == 1) { //question mark option
		board.tile[row][col].marked = '?';
		board.tile[row][col].revealed = board.tile[row][col].marked;
		return 1;
	}
	else if (entered_option == 2) { //to mark with an exclamation point
		board.tile[row][col].marked = '!';
		board.tile[row][col].revealed = board.tile[row][col].marked;
		return 1;
	}
	else if (entered_option == 3) { //to cancel their move
		return 0;
	}
	else {
		return 0;
	}
}

//function if the user wants to mark the board
int option_2(Board board, int row, int col) {
	int entered_option;
	printf("Enter Action\n0. UnMark\n1. Cancel\nAction: ");
	scanf("%d", &entered_option);
	if (entered_option == 0) {
		board.tile[row][col].marked = ' ';
		board.tile[row][col].revealed = '#';
		return 1;
	}
	else if (entered_option == 1) {
		return 0;
	}
	else {
		return 0;
	}
}

//function to execute if the user wants to cancel their move
int option_3(Board board, int row, int col) {
	int entered_option;
	printf("Enter Action\n0. UnQuestion\n1. Cancel\nAction: ");
	scanf("%d", &entered_option);
	if (entered_option == 0) {
		board.tile[row][col].marked = ' ';
		board.tile[row][col].revealed = '#';
		return 1;
	}
	else if (entered_option == 1) {
		return 0;
	}
	else {
		return 0;
	}
}

//option to check if the game has been won
int check_win(Board board) {
	int i, j;
	int count = 0;
	for(i = 0; i < board.row; i++){
		for(j = 0; j < board.col; j++){
			if (board.tile[i][j].revealed == '!' && board.tile[i][j].concealed == '*') {
				count++;
			}
			else if (board.tile[i][j].revealed == '!') {
				continue; //if the board has been marked
			}
			else if (board.tile[i][j].revealed == '?') { //if the spot has been questioned
				continue;
			}
			else if (board.tile[i][j].revealed == '#') { //if the board is still concealed
				continue;
			}
			else {
				count++;
			}
		}
	}
	if (count == board.row * board.col) { 
		for(i = 0; i < board.row; i++){
			for(j = 0; j < board.col; j++){
				board.tile[i][j].revealed = board.tile[i][j].concealed;
			}
		}
		return 1;
	}
	return 0;
}

//function to check if the game is over
int isgameover(Board board) {
	int i, j;
	for(i = 0; i < board.row; i++){ //for ever row
		for(j = 0; j < board.col; j++){ //for every column
			if (board.tile[i][j].revealed == '*') {  //if the tile is a mine
				int k, l;
				for(k = 0; k < board.row; k++){
					for(l = 0; l < board.col; l++){
						board.tile[k][l].revealed = board.tile[k][l].concealed;
					}
				}
				return 1; //keep playing the game 
			}
		}
	}
	return 0;
}

//function to put the mine on the board
//using the random function to produce the mine locations
void mine_location_generator(Board board) {
	int i;
	int row, column;
	srand(board.seed); 
	i = board.mine; //number of mines 
	while (i > 0) {
		// Pick a random row and col
		row = board.row - rand() % board.row - 1; //choose a random row
		column = rand() % board.col; //chose a random column 
		if (board.tile[row][column].concealed == '*') { //if there is already a mine there skip to the next one 
			continue;
		}
		else {
			board.tile[row][column].concealed = '*';
			printf("Placing mine at %d, %d\n", board.row - row - 1, column); // tell the user where you are placing the mine 
		} 
		i--; //decrememnt the value of i so that you can keep track of how many total mines to place on the board 
	}
	put_concealed(board); // Set the number of mines around one space
	printf("There are %d mines left\n", board.mine);
	return;
}

//function to place the mines and then check their visibility
void put_concealed(Board board) {
	int i, j;
	for(i = 0; i < board.row; i++){
		for(j = 0; j < board.col; j++){
			if (board.tile[i][j].concealed != '*') { //if the spot isn't a mine
				board.tile[i][j].concealed = count_mine(board, i, j); //count the number of mines left 
			}
		}
	}
	
	return;
}
/*
//adding one to each space around the mine on the board
//have to make sure we don't go out of bounds
char count_mine(Board board, int row, int col) {
	int count = 48;
	char count_num;
//have to check for all 8 surrounding squares of where the mine is placed
	if (in_bounds(board, row-1, col-1)) {
		if (checkmine(board, row-1, col-1)) {
			count += 1;
		}
	}
	if (in_bounds(board, row, col-1)) {
		if (checkmine(board, row, col-1)) {
			count += 1;
		}
	}
	if (in_bounds(board, row+1, col-1)) {
		if (checkmine(board, row+1, col-1)) {
			count += 1;
		}
	}
	if (in_bounds(board, row-1, col)) {
		if (checkmine(board, row-1, col)) {
			count += 1;
		}
	}
	if (in_bounds(board, row+1, col)) {
		if (checkmine(board, row+1, col)) {
			count += 1;
		}
	}
	if (in_bounds(board, row-1, col+1)) {
		if (checkmine(board, row-1, col+1)) {
			count += 1;
		}
	}
	if (in_bounds(board, row, col+1)) {
		if (checkmine(board, row, col+1)) {
			count += 1;
		}
	}
	if (in_bounds(board, row+1, col+1)) {
		if (checkmine(board, row+1, col+1)) {
			count += 1;
		}
	}

	count_num = count;
	return count_num;
}
*/
char count_mine(Board board, int row, int col) {
	int count = 48;
	char count_num;
//have to check for all 8 surrounding squares of where the mine is placed
	if (board -> tiles[row][col].ismine == 0{ 
		for (i=0;i<8;i++){
			switch(i){
				case 0:
					if (in_bounds(board, row-1, col-1)) {
						if (checkmine(board, row-1, col-1)) {
							count += 1;
						}
					}
					break;
				case 1:
					if (in_bounds(board, row, col-1)) {
						if (checkmine(board, row, col-1)) {
							count += 1;
						}
					}
					break;
				case 2:
					if (in_bounds(board, row+1, col-1)) {
						if (checkmine(board, row+1, col-1)) {
							count += 1;
						}
					}
					break;
				case 3:
			if (in_bounds(board, row-1, col)) {
				if (checkmine(board, row-1, col)) {
					count += 1;
				}
			}
					break;
				case 4:
			if (in_bounds(board, row+1, col)) {
				if (checkmine(board, row+1, col)) {
					count += 1;
				}
			}
					break;
				case 5:
			if (in_bounds(board, row-1, col+1)) {
				if (checkmine(board, row-1, col+1)) {
					count += 1;
				}
			}
					break;
				case 6:
			if (in_bounds(board, row, col+1)) {
				if (checkmine(board, row, col+1)) {
					count += 1;
				}
			}
					break;
				case 7:
			if (in_bounds(board, row+1, col+1)) {
				if (checkmine(board, row+1, col+1)) {
					count += 1;
				}
			}
					break;
		}
	}
}
	count_num = count;
	return count_num;
}

//function to check if inputted play is valid
int in_bounds(Board board, int row, int col) {
	if ((row < 0 || row > board.row - 1) 
		|| (col < 0 || col > board.col - 1)) {
		return 0; //not a valid play because it goes out of bounds of the board
	}
	return 1;
}

//function to check how many mines have been marked
int marked_mines(Board board) {
	int count = 0;
	int i, j;
	for(i = 0; i < board.row; i++){
		for(j = 0; j < board.col; j++){
			if (board.tile[i][j].revealed == '!') {
				count++;
			}
		}
	}
	return count;
}


//function to check if the space is a mine
int checkmine(Board board, int row, int col) {
	if (board.tile[row][col].concealed == '*') {
		return 1;
	}
	return 0;
}


//function to reveal zeroes on the board
//recursive function
void reveal_board(Board board, int row, int col, int number) {
	if (!in_bounds(board, row, col)){
		return;
	}
	else if (board.tile[row][col].revealed == '!') {
		return; //base case, if the spot is marked then return
	}
	else if (board.tile[row][col].revealed == '?') {
		return; //base case, if the spot is marked with a question mark then return
	}
	else if (board.tile[row][col].revealed != '#' && number == 1) {
		return; //if the number is a one, it is next to a mine
	}
	else if (board.tile[row][col].concealed == '*') {
		return; //if the spot is a mine 
	}
	else if (board.tile[row][col].revealed == '0' && number == 0) { //if it is a zero
		//can't go out of bounds
		//need to reveal all of the zeroes around it
		board.tile[row][col].revealed = board.tile[row][col].concealed;
		reveal_board(board, row-1, col-1, 1);  //have to call the function for each surrounding spot
		reveal_board(board, row, col-1, 1);
		reveal_board(board, row+1, col-1, 1);
		reveal_board(board, row-1, col, 1);
		reveal_board(board, row+1, col, 1);
		reveal_board(board, row-1, col+1, 1);
		reveal_board(board, row, col+1, 1);
		reveal_board(board, row+1, col+1, 1);
	}
	
	else if (board.tile[row][col].concealed == '0' && number == 1) { //call the function again with all surrounding spaces
		board.tile[row][col].revealed = board.tile[row][col].concealed;
		reveal_board(board, row-1, col-1, 1);
		reveal_board(board, row, col-1, 1);
		reveal_board(board, row+1, col-1, 1);
		reveal_board(board, row-1, col, 1);
		reveal_board(board, row+1, col, 1);
		reveal_board(board, row-1, col+1, 1);
		reveal_board(board, row, col+1, 1);
		reveal_board(board, row+1, col+1, 1);
	}
	else {
		board.tile[row][col].revealed = board.tile[row][col].concealed;
	}
	return;
}
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
