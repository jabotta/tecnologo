#ifndef DATACOLABORADOR_H
#define DATACOLABORADOR_H
#include <iostream>
#include <string>
#include "DateTime.h"
#include "DataCarpeta.h"
#include "DataUsuario.h"

using namespace std;

class DataColaborador {
	private:
		DataCarpeta carpeta;
		DataUsuario usuario;
		DateTime fecha;

	public:
		// Constructores	   
	   	DataColaborador(); //por defecto
		DataColaborador(DataUsuario, DataCarpeta, DateTime); // por parametro
		DataColaborador(const DataColaborador &); // por copia
		
		// Destructor
		~DataColaborador();
		 
		// Selectores
		DataCarpeta getCarpeta() const;
		DataUsuario getUsuario() const;
		DateTime getFecha() const;

		
		// Modificadores
		void setCarpeta(DataCarpeta);
		void setUsuario(DataUsuario);
		void setFecha(DateTime);	
};
#endif