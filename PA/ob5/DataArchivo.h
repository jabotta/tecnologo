#ifndef DATAARCHIVO_H 
#define DATAARCHIVO_H
#include <iostream>
#include <string>
#include "DataRecurso.h"

using namespace std;

class DataArchivo: public DataRecurso{
	public:
		//Constructores
		DataArchivo();
		DataArchivo(string, DataUsuario, string, DateTime, DateTime,string);
		DataArchivo(const DataArchivo&);

		//Destructor
		~DataArchivo();

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