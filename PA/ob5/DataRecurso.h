#ifndef DATARECURSO_H 
#define DATARECURSO_H
#include <iostream>
#include <string>
#include "DataUsuario.h"
#include "DateTime.h"

using namespace std;

class DataRecurso{
	private:
		string nombre;
		DataUsuario usuarioCreo;
		string descripcion;
		DateTime fechaUltimoAcceso;
		DateTime fechaCreacion;
		string ubicacion;
		
	public:
		//Destructor
		DataRecurso();
		DataRecurso(const DataRecurso&);
		~DataRecurso();

		//Selectores
		string getNombre() const ;
		DataUsuario getUsuarioCreo() const ;
		string getDescripcion() const ;
		DateTime getFechaUltimoAcceso() const ;
		DateTime getFechaCreacion() const ;
		string getUbicacion() const ;

		//Modificadores
		void setNombre(string) ;
		void setUsuarioCreo(DataUsuario) ;
		void setDescripcion(string) ;
		void setFechaUltimoAcceso(DateTime) ;
		void setFechaCreacion(DateTime) ;
		void setUbicacion(string) ;
};
	std::ostream& operator<< (std::ostream& stream, const DataRecurso&);
#endif