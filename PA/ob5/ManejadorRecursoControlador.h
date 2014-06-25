#ifndef MANEJADORRECURSOCONTROLADOR_H
#define MANEJADORRECURSOCONTROLADOR_H
#include "RecursoControlador.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class ManejadorRecursoControlador {

private:
	static ManejadorRecursoControlador * instance;
	ManejadorRecursoControlador();
	map<int, RecursoControlador*> recursoControladores;
	int ultimoEnMapa;

public:
	~ManejadorRecursoControlador();
	static ManejadorRecursoControlador * getInstance();
	RecursoControlador* obtenerControlerPorId(int);
	int getUltimoEnMapa();
	void agregarController(RecursoControlador *);
};
#endif