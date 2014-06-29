#ifndef DATACARPETA_H 
#define DATACARPETA_H
#include <iostream>
#include <string>
#include "DataRecurso.h"
#include <list>

using namespace std;

class DataCarpeta: public DataRecurso{
	private:
		list<DataRecurso> recursos;
		
	public:
		//Constructores
		DataCarpeta();
		DataCarpeta(string, DataUsuario, string, DateTime, DateTime, string, string);
		DataCarpeta(const DataCarpeta&);

		//Destructor
		~DataCarpeta();

		void setRecursos(list<DataRecurso>);
		list<DataRecurso> getRecursos();

		DataCarpeta& operator = (const DataRecurso&);
};
#endif