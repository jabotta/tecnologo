#include "Comentario.h"

//Constructores
Comentario::Comentario(){

}

Comentario::Comentario(const Comentario& cm){
	setCodigo(cm.getCodigo());
	setContenido(cm.getContenido());
	setUsuario(cm.getUsuario());
	setArchivo(cm.getArchivo());
}

Comentario::Comentario(int cd, string con, Usuario* usr, Archivo* arc){
	setCodigo(cd);
	setContenido(con);
	setUsuario(usr);
	setArchivo(arc);
}

//Destructor
Comentario::~Comentario(){
	delete usuario;
	delete archivo;
}

//Selectores
int Comentario::getCodigo() const{
	return codigo;
}

string Comentario::getContenido() const{
	return contenido;
}

Usuario* Comentario::getUsuario() const{
	return usuario;
}

Archivo* Comentario::getArchivo() const{
	return archivo;
}

//Modificadores
void Comentario::setCodigo(int cd){
	codigo = cd;
}

void Comentario::setContenido(string con){
	contenido = con;
}

void Comentario::setUsuario(Usuario* usu){
	usuario = usu;
}

void Comentario::setArchivo(Archivo* arc){
	archivo = arc;
}