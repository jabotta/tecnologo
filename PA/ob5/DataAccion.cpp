#include "DataAccion.h"

using namespace std;

// Constructores
DataAccion::DataAccion(){
	fecha = DateTime();
	tipo = TipoAccion();
	usuario = DataUsuario();
};

DataAccion::DataAccion(DateTime fec, TipoAccion ta, DataUsuario du){
	fecha = fec;
	tipo = ta;
	usuario = du;
}

// Instancia por copia
DataAccion::DataAccion(const DataAccion &da){
	fecha = da.getFecha();
    tipo = da.getTipo();
    usuario = da.getUsuario();
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