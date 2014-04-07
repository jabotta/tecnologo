#ifndef DATETIME_H
#define DATETIME_H

#include "Comparable.h"
using namespace std;

class DateTime : public Comparable {
	private:
		int y;
		int m;
		int d;
		int h;
		int i;

	public:
		// Constructores	   
	   	DateTime(); //por defecto
		DateTime(int, int, int, int = 00, int = 00); // por parametro
		DateTime(DateTime &); // por copia
		
		// Destructor
		~DateTime();
		 
		// Selectores
		int getAnio() const;
		int getMes() const;
		int getDia() const;
		int getHora() const;
		int getMinuto() const;
		
		// Modificadores
		void setAnio(int);
		void setMes(int);
		void setDia(int);
		void setHora(int);
		void setMinuto(int);
				
		// Operaciones
		bool operator == (DateTime);
		bool operator != (DateTime);
		bool operator < (DateTime);
		bool operator > (DateTime);
		bool operator <= (DateTime);
		bool operator >= (DateTime);
				
	    int obtenerMaximoDiaDelMes(int,int);
		bool esBiciesto(int);
		DateTime operator + (double);
		DateTime& operator = (const DateTime& d);
		DateTime operator - (double);
		double operator - (DateTime);

		//operacion abstracta de Comparable
		int comparar(Comparable&);
	
};
	
	std::ostream& operator<< (std::ostream& stream, const DateTime& );
#endif