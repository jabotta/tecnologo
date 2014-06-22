main:	main.o DateTime.o Comparable.o Usuario.o UsuarioControlador.o
	g++ main.o DateTime.o Comparable.o Usuario.o UsuarioControlador.o -o main
	
main.o:	main.cpp 
	g++ -c main.cpp -I.

Comparable.o:	Comparable.cpp	Comparable.h
	g++ -c Comparable.cpp -I.

DateTime.o:	DateTime.cpp	DateTime.h
	g++ -c DateTime.cpp -I.

DataUsuario.o:	DataUsuario.cpp	DataUsuario.h
	g++ -c DataUsuario.cpp -I.

DataInformacionUsuario.o: DataInformacionUsuario.cpp DataInformacionUsuario.h
	g++ -c DataInformacionUsuario.cpp -I.

Usuario.o:	Usuario.cpp	Usuario.h
	g++ -c Usuario.cpp -I.

UsuarioControlador.o:	UsuarioControlador.cpp	UsuarioControlador.h
	g++ -c UsuarioControlador.cpp -I.

limpiar:
	rm *.o