#include "ManejadorUsuarioControlador.h"

ManejadorUsuarioControlador * ManejadorUsuarioControlador::instance = NULL;

ManejadorUsuarioControlador * ManejadorUsuarioControlador::getInstance(){
	if(ManejadorUsuarioControlador::instance == NULL){
		ManejadorUsuarioControlador::instance = new ManejadorUsuarioControlador();
	}
	return ManejadorUsuarioControlador::instance;

}
ManejadorUsuarioControlador::ManejadorUsuarioControlador(){

}
ManejadorUsuarioControlador::~ManejadorUsuarioControlador(){
	for(map<int, UsuarioControlador*>::iterator it = usuarioControladores.begin();it!=usuarioControladores.end();++it){
		delete it->second;
	}
}

UsuarioControlador* ManejadorUsuarioControlador::obtenerControlerPorId(int id){
	map<int, UsuarioControlador*>::iterator it= usuarioControladores.find(id);
	return it->second;		
}

int ManejadorUsuarioControlador::getUltimoEnMapa(){
	return ultimoEnMapa;
}

void ManejadorUsuarioControlador::agregarController(UsuarioControlador * ucont){
	usuarioControladores.insert(pair<int, UsuarioControlador*>(ucont->getId(),ucont));
	ultimoEnMapa++;
}