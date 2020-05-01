EXECUTABLES=paging
CC=gcc
CFLAGS=-g

all: $(EXECUTABLES)

paging:
	$(CC) $(CFLAGS) -c paging.c
	$(CC) $(CFLAGS) -o $@ paging.o

clean:
	rm -f $(EXECUTABLES) paging.o 
