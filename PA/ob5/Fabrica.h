#ifndef FABRICA_H
#define FABRICA_H
#include "RecursoControlador.h"
#include "UsuarioControlador.h"
class Fabrica {
	
public:
	IUsuarioControlador* getUControlador();
	static Fabrica& getInstance();
	//IRecursoControlador getRControlador();
private:

	//Constructor

	Fabrica();
	//Destructor
	~Fabrica();
};
#endif
