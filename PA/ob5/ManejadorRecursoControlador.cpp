#include "ManejadorRecursoControlador.h"

ManejadorRecursoControlador * ManejadorRecursoControlador::instance = NULL;

ManejadorRecursoControlador * ManejadorRecursoControlador::getInstance(){
	if(ManejadorRecursoControlador::instance == NULL){
		ManejadorRecursoControlador::instance = new ManejadorRecursoControlador();
	}
	return ManejadorRecursoControlador::instance;

}
ManejadorRecursoControlador::ManejadorRecursoControlador(){

}
ManejadorRecursoControlador::~ManejadorRecursoControlador(){
	// delete lista de controllers antes de borrar
}

RecursoControlador* ManejadorRecursoControlador::obtenerControlerPorId(int id){
	map<int, RecursoControlador*>::iterator it= recursoControladores.find(id);
	return it->second;		
}

int ManejadorRecursoControlador::getUltimoEnMapa(){
	return ultimoEnMapa;
}

void ManejadorRecursoControlador::agregarController(RecursoControlador * ucont){
	recursoControladores.insert(pair<int, RecursoControlador*>(ucont->getId(),ucont));
	ultimoEnMapa++;
}