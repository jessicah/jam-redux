
jam_objects = make.o jam.o rules.o path.o variable.o intern.o search.o timestamp.o file.o

parser_objects = $(addprefix grammar/,JamParser.o JamTokenizer.o Location.o RawStream.o)

all: jam

jam: $(jam_objects) $(parser_objects)
	g++ -o $@ $+

%.o: %.cpp
	g++ -std=c++17 -fpermissive -c -o $@ $<

clean:
	rm -f jam *.o
