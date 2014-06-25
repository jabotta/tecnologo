 #include "UsuarioControlador.h"

//Constructores
UsuarioControlador::UsuarioControlador(){
	
}

UsuarioControlador::UsuarioControlador(int iduc){
	id = iduc;
}

UsuarioControlador::~UsuarioControlador(){
	//debemos liberar la memoria de todos los pseudoatributos 
}
UsuarioControlador::UsuarioControlador(const UsuarioControlador& i){
	//debemos liberar la memoria de todos los pseudoatributos 
}

//Setters
// void UsuarioControlador::setRecCreados(Set<Recurso> r){

// 	recCreados = r;

// }

// void UsuarioControlador::setcolaboracionList(Set<Colaboracion> c){
// 	colaboracionList = c ;
// }

// void UsuarioControlador::setAccList(Set<Accion> a){
// 	accList = a;
// }

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
// Set<Recurso> UsuarioControlador::getRecCreados(){}

// Set<Colaboracion> UsuarioControlador::getcolaboracionList(){}

// Set<Accion>UsuarioControlador::getAccList(){}

// Usuario* UsuarioControlador::getUsuarioElegido(){
// 	return usuarioElegido;
// }

DataUsuario& UsuarioControlador::getDataUsuarioIngresar(){
	return dataUsuarioIngresar;
}

string UsuarioControlador::getNickname(){ 
	return nickname;
}

bool UsuarioControlador::checkeoNickname(string nickname){
	return ManejadorUsuario::getInstance()->checkeoNickname(nickname);
}

void UsuarioControlador::ingresarDatosUsuario(DataUsuario d){
	dataUsuarioIngresar = DataUsuario(d);
}

void UsuarioControlador::guardarUsuario(){
	Usuario us = Usuario(dataUsuarioIngresar);
	ManejadorUsuario::getInstance()->guardarUsuario(us);
}
int UsuarioControlador::getId(){
	return id;
}
DataInformacionUsuario UsuarioControlador::obtenerInformacionUsuario(){

}
// Set(DataUsuario) UsuarioControlador::ListarUsuarios(){

// }

void UsuarioControlador::elegirUsuario(string nickname){

}