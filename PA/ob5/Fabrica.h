#ifndef FABRICA_H
#define FABRICA_H
#include "RecursoControlador.h"
#include "UsuarioControlador.h"
class Fabrica {
	
private:
	static Fabrica * instance;	
	Fabrica();	

public:
	static Fabrica * getInstance();
	IUsuarioControlador * getUControlador();
	//IRecursoControlador getRControlador();

	//Destructor
	~Fabrica();
};
#endif
