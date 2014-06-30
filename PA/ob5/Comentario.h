#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <iostream>
#include <string>
#include "Usuario.h"
#include "Archivo.h"
#include "DataComentario.h"

using namespace std;

class Comentario {
	private:
		int codigo;
		string contenido;
		Usuario* usuario;
		Archivo* archivo;
		Comentario* parent;

	public:
		//Constructores
		Comentario();
		Comentario(const Comentario&);
		
		//Destructor
		~Comentario();

		//Selectores
		int getCodigo() const;
		string getContenido() const;
		Usuario* getUsuario() const;
		Archivo* getArchivo() const;
		Comentario* getParent() const;

		//Modificadores
		void setCodigo(int);
		void setContenido(string);
		void setUsuario(Usuario*);
		void setArchivo(Archivo*);
		void setParent(Comentario*);
};
#endif