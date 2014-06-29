#ifndef MANEJADORCOLABORADOR_H
#define MANEJADORCOLABORADOR_H
#include <map>
#include <list>
#include <string>
#include "Comentario.h"

using namespace std;

class ManejadorComentario {	
	private:
		static ManejadorComentario * instance;
		map<string, Comentario> comentarios;
		ManejadorComentario();
		
	public:
		static ManejadorComentario * getInstance();
		~ManejadorComentario();

		void guardarComentario(Comentario);
		list<Comentario> listarComentarios();
};
#endif