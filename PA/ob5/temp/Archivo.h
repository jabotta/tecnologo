#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "Recurso.h"
#include "DataArchivo.h"
#include "DataErrores.h"
#include "Colaboradores.h"
class Archivo :public Recurso{
	
	private:
		Set(Colaboradores) listaColaboradores;
		Set(Recurso) listaRecursos;
	public:
		Archivo();
		Archivo(Archivo &);
		Archivo(DataArchivo &);
		~Archivo();


		Set(DataErrores) controlarNombreRecurso();
		bool existeNombre();
		Set(Recurso) getListaRecursos();
		Set(Colaboradores) getListaColaboradores();

};

#endif