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

class  RecursoControlador: public IRecursoControlador{
	
private:
	string accionTipo;
	Comentario nuevoComantario;
	Comentario padreComentario;
	Carpeta carpetaElegida;
	Archivo archivoElegido;
	Colaborador colaboradorCreado;
	list<DataErrores> errores;
	list<Recurso> recursosLista;
	Usuario usuarioElegido;
	Usuario usuarioColaborador;
	bool existen;
	int id;
public:

	RecursoControlador();
	RecursoControlador(int);
	RecursoControlador(const RecursoControlador&);
	~RecursoControlador();

	list<DataCarpeta> ListarCarpetasPorUsuario();
	void agregarColaborador();
	//void ingresarRecurso(DataRecurso recurso,string tipo );
	void controlDeErrores();
	void guardarRecurso();
	list<DataErrores> imprimirErroresGenerados();
	list<DataCarpeta> ListarCarpetas();
	void elegirCarpeta(string path);
	list<DataArchivo> ListarArchivos();
	void elegirArchivo(string path);
	//list<DataComentario> listarComentario();
	void accionSobreComentario(string acc);
	void agregarComentario(string comentario);
	void responderComentario(string c,int id );


	string getAccionTipo()const;
	Comentario getNuevoComantario()const;
	Comentario getPadreComentario()const;
	Carpeta getCarpetaElegida()const;
	Archivo getArchivoElegido()const;
	Colaborador getColaboradorCreado()const;
	list<DataErrores> getErrores()const;
	//list<Recurso> getRecursosLista()const;
	Usuario getUsuarioElegido()const;
	Usuario getUsuarioColaborador()const;

	void setAccionTipo (string);
	void setNuevoComantario (Comentario);
	void setPadreComentario (Comentario);
	void setCarpetaElegida (Carpeta);
	void setArchivoElegido (Archivo);
	void setColaboradorCreado(Colaborador);
	void setErrores(list<DataErrores> );
	//void setRecursosLista(list<Recurso>);
	void setUsuarioElegido(Usuario&);
	void setUsuarioColaborador(Usuario&);
	void setExisten(bool);
	int getId();

};
#endif