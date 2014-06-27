#include "ManejadorUsuario.h"

ManejadorUsuario * ManejadorUsuario::instance = NULL;

ManejadorUsuario::ManejadorUsuario(){

}

ManejadorUsuario * ManejadorUsuario::getInstance(){
	if (ManejadorUsuario::instance == NULL){
		ManejadorUsuario::instance = new ManejadorUsuario();
	}
	return ManejadorUsuario::instance;
}

ManejadorUsuario::~ManejadorUsuario(){
	// delete lista de usuarios antes de borrar
}

bool ManejadorUsuario::checkeoNickname(string nickname){
	return (usuarios.count(nickname) > 0);
}

void ManejadorUsuario::guardarUsuario(Usuario u){
	usuarios.insert(pair<string, Usuario>(u.getNickname(),u));
}

list<DataUsuario> ManejadorUsuario::listarUsuarios(){
	list<DataUsuario> du;
	for (map<string, Usuario>::iterator it = usuarios.begin(); it != usuarios.end(); ++it){
		Usuario u = Usuario((*it).second);
		DataUsuario tmp_du = DataUsuario(u.getNickname(), u.getNombre(), u.getSexo(), u.getEdad(), u.getFechaNac());
		du.push_back(tmp_du);
	}	
	return du;
}

Usuario* ManejadorUsuario::elegirUsuario(string nickname){
	if(usuarios.count(nickname) > 0){
		map<string, Usuario>::iterator it = usuarios.find(nickname);
		return &it->second;		
	}
	return NULL;
}