CC=gcc
CFLAGS=-g
SRC=spiritd.c
OBJ=spiritd.o
SRCT=mole.c
OBJT=mole.o
all:
		$(CC) $(CFLAGS) -c $(SRC)
		$(CC) $(CFLAGS) -o spiritd $(OBJ)
		$(CC) $(CFLAGS) -c $(SRCT)
		$(CC) $(CFLAGS) -o mole $(OBJT)
spiritd:
		$(CC) $(CFLAGS) -c $(SRC)
		$(CC) $(CFLAGS) -o spiritd $(OBJ)
mole:
		$(CC) $(CFLAGS) -c $(SRCT)
		$(CC) $(CFLAGS) -o mole $(OBJT)
clean:
		rm -f spiritd mole $(OBJT) $(SRCT) $(OBJT) $(SRCT)
