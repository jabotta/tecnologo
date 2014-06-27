#include "DataArchivo.h"

DataArchivo::DataArchivo(){

}

DataArchivo::DataArchivo(string nm, DataUsuario uc, string dc, DateTime fua, DateTime fc, string lc){
	setNombre(nm);
	setUsuarioCreo(uc);
	setDescripcion(dc);
	setFechaUltimoAcceso(fua);
	setFechaCreacion(fc);
	setUbicacion(lc);
}

DataArchivo::DataArchivo(const DataArchivo& da){
	
	setNombre(da.getNombre());
	setUsuarioCreo(da.getUsuarioCreo());
	setDescripcion(da.getDescripcion());
	setFechaUltimoAcceso( da.getFechaUltimoAcceso());
	setFechaCreacion( da.getFechaCreacion());
	setUbicacion( da.getUbicacion());

}

DataArchivo::~DataArchivo(){

}
