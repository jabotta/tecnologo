#include "Fabrica.h"

Fabrica * Fabrica::instance = NULL;

Fabrica::Fabrica(){
	mucontroller = ManejadorUsuarioControlador::getInstance();
}

Fabrica * Fabrica::getInstance(){
	if (Fabrica::instance == NULL){
		Fabrica::instance = new Fabrica();
	}
	return Fabrica::instance;
}

Fabrica::~Fabrica(){
	
}

IUsuarioControlador * Fabrica::getUControlador(int id){
	if(id >= 0){
		return mucontroller->obtenerControlerPorId(id);
	}
	int newId = mucontroller->getUltimoEnMapa();
	UsuarioControlador* nuevaInstancia = new UsuarioControlador(newId);
	mucontroller->agregarController(nuevaInstancia);
	return nuevaInstancia;
}

//IRecursoControlador getRControlador();