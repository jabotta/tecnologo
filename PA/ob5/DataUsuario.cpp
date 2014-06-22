#include "DataUsuario.h"

// Constructores
DataUsuario::DataUsuario(){
    nickname = ""; 
    nombre = "";
    sexo = "";
	edad = 0;
	fechaNac = DateTime();
};

DataUsuario::DataUsuario(string nck, string nm, string sx, int edad, DateTime fn){
	nickname = nck;
	nombre = nm;
	sexo = sx;
	edad = edad;
	fechaNac = fn;
}

// Instancia por copia
DataUsuario::DataUsuario(DataUsuario &du){
	nickname = du.getNickname();
    nombre = du.getNombre();
    sexo = du.getSexo();
    edad = du.getEdad();
    fechaNac = du.getFechaNac();
}

// Destructor
DataUsuario::~DataUsuario(){}

// Selectores
string DataUsuario::getNickname () const{
	return nickname;
}

string DataUsuario::getNombre () const{
	return nombre;
}

string DataUsuario::getSexo () const{
	return sexo;
}

int DataUsuario::getEdad () const{
	return edad;
}

DateTime DataUsuario::getFechaNac (){
	return fechaNac;
}

// Modificadores
void DataUsuario::setNickname(string nm){
	nickname = nm;
}

void DataUsuario::setNombre(string nm){
	nombre = nm;
}

void DataUsuario::setSexo(string sx){
	sexo = sx;
}

void DataUsuario::setEdad(int ed){
	edad = ed;
}

void DataUsuario::setFechaNac(DateTime fn){
	fechaNac = fn;
}