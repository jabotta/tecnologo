#ifndef DATAERRORES_H 
#define DATAERRORES_H
#include <iostream>
#include <string>

using namespace std;

class DataErrores{
	private:
		int codigo;
		string mensaje;

	public:
		// Constructores	   
	   	DataErrores(); //por defecto
		DataErrores(int, string); // por parametro
		DataErrores(const DataErrores&); // por copia
		
		// Destructor
		~DataErrores();
		 
		// Selectores
		int getCodigo() const;
		string getMensaje() const;

		
		// Modificadores
		void setCodigo(int);
		void setMensaje(string);	
};
	ostream& operator<<(ostream& ,const DataErrores&);
#endif