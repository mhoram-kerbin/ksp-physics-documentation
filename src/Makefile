all: main

clean:
	rm -f *.o kapri

vector.o: vector.cc vector.hh
	g++ -Wall -pedantic -c vector.cc

planet.o: planet.cc planet.hh vector.o
	g++ -Wall -pedantic -c planet.cc

engine.o: engine.cc engine.hh
	g++ -Wall -pedantic -c engine.cc

main: planet.o engine.o main.cc
	g++ -Wall -pedantic -o kapri planet.o engine.o vector.o main.cc
