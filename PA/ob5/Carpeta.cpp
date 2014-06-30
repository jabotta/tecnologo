#include "Carpeta.h"
Carpeta::Carpeta(){

}
Carpeta::Carpeta(const Carpeta& c){
	setNombre(c.getNombre()); 
	setUsuarioCreo(c.getUsuarioCreo());
	setDescripcion(c.getDescripcion());
	setFechaUltimoAcceso( c.getFechaUltimoAcceso());
	setFechaCreacion( c.getFechaCreacion());
	setUbicacion( c.getUbicacion());	
}

Carpeta::Carpeta(const DataCarpeta dc){ 
	setNombre(dc.getNombre()); 
	// setUsuarioCreo(dc.getUsuarioCreo());
	setDescripcion(dc.getDescripcion());
	setFechaUltimoAcceso( dc.getFechaUltimoAcceso());
	setFechaCreacion( dc.getFechaCreacion());
	setUbicacion( dc.getUbicacion());
}

//Destructor
Carpeta::~Carpeta(){

	recursos.clear();

}

void Carpeta::setRecursos(map<string, Recurso*> r){
	recursos = r;
}

map<string, Recurso*> Carpeta::getRecursos()const{
	return recursos;
}

list<DataErrores> Carpeta::controlarNombreRecurso(){
	list<DataErrores> errores;
	int size = getNombre().size();
	
	if(getNombre().find("/")!=-1){
		DataErrores raizConflict = DataErrores(1,"El nombre de la carpeta no puede contener caracteres del tipo '/' ");
		errores.push_back(raizConflict);
	}

	if(size<1){
		DataErrores sizeError = DataErrores(2,"El nombre de la carpeta debe tener al menos un caracter");
		errores.push_back(sizeError);
	}

	if(size>8){
		DataErrores sizeError = DataErrores(2,"El nombre de la carpeta no puede superar los 8 caracteres");
		errores.push_back(sizeError);
	}

	return 	errores;
}

bool Carpeta::existeNombre(string nombre){
	return getNombre() == nombre;
}