#include "Recurso.h"

Recurso::Recurso(){

}

Recurso::Recurso(const Recurso& da){
	setNombre(da.getNombre()); 
	setDescripcion(da.getDescripcion());
	setFechaUltimoAcceso(da.getFechaUltimoAcceso());
	setFechaCreacion(da.getFechaCreacion());
	setUbicacion(da.getUbicacion());
}

//Destructor
Recurso::~Recurso(){

}

void Recurso::Recurso::setNombre(string n){
	nombre = n;
}

void Recurso::Recurso::setUbicacion(string u){
	ubicacion = u;
}

void Recurso::setUsuarioCreo(Usuario* u){
	usuarioCreo = u;
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

Usuario* Recurso::getUsuarioCreo() const{
	return usuarioCreo;
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
	return ubicacion;
}

Recurso& Recurso::operator = (const Recurso& da){
	(*this).setNombre(da.getNombre()); 
	(*this).setDescripcion(da.getDescripcion());
	(*this).setFechaUltimoAcceso(da.getFechaUltimoAcceso());
	(*this).setFechaCreacion(da.getFechaCreacion());
	(*this).setUbicacion(da.getUbicacion());
	return (*this);
}

list<DataErrores> Recurso::controlarNombreRecurso(){
	cout<<"Recurso linea 85 "<<endl;
	list<DataErrores> errores;
	return errores;
}

bool Recurso::existeNombre(string s){
	return getPath() == s;
}