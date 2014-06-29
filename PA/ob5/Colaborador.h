#ifndef COLABORADOR_H
#define COLABORADOR_H
#include <iostream>
#include <string>
#include "DateTime.h"
#include "Carpeta.h"
#include "Usuario.h"

using namespace std;

class Colaborador {
	private:
		DateTime fechaIngreso;
		Carpeta* carpeta;
		Usuario* usuario;
		
	public:
		//Constructores
		Colaborador();
		Colaborador(const Colaborador&);
		Colaborador(DateTime, Carpeta*);

		//Destructor
		~Colaborador();

		//Selectores
		DateTime getFechaIngreso() const;
		Carpeta* getCarpeta() const;
		Usuario* getUsuario() const;

		//Modificadores
		void setFechaIngreso(DateTime);
		void setCarpeta(Carpeta*);
		void setUsuario(Usuario*);
};
#endif