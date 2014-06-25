#include "DataColaborador.h"

// Constructores
DataColaborador::DataColaborador(){
    carpeta = DataCarpeta();
	fecha = DateTime();
};

DataColaborador::DataColaborador(DataCarpeta dc, DateTime fc){
	carpeta = dc;
	fecha = fc;
}

// Instancia por copia
DataColaborador::DataColaborador(const DataColaborador& dc){
	carpeta = dc.getCarpeta();
    fecha = dc.getFecha();
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