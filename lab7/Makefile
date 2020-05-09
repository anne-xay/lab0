CC=gcc
CFLAGS=-g
SRC=matrix_gen.c
OBJ=matrix_gen.o
SRCT=matrix_add.c
OBJT=matrix_add.o
all:
		$(CC) $(CFLAGS) -c $(SRC)
		$(CC) $(CFLAGS) -o matrix_gen $(OBJ)
		$(CC) $(CFLAGS) -c $(SRCT)
		$(CC) $(CFLAGS) -o matrix_add $(OBJT)
matrix_gen:
		$(CC) $(CFLAGS) -c $(SRC)
		$(CC) $(CFLAGS) -o matrix_gen $(OBJ)
matrix_add:
		$(CC) $(CFLAGS) -c $(SRCT)
		$(CC) $(CFLAGS) -o matrix_add $(OBJT)
clean:
		rm -f matrix_gen matrix_add $(OBJT) $(SRCT) $(OBJT) $(SRCT)
