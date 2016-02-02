#include <stdio.h>
#include <stdlib.h>

enum Visibility {REVEALED, CONCEALED, MARKED, QUESTIONED};


typedef struct board_struct{
	int row;
	int col;
	int num_mines;
	Tiles** tile;
} Board;

typedef struct tiles_struct{
	Visibility visibility;
	int is_mine;
	int num_surrounding_mines;
} Tile;

void print_board(board** board()){
}
Board create_board(int rows, int cols, int num_mines){
	int i;
	Board board;
	board.rows = rows;
	board.cols = cols
	board.num_mines = num_mines;
	board.tiles = (Tile**)malloc(rows*sizeof(Tile*));
	for (i=0;i<rows; i++){
		board.tiles[i] = (Tile*)malloc(rows*sizeof(Tile));
	}
	
}
void read_args(int argc, char** argv){
	board* boardptr = NULL;
	boardptr = (board*)malloc(sizeof(board));
	if (argc == 4 || argc == 5){
		boardptr -> row = atoi(argv[1]);
		boardptr -> col = atoi(argv[2]);
		boardptr -> num_mines = atoi(argv[3]);
	}
	Tile** tileptr = (Tile**)malloc(row*sizeof(Tile*);
	for (i=0; i< board -> row; i++){
		tileptr[i] = (Tile*)malloc(col *sizeof(Tile));
		}
	if (argc == 5){
		srand(atoi(argv[4]));
	}
	else {
		srand(seed);
	}
}

int main(int argc, char** argv){


	return 0;
}
