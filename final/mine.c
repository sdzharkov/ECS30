#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//program to implement the game of minesweeper 

enum status {CONCEALED, REVEALED, QUESTIONED, MARKED, CANCEL};

typedef struct tile_struct{
	enum status visibility;
	int is_mine;
	int surrounding_mines;
} tile;

typedef struct BOARD_STRUCT {
	int num_rows;
	int num_columns;
	int num_mines;
	tile** tiles; 
} BOARD;


void read_args(int argc, char** argv, int* num_rows, int* num_columns, int* num_mines) {

	if (argc == 4) {
		*num_rows = atoi(argv[1]);
		*num_columns = atoi(argv[2]);
		*num_mines = atoi(argv[3]);
		srand(time(0));

		//srand((int)time(0));
	}
	else if (argc == 5) {
		*num_rows = atoi(argv[1]);
		*num_columns = atoi(argv[2]);
		*num_mines = atoi(argv[3]);
		srand(atoi(argv[4]));
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
	int i, j;

	board.tiles = (tile**)malloc(num_rows * sizeof(tile*));
	for (i = 0; i < num_rows; i++) {
		board.tiles[i] = (tile*)malloc(num_columns * sizeof(tile));
	}
	for (i = 0; i < num_rows; i++) {
		for (j = 0; j < num_columns; j++) {
			board.tiles[i][j].visibility = REVEALED;
			board.tiles[i][j].is_mine=0;
			board.tiles[i][j].surrounding_mines=0;
		}
	}

	int mine_row;
	int mine_col;
	int count = 0;
	while(count < num_mines){
		mine_row = rand()% board.num_rows;
		mine_col = rand()% board.num_columns; // vig told me to do that big error
		if(board.tiles[board.num_rows - mine_row - 1][mine_col].is_mine != 1){
			board.tiles[board.num_rows - mine_row - 1][mine_col].is_mine = 1;
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
  /* This would also print the board ll
  for (i=0;i<board.num_rows; i++){
	printf("%d ",board.num_rows-1-i);
	for (j=0;j<board.num_columns; j++){
		printf("%c ",board.tiles[i][j]);
	}
	printf("\n");
	}
	printf("  ");
	for (i=0;i<board.num_columns; i++){
		printf("%d ",i);
	}
	}
  */
  for (i = 0 ; i<board.num_rows ; i++) 
    {
      //printf("%d ", count);
      for (j = 0; j < board.num_columns; j++) 
	{
	  if (board.tiles[i][j].is_mine)
	    {
	      printf("M ");
	    }
	  else if (board.tiles[i][j].visibility == CONCEALED) 
	    {
	      printf("# ");
	    }
	  else if (board.tiles[i][j].visibility == REVEALED) 
	    {
	      printf("%d ", board.tiles[i][j].surrounding_mines);
	    }
	  else if (board.tiles[i][j].visibility == QUESTIONED) 
	    {
	      printf("? ");
	    }

	  else if (board.tiles[i][j].visibility == MARKED) 
	    {
	      printf("! ");
	    }
	 
	}
      printf("\n");
    }
 }   



//function to free all the memory we used for the board
void destroy_board(BOARD board) {
	int i;
	for (i = 0; i < board.num_rows; i++) {
		free(board.tiles[i]);
	}
	free(board.tiles);
}

int play_is_valid(BOARD board, int check_row, int check_col)
{
  return(1);
}

void get_play(BOARD board) {
	int enter_column;
	int enter_row;

	printf("Enter a row between 0-%d and a column between 0-%d: ", board.num_rows-1, board.num_columns-1);
	scanf("%d %d", &enter_row, &enter_column);

	while (!play_is_valid(board, enter_row, enter_column)) {
	  printf("Enter a row between 0-%d and a column between 0-%d: ", board.num_rows-1, board.num_columns-1);
		scanf("%d %d", &enter_row, &enter_column);
	}
}


// SGQ - I don't know what this function is intended to do -- why use recursion???
// this was my attempt at recursion, but I have no clue how to make it work
void reveal_board(BOARD board, int enter_row, int enter_column) {
	int i, j;

	if (enter_row < 0 || enter_row > board.num_rows - 1 || enter_column < 0 || enter_column > board.num_columns-1){
		return;
		}
	else if (board.tiles[i][j].visibility == QUESTIONED || board.tiles[i][j].visibility == MARKED){
		return;
		}
	else {
		board.tiles[i][j].visibility = CONCEALED;
		for (i = -1;i<=1;i++){
			for (j = -1; j<= 1; j++){
				reveal_board(board,enter_row + i, enter_column + j);
			}
		}
	}
}

int count_surrounding(BOARD *board, int row, int col)
{
  int res=0;
  int i;

  if (board->tiles[row][col].is_mine==0)  // don't count if current tile is a mine
    {
      // we have 4 neighbors we have to visit to count....but don't leave boundaries of board
      for (i=0;i<5;i++)
	{
	  switch(i)
	    {
	    case 0:  // up
	      if (row>0)
		{
		  if (board->tiles[row-1][col].is_mine)
		    res++;
		}
	      break;
	    case 1:  // down
	      if (row+1<board->num_rows)
		{
		  if (board->tiles[row+1][col].is_mine)
		    res++;
		}
	      break;
	    case 2:  // left
	      if (col>0)
		{
		  if (board->tiles[row][col-1].is_mine)
		    res++;
		}
	      break;
	    case 3:  // right
	      if (col+1<board->num_columns)
		{
		  if (board->tiles[row][col+1].is_mine)
		    res++;
		}
	      break;
	     case 4: // trying to get top left 
	    if (row>0){
	   
	   if (col>0){
	    
		  if (board->tiles[row-1][col-1].is_mine){
		    res++;
		    printf("hello");
		   }
		   }
		   }
				break;
	     case 5: //trying to get top right
	     
	    if (row>0){
	   
	    if (col>0){
	    
		  if (board->tiles[row-1][col+1].is_mine){
		    res++;
		   }
		   }
		   }
		   break;
}
}
}
  return(res);
}
/*  attempt at a count mines function 
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
*/

int count_mines_on_board(BOARD* board)
{
  int i,j;
  for (i=0;i<board->num_rows;i++)
    {
      for (j=0;j<board->num_columns;j++)
	{
	  board->tiles[i][j].surrounding_mines=count_surrounding(board,i,j);
	}
    }
}

int main(int argc, char** argv) {

	int num_rows, num_columns, num_mines;
	read_args(argc, argv, &num_rows, &num_columns, &num_mines);
	printf("num_rows=%d cols=%d mines=%d\n",num_rows,num_columns,num_mines);
	BOARD board = create_board(num_rows, num_columns, num_mines);
	count_mines_on_board(&board);
	print_board(board);
	return 0;
}
