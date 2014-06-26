#include "DataAccion.h"

using namespace std;

// Constructores
DataAccion::DataAccion(){
	setFecha(DateTime());
	setTipo(TipoAccion());
	setUsuario(DataUsuario());
};

DataAccion::DataAccion(DateTime fec, TipoAccion ta, DataUsuario du){
	setFecha(fec);
	setTipo(ta);
	setUsuario(du);
}

// Instancia por copia
DataAccion::DataAccion(const DataAccion &da){
	setFecha(da.getFecha());
    setTipo(da.getTipo());
    setUsuario(da.getUsuario());
}

// Destructor
DataAccion::~DataAccion(){}

// Selectores
DateTime DataAccion::getFecha () const{
	return fecha;
}

TipoAccion DataAccion::getTipo () const{
	return tipo;
}

DataUsuario DataAccion::getUsuario () const{
	return usuario;
}

// Modificadores
void DataAccion::setFecha(DateTime fec){
	fecha = fec;
}

void DataAccion::setTipo(TipoAccion ta){
	tipo = ta;
}

void DataAccion::setUsuario(DataUsuario du){
	usuario = du;
}