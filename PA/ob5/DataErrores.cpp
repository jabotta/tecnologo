#include "DataErrores.h"

// Constructores
DataErrores::DataErrores(){
    setCodigo(-1);
	setMensaje("");
};

DataErrores::DataErrores(int cd, string msj){
	setCodigo(cd);
	setMensaje(msj);
}

// Instancia por copia
DataErrores::DataErrores(const DataErrores& de){
	setCodigo(de.getCodigo());
    setMensaje(de.getMensaje());
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