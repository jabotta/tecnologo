#include "Colaborador.h"

//Constructores
Colaborador::Colaborador(){

}

Colaborador::Colaborador(const Colaborador& col){
	fechaIngreso = col.getFechaIngreso();
	carpeta = col.getCarpeta();
}

Colaborador::Colaborador(DateTime fi, Carpeta* car){
	fechaIngreso = fi;
	carpeta = car;
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

//Modificadores
void Colaborador::setFechaIngreso(DateTime fi){
	fechaIngreso = fi;
}

void Colaborador::setCarpeta(Carpeta* car){
	carpeta = car;
};

