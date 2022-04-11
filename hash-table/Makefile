CC=gcc
FLAGS=-Wall -g -save-temps

all: hashTable

hashTable: main.c hashTable.c array.c
	$(CC) $(FLAGS) main.c hashTable.c array.c

run:
	./a.out

clean: 
	rm a.out main array hashTable