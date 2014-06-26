#include "DataInformacionUsuario.h"

// Constructores
DataInformacionUsuario::DataInformacionUsuario(){
	setUsuario(DataUsuario());
	setRecursos(list<DataRecurso>());
	setColaboradores(list<DataColaborador>());
	setAcciones(list<DataAccion>());
};

DataInformacionUsuario::DataInformacionUsuario(DataUsuario us,list<DataRecurso> ldr,list<DataColaborador> ldc,list<DataAccion> la){
	setUsuario(us);
	setRecursos(ldr);
	setColaboradores(ldc);
	setAcciones(la);
}

// Instancia por copia
DataInformacionUsuario::DataInformacionUsuario(const DataInformacionUsuario& diu){
	setUsuario(diu.getUsuario());
	setRecursos(diu.getRecursos());
	setColaboradores(diu.getColaboradores());
	setAcciones(diu.getAcciones());
}

// Destructor
DataInformacionUsuario::~DataInformacionUsuario(){}

// Selectores
DataUsuario DataInformacionUsuario::getUsuario () const{
	return usuario;
}

list<DataRecurso> DataInformacionUsuario::getRecursos () const{
	return recursos;
}

list<DataColaborador> DataInformacionUsuario::getColaboradores () const{
	return colaboradores;
}

list<DataAccion> DataInformacionUsuario::getAcciones () const{
	return acciones;
}

// Modificadores
void DataInformacionUsuario::setUsuario(DataUsuario us){
	usuario = us;
}

void DataInformacionUsuario::setRecursos(list<DataRecurso> re ){
	recursos = re;
}

void DataInformacionUsuario::setColaboradores(list<DataColaborador> col){
	colaboradores = col;
}

void DataInformacionUsuario::setAcciones(list<DataAccion> acc){
	acciones = acc;
}