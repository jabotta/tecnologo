 #include "UsuarioControlador.h"

//Constructores
UsuarioControlador::UsuarioControlador(){

}
UsuarioControlador::~UsuarioControlador(){
	//debemos liberar la memoria de todos los pseudo atributos 
}

//Setters
/*
void UsuarioControlador::setRecCreados(Set<Recurso> r){

	recCreados = r;

}
void UsuarioControlador::setcolaboracionList(Set<Colaboracion> c){
	colaboracionList = c ;
}
void UsuarioControlador::setAccList(Set<Accion> a){

	accList = a;

}
*/
void UsuarioControlador::setUsuarioElegido(Usuario *u){

	usuarioElegido = u;
}
void UsuarioControlador::setDataUsuarioIngresar(DataUsuario du){
	//dataUsuarioIngresar = du;
}
void UsuarioControlador::setNickname(string n){
	nickname = n;
}

//Getters
/*
Set<Recurso> UsuarioControlador::getRecCreados(){}
Set<Colaboracion> UsuarioControlador::getcolaboracionList(){}
Set<Accion>UsuarioControlador::getAccList(){}
*/
Usuario* UsuarioControlador::getUsuarioElegido(){

	return usuarioElegido;
}
DataUsuario& UsuarioControlador::getDataUsuarioIngresar(){

	return dataUsuarioIngresar;
}
string UsuarioControlador::getNickname(){ 
	return nickname;
}

//otras
bool UsuarioControlador::checkeoNickname(string nickname){
	return ManejadorUsuario::getInstance().checkeoNickname(nickname);
}
void UsuarioControlador::ingresarDatosUsuario(DataUsuario d){
	dataUsuarioIngresar = d;
}
void UsuarioControlador::guardarUsuario(){
	
	Usuario us = new Usuario(dataUsuarioIngresar);
	ManejadorUsuario::getInstance().guardarUsuario(us);
}
DataInformacionUsuario UsuarioControlador::obtenerInformacionUsuario(){

}
// Set(DataUsuario) UsuarioControlador::ListarUsuarios(){

// }
void UsuarioControlador::elegirUsuario(string nickname){

}