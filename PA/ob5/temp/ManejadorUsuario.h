#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H
#include "Usuario.h"
#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

class ManejadorUsuario {
private:
	static ManejadorUsuario * instance;
	map<string, Usuario> usuarios;
	ManejadorUsuario();
	
public:
	static ManejadorUsuario * getInstance();
	~ManejadorUsuario();

	bool checkeoNickname(string);
	void guardarUsuario(Usuario);
	list<Usuario*>ListarUsuarios();
	Usuario* elegirUsuario(string);
};
#endif