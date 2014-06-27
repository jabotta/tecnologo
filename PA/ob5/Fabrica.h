#ifndef FABRICA_H
#define FABRICA_H
#include "RecursoControlador.h"
#include "UsuarioControlador.h"
#include "ManejadorUsuarioControlador.h"
#include "ManejadorRecursoControlador.h"

class Fabrica {	
	private:
		static Fabrica * instance;	
		Fabrica();	
		ManejadorUsuarioControlador* mucontroller;
		ManejadorRecursoControlador* mrcontroller;
		
	public:
		static Fabrica * getInstance();
		IUsuarioControlador * getUControlador(int id);
		IRecursoControlador * getRControlador(int id);

		//Destructor
		~Fabrica();
};
#endif
