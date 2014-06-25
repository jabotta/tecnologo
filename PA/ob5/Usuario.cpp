#include "Usuario.h"

using namespace std;

//Constructores
Usuario::Usuario(){
	nickname = "";
	nombre = "";
	sexo = "";
	cout<< "usuario por def"<<endl;
	fechaNac = DateTime();
}

Usuario::Usuario(DataUsuario & d){
cout<< " usuario datausercop"<<endl;
cout<<d<<endl;
	nickname = d.getNickname();
	nombre = d.getNombre();
	sexo = d.getSexo();
	fechaNac = d.getFechaNac();
}

Usuario::Usuario(const Usuario& u){
cout<< " usuario cop ."<<endl;
cout<<u.getNickname()<<endl;
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

string Usuario::getNickname() const{
	return this->nickname;
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