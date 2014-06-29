#ifndef RECURSOCONTROLADOR_H
#define RECURSOCONTROLADOR_H
#include <iostream>
#include <string>
#include "IRecursoControlador.h"
#include "Comentario.h"
#include "Recurso.h"
#include "Carpeta.h"
#include "Archivo.h"
#include "Colaborador.h"	
#include "Usuario.h"
#include "DataRecurso.h"
#include "ManejadorRecursos.h"
#include "ManejadorUsuario.h"
//#include "DataComentario.h"

class  RecursoControlador: public IRecursoControlador{
	private:
		DataRecurso recursoNuevo;
		string accionTipo;
		Comentario nuevoComentario;
		Comentario padreComentario;
		Carpeta* carpetaElegida;
		Archivo* archivoElegido;
		Colaborador colaboradorCreado;
		list<DataErrores> errores;
		list<Recurso> recursosLista;
		Usuario* usuarioElegido;
		Usuario* usuarioColaborador;
		string tiporec;
		DataCarpeta dataCarpeta;
		DataArchivo dataArchivo;
		bool existen;
		int id;

	public:
		// Constructores
		RecursoControlador();
		RecursoControlador(int);
		RecursoControlador(const RecursoControlador&);
		
		// Destructor
		~RecursoControlador();

		list<DataCarpeta> listarCarpetasPorUsuario();
		void agregarColaborador();
		void ingresarRecurso(DataRecurso recurso,string tipo );
		void controlDeErrores();
		void guardarRecurso();
		list<DataErrores> imprimirErroresGenerados();
		list<DataCarpeta> listarCarpetas();
		void elegirCarpeta(string path);
		list<DataArchivo> listarArchivos();
		void elegirArchivo(string path);
		//list<DataComentario> listarComentario();
		void accionSobreComentario(string acc);
		void agregarComentario(string comentario);
		void responderComentario(string c,int id );
		void elegirUsuario(string);
		
		string getAccionTipo()const;
		Comentario getNuevoComentario()const;
		Comentario getPadreComentario()const;
		Carpeta* getCarpetaElegida()const;
		Archivo* getArchivoElegido()const;
		Colaborador getColaboradorCreado()const;
		list<DataErrores> getErrores()const;
		list<Recurso> getRecursosLista()const;
		DataRecurso getRecursoNuevo()const;
		Usuario* getUsuarioElegido()const;
		Usuario* getUsuarioColaborador()const;

		void setAccionTipo (string);
		void setNuevoComentario (Comentario);
		void setPadreComentario (Comentario);
		void setCarpetaElegida (Carpeta*);
		void setArchivoElegido (Archivo*);
		void setColaboradorCreado(Colaborador);
		void setErrores(list<DataErrores> );
		void setRecursoNuevo(DataRecurso);
		void setRecursosLista(list<Recurso>);
		void setUsuarioElegido(Usuario *);
		void setUsuarioColaborador(Usuario*);
		void setExisten(bool);
		int getId();
};
#endif