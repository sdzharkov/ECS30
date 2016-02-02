#include <stdio.h>
#include <stdlib.h>



//function to read in the command line arguments
void read_args(int argc, char* argv[], int* num_rows, int* num_columns, int* plays_to_win) {

	if (argc < 4) {
		printf("1. Too few arguments entered \n2. Usage ./connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0);
	}
	else if (argc > 4) {
		printf("1. Too many arguments entered \n2. Usage ./connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0);
	}
	else {
		*num_rows = atoi(argv[1]);
		*num_columns = atoi(argv[2]);
		*plays_to_win = atoi(argv[3]);

	}

	return; 
}

//function to dynamically allocate space for the board based on user defined sizes
char** create_board(int num_rows, int num_columns) {
	int i= 0
	char** board = (int**)malloc(num_rows * sizeof(int*));
	for (i= 0; i < num_rows; i++) {
		board[i] = (int*)malloc(num_columns * sizeof(int));
	}


	return board;
}

//function to free all the space allocated for the board if the game is over
void destroy_board(char** board, int num_rows) {
	int i;
	for (i = 0; i < num_rows; i++) {
		free(board[i]);
	}
	free(board);

	return;
}

//function to print the board for the user to see after every turn
void print_board(char** board, int num_rows, int num_columns) {
	int i, j;
	for (i = 0; i < num_rows, i++){
		printf("%d ", num_rows-i);
		for (j = 0; j < num_columns; j++) {
			printf("* ");
		}
		printf("\n");
	}
	printf(" ");
	j = 0;
	for (j = 0; j < num_columns; j++) {
		printf("%d ", j);
	}

	return;
}

//function to ask the user what column they would like to play in
void get_play(int num_columns, int* column_play) {

	printf("Enter a column between 0 and %d to play in: ", num_columns);
	scanf("%d", column_play);

	while (!(play_is_valid(column_play))) {
		printf("Enter a column between 0 and %d to play in: ", num_columns);
		scanf("%d", column_play);
	}

	return;
}

void play_is_valid(int num_columns, int* column_play) {
	if (*column_play > ) //FIXME1!!!!!!!!!!!!!!!
}


int main(int argc, char* argv[]){
	int num_rows = 0;
	int num_columns = 0;
	int plays_to_win = 0;
	int column_play = 0;

	read_args(argc, char* argv[], &num_rows, &num_columns, &plays_to_win);
	char** board = create_board(num_rows, num_columns);
	print_board(board, num_rows, num_columns);
	get_play(num_columns, &column_play);
	
	

	return 0;
}
