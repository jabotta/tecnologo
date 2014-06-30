#ifndef DATACOMENTARIO_H
#define DATACOMENTARIO_H
#include <iostream>
#include <string>
#include "DataUsuario.h"
#include "DataArchivo.h"

using namespace std;

class DataComentario {
	private:
		int codigo;
		string contenido;
		DataUsuario usuario;
		DataArchivo archivo;

	public:
		//Constructores
		DataComentario();
		DataComentario(const DataComentario&);
		DataComentario(int, string, DataUsuario, DataArchivo);

		//Destructor
		~DataComentario();

		//Selectores
		int getCodigo() const;
		string getContenido() const;
		DataUsuario getUsuario() const;
		DataArchivo getArchivo() const;

		//Modificadores
		void setCodigo(int);
		void setContenido(string);
		void setUsuario(DataUsuario);
		void setArchivo(DataArchivo);
};
#endif