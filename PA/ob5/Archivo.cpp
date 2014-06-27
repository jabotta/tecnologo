#include "Archivo.h"

Archivo::Archivo(){

}
Archivo::Archivo(const Archivo &){

}
Archivo::Archivo(const DataArchivo & da){
	setNombre(da.getNombre());
	//setUsuarioCrea(da.getUsuarioCreo());
	setDescripcion(da.getDescripcion());
	setFechaUltimoAcceso( da.getFechaUltimoAcceso());
	setFechaCreacion( da.getFechaCreacion());
	setUbicacion( da.getUbicacion());
}
Archivo::~Archivo(){

}


list<DataErrores> Archivo::controlarNombreRecurso(){
	list<DataErrores> errores;
	return 	errores;
}
bool Archivo::existeNombre(){
	return false;
}
list<Recurso> Archivo::getListaRecursos(){
	return listaRecursos;
}
list<Colaborador> Archivo::getListaColaboradores(){
	return listaColaboradores;
}
