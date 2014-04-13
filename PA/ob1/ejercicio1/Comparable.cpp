#include <iostream>
#include "Comparable.h"
#include "DateTime.h"
using namespace std;

void Comparable::ordenar(Comparable** c, int largo){	
	Comparable *temp;
	int imin; 	
	for(int i = 0; i <= (largo-2); i++){ 
	    imin=i;
		for(int j = i+1; j <= (largo-1); j++){
			if(c[j]->comparar(c[imin]) < 0){
				imin=j;
			} 
		}
		temp = c[i];  
        c[i] = c[imin]; 
        c[imin] = temp;
	} 		
}; 