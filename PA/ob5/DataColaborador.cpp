#include "DataColaborador.h"

// Constructores
DataColaborador::DataColaborador(){
    setCarpeta(DataCarpeta());
	setFecha(DateTime());
}

DataColaborador::DataColaborador(DataUsuario du, DataCarpeta dc, DateTime fc){
	setUsuario(du);
	setCarpeta(dc);
	setFecha(fc);
}

// Instancia por copia
DataColaborador::DataColaborador(const DataColaborador& dc){
	setUsuario(dc.getUsuario());
	setCarpeta(dc.getCarpeta());
    setFecha(dc.getFecha());
}

// Destructor
DataColaborador::~DataColaborador(){}

// Selectores
DataCarpeta DataColaborador::getCarpeta () const{
	return carpeta;
}

DataUsuario DataColaborador::getUsuario () const{
	return usuario;
}

DateTime DataColaborador::getFecha () const{
	return fecha;
}

// Modificadores
void DataColaborador::setCarpeta(DataCarpeta dc){
	carpeta = dc;
}

void DataColaborador::setUsuario(DataUsuario usu){
	usuario = usu;
}

void DataColaborador::setFecha(DateTime fc){
	fecha = fc;
}