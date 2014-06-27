#include "Accion.h"
#include "Archivo.h"

//Constructores
Accion::Accion(){

}

Accion::Accion(const Accion& acc){
	setTipo(acc.getTipo());
	fecha = acc.getFecha();
	//setArchivo(acc.getArchivo());
}

Accion::Accion(TipoAccion tp, Archivo* arc){
	setTipo(tp);
	fecha = DateTime();
	setArchivo(arc);
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

//Modificadores
void Accion::setTipo(TipoAccion tp){
	tipo = tp;
}

void Accion::setArchivo(Archivo* arc){
	archivo = arc;
};