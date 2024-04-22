CC = g++

all: hw08

hw08: hw08.h
	$(CC) hw08.cpp -o hw08 

clean:
	rm -f hw08