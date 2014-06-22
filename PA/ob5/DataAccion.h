#ifndef DATAACCION_H
#define DATAACCION_H
#include <string.h>
#include "Datetime.h"
#include "DataUsuario.h"
#include "TipoAccion.h"

class DataAccion {
	private:
		DateTime fecha;
		TipoAccion tipo;
		DataUsuario Usuario;

	public:
		// Constructores	   
	   	DataAccion(); //por defecto
		DataAccion(DateTime, TipoAccion, DataUsuario); // por parametro
		DataAccion(DataAccion &); // por copia
		
		// Destructor
		~DataAccion();
		 
		// Selectores
		int getFecha() const;
		int getTipo() const;
		int getUsuario() const;
		
		// Modificadores
		void setFecha(string);
		void setTipo(string);
		void setUsuario(string);

};
#endif