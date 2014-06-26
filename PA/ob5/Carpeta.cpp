#include "Carpeta.h"
Carpeta::Carpeta(){

}
Carpeta::Carpeta(const Carpeta &){

}
Carpeta::Carpeta(const DataCarpeta &){

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