main:	  DateTime.o Comparable.o DataUsuario.o DataInformacionUsuario.o Usuario.o UsuarioControlador.o ManejadorUsuario.o Fabrica.o main.o
	g++   DateTime.o Comparable.o DataUsuario.o DataInformacionUsuario.o Usuario.o UsuarioControlador.o ManejadorUsuario.o Fabrica.o main.o -o main

DateTime.o:	DateTime.cpp	DateTime.h
	g++ -c DateTime.cpp -I.

DataUsuario.o:	DataUsuario.cpp	DataUsuario.h
	g++ -c DataUsuario.cpp -I.


main.o:	main.cpp 
	g++ -c main.cpp -I.

Fabrica.o: Fabrica.cpp Fabrica.h
	g++ -c Fabrica.cpp -I.

Comparable.o:	Comparable.cpp	Comparable.h
	g++ -c Comparable.cpp -I.


DataInformacionUsuario.o: DataInformacionUsuario.cpp DataInformacionUsuario.h
	g++ -c DataInformacionUsuario.cpp -I.

Usuario.o:	Usuario.cpp	Usuario.h
	g++ -c Usuario.cpp -I.

UsuarioControlador.o:	UsuarioControlador.cpp	UsuarioControlador.h
	g++ -c UsuarioControlador.cpp -I.

ManejadorUsuario.o: ManejadorUsuario.cpp ManejadorUsuario.h
	g++ -c ManejadorUsuario.cpp -I.
limpiar:
	rm *.o