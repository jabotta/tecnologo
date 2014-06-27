#ifndef ACCION_H
#define ACCION_H
#include <iostream>
#include <string>
#include "DateTime.h"
//#include "Archivo.h"
#include "TipoAccion.h"

using namespace std;
class Archivo;
class Accion {
	private:
		TipoAccion tipo;
		DateTime fecha;
		Archivo* archivo;
	public:
		//Constructores
		Accion();
		Accion(const Accion&);
		Accion(TipoAccion, Archivo*);
		//Destructor
		~Accion();
		//Selectores
		TipoAccion getTipo() const;
		DateTime getFecha() const;
		Archivo* getArchivo() const;
		//Modificadores
		void setTipo(TipoAccion);
		void setArchivo(Archivo*);


};
#endif