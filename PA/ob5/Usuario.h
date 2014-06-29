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
		// Constructores
		Usuario();
		Usuario(DataUsuario);
		Usuario(string, string, string, DateTime);

		// Destructor
		~Usuario();

		void setNickname(string n);
		void setNombre(string n);
		void setSexo(string s);
		void setFechaNac(DateTime t);
		void setAcciones(list<Accion*>);

		list<Accion*> obtenerAcciones();
		string getNickname() const;
		string getNombre() const;
		string getSexo() const;
		DateTime getFechaNac() const;
		list<Accion*> getAcciones() const;
		int getEdad() const;

		Usuario &operator = (Usuario &);
		int operator < (Usuario &);
		int operator == (Usuario &);
};
#endif