all: main.o
	gcc -o program main.c
main.o: main.c
	gcc -c -g main.c
run:
	./program
clean:
	rm ~.o
	rm ~*
