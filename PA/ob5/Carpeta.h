#ifndef CARPETA_H
#define CARPETA_H
#include "Recurso.h"
#include "DataCarpeta.h"
#include "DataErrores.h"
class  Carpeta: public Recurso{


	public:
		//Constructores
		Carpeta();
		Carpeta(Carpeta &);
		Carpeta(DataCarpeta);

		//Destructor
		~Carpeta();


		Set(DataErrores) controlarNombreRecurso();
		bool existeNombre();







};
#endif