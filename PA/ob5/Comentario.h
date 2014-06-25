#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <iostream>
#include <string>
#include "Usuario.h"
#include "Archivo.h"

using namespace std;

class Comentario {
	private:
		int codigo;
		string contenido;
		Usuario* usuario;
		Archivo* archivo;
	public:
		//Constructores
		Comentario();
		Comentario(const Comentario&);
		Comentario(int, string, Usuario*, Archivo*);
		//Destructor
		~Comentario();
		//Selectores
		int getCodigo() const;
		string getContenido() const;
		Usuario* getUsuario() const;
		Archivo* getArchivo() const;
		//Modificadores
		void setCodigo(int);
		void setContenido(string);
		void setUsuario(Usuario*);
		void setArchivo(Archivo*);


};
#endif