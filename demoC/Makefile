

CC=gcc

CFLAGS = -Wall -g

all: chararr intarr inttwoarr





chararr: charpointarr.c genarr.o
	$(CC) $(CFLAGS) charpointarr.c genarr.o -o chararr

intarr: intarrpoint.c genarr.o
	$(CC) $(CFLAGS) intarrpoint.c genarr.o -o intarr

inttwoarr: inttwoarrpoint.c genarr.o
    $(CC) $(CFLAGS) inttwoarrpoint.c genarr.o -o inttwoarr

genarr.o: genarr.c
	$(CC) $(CFLAGS) -c genarr.c



clean:
	rm -rf *.o chartarr intarr inttwoarr

