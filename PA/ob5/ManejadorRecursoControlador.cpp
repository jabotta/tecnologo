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
	for(map<int, RecursoControlador*>::iterator it = recursoControladores.begin();it!=recursoControladores.end();++it){
		delete it->second;
	}
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