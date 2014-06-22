#ifndef USUARIO_H
#define USUARIO_H
#include "Datetime.h"
#include <iostream.h>
#include <string.h>
class Usuario {
	private:
		String nickname;
		String nombre;
		String sexo;
		Datetime fechaNac;
		Set<Accion> acciones;

	public:

		Usuario();
		Usuario(Usuario &);
		Usuario(String,String,String,Datetime);

		~Usuario();


		setNickname(String n);
		setNombre(String n);
		setSexo(String s);
		setFechaNac(Datetime t);
		setAccion(Set<Accion> s);

		Set<Accion> obtenerAcciones();
		String getNickname();
		String getNombre();
		String getSexo();
		Datetime getFechaNac();

	
};
#endif