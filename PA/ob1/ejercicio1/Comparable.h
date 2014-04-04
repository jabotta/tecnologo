#ifndef COMPARABLE__
#define COMPARABLE__
#include <iostream>
#include <stdio.h>

class Comparable {
	 
	public:
		void ordenar(Comparable[]);
		virtual int comparar(Comparable&) = 0;
};
#endif