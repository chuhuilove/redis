

CC=gcc

CFLAGS = -Wall -g

all: chararr intarr





chararr: charpointarr.c genarr.o
	$(CC) $(CFLAGS) charpointarr.c genarr.o -o chararr

intarr: intarrpoint.c genarr.o
	$(CC) $(CFLAGS) intarrpoint.c genarr.o -o intarr



genarr.o: genarr.c
	$(CC) $(CFLAGS) -c genarr.c


clean:
	rm -rf *.o chartarr intarr

