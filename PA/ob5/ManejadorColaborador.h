#ifndef MANEJADORCOLABORADOR_H
#define MANEJADORCOLABORADOR_H
#include <map>
#include <list>
#include <string>
#include "Colaborador.h"

using namespace std;

class ManejadorColaborador {
private:
	static ManejadorColaborador * instance;
	list<Colaborador*> colaboradores;
	ManejadorColaborador();
	
public:
	static ManejadorColaborador * getInstance();
	~ManejadorColaborador();

	void agregarALista(Colaborador*);
	list<Colaborador*> listarColaboradores();


};
#endif