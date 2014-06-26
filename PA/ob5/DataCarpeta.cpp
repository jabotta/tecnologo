#include "DataCarpeta.h"

DataCarpeta::DataCarpeta(){

}

DataCarpeta::DataCarpeta(string nm, DataUsuario uc, string dc, DateTime fua, DateTime fc, string lc){
	nombre = nm;
	usuarioCreo = uc;
	descripcion = dc;
	fechaUltimoAcceso = fua;
	fechaCreacion = fc;
	ubicacion = lc;
}

DataCarpeta::DataCarpeta(const DataCarpeta& da){
	nombre = da.getNombre();
	usuarioCreo = da.getUsuarioCreo();
	descripcion = da.getDescripcion();
	fechaUltimoAcceso = da.getFechaUltimoAcceso();
	fechaCreacion = da.getFechaCreacion();
	ubicacion = da.getUbicacion();
}

DataCarpeta::~DataCarpeta(){

}

string DataCarpeta::getNombre() const{
	return nombre;
}


DataUsuario DataCarpeta::getUsuarioCreo() const{
	return usuarioCreo
}

string DataCarpeta::getDescripcion() const{
	return descripcion;
}

DateTime DataCarpeta::getFechaUltimoAcceso() const{
	return fechaUltimoAcceso;
}

DateTime DataCarpeta::getFechaCreacion() const{
	return fechaCreacion;
}

string DataCarpeta::getUbicacion() const{
	retusn ubicacion;
}

void DataCarpeta::setNombre(string nm){
	nombre = nm;
}

void DataCarpeta::getUsuarioCreo(DataUsuario du){
	usuarioCreo = du;
}

void DataCarpeta::getDescripcion(string dc){
	descripcion = dc;
}

void DataCarpeta::getFechaUltimoAcceso(DateTime fua){
	fechaUltimoAcceso = fua;
}

void DataCarpeta::getFechaCreacion(DateTime fc){
	fechaCreacion = fc;
}

void DataCarpeta::getUbicacion(string lc){
	ubicacion = lc;
}: