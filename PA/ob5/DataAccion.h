#ifndef DATAACCION_H
#define DATAACCION_H
#include <string.h>
#include "DateTime.h"
#include "DataUsuario.h"
#include "DataArchivo.h"
#include "TipoAccion.h"

class DataAccion {
	private:
		DateTime fecha;
		TipoAccion tipo;
		DataUsuario usuario;
		DataArchivo archivo;

	public:
		// Constructores	   
	   	DataAccion(); //por defecto
		DataAccion(DateTime, TipoAccion, DataUsuario, DataArchivo); // por parametro
		DataAccion(const DataAccion &); // por copia
		
		// Destructor
		~DataAccion();
		 
		// Selectores
		DateTime getFecha() const;
		TipoAccion getTipo() const;
		DataUsuario getUsuario() const;
		DataArchivo getArchivo() const;
		
		// Modificadores
		void setFecha(DateTime);
		void setTipo(TipoAccion);
		void setUsuario(DataUsuario);
		void setArchivo(DataArchivo);

};
#endif