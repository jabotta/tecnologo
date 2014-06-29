#include "DataComentario.h"

//Constructores
DataComentario::DataComentario(){

}

DataComentario::DataComentario(const DataComentario& cm){
	setCodigo(cm.getCodigo());
	setContenido(cm.getContenido());
	setUsuario(cm.getUsuario());
	setArchivo(cm.getArchivo());
	// setParent(cm.getParent());
}

DataComentario::DataComentario(int cd, string con, DataUsuario usr, DataArchivo arc){
	setCodigo(cd);
	setContenido(con);
	setUsuario(usr);
	setArchivo(arc);
}

//Destructor
DataComentario::~DataComentario(){
	
}

//Selectores
int DataComentario::getCodigo() const{
	return codigo;
}

string DataComentario::getContenido() const{
	return contenido;
}

DataUsuario DataComentario::getUsuario() const{
	return usuario;
}

DataArchivo DataComentario::getArchivo() const{
	return archivo;
}

// DataComentario DataComentario::getParent() const{
// 	return parent;
// }

//Modificadores
void DataComentario::setCodigo(int cd){
	codigo = cd;
}

void DataComentario::setContenido(string con){
	contenido = con;
}

void DataComentario::setUsuario(DataUsuario usu){
	usuario = usu;
}

void DataComentario::setArchivo(DataArchivo arc){
	archivo = arc;
}

// void DataComentario::setParent(DataComentario par){
// 	parent = par;
// }