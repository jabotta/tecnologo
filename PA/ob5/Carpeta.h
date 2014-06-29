#ifndef CARPETA_H
#define CARPETA_H
#include <iostream>
#include <string>
#include <list>
#include <map>
#include "Recurso.h"
#include "DataCarpeta.h"
#include "DataErrores.h"

class  Carpeta: public Recurso{
	private:
		map<string, Recurso*> recursos;
		
	public:
		//Constructores
		Carpeta();
		Carpeta(const Carpeta &);
		Carpeta(const DataCarpeta );

		//Destructor
		~Carpeta();

		void setRecursos(map<string, Recurso*>);
		map<string, Recurso*> getRecursos()const;

		list<DataErrores> controlarNombreRecurso();
		bool existeNombre(string );
};
#endif