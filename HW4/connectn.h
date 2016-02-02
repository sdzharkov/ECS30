#ifndef CONNECTN_H
	#define CONNECTN_H

void read_args(int argc, char* argv[], int* num_rows, int* num_columns, int* plays_to_win);
char** create_board(int num_rows, int num_columns);
void destroy_board(char** board, int num_rows);
void print_board(char** board, int num_rows, int num_columns);
void get_play(int num_columns, int num_rows, char** board, int turn_count);
void play_game(char** board, int turn_count, int num_rows, int column_play);
bool play_is_valid(int num_rows, int num_columns, int column_play, char** board);
bool row_win(char** board, int num_rows, int num_columns, int plays_to_win);
bool col_win(char** board, int num_rows, int num_columns, int plays_to_win);
bool right_diag_win(char** board, int num_rows, int num_columns, int plays_to_win);
bool left_diag_win(char** board, int num_rows, int num_columns, int plays_to_win);
void execute_game(char** board, int num_rows, int num_columns, int plays_to_win, int turn_count);
bool game_won(char** board, int num_rows, int num_columns, int plays_to_win);
bool game_over(char** board, int num_rows, int num_columns);

#endif

