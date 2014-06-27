#ifndef	RECURSO_H
#define RECURSO_H

#include <iostream>
#include <string>
#include <list>
#include "DateTime.h"
#include "Usuario.h"
#include "DataErrores.h"

using namespace std;

class Recurso {
	private: 
		string nombre ; 
		string ubicacion;
		Usuario* usuarioCrea;
		string descripcion; 
		DateTime fechaUltimoAcceso;
		DateTime fechaCreacion;
		DateTime fechaModificacion;

	public:
		Recurso();
		Recurso(const Recurso&);
		//Destructor
		~Recurso();
		//Funciones virtuales 
		virtual list<DataErrores> controlarNombreRecurso();
		virtual bool existeNombre(string ) ;

		void setNombre(string);
		void setUbicacion(string);
		void setUsuarioCrea(Usuario*);
		void setDescripcion(string);
		void setFechaUltimoAcceso(DateTime);
		void setFechaCreacion(DateTime);
		void setFechaModificacion(DateTime);

		string getNombre() const;
		string getUbicacion() const;
		Usuario* getUsuarioCrea() const;
		string getDescripcion() const;
		DateTime getFechaUltimoAcceso() const;
		DateTime getFechaCreacion() const;
		DateTime getFechaModificacion() const;
		string getPath() const;

		Recurso operator = (const Recurso&);
};
#endif