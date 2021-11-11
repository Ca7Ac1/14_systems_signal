all: signal.o
	gcc -o main signal.o

signal.o: signal.c
	gcc -c signal.c

run:
	./main