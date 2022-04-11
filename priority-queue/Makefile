CC=gcc
FLAGS=-Wall -g

all: priorityQueue

priorityQueue: main.c priorityQueue.c array.c
	$(CC) ${FLAGS} main.c priorityQueue.c array.c

run:
	./a.out

clean: 
	rm a.out main priorityQueue