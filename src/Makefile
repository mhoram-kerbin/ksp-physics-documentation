all: main

clean:
	rm -f *.o kapri

vector.o: vector.cc vector.hh
	g++ -Wall -pedantic -c vector.cc

planet.o: planet.cc planet.hh vector.o
	g++ -Wall -pedantic -c planet.cc

main: planet.o main.cc
	g++ -Wall -pedantic -o kapri planet.o vector.o main.cc
