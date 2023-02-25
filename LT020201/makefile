CPPFLAGS=-std=c++0x -I ../include -g
a.out: LT020201.o
	g++ -o $@ $^  -std=c++11
..c.o:
	g++ -c $<

clean:
	rm -f *.o
	rm -f a.out