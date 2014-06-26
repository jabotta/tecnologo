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
		virtual ~DataRecurso();

		//Selectores
		virtual string getNombre() const = 0;
		virtual DataUsuario getUsuarioCreo() const = 0;
		virtual string getDescripcion() const = 0;
		virtual DateTime getFechaUltimoAcceso() const = 0;
		virtual DateTime getFechaCreacion() const = 0;
		virtual string getUbicacion() const = 0;

		//Modificadores
		virtual void setNombre(string) = 0;
		virtual void getUsuarioCreo(DataUsuario) = 0;
		virtual void getDescripcion(string) = 0;
		virtual void getFechaUltimoAcceso(DateTime) = 0;
		virtual void getFechaCreacion(DateTime) = 0;
		virtual void getUbicacion(string) = 0;
};
#endif