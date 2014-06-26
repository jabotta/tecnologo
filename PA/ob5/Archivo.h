#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <iostream>
#include <list>
#include "Recurso.h"
#include "DataArchivo.h"
#include "DataErrores.h"
#include "Colaboradores.h"
class Archivo :public Recurso{
	
	private:
		list<Colaboradores> listaColaboradores;
		list<Recurso> listaRecursos;
	public:
		Archivo();
		Archivo(const Archivo &);
		Archivo(const DataArchivo &);
		~Archivo();


		list<DataErrores> controlarNombreRecurso();
		bool existeNombre();
		list<Recurso> getListaRecursos();
		list<Colaboradores> getListaColaboradores();
};

#endif