#ifndef FABRICA_H
#define FABRICA_H
#include "RecursoControlador.h"
#include "UsuarioControlador.h"
#include "ManejadorUsuarioControlador.h"
class Fabrica {
	
private:
	static Fabrica * instance;	
	Fabrica();	
	ManejadorUsuarioControlador mucontroller;
public:
	static Fabrica * getInstance();
	IUsuarioControlador * getUControlador(int id);
	//IRecursoControlador getRControlador();

	//Destructor
	~Fabrica();
};
#endif
