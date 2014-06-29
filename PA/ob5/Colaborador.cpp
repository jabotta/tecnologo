#include "Colaborador.h"

//Constructores
Colaborador::Colaborador(){

}

Colaborador::Colaborador(const Colaborador& col){
	setFechaIngreso(col.getFechaIngreso());
	setCarpeta(col.getCarpeta());
	setUsuario(col.getUsuario());
}

Colaborador::Colaborador(DateTime fi, Carpeta* car, Usuario* usu){
	setFechaIngreso(fi);
	setCarpeta(car);
	setUsuario(usu);
}

//Destructor
Colaborador::~Colaborador(){

}

//Selectores
DateTime Colaborador::getFechaIngreso() const{
	return fechaIngreso;
}

Carpeta* Colaborador::getCarpeta() const{
	return carpeta;
}

Usuario* Colaborador::getUsuario() const{
	return usuario;
}

//Modificadores
void Colaborador::setFechaIngreso(DateTime fi){
	fechaIngreso = fi;
}

void Colaborador::setCarpeta(Carpeta* car){
	carpeta = car;
}

void Colaborador::setUsuario(Usuario* usu){
	usuario = usu;
}