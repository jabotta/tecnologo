#include "Fabrica.h"

Fabrica * Fabrica::instance = NULL;

Fabrica::Fabrica(){

}

Fabrica * Fabrica::getInstance(){
	if (Fabrica::instance == NULL){
		Fabrica::instance = new Fabrica();
	}
	return Fabrica::instance;
}

Fabrica::~Fabrica(){
	
}

IUsuarioControlador * Fabrica::getUControlador(){
	return new UsuarioControlador();
}

//IRecursoControlador getRControlador();