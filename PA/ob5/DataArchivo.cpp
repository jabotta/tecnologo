#include "DataArchivo.h"

DataArchivo::DataArchivo(){

}

DataArchivo::DataArchivo(string nm, DataUsuario uc, string dc, DateTime fua, DateTime fc,string lc){
	nombre = nm;
	usuarioCreo = uc;
	descripcion = dc;
	fechaUltimoAcceso = fua;
	fechaCreacion = fc;
	ubicacion = lc;
}

DataArchivo::DataArchivo(const DataArchivo& da){
	nombre = da.getNombre();
	usuarioCreo = da.getUsuarioCreo();
	descripcion = da.getDescripcion();
	fechaUltimoAcceso = da.getFechaUltimoAcceso();
	fechaCreacion = da.getFechaCreacion();
	ubicacion = da.getUbicacion();
}

DataArchivo::~DataArchivo(){

}

string DataArchivo::getNombre() const{
	return nombre;
}


DataUsuario DataArchivo::getUsuarioCreo() const{
	return usuarioCreo
}

string DataArchivo::getDescripcion() const{
	return descripcion;
}

DateTime DataArchivo::getFechaUltimoAcceso() const{
	return fechaUltimoAcceso;
}

DateTime DataArchivo::getFechaCreacion() const{
	return fechaCreacion;
}

string DataArchivo::getUbicacion() const{
	retusn ubicacion;
}

void DataArchivo::setNombre(string nm){
	nombre = nm;
}

void DataArchivo::getUsuarioCreo(DataUsuario du){
	usuarioCreo = du;
}

void DataArchivo::getDescripcion(string dc){
	descripcion = dc;
}

void DataArchivo::getFechaUltimoAcceso(DateTime fua){
	fechaUltimoAcceso = fua;
}

void DataArchivo::getFechaCreacion(DateTime fc){
	fechaCreacion = fc;
}

void DataArchivo::getUbicacion(string lc){
	ubicacion = lc;
}: