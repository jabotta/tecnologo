#ifndef	RECURSO_H
#define RECURSO_H

#include <iostream>
#include <string>
#include <list>
#include "DateTime.h"
#include "Usuario.h"
#include "DataErrores.h"

class Recurso {
	private: 
		string Nombre ; 
		string Ubicacion;
		Usuario UsuarioCrea;
		string Descripcion; 
		DateTime FechaUltimoAcceso;
		DateTime FechaCreacion;
		DateTime FechaModificacion;	
	public:
		//Destructor
		virtual ~Recurso();
		//Funciones virtuales 
		virtual list<DataErrores> controlarNombreRecurso() = 0;
		virtual bool existeNombre() = 0;


};
#endif