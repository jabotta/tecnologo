#ifndef	RECURSO_H
#define RECURSO_H

#include <iostream.h>
#include <string.h>
#include "DateTime.h"
#include "Usuario.h"
#include "DataErrores.h"

class Recurso {
	private: 
		String Nombre ; 
		String Ubicacion;
		Usuario UsuarioCrea;
		String Descripcion; 
		DateTime FechaUltimoAcceso;
		DateTime FechaCreacion;
		DateTime FechaModificacion;	
	public:
		//Destructor
		virtual ~Recurso();
		//Funciones virtuales 
		virtual Set(DataErrores) controlarNombreRecurso() = 0;
		virtual bool existeNombre() = 0;


};
#endif