#include "Carpeta.h"
Carpeta::Carpeta(){

}
Carpeta::Carpeta(const Carpeta& da){
	setNombre(da.getNombre()); 
	setDescripcion(da.getDescripcion());
	setFechaUltimoAcceso( da.getFechaUltimoAcceso());
	setFechaCreacion( da.getFechaCreacion());
	setUbicacion( da.getUbicacion());	
}
Carpeta::Carpeta(const DataCarpeta da){ 

	setNombre(da.getNombre()); 
	setDescripcion(da.getDescripcion());
	setFechaUltimoAcceso( da.getFechaUltimoAcceso());
	setFechaCreacion( da.getFechaCreacion());
	setUbicacion( da.getUbicacion());
}

//Destructor
Carpeta::~Carpeta(){

}
void Carpeta::setRecursos(map<string, Recurso*> r){
	recursos = r;
}

map<string, Recurso*> Carpeta::getRecursos()const{
	return recursos;
}


list<DataErrores> Carpeta::controlarNombreRecurso(){
	cout<<"carpeta linea 31"<<endl;
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