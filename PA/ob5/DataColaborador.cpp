#include "DataColaborador.h"

// Constructores
DataColaborador::DataColaborador(){
    setCarpeta(DataCarpeta());
	setFecha(DateTime());
};

DataColaborador::DataColaborador(DataCarpeta dc, DateTime fc){
	setCarpeta(dc);
	setFecha(fc);
}

// Instancia por copia
DataColaborador::DataColaborador(const DataColaborador& dc){
	setCarpeta(dc.getCarpeta());
    setFecha(dc.getFecha());
}

// Destructor
DataColaborador::~DataColaborador(){}

// Selectores
DataCarpeta DataColaborador::getCarpeta () const{
	return carpeta;
}

DateTime DataColaborador::getFecha () const{
	return fecha;
}

// Modificadores
void DataColaborador::setCarpeta(DataCarpeta dc){
	carpeta = dc;
}

void DataColaborador::setFecha(DateTime fc){
	fecha = fc;
}