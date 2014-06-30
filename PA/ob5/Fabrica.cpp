#include "Fabrica.h"

Fabrica * Fabrica::instance = NULL;

Fabrica::Fabrica(){
	mucontroller = ManejadorUsuarioControlador::getInstance();
	mrcontroller = ManejadorRecursoControlador::getInstance();
}

Fabrica * Fabrica::getInstance(){
	if (Fabrica::instance == NULL){
		Fabrica::instance = new Fabrica();
	}
	return Fabrica::instance;
}

Fabrica::~Fabrica(){
	delete mucontroller;
	delete mrcontroller;
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

IRecursoControlador * Fabrica::getRControlador(int id){
	if(id >= 0){
		return mrcontroller->obtenerControlerPorId(id);
	}
	int newId = mrcontroller->getUltimoEnMapa();
	RecursoControlador* nuevaInstancia = new RecursoControlador(newId);
	mrcontroller->agregarController(nuevaInstancia);
	return nuevaInstancia;
}