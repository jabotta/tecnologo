#include "DataRecurso.h"

DataRecurso::DataRecurso(){

}

DataRecurso::DataRecurso(string nm, DataUsuario uc, string dc, DateTime fua, DateTime fc, string lc, string pt){
	setNombre(nm);
	setUsuarioCreo(uc);
	setDescripcion(dc);
	setFechaUltimoAcceso(fua);
	setFechaCreacion(fc);
	setUbicacion(lc);
	setPath(pt);
}

DataRecurso::DataRecurso(const DataRecurso& r){
	setNombre(r.getNombre());
	setUbicacion(r.getUbicacion());
	setDescripcion(r.getDescripcion());
	setUsuarioCreo(r.getUsuarioCreo());
	setFechaUltimoAcceso(r.getFechaUltimoAcceso());
	setUbicacion(r.getUbicacion());
	setPath(r.getPath());
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

string DataRecurso::getPath() const {
	return path;
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

void DataRecurso::setPath(string p){
	path = p;
}

DataRecurso& DataRecurso::operator = (const DataRecurso& r){
	(*this).setNombre(r.getNombre());
	(*this).setUbicacion(r.getUbicacion());
	(*this).setDescripcion(r.getDescripcion());
	(*this).setUsuarioCreo(r.getUsuarioCreo());
	(*this).setFechaUltimoAcceso(r.getFechaUltimoAcceso());
	(*this).setFechaCreacion(r.getFechaCreacion());
	(*this).setUbicacion(r.getUbicacion());
	(*this).setPath(r.getPath());
	return (*this);
}

ostream& operator<< (ostream& out,const DataRecurso& o){
    out << o.getNombre() << " - " << o.getDescripcion();
    return out;
}