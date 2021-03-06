#include "DataCarpeta.h"

DataCarpeta::DataCarpeta(){

}

DataCarpeta::DataCarpeta(string nm, DataUsuario uc, string dc, DateTime fua, DateTime fc, string lc, string pt){
	setNombre(nm);
	setUsuarioCreo(uc);
	setDescripcion(dc);
	setFechaUltimoAcceso(fua);
	setFechaCreacion(fc);
	setUbicacion(lc);
	setPath(pt);
}

DataCarpeta::DataCarpeta(const DataCarpeta& da){	
	setNombre(da.getNombre());
	setUsuarioCreo(da.getUsuarioCreo());
	setDescripcion(da.getDescripcion());
	setFechaUltimoAcceso( da.getFechaUltimoAcceso());
	setFechaCreacion( da.getFechaCreacion());
	setUbicacion( da.getUbicacion());
	setPath( da.getPath());
}

DataCarpeta::~DataCarpeta(){

}

void DataCarpeta::setRecursos(list<DataRecurso> lr){
	recursos = lr;
}

list<DataRecurso> DataCarpeta::getRecursos(){
	return recursos;
}

DataCarpeta& DataCarpeta::operator = (const DataRecurso& r){
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
