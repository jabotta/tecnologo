#include "ManejadorUsuario.h"


ManejadorUsuario&  ManejadorUsuario::getInstance(){

	static ManejadorUsuario instance;

	return instance;

}
ManejadorUsuario::ManejadorUsuario(){

}
ManejadorUsuario::~ManejadorUsuario(){
	// delete lista de usuarios antes de borrar
}
bool ManejadorUsuario::checkeoNickname(string nickname){
	
	return (usuarios.count(nickname)>0);
	
}
void ManejadorUsuario::guardarUsuario(Usuario& e){
	usuarios.insert(pair<string, Usuario>(e.getNickname(),e));

}

list<Usuario*> ManejadorUsuario::ListarUsuarios(){

	list<Usuario*> a;
	for (map<string, Usuario>::iterator it=usuarios.begin(); it!=usuarios.end(); ++it){
		Usuario u = it->second;
		a.push_back(&u);
	}
	
	return a;

}
Usuario* ManejadorUsuario::elegirUsuario(string nickname){

	if(usuarios.count(nickname)>0){

		map<string, Usuario>::iterator it= usuarios.find(nickname);
		return &it->second;
		
	}
	return NULL;
}