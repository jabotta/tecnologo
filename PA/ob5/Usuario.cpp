#include "Usuario.h"

//Constructores
Usuario::Usuario(){
	this.nickname = "";
	this.nombre = "";
	this.sexo = "";
	this.fechaNac = "";

}
Usuario::Usuario(DataUsuario & d){
	this.nickname = d.getNickname();
	this.nombre = d.getNombre();
	this.sexo = d.getSexo();
	this.fechaNac = d.getFechaNac();

}
Usuario::Usuario(Usuario & u){

	this.nickname = u.getNickname();
	this.nombre = u.getNombre();
	this.sexo = u.getSexo();
	this.fechaNac = u.getFechaNac();
}
Usuario::Usuario(String nickname,String nombre,String sexo,Datetime fc){
	this.nickname = nickname;
	this.nombre = nombre;
	this.sexo = sexo;
	this.fechaNac = fc;
}
//Destructor
Usuario::~Usuario(){
	// delete all the asociated object before to destroy the user 
	// actions associatedto the user must be deleted
}
// Setters
Usuario::setNickname(String n){
	this.nickname = n;
}
Usuario::setNombre(String n){
	this.nombre = n;
}
Usuario::setSexo(String s){
	this.sexo = s;

}
Usuario::setFechaNac(Datetime t){
	this.fechaNac = t;
}

// esta no se si tiene sentido
Usuario::setAccion(Set<Accion> s){
	this.acciones = s;
}

//Getters
Set<Accion> Usuario::obtenerAcciones(){
	return this.acciones;
}
String Usuario::getNickname(){
	return this.nickname;
}
String Usuario::getNombre(){
	return this.nombre;
}
String Usuario::getSexo(){
	return this.sexo;
}
Datetime Usuario::getFechaNac(){
	return this.fechaNac;
}
int Usuario::getEdad(){
	
	return this.edad;
}