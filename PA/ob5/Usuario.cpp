#include "Usuario.h"

using namespace std;

//Constructores
Usuario::Usuario(){
	setNickname("");
	setNombre("");
	setSexo("");
	setFechaNac(DateTime());
	acciones = list<Accion*>();
}

Usuario::Usuario(DataUsuario d){
	setNickname(d.getNickname());
	setNombre(d.getNombre());
	setSexo(d.getSexo());
	setFechaNac(d.getFechaNac());
	acciones = list<Accion*>();
}

Usuario::Usuario(string nickname, string nombre, string sexo, DateTime fc){
	setNickname(nickname);
	setNombre(nombre);
	setSexo(sexo);
	setFechaNac(fc);
	acciones = list<Accion*>();
}

//Destructor
Usuario::~Usuario(){
	// delete all the asociated object before to destroy the user 
	// actions associatedto the user must be deleted
}

// Setters
void Usuario::setNickname(string n){
	nickname = n;
}

void Usuario::setNombre(string n){
	nombre = n;
}

void Usuario::setSexo(string s){
	sexo = s;
}

void Usuario::setFechaNac(DateTime t){
	fechaNac = t;
}

void Usuario::setAcciones(list<Accion*> acc){
	acciones = acc;
}

//Getters
list<Accion*> Usuario::obtenerAcciones(){
 	return acciones;
}

string Usuario::getNickname() const{
	return nickname;
}

string Usuario::getNombre()const{
	return nombre;
}

string Usuario::getSexo()const{
	return sexo;
}

DateTime Usuario::getFechaNac()const{
	DateTime d = DateTime(fechaNac);
	return (d);
}

list<Accion*> Usuario::getAcciones()const{
	return acciones;
}

int Usuario::getEdad() const{
	return edad;
}

Usuario& Usuario::operator = (Usuario& u){
	return *this;
}

int Usuario::operator < (Usuario& u){
	return 0;
}

int Usuario::operator == (Usuario& u){
	return 0;
}	