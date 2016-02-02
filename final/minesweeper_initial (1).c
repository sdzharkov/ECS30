#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//program to implement the game of minesweeper 

enum status{CONCEALED, REVEALED, QUESTIONED, MARKED, CANCEL};
enum status visibility = CONCEALED;

typedef struct tile_struct{
	status visibility;
	int is_mine;
	int surrounding_mines;
} tile;

typedef struct BOARD_STRUCT {
	int num_rows;
	int num_columns;
	int num_mines;
	tile** tiles; 
} BOARD;


void read_args(int argc, char** argv, int* num_rows, int* num_columns, int* num_mines, int* seed) {

	if (argc == 4) {
		num_rows = atoi(argv[1]);
		num_columns = atoi(argv[2]);
		num_mines = atoi(argv[3]);
		seed = srand(time(0));

		//srand((int)time(0));
	}
	else if (argc == 5) {
		num_rows = atoi(argv[1]);
		num_columns = atoi(argv[2]);
		num_mines = atoi(argv[3]);
		seed = srand(atoi(argv[4]));
	}
	else {
		printf("Not enough command line arguments.");
		exit(0);
	}
}


BOARD create_board(int num_rows, int num_columns, int num_mines) {
	BOARD board;
	board.num_rows = num_rows;
	board.num_columns = num_columns;
	board.num_mines = num_mines;
	int i, j, k, l;

	board.tiles = (tile**)malloc(num_rows * sizeof(tile*));
	for (i = 0; i < num_rows; i++) {
		board.tiles[i] = (tile*)malloc(num_columns * sizeof(tile));
	}
	for (i = 0; i < num_rows; i++) {
		for (j = 0; j < num_columns; j++) {
			board.tiles[i][j] == 0;
		}
	}

	int mine_row;
	int mine_col;
	int count = 0;
	while(count < num_mines){
		mine_row = rand()% board.num_rows;
		mine_col = rand()% board.num_columns;
		if(board.tile[mine_row][mine_col] != '*'){
			board.tile[][] = '*';
			count++;
		}
		else
			continue;
	}

	return board;
}

//function to print out the board
void print_board(BOARD board) {
	int i, j;
	int count = num_rows-1;
	for (i = board.num_rows - 1 ; i >= 0 ; i--) {
		printf("%d ", count);
		for (j = 0; j < board.num_columns; j++) {
			if (tiles[i][j].visibility == CONCEALED) {
			printf("# ");
			}
			else if (tiles[i][j].visibility == REVEALED) {
				printf("%d ", board.tiles[i][j]);
			}
			else if (tiles[i][j].visiblity == QUESTIONED) {
				printf("? ");
			}
			else if (tiles[i][j].visibility == MARKED) {
				printf("! ");
			}
		}
		printf("\n");
		count--;
	}
	printf(" ");
	j = 0;
	for (j = 0; j < num_columns; j++) {
		printf("%d", j);
	}
	printf("\n");

	return;
}

//function to free all the memory we used for the board
void destroy_board(BOARD board) {
	int i;
	for (i = 0; i < board.num_rows; i++) {
		free(board.tiles[i]);
	}
	free(board.tiles);
}

void get_play(BOARD board) {
	int enter_column;
	int enter_row;

	printf("Enter a row between 0-%d and a column between 0-%d: ", board.num_rows-1; board.num_columns-1);
	scanf("%d %d", &enter_row, &enter_column);

	while (!play_is_valid(board, enter_row, enter_column)) {
		printf("Enter a row between 0-%d and a column between 0-%d: ", board.num_rows-1; board.num_columns-1);
		scanf("%d %d", &enter_row, &enter_column);
	}
}


int reveal_board(BOARD board, int enter_row, int enter_column) {
	int i, j;
	if (enter_row < 0 || enter_row > board.num_rows - 1 || enter_column < 0 || enter_column > board.num_columns-1){
		return;
		}
	else if (board.tiles[i][j] == '!' || board.tiles[i][j] == '?'){
		return;
		}
	else {
		board.tiles[i][j] = CONCEALED;
		for (i = -1;i<=1;i++){
			for (j = -1; j<= 1; j++){
				reveal_board(board,enter_row + i, enter_column + j);
			}
		}
	}
}

int count_mines(BOARD* board,tile* tiles){
	int i,j,k,l;
	for (i=0;i<board.num_rows;i++){
		for (j=0;j<board.num_columns;j++){
			for (k=-1; k <=1; k++){
				for (l=-1; l<= 1: l++){
					if (i+k > 0 && i+k < board.num_rows){
						if (j+l > 0 && j +l <board.num_columns){
							if (j != 0 && k!=0){
								surrounding_mines ++;
							}
						}
					}
					printf("%d",surrounding_mines); // to test if numbers work?
				}
			}
		}
	}
}

int main(int argc, char** argv) {

	int num_rows, num_columns, num_mines, seed;
	read_args(argc, argv, &num_rows, &num_columns, &num_mines,&seed);
	BOARD board = create_board(num_rows, num_columns, num_mines);


	return 0;
}


/*
bool play_is_valid(BOARD board, int enter_row, int enter_column) {
	

if (enter_row > board.num_rows-1 || enter_row < 0) {
		return false;
	}
	else if (tiles)
}



int reveal_board(BOARD board, int enter_row, int enter_column) {
	int i, j;
	if (board.tile[enter_row][enter_column] == '*') {
		for (i = 0; i < board.num_rows, i++) {
			for (j = 0; j < board.num_columns, j++) {
				board.tile[i][j].visibility = REVEALED;
			}
		}
		return 1;
	}
	else if (board.tile[enter_row][enter_column] != 0) {
		board.tile[enter_row][enter_column].visibility = REVEALED;
		return 1;
	}
	else {
		if (enter_row == 0) {
			if (enter_column == 0) {
				board.tiles[0][1].visibility = REVEALED;
				board.tiles[1][0].visibility = REVEALED;
				board.tiles[1][1].visibility = REVEALED;
				if (board[0][1] == 0) {
					reveal_board(board, 0, 1);
				}
				if (board[1][0] == 0) {
					reveal_board(board, 1, 0);
				}
				if (board[1][1] == 0) {
					reveal_board(board, 1, 1);
				}
			}
			else if (enter_column == board.num_columns-1) {
				board.tiles[0][enter_column-1] = REVEALED;
				board.tiles[1][enter_column] = REVEALED;
				board.tiles[1][enter_column-1] = REVEALED;
				if (board[0][enter_column-1] == 0) {
					reveal_board(board, 0, enter_column-1);
				}
				if (board[1][enter_column] == 0) {
					reveal_board(board, 1, enter_column);
				}
				if (board[1][enter_column-1] == 0) {
					reveal_board(board, 1, enter_column-1);
				}
			}
			else {
				board.tiles[0][enter_column-1] = REVEALED;
				board.tiles[0][enter_column+1] = REVEALED;
				board.tiles[1][enter_column] = REVEALED;
				board.tiles[1][enter_column-1] = REVEALED;
				board.tiles[1][enter_column+1] = REVEALED;
				if (board.tiles[0][enter_column-1] == 0) {
					reveal_board(board, 0, enter_column-1);
				}
				if (board.tiles[0][enter_column+1] == 0) {
					reveal_board(board, 0, enter_column+1);
				}
				if (board.tiles[1][enter_column] == 0) {
					reveal_board(board, 1, enter_column);
				}
				if (board.tiles[1][enter_column-1] == 0) {
					reveal_board(board, 1, enter_column-1);
				}
				if (board[1][enter_column+1] == 0) {
					reveal_board(board, 1, enter_column+1);
				}
			}

		}
		else if (enter_row == board.num_rows-1) {
			if (enter_column == 0) {
				board.tiles[enter_row][1] = REVEALED;
				board.tiles[enter_row-1][0] = REVEALED;
				board.tiles[enter_row-1][1] = REVEALED;
				if (board.tiles[enter_row][1] == 0) {
					reveal_board(board, enter_row, 1);
				}
				if (board.tiles[enter_row-1][0] == 0) {
					reveal_board(board, enter_row-1, 0);
				}
				if (board.tiles[enter_row-1][1] == 0) {
					reveal_board(board, enter_row-1, 1);
				}
			}
			else if (enter_column == board.num_columns-1) {
				board.tiles[enter_row][enter_column-1] = REVEALED;
				board.tiles[enter_row-1][enter_column-1] = REVEALED;
				board.tiles[enter_row-1][enter_column] = REVEALED;
				if (board.tiles[enter_row][enter_column-1] == 0) {
					reveal_board(board, enter_row, enter_column-1);
				}
				if (board.tiles[enter_row-1][enter_column-1] == 0) {
					reveal_board(board, enter_row-1, enter_column-1);
				}
				if (board.tiles[enter_row-1][enter_column] == 0) {
					reveal_board(board, enter_row-1, enter_column);
				}
			}
			else {
				board.tiles[enter_row][enter_column-1] = REVEALED;
				board.tiles[enter_row][enter_column+1] = REVEALED;
				board.tiles[enter_row-1][enter_column] = REVEALED;
				board.tiles[enter_row-1][enter_column-1] = REVEALED;
				board.tiles[enter_row-1][enter_column+1] = REVEALED;
				if (board.tiles[enter_row][enter_column-1] == 0) {
					reveal_board(board, enter_row, enter_column-1);
				}
				if (board.tiles[enter_row][enter_column+1] == 0) {
					reveal_board(board, enter_row, enter_column+1);
				}
				if (board.tiles[enter_row-1][enter_column] == 0) {
					reveal_board(board, enter_row-1, enter_column);
				}
				if (board.tiles[enter_row-1][enter_column-1] == 0) {
					reveal_board(board, enter_row-1, enter_column-1);
				}
				if (board.tiles[enter_row-1][enter_column+1] == 0) {
					reveal_board(board, enter_row-1, enter_column+1);
				}
			}
		}
		else if (enter_column == 0 && (enter_row > 0 && enter_row < num_rows-1)) {
			board.tiles[enter_row-1][0] = REVEALED;
			board.tiles[enter_row+1][0] = REVEALED;
			board.tiles[enter_row-1][1] = REVEALED;
			board.tiles[enter_row][1] = REVEALED;
			board.tiles[enter_row+1][1] = REVEALED;
			if (board.tiles[enter_row-1][0] == 0) {
				reveal_board(board, enter_row-1, 0);
			}
			if (board.tiles[enter_row+1][0] == 0) {
				reveal_board(board, enter_row+1, 0);
			}
			if (board.tiles[enter_row-1][1] == 0) {
				reveal_board(board, enter_row-1, 1);
			}
			if (board.tiles[enter_row][1] == 0) {
				reveal_board(board, enter_row, 1);
			}
			if (board.tiles[enter_row+1][1] == 0) {
				reveal_board(board, enter_row+1, 1);
			}
		}
		else if (enter_column == board.num_columns-1 && (enter_row > 0 && enter_row < num_rows-1)) {
			board.tiles[enter_row-1][enter_column] = REVEALED;
			board.tiles[enter_row+1][enter_column] = REVEALED;
			board.tiles[enter_row-1][enter_column-1] = REVEALED;
			board.tiles[enter_row][enter_column-1] = REVEALED;
			board.tiles[enter_row+1][enter_column-1] = REVEALED;
			if (board.tiles[enter_row-1][enter_column] == 0) {
				reveal_board(board, enter_row-1, enter_column);
			}
			if (board.tiles[enter_row+1][enter_column] == 0) {
				reveal_board(board, enter_row+1, enter_column);
			}
			if (board.tiles[enter_row-1][enter_column-1] == 0) {
				reveal_board(board, enter_row-1, enter_column-1);
			}
			if (board.tiles[enter_row][enter_column-1] == 0) {
				reveal_board(board, enter_row, enter_column-1);
			}
			if (board.tiles[enter_row+1][enter_column-1] == 0) {
				reveal_board(board, enter_row+1; enter_column-1);
			}
		}
		else {
			board.tiles[enter_row][enter_column-1] = REVEALED;
			board.tiles[enter_row][enter_column+1] = REVEALED;
			board.tiles[enter_row-1][enter_column-1] = REVEALED;
			board.tiles[enter_row-1][enter_column] = REVEALED;
			board.tiles[enter_row-1][enter_column+1] = REVEALED;
			board.tiles[enter_row+1][enter_column-1] = REVEALED;
			board.tiles[enter_row+1][enter_column] = REVEALED;
			board.tiles[enter_row+1][enter_column+1] = REVEALED;
			if (board.tiles[enter_row][enter_column-1] == 0) {
				reveal_board(board, enter_row, enter_column-1);
			}
			if (board.tiles[enter_row][enter_column+1] == 0) {
				reveal_board(board, enter_row, enter_column+1);
			}
			if (board.tiles[enter_row-1][enter_column-1] == 0) {
				reveal_board(board, enter_row-1, enter_column-1);
			}
			if (board.tiles[enter_row-1][enter_column] == 0) {
				reveal_board(board, enter_row-1, enter_column);
			}
			if (board.tiles[enter_row-1][enter_column+1] == 0) {
				reveal_board(board, enter_row+1, enter_column-1);
			}
			if (board.tiles[enter_row+1][enter_column-1] == 0) {
				reveal_board(board, enter_row+1, enter_column-1);
			}
			if (board.tiles[enter_row+1][enter_column] == 0) {
				reveal_board(board, enter_row+1, enter_column);
			}
			if (board.tiles[enter_row+1][enter_column+1] == 0) {
				reveal_board(board, enter_row+1, enter_column+1);
			}
		}
	}
}
*/
