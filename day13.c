CC=gcc
SRC=src
INC=inc
BIN=bin
OBJ=obj
CFLAGS= -c -g-Wall
day13:$(BIN)/day13

$(BIN)/day13:$(OBJ)/day13.o
	$(CC) -o $(BIn)/day13 $(OBJ)/day13.o

$(OBJ)/day13.o:$(SRC)/day13.c
	$(CC) $(CFLAGS) $(SRC)/day13.c -I $(INC)/

clean:
	rm -f a.out *.o
	rm -f $(OBJ)/*
	rm -f $(BIN)/*
	@echo "Cleaning Complete!"
