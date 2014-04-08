#ifndef COMPARABLE_H
#define COMPARABLE_H
#include <iostream>
#include <stdio.h>

class Comparable {	 
	public:
		virtual int comparar(Comparable*) = 0;
		void ordenar(Comparable **);		
};

#endif
