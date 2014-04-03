#include <iostream>
#include "DateTime.h"


using namespace std;


void createDateTimes(DateTime& d){
	
	int dato;
	cout << "************Crear DateTime***************" << endl;
	
	cout << "Insertar Anio: ";
	cin >> dato;
	d.setAnio(dato);
	cout << "Insertar Mes: ";
	cin >> dato;
	d.setMes(dato);
	cout << "Insertar Dia: ";
	cin >> dato;
	d.setDia(dato);
	cout << "Insertar Hora: ";
	cin >> dato;
	d.setHora(dato);
	cout << "Insertar Minuto: ";
	cin >> dato;
	d.setMinuto(dato);
	cout<<"la fecha es : "<< d<<endl;
}
main(){

	int opcion,sumando;

	DateTime a;
	DateTime b;
	DateTime c;
 
	do{
		cout << "***************************" << endl;
		cout << " 1) Suma" << endl;
		cout << " 2) Resta" << endl;
		cout << " 3) Asignacion (=)" << endl;
		cout << " 4) Comparacion (==)" << endl;
		cout << " 5) Comparacion (!=)" << endl;
		cout << " 6) Comparacion (<)" << endl;
		cout << " 7) Comparacion (>)" << endl;
		cout << " 8) Comparacion (>=)" << endl;
		cout << " 9) Comparacion (<=)" << endl;
		cout << "10) Crear DateTime por Copia" << endl;
		cout << "11) SALIR" << endl;
		cout << "***************************" << endl << endl;
		cout << "INGRESE LA OPCION DESEADA: ";
		
		cin >> opcion;
		cout<<endl;
		
		switch(opcion){
			/************************************************************************************/
			case 1:{
				createDateTimes(a);
				cout<<"inserte double:";
				cin >> sumando;
				cout<< (a + sumando)<<endl;
				break;
			}
			/************************************************************************************/
			case 2:{
				createDateTimes(a);
				cout<<"inserte double:";
				cin >> sumando;
				cout<< (a - sumando)<<endl;
		 
				break;
			}
			/************************************************************************************/
			case 3:{

				break;
			}
			/**********************************************************************************/
			case 4:{
				
				break;
			}
			/************************************************************************************/
			case 5:{
				
				break;
			}
			/************************************************************************************/

			case 6:{
				
				break;
			}
			/************************************************************************************/

			case 7:{
				
				break;
			}
			/************************************************************************************/
			case 8:{
				
				break;
			}
			/************************************************************************************/
			case 9:{
				
				break;
			}
			/************************************************************************************/
			case 10:{
				
				break;
			}
			/************************************************************************************/
			case 11: 

				break;
			/************************************************************************************/
			default: cout << "Opción Invalida, vuelva a intentarlo!" << endl;
		}

	cout << endl << endl;

	}while(opcion != 11);

	cout << "Saliendo..." << endl;

	return 0;
}