#include "DataErrores.h"

// Constructores
DataErrores::DataErrores(){
    codigo = -1;
	mensaje = "";
};

DataErrores::DataErrores(int cd, string msj){
	codigo = cd;
	mensaje = msj;
}

// Instancia por copia
DataErrores::DataErrores(const DataErrores& de){
	codigo = de.getCodigo();
    mensaje = de.getMensaje();
}

// Destructor
DataErrores::~DataErrores(){}

// Selectores
int DataErrores::getCodigo () const{
	return codigo;
}

string DataErrores::getMensaje () const{
	return mensaje;
}

// Modificadores
void DataErrores::setCodigo(int cd){
	codigo = cd;
}

void DataErrores::setMensaje(string msj){
	mensaje = msj;
}