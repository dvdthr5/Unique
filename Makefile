HEADERS= tree.h
all: unique unittests
unique: unique.o tree.o
	clang unique.o tree.o -o unique

unittests: unittests.o tree.o
	clang unittests.o tree.o -o unittests

unique.o: unique.c $(HEADERS)
	clang -c -g unique.c

tree.o: tree.c $(HEADERS)
	clang -c -g tree.c

unittests.o: unittests.c
	clang -c -g unittests.c

clean:
	rm -f *.o unique
