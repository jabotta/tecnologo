#include "ManejadorColaborador.h"

ManejadorColaborador * ManejadorColaborador::instance = NULL;

ManejadorColaborador::ManejadorColaborador(){

}

ManejadorColaborador * ManejadorColaborador::getInstance(){
	if (ManejadorColaborador::instance == NULL){
		ManejadorColaborador::instance = new ManejadorColaborador();
	}
	return ManejadorColaborador::instance;
}

ManejadorColaborador::~ManejadorColaborador(){
	// delete lista de usuarios antes de borrar
}

void ManejadorColaborador::agregarALista(Colaborador* c){
	colaboradores.push_back(c);
}

list<Colaborador*> ManejadorColaborador::listarColaboradores(){
	return colaboradores;
};