#ifndef DATACARPETA_H 
#define DATACARPETA_H
#include "DataRecurso.h"

class DataCarpeta: public DataRecurso{
	public:
		//Constructores
		DataCarpeta();
		DataCarpeta(string, DataUsuario, string, DateTime, DateTime,string);
		DataCarpeta(const DataCarpeta&);

		//Destructor
		~DataCarpeta();

		//Selectores
		string getNombre() const;
		DataUsuario getUsuarioCreo() const;
		string getDescripcion() const;
		DateTime getFechaUltimoAcceso() const;
		DateTime getFechaCreacion() const;
		string getUbicacion() const;

		//Modificadores
		void setNombre(string);
		void getUsuarioCreo(DataUsuario);
		void getDescripcion(string);
		void getFechaUltimoAcceso(DateTime);
		void getFechaCreacion(DateTime);
		void getUbicacion(string);
};
#endif