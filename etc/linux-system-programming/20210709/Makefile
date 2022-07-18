all: wv rv

wv: writev.o
	gcc -o wv writev.o

rv: readv.o
	gcc -o rv readv.o

writev.o:
	gcc -g -Wall -c writev.c

readv.o:
	gcc -g -Wall -c readv.c

clean:
	rm -f *.o wv rv buccaneer.txt