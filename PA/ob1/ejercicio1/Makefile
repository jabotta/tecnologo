main:	main.o	DateTime.o
	g++ main.o DateTime.o -o main
	
main.o:	main.cpp
	g++ -c main.cpp -I.

Comparable.o:	Comparable.cpp	Comparable.h
	g++ -c Comparable.cpp -I.

DateTime.o:	DateTime.cpp	DateTime.h
	g++ -c DateTime.cpp -I.
	
limpiar:
	rm *.o
	