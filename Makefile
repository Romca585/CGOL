

all: cgol dynCGOL

cgol: cgol.o reduceSpace.o
	gcc -ansi -Wall -o cgol cgol.o reduceSpace.o

dynCGOL: dynCGOL.o reduceSpace.o
	gcc -ansi -Wall -o dynCGOL dynCGOL.o reduceSpace.o

cgol.o: cgol.c
	gcc -ansi -Wall -c cgol.c

dynCGOL.o: dynCGOL.c
	gcc -ansi -Wall -c dynCGOL.c

reduceSpace.o: reduceSpace.c
	gcc -ansi -Wall -c reduceSpace.c

clean:
	rm reduceSpace.o cgol.o dynCGOL.o cgol dynCGOL
