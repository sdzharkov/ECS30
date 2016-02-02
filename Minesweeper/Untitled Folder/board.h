#ifndef BOARD_H
	#define BOARD_H

typedef struct tiles_Struct{ //struct for the tiles on the board
	char revealed;
	char concealed;
	char marked;
} tiles;

typedef struct Board_Struct{ //struct for the board 
	int row;
	int col;
	int mine;
	int seed;
	tiles** tile;
} Board;

	tiles** create_board(Board board); //function that creates and returns the board
	void print_board(Board board);
	void destroy_board(Board board);
	void read_args(int argc, char** argv, int* row, int* column, int* mine);

#endif
