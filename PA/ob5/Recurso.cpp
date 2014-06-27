#include "Recurso.h"

Recurso::Recurso(){

}

Recurso::Recurso(const Recurso& rCopy){

}

//Destructor
Recurso::~Recurso(){

}

void Recurso::Recurso::setNombre(string n ){
	nombre = n;
}

void Recurso::Recurso::setUbicacion(string u){
	ubicacion = u;
}

void Recurso::setUsuarioCrea(Usuario* u ){
	usuarioCrea = u;
}

void Recurso::setDescripcion(string d){
	descripcion = d;
}

void Recurso::setFechaUltimoAcceso(DateTime fua){
	fechaUltimoAcceso = fua;
}

void Recurso::setFechaCreacion(DateTime fc){
	fechaCreacion = fc;
}

void Recurso::setFechaModificacion(DateTime fm){
	fechaModificacion = fm;
}

string Recurso::getNombre() const{
	return nombre;
}

string Recurso::getUbicacion() const{
	return ubicacion;
}

Usuario* Recurso::getUsuarioCrea() const{
	return usuarioCrea;
}

string Recurso::getDescripcion() const{
	return descripcion;
}

DateTime Recurso::getFechaUltimoAcceso() const{
	return fechaUltimoAcceso;
}

DateTime Recurso::getFechaCreacion() const{
	return fechaCreacion;
}

DateTime Recurso::getFechaModificacion() const{
	return fechaModificacion;
}

string Recurso::getPath() const{
	//string aux = strcat(ubicacion,"/");
	//string result = strcat(aux,nombre);
	return ubicacion;
}

Recurso Recurso::operator = (const Recurso& rCopy){
	return (rCopy);

}
list<DataErrores> Recurso::controlarNombreRecurso(){
	list<DataErrores> errores;
	return errores;
}
bool Recurso::existeNombre(){return true;}