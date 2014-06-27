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
		DataArchivo& operator = (const DataRecurso&);
};
#endif