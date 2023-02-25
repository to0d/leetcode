CPPFLAGS=-std=c++11 -I ../include -g
a.out: LT007501.o
	g++ -o $@ $^ 
..c.o:
	g++ -c $<

clean:
	rm -f *.o
	rm -f a.out