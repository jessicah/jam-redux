
all: jam

jam: make.o jam.o rules.o path.o
	g++ -o $@ $+

%.o: %.cpp
	g++ -std=c++17 -c -o $@ $<

clean:
	rm -f jam *.o
