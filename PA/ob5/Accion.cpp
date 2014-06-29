#include "Accion.h"
#include "Archivo.h"
#include "Usuario.h"

//Constructores
Accion::Accion(){

}

Accion::Accion(const Accion& acc){
	setTipo(acc.getTipo());
	fecha = acc.getFecha();
	setArchivo(acc.getArchivo());
	setUsuario(acc.getUsuario());
}

Accion::Accion(TipoAccion tp, Archivo* arc, Usuario* usu){
	setTipo(tp);
	fecha = DateTime();
	setArchivo(arc);
	setUsuario(usu);
}

//Destructor
Accion::~Accion(){

}

//Selectores
TipoAccion Accion::getTipo() const{
	return tipo;
}

DateTime Accion::getFecha() const{
	return fecha;
}

Archivo* Accion::getArchivo() const{
	return archivo;
}

Usuario* Accion::getUsuario() const{
	return usuario;
}

//Modificadores
void Accion::setTipo(TipoAccion tp){
	tipo = tp;
}

void Accion::setArchivo(Archivo* arc){
	archivo = arc;
}

void Accion::setUsuario(Usuario* usu){
	usuario = usu;
}