#include "Comentario.h"

//Constructores
Comentario::Comentario(){

}

Comentario::Comentario(const Comentario& cm){
	codigo = cm.getCodigo();
	contenido = cm.getContenido();
	usuario = cm.getUsuario();
	archivo = cm.getArchivo();
}

Comentario::Comentario(int cd, string con, Usuario* usr, Archivo* arc){
	codigo = cd;
	contenido = con;
	usuario = usr;
	archivo = arc;
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
};

