#ifndef IUSUARIOCONTROLADOR_H
#define IUSUARIOCONTROLADOR_H
#include <iostream.h>
#include <string.h>
//#include ""
class iUsuarioControlador{
	public:
		virtual checkeoNickname(String) = 0;
		virtual ingresarDatosUsuario(DatoUsuario usuario) = 0;
		virtual guardarUsuario() = 0;
		virtual DataInformacionUsuario obtenerInformacionUsuario() = 0;
		virtual IUserDictionary listarUsuarios() = 0;
		virtual elegirUsuario(String) = 0;
};
#endif