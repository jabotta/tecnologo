#include <iostream>
#include "Comparable.h"

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
		cout << i << " "<<c[i] << endl;
        c[i] = c[imin];
        cout << imin << " " << c[i] << endl; 
        c[imin] = temp;
	}

	for(int i = 0; i < largo; i++){
 		//cout << c[i] << endl; 
	} 
}; 