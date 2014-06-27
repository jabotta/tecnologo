#include "Carpeta.h"
Carpeta::Carpeta(){

}
Carpeta::Carpeta(const Carpeta &){

}
Carpeta::Carpeta(const DataCarpeta & da){ 

	setNombre(da.getNombre());
//	setUsuarioCrea(da.getUsuarioCreo());
	setDescripcion(da.getDescripcion());
	setFechaUltimoAcceso( da.getFechaUltimoAcceso());
	setFechaCreacion( da.getFechaCreacion());
	setUbicacion( da.getUbicacion());
}

//Destructor
Carpeta::~Carpeta(){

}


list<DataErrores> Carpeta::controlarNombreRecurso(){
	list<DataErrores> errores;
	return errores;	
}
bool Carpeta::existeNombre(){
	return true;
}