#ifndef CARPETA_H
#define CARPETA_H
#include <iostream>
#include <list>
#include "Recurso.h"
#include "DataCarpeta.h"
#include "DataErrores.h"

class  Carpeta: public Recurso{


	public:
		//Constructores
		Carpeta();
		Carpeta(const Carpeta &);
		Carpeta(const DataCarpeta &);

		//Destructor
		~Carpeta();


		list<DataErrores> controlarNombreRecurso();
		bool existeNombre();
};
#endif