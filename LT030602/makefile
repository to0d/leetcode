CFLAGS=-I ../include -g
a.out: LT030602.o
	gcc -o $@ $^
..c.o:
	gcc -c $<
clean:
	rm -f *.o
	rm -f a.out