FLAGS = -Wall -g 
CC = gcc

all: sort.c string.c

isort: sort.c
	$(CC) $(FLAGS) sort.c -o isort


txtfind: string.c 
	$(CC) $(FLAGS) string.c -o txtfind 
	
.PHONY: clean all txtfind isort 

clean:
	rm txtfind isort 