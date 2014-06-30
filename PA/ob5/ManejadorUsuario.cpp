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
		for(map<string, Usuario*>::iterator it = usuarios.begin();it!=usuarios.end();++it){
		delete it->second;
	}
}

bool ManejadorUsuario::checkeoNickname(string nickname){
	return (usuarios.count(nickname) > 0);
}

void ManejadorUsuario::guardarUsuario(Usuario* u){
	usuarios.insert(pair<string, Usuario*>(u->getNickname(),u));
}

list<Usuario*> ManejadorUsuario::listarUsuarios(){
	list<Usuario*> u;
	for (map<string, Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it){
		u.push_back(it->second);
	}	
	return u;
}

Usuario* ManejadorUsuario::elegirUsuario(string nickname){
	if(usuarios.count(nickname) > 0){
		map<string, Usuario*>::iterator it = usuarios.find(nickname);
		return it->second;		
	}
	return NULL;
}