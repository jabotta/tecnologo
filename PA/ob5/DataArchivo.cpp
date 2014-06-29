#include "DataArchivo.h"

DataArchivo::DataArchivo(){

}

DataArchivo::DataArchivo(string nm, DataUsuario uc, string dc, DateTime fua, DateTime fc, string lc, string pt){
	setNombre(nm);
	setUsuarioCreo(uc);
	setDescripcion(dc);
	setFechaUltimoAcceso(fua);
	setFechaCreacion(fc);
	setUbicacion(lc);
	setPath(pt);
}

DataArchivo::DataArchivo(const DataArchivo& da){
	setNombre(da.getNombre());
	setUsuarioCreo(da.getUsuarioCreo());
	setDescripcion(da.getDescripcion());
	setFechaUltimoAcceso( da.getFechaUltimoAcceso());
	setFechaCreacion( da.getFechaCreacion());
	setUbicacion( da.getUbicacion());
	setUbicacion( da.getPath());
}

DataArchivo::~DataArchivo(){

}

DataArchivo& DataArchivo::operator = (const DataRecurso& r){
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
