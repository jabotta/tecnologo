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
Usuario* UsuarioControlador::getUsuarioElegido(){}
DataUsuario& UsuarioControlador::getDataUsuarioIngresar(){}
string UsuarioControlador::getNickname(){}

//otras
void UsuarioControlador::checkeoNickname(string){

}
void UsuarioControlador::ingresarDatosUsuario(DataUsuario){

}
void UsuarioControlador::guardarUsuario(){

}
DataInformacionUsuario UsuarioControlador::obtenerInformacionUsuario(){

}
// Set(DataUsuario) UsuarioControlador::ListarUsuarios(){

// }
void UsuarioControlador::elegirUsuario(string nickname){

}