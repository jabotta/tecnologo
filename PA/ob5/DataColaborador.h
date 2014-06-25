#ifndef DATACOLABORADOR_H
#define DATACOLABORADOR_H
#include <iostream>
#include <string>
#include "DateTime.h"
#include "DataCarpeta.h"

using namespace std;

class DataColaborador {
	private:
		DataCarpeta carpeta;
		DateTime fecha;

	public:
		// Constructores	   
	   	DataColaborador(); //por defecto
		DataColaborador(DataCarpeta, DateTime); // por parametro
		DataColaborador(const DataColaborador &); // por copia
		
		// Destructor
		~DataColaborador();
		 
		// Selectores
		DataCarpeta getCarpeta() const;
		DateTime getFecha() const;

		
		// Modificadores
		void setCarpeta(DataCarpeta);
		void setFecha(DateTime);	
};
#endif