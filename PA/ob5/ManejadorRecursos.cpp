#include "ManejadorRecursos.h"

ManejadorRecursos * ManejadorRecursos::instance = NULL;

ManejadorRecursos::ManejadorRecursos(){

}

ManejadorRecursos * ManejadorRecursos::getInstance(){
	if (ManejadorRecursos::instance == NULL){
		ManejadorRecursos::instance = new ManejadorRecursos();
	}
	return ManejadorRecursos::instance;
}

ManejadorRecursos::~ManejadorRecursos(){
	// delete lista de usuarios antes de borrar
}

void ManejadorRecursos::ingresarRecurso(Recurso* r){
	recursos.insert(pair<string, Recurso*>(r->getPath(),r));
}

list<Recurso*> ManejadorRecursos::listarRecursos(){
	list<Recurso*> r;
	for (map<string, Recurso*>::iterator it = recursos.begin(); it != recursos.end(); ++it){
		r.push_back(it->second);
	}	
	return r;
}

list<Carpeta*> ManejadorRecursos::listarCarpetas(string loc){
 
	list<Carpeta*> c;
	
	for (map<string, Recurso*>::iterator it = recursos.begin(); it != recursos.end(); ++it){
		Recurso* r = it->second;
		Carpeta* newc = dynamic_cast<Carpeta*>(r);
	
		if(newc != 0){
			c.push_back(newc);
		}
	}
	return c;
}

Carpeta* ManejadorRecursos::elegirCarpeta(string key){
 	if(recursos.count(key) > 0){ 
	 	map<string, Recurso*>::iterator it = recursos.find(key);
		Recurso* r = it->second;
		Carpeta* newc = dynamic_cast<Carpeta*>(r);
		if(newc != 0){
	 		return newc;
		}	
	}
	return NULL;
}

list<Archivo*> ManejadorRecursos::listarArchivos(string loc){
	list<Archivo*> c;
	for (map<string, Recurso*>::iterator it = recursos.begin(); it != recursos.end(); ++it){
		Recurso* r = it->second;
		Archivo* newa = dynamic_cast<Archivo*>(r);
		if(newa != 0){
			c.push_back(newa);
		}
	}	
	return c;
}

Archivo* ManejadorRecursos::elegirArchivo(string key){
	if(recursos.count(key) > 0){
		map<string, Recurso*>::iterator it = recursos.find(key);
		Recurso* r = it->second;
		Archivo* newa = dynamic_cast<Archivo*>(r);
		if(newa != 0){
			return newa;
		}	
	}
	return NULL;
}
