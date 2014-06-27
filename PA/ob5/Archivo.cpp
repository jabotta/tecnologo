#include "Archivo.h"

Archivo::Archivo(){

}
Archivo::Archivo(const Archivo& da){
	setNombre(da.getNombre()); 
	setDescripcion(da.getDescripcion());
	setFechaUltimoAcceso( da.getFechaUltimoAcceso());
	setFechaCreacion( da.getFechaCreacion());
	setUbicacion( da.getUbicacion());
}
Archivo::Archivo(const DataArchivo da){
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
	cout<<"archivo linea 25"<<endl;
	list<DataErrores> errores;
	int size = getNombre().size();
	if(getNombre().find("/")!=-1){
		DataErrores raizConflict = DataErrores(4,"El nombre del archivo no puede contener caracteres del tipo '/' ");
		errores.push_back(raizConflict);

	}

	if(size<1){

		DataErrores sizeError = DataErrores(5,"El nombre del archivo debe tener al menos un caracter");
		errores.push_back(sizeError);
	}

	if(size>8){

		DataErrores sizeError = DataErrores(6,"El nombre del archivo no puede superar los 8 caracteres");
		errores.push_back(sizeError);

	}


	return 	errores;
}
bool Archivo::existeNombre(string nombre){
	return getNombre() == nombre;
}
list<Recurso> Archivo::getListaRecursos(){
	return listaRecursos;
}
list<Colaborador> Archivo::getListaColaboradores(){
	return listaColaboradores;
}
