C=gcc
SRC=src
INC=inc
BIN=bin
OBJ=obj
CFLAGS= -c -g -Wall

day10-3c:$(BIN)/day10-3c

$(BIN)/day10-3c:$(OBJ)/day10-3c.o
	        $(CC) -o $(BIN)/day12 $(OBJ)/day10-3c.o

$(OBJ)/day10-3c.o:$(SRC)/day10-3c
	        $(CC) $(CFLAGS) $(SRC)/day12.c -I $(INC)/


clean:
	        rm -f a.out *.o
		rm -f $(OBJ)/*
		rm -f $(BIN)/*
		@echo "Cleaning done!"
