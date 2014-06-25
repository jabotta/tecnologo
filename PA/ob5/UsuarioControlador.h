#ifndef USUARIOCONTROLADOR_H
#define USUARIOCONTROLADOR_H
#include "IUsuarioControlador.h"
#include "Usuario.h"
//#include "Recurso.h"
// #include "Accion.h"
#include "DataUsuario.h"
//#include "Colaboracion.h"
//#include "DataInformacionUsuario.h"
#include "ManejadorUsuario.h"
#include <iostream>
#include <string>

using namespace std;

class UsuarioControlador : public IUsuarioControlador{

private:
	//Set(Recurso) recCreados;
	//Set(Colaboracion) colaboracionList;
	//Set(Accion) accList;
	Usuario* usuarioElegido;
	bool existe;
	DataUsuario dataUsuarioIngresar;
	string nickname;
public:
	//Constructores
	UsuarioControlador();
	//Destructor	
	~UsuarioControlador();
	//Setters
/*	void setRecCreados(Set<Recurso>);
	void setcolaboracionList(Set<Colaboracion>);
	void setAccList(Set<Accion>);
*/
	void setUsuarioElegido(Usuario *);
	void setDataUsuarioIngresar(DataUsuario);
	void setNickname(string);

	//Getters
	//Set<Recurso> getRecCreados();
	//Set<Colaboracion> getcolaboracionList();
	//Set<Accion>getAccList();
	// Usuario* getUsuarioElegido();
	DataUsuario& getDataUsuarioIngresar();
	string getNickname();

	//otras
	bool checkeoNickname(string);
	void ingresarDatosUsuario(DataUsuario);
	// void guardarUsuario();
	DataInformacionUsuario obtenerInformacionUsuario();
	// Set(DataUsuario) ListarUsuarios();
	void elegirUsuario(string);


};
#endif