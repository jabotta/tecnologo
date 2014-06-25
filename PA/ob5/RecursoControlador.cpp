#include "RecursoControlador.h"

RecursoControlador::RecursoControlador(){
	
}

RecursoControlador::RecursoControlador(int iduc){
	id = iduc;
}

RecursoControlador::~RecursoControlador(){
	//debemos liberar la memoria de todos los pseudoatributos 
}
RecursoControlador::RecursoControlador(const RecursoControlador& i){
	//debemos liberar la memoria de todos los pseudoatributos 
}

int RecursoControlador::getId(){
	return id;
}