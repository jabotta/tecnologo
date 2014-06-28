#ifndef ACCION_H
#define ACCION_H
#include <iostream>
#include <string>
#include "DateTime.h"
//#include "Archivo.h"
#include "TipoAccion.h"

using namespace std;
class Archivo;
class Usuario;
class Accion {
	private:
		TipoAccion tipo;
		DateTime fecha;
		Archivo* archivo;
		Usuario* usuario;
	public:
		//Constructores
		Accion();
		Accion(const Accion&);
		Accion(TipoAccion, Archivo*, Usuario*);
		//Destructor
		~Accion();
		//Selectores
		TipoAccion getTipo() const;
		DateTime getFecha() const;
		Archivo* getArchivo() const;
		Usuario* getUsuario() const;
		//Modificadores
		void setTipo(TipoAccion);
		void setArchivo(Archivo*);
		void setUsuario(Usuario*);


};
#endif