CPPFLAGS=-I ../include/ctl -g
a.out: LT006201.o
	gcc -o $@ $^
..c.o:
	gcc -c $<
clean:
	rm -f *.o
	rm -f a.out