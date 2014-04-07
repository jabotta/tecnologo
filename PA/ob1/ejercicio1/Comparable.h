#ifndef COMPARABLE__
#define COMPARABLE__
#include <iostream>
#include <stdio.h>

class Comparable {
	 
	public:
		virtual int comparar(Comparable& c) = 0;
		void ordenar(Comparable** a[]);		
};
#endif
