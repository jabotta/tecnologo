#ifndef IRECURSOCONTROLADOR_H
#define	IRECURSOCONTROLADOR_H
#include <iostream>
#include <string>
#include <list>
#include "DataCarpeta.h"
#include "DataErrores.h"
#include "DataArchivo.h"
#include "DataComentario.h"
#include "DataRecurso.h"
#include "Carpeta.h"

class IRecursoControlador{
	public:
		virtual list<DataCarpeta> listarCarpetasPorUsuario() = 0 ;
		virtual void agregarColaborador(Carpeta*) = 0 ;
		virtual void ingresarRecurso(DataRecurso recurso,string tipo ) = 0 ;
		virtual void controlDeErrores() = 0 ;
	 	virtual void guardarRecurso() = 0 ;
		virtual list<DataErrores> imprimirErroresGenerados() = 0;
		virtual list<DataCarpeta> listarCarpetas() = 0 ;
		virtual list<DataArchivo> listarArchivos() = 0 ;
		virtual void elegirCarpeta(string path) = 0 ;
		virtual void elegirArchivo(string path) = 0 ;
		virtual void elegirUsuario(string nickname) = 0 ;
		virtual list<DataComentario> listarComentariosPorArchivo() = 0 ;
		virtual void guardarComentario(string contenido, int parent, int comentarioId) = 0 ;
		virtual int getId() = 0;
		virtual Carpeta* getCarpetaElegida()const = 0;
		virtual Usuario* getUsuarioElegido()const = 0;
};
#endif