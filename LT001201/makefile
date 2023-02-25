CFLAGS=-I ../include -g
a.out: LT001201.o
	gcc -o $@ $^
..c.o:
	gcc -c $<
clean:
	rm -f *.o
	rm -f a.out