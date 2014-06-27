#include "DataRecurso.h"

DataRecurso::DataRecurso(){

}

DataRecurso::DataRecurso(const DataRecurso& dr){

}

DataRecurso::~DataRecurso(){

}

//Selectores
string DataRecurso::getNombre() const {
	return nombre;
}

DataUsuario DataRecurso::getUsuarioCreo() const {
	return usuarioCreo;
}

string DataRecurso::getDescripcion() const {
	return descripcion;
}

DateTime DataRecurso::getFechaUltimoAcceso() const {
	return fechaUltimoAcceso;
}

DateTime DataRecurso::getFechaCreacion() const {
	return fechaCreacion;
}

string DataRecurso::getUbicacion() const {
	return ubicacion;
}

//Modificadores
void DataRecurso::setNombre(string n) {
	nombre = n;
}

void DataRecurso::setUsuarioCreo(DataUsuario u) {
	usuarioCreo = u;
}

void DataRecurso::setDescripcion(string d) {
	descripcion = d;
}

void DataRecurso::setFechaUltimoAcceso(DateTime fua) {
	fechaUltimoAcceso = fua;
}

void DataRecurso::setFechaCreacion(DateTime fc) {
	fechaCreacion = fc;
}

void DataRecurso::setUbicacion(string u){
	ubicacion = u;
}


ostream& operator<< (ostream& out,const DataRecurso& o){
    out << o.getNombre() << " - " << o.getDescripcion() << endl;
    return out;
}