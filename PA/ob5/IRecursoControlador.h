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
		virtual void agregarColaborador() = 0 ;
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
		virtual void accionSobreComentario(string acc) = 0 ;
		virtual void agregarComentario(string comentario) = 0 ;
		virtual void responderComentario(string c,int id ) = 0 ;
		virtual int getId() = 0;
		virtual Carpeta* getCarpetaElegida()const = 0;
};
#endif