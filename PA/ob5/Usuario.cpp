#include "Usuario.h"

using namespace std;

//Constructores
Usuario::Usuario(){
	nickname = "";
	nombre = "";
	sexo = "";
	fechaNac = DateTime();
}

Usuario::Usuario(DataUsuario & d){

	nickname = d.getNickname();
	nombre = d.getNombre();
	sexo = d.getSexo();
	fechaNac = d.getFechaNac();
}

Usuario::Usuario(Usuario & u){

	nickname = u.getNickname();
	nombre = u.getNombre();
	sexo = u.getSexo();
	fechaNac = u.getFechaNac();
}

Usuario::Usuario(string nickname,string nombre,string sexo,DateTime fc){
	nickname = nickname;
	nombre = nombre;
	sexo = sexo;
	fechaNac = fc;
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

// esta no se si tiene sentido
// Usuario::setAccion(Set<Accion> s){
// 	acciones = s;
// }

//Getters
// Set<Accion> Usuario::obtenerAcciones(){
// 	return acciones;
// }

string Usuario::getNickname(){
	return nickname;
}

string Usuario::getNombre(){
	return nombre;
}

string Usuario::getSexo(){
	return sexo;
}

DateTime Usuario::getFechaNac(){
	return fechaNac;
}

int Usuario::getEdad(){
	return edad;
}