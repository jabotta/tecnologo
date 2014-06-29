#ifndef MANEJADORRECURSOS_H
#define MANEJADORRECURSOS_H
#include "Archivo.h"
#include "Carpeta.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorRecursos {
	private:
		static ManejadorRecursos * instance;
		map<string, Recurso*> recursos;
		ManejadorRecursos();
		
	public:
		static ManejadorRecursos * getInstance();
		~ManejadorRecursos();

		void ingresarRecurso(Recurso*);
		list<Recurso*> listarRecursos();
		list<Carpeta*> listarCarpetas();
		Carpeta* elegirCarpeta(string);
		list<Archivo*> listarArchivos();
		Archivo* elegirArchivo(string);
};
#endif