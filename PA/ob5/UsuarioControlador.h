#ifndef USUARIOCONTROLADOR_H
#define USUARIOCONTROLADOR_H
#include "IUsuarioControlador.h"
#include "Usuario.h"
#include "Recurso.h"
#include "Accion.h"
#include "DataUsuario.h"
#include "DataInformacionUsuario.h"

class UsuarioControlador : IUsuarioControlador{

private:
	Set(Recurso) recCreados;
	Set(Colaboracion) colaboracionList;
	Set(Accion) accList;
	Usuario usuarioElegido;
	Boolean existe;
	DataUsuario dataUsuarioIngresar;
	String nickname;
public:
	//Constructores
	UsuarioControlador();
	UsuarioControlador(UsuarioControlador &);
	UsuarioControlador();
	//Destructor	
	~UsuarioControlador();
	//Getters
	setRecCreados(Set<Recurso>);
	setcolaboracionList(Set(Colaboracion));


	//Setters


	//
	checkeoNickname(String);
	ingresarDatosUsuario(DataUsuario);
	guardarUsuario();
	DataInformacionUsuario obtenerInformacionUsuario():
	Set(DataUsuario) ListarUsuarios();
	elegirUsuario(nickname);


};
#endif