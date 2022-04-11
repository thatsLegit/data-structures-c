CC=gcc
FLAGS=-Wall -g

all: BST

BST: main.c BST.c array.c queue.c
	$(CC) ${FLAGS} main.c BST.c array.c queue.c

run:
	./a.out

clean: 
	rm a.out main array BST queue