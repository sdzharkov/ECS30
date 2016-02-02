#ifndef PLAY_H
	#define PLAY_H

//function definitions required to play the game

	int generate_seed(char** argv);
	void put_concealed(Board board);
	char count_mine(Board board, int row, int col);
	int checkmine(Board board, int row, int col);
	int check_valid(Board board, int row, int col);
	void play_is_valid(Board board);
	void play_game(Board board);
	void get_play(Board board);
	int option_1(Board board, int row, int col);
	int option_2(Board board, int row, int col);
	int option_3(Board board, int row, int col);
	int isgameover(Board board);
	void mine_location_generator(Board board);
	int check_win(Board board);
	int marked_mines(Board board);
	void reveal_board(Board board, int row, int col, int number);

#endif