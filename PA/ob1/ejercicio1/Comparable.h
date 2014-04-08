#ifndef COMPARABLE_H
#define COMPARABLE_H

class Comparable {	 
	public:
		virtual int comparar(Comparable*) = 0;
		void ordenar(Comparable**, int largo);		
};

#endif
