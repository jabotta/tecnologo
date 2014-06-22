#ifndef DATAUSUARIO_H
#define DATAUSUARIO_H
#include <string.h>
#include "Datetime.h"

class DataUsuario{
	private:
		string nickname;
		string nombre
		string sexo;
		int edad;
		Datetime fechaNac;

	public:
		// Constructores	   
	   	DataUsuario(); //por defecto
		DataUsuario(string, string, string, int, DateTime); // por parametro
		DataUsuario(DataUSuario &); // por copia
		
		// Destructor
		~DataUsuario();
		 
		// Selectores
		int getNickname() const;
		int getNombre() const;
		int getSexo() const;
		int getEdad() const;
		int getFechaNac() const;
		
		// Modificadores
		void setNickname(string);
		void setNombre(string);
		void setSexo(string);
		void setEdad(int);
		void setFechaNac(Datetime);

};
#endif
