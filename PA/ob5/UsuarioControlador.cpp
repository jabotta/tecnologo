#include "UsuarioControlador.h"
using namespace std;

//Constructores
UsuarioControlador::UsuarioControlador(){

}
UsuarioControlador::~UsuarioControlador(){
	//debemos liberar la memoria de todos los pseudo atributos 
}

//Setters
/*
UsuarioControlador::setRecCreados(Set<Recurso> r){

	this.recCreados = r;

}
UsuarioControlador::setcolaboracionList(Set<Colaboracion> c){
	this.colaboracionList = c ;
}
UsuarioControlador::setAccList(Set<Accion> a){

	this.accList = a;

}
*/
UsuarioControlador::setUsuarioElegido(Usuario u){

	this.usuarioElegido = u;
}
UsuarioControlador::setDataUsuarioIngresar(DataUsuario du){
	this.dataUsuarioIngresar = du;
}
UsuarioControlador::setNickname(String n){
	this.nickname = n;
}

//Getters
/*
Set<Recurso> UsuarioControlador::getRecCreados(){}
Set<Colaboracion> UsuarioControlador::getcolaboracionList(){}
Set<Accion>UsuarioControlador::getAccList(){}
*/
Usuario* UsuarioControlador::getUsuarioElegido(){}
DataUsuario UsuarioControlador::getDataUsuarioIngresar(){}
String suarioControlador::getNickname(){}

//otras
UsuarioControlador::checkeoNickname(String){

}
UsuarioControlador::ingresarDatosUsuario(DataUsuario){

}
UsuarioControlador::guardarUsuario(){

}
DataInformacionUsuario UsuarioControlador::obtenerInformacionUsuario(){

}
Set(DataUsuario) UsuarioControlador::ListarUsuarios(){

}
UsuarioControlador::elegirUsuario(nickname){

}