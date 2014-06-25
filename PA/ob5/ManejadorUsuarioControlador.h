#ifndef MANEJADORUSUARIOCONTROLADOR_H
#define MANEJADORUSUARIOCONTROLADOR_H
#include "UsuarioControlador.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class ManejadorUsuarioControlador {

private:
	static ManejadorUsuarioControlador * instance;
	ManejadorUsuarioControlador();
	map<int, UsuarioControlador*> usuarioControladores;
	int ultimoEnMapa;

public:
	~ManejadorUsuarioControlador();
	static ManejadorUsuarioControlador * getInstance();
	UsuarioControlador* obtenerControlerPorId(int);
	int getUltimoEnMapa();
	void agregarController(UsuarioControlador *);
};
#endif