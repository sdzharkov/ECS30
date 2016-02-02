mine_sweeper.out: main.o play.o board.o
	gcc -Wall -g -o mine_sweeper.out board.o main.o play.o
	
main.o: play.h board.h main.c
	gcc -Wall -g -c -o main.o main.c
	
play.o: play.h board.h play.c
	gcc -Wall -g -c -o play.o play.c

board.o: board.h board.c
	gcc -Wall -g -c -o board.o board.c
	
clean:
	rm *.o *.out
