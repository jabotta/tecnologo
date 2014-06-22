#include <iostream>
#include "DateTime.h"
#include "DataUsuario.h"

using namespace std;

// Constructores
DataUsuario::DataUsuario(){
    nickname = ""; 
    nombre = "";
    sexo = "";
	edad = 0;
	fechaNac = new DateTime();
};

DataUsuario::DataUsuario(string nck, string nm, string sx, string edad, DateTime fn){
	nickname = nck;
	nombre = nm;
	sexo = sx;
	edad = edad;
	fechaNac = fn;
}

// Instancia por copia
DataUsuario::DataUsuario(DataUsuario &du){
	nickname = du.getNickname();
    nombre = dt.getNombre();
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

DateTime DataUsuario::getFechaNac () const{
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

void DataUsuario::setSexo(int ed){
	edad = ed;
}

void DataUsuario::setFechaNac(DataTime fn){
	fechaNac = fn;
}
