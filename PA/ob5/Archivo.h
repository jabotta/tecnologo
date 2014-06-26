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
		list<Recurso> listaRecursos;
	public:
		Archivo();
		Archivo(const Archivo &);
		Archivo(const DataArchivo &);
		~Archivo();


		list<DataErrores> controlarNombreRecurso();
		bool existeNombre();
		list<Recurso> getListaRecursos();
		list<Colaborador> getListaColaboradores();
};

#endif