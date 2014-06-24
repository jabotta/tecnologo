#include "Fabrica.h"

Fabrica::Fabrica(){

}
Fabrica::~Fabrica(){
	
}

IUsuarioControlador* Fabrica::getUControlador(){

	return new UsuarioControlador();

}
Fabrica& Fabrica::getInstance(){
	
	static Fabrica instance;

	return instance;
}
//IRecursoControlador getRControlador();