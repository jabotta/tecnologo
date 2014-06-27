#ifndef USUARIO_H
#define USUARIO_H
#include "DateTime.h"
#include "DataUsuario.h"
#include <iostream>
#include <string>
#include <list>
#include "Accion.h"

using namespace std;

class Usuario {
	private:
		string nickname;
		string nombre;
		string sexo;
		DateTime fechaNac;
		int edad;
		list<Accion*> acciones;

	public:
		Usuario();
		Usuario(DataUsuario);
		Usuario(string, string, string, DateTime);

		~Usuario();

		void setNickname(string n);
		void setNombre(string n);
		void setSexo(string s);
		void setFechaNac(DateTime t);

		list<Accion*> obtenerAcciones();
		string getNickname() const;
		string getNombre() const;
		string getSexo() const;
		DateTime getFechaNac() const;
		int getEdad() const;

		Usuario &operator = (Usuario &);
		int operator < (Usuario &);
		int operator == (Usuario &);
};
#endif