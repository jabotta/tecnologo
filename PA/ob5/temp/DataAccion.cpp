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
DataAccion::DataAccion(DataAccion &da){
	fecha = du.getFecha();
    tipo = du.getTipo();
    usuario = du.getUsuario();
}

// Destructor
DataAccion::~DataAccion(){}

// Selectores
string DataAccion::getFecha () const{
	return fecha;
}

string DataAccion::getTipo () const{
	return tipo;
}

string DataAccion::getAccion () const{
	return usuario;
}

// Modificadores
void DataAccion::setFecha(DateTime fec){
	fecha = fec;
}

void DataAccion::setTipo(TipoAccion ta){
	tipo = nta;
}

void DataAccion::setUsuario(DataUusario du){
	usuario = da;
}