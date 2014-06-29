#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <iostream>
#include <list>
#include "Recurso.h"
#include "DataArchivo.h"
#include "DataErrores.h"
#include "Colaborador.h"

class Archivo :public Recurso{
	private:
		list<Colaborador> listaColaboradores;

	public:
		// Constructores
		Archivo();
		Archivo(const Archivo &);
		Archivo(const DataArchivo);

		// Destructor
		~Archivo();

		list<DataErrores> controlarNombreRecurso();
		bool existeNombre(string);
		
		list<Colaborador> getListaColaboradores();
};
#endif