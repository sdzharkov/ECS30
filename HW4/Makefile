connectn.out: connectn.o main.o
	gcc -Wall -g -o connectn.out connectn.o main.o

main.o: main.c connectn.h	
	gcc -Wall -g -c -o main.o main.c

connectn.o: connectn.c connectn.h
	gcc -g -Wall -c -o connectn.o connectn.c

clean:
	rm *.o *.out