#ifndef DATAACCION_H
#define DATAACCION_H
#include <string.h>
#include "DateTime.h"
#include "DataUsuario.h"
#include "TipoAccion.h"

class DataAccion {
	private:
		DateTime fecha;
		TipoAccion tipo;
		DataUsuario usuario;

	public:
		// Constructores	   
	   	DataAccion(); //por defecto
		DataAccion(DateTime, TipoAccion, DataUsuario); // por parametro
		DataAccion(const DataAccion &); // por copia
		
		// Destructor
		~DataAccion();
		 
		// Selectores
		DateTime getFecha() const;
		TipoAccion getTipo() const;
		DataUsuario getUsuario() const;
		
		// Modificadores
		void setFecha(DateTime);
		void setTipo(TipoAccion);
		void setUsuario(DataUsuario);

};
#endif