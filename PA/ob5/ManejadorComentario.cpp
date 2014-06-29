#include "ManejadorComentario.h"

ManejadorComentario * ManejadorComentario::instance = NULL;

ManejadorComentario::ManejadorComentario(){

}

ManejadorComentario * ManejadorComentario::getInstance(){
	if (ManejadorComentario::instance == NULL){
		ManejadorComentario::instance = new ManejadorComentario();
	}
	return ManejadorComentario::instance;
}

ManejadorComentario::~ManejadorComentario(){
	// delete lista de usuarios antes de borrar
}

void ManejadorComentario::guardarComentario(Comentario c){
	comentarios.push_back(c);
}

list<Comentario> ManejadorComentario::listarComentarios(){
	list<Comentario> cm;
	for (map<string, Comentario>::iterator it = comentarios.begin(); it != comentarios.end(); ++it){
		cm.push_back((*it).second);
	}	
	return cm;
}