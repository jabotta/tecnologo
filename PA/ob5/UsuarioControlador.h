#ifndef USUARIOCONTROLADOR_H
#define USUARIOCONTROLADOR_H
#include "IUsuarioControlador.h"
#include "Usuario.h"
//#include "Recurso.h"
#include "Accion.h"
#include "DataUsuario.h"
//#include "Colaboracion.h"
//#include "DataInformacionUsuario.h"
#include <iostream.h>
#include <string.h>

class UsuarioControlador : IUsuarioControlador{

private:
	//Set(Recurso) recCreados;
	//Set(Colaboracion) colaboracionList;
	//Set(Accion) accList;
	Usuario* usuarioElegido;
	Boolean existe;
	DataUsuario dataUsuarioIngresar;
	String nickname;
public:
	//Constructores
	UsuarioControlador();
	//Destructor	
	~UsuarioControlador();
	//Setters
	setRecCreados(Set<Recurso>);
	setcolaboracionList(Set<Colaboracion>);
	setAccList(Set<Accion>);
	setUsuarioElegido(Usuario);
	setDataUsuarioIngresar(DataUsuario);
	setNickname(String);

	//Getters
	//Set<Recurso> getRecCreados();
	//Set<Colaboracion> getcolaboracionList();
	//Set<Accion>getAccList();
	Usuario* getUsuarioElegido();
	DataUsuario getDataUsuarioIngresar();
	String getNickname();

	//otras
	checkeoNickname(String);
	ingresarDatosUsuario(DataUsuario);
	guardarUsuario();
	DataInformacionUsuario obtenerInformacionUsuario():
	Set(DataUsuario) ListarUsuarios();
	elegirUsuario(nickname);


};
#endif