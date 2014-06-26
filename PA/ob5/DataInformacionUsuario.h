#ifndef DATAINFORMACIONUSUARIO_H
#define DATAINFORMACIONUSUARIO_H
#include <iostream>
#include <string>
#include <list>
#include "DataUsuario.h"
#include "DataRecurso.h"
#include "DataColaborador.h"
#include "DataAccion.h"

class DataInformacionUsuario{
	private:
		DataUsuario usuario;
		list<DataRecurso> recursos;
		list<DataColaborador> colaboradores;
		list<DataAccion> acciones;

	public:
		// Constructores	   
	   	DataInformacionUsuario(); //por defecto
		DataInformacionUsuario(DataUsuario,list<DataRecurso>,list<DataColaborador>,list<DataAccion>); // por parametro
		DataInformacionUsuario(const DataInformacionUsuario&); // por copia
		
		// Destructor
		~DataInformacionUsuario();
		 
		// Selectores
		DataUsuario getUsuario() const;
		list<DataRecurso> getRecursos() const;
		list<DataColaborador> getColaboradores() const;
		list<DataAccion> getAcciones() const;

		
		// Modificadores
		void setUsuario(DataUsuario);
		void setRecursos(list<DataRecurso>);
		void setColaboradores(list<DataColaborador>);
		void setAcciones(list<DataAccion>);	
};
#endif