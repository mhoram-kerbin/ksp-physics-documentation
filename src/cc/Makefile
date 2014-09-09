all: main

clean:
	rm -f *.o kapri

Vector.o: Vector.cc Vector.hh
	g++ -Wall -pedantic -c Vector.cc

Planet.o: Planet.cc Planet.hh Vector.o
	g++ -Wall -pedantic -c Planet.cc

Engine.o: Engine.cc Engine.hh
	g++ -Wall -pedantic -c Engine.cc

Cartesian.o: Cartesian.cc Cartesian.hh Orbit.hh
	g++ -Wall -pedantic -c Cartesian.cc

main: Planet.o Engine.o main.cc Cartesian.o
	g++ -Wall -pedantic -o kapri Cartesian.o Engine.o Planet.o Vector.o main.cc
