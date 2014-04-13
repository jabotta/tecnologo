#include <iostream>
#include "DateTime.h"

using namespace std;

void createDateTimes(DateTime& d, const char* c){	
	int dato;
	cout << "Crear DateTime : " << c << endl;	
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
	cout << "la fecha es : " << d;
}
int main(){

	// DateTime tests[4];
	// for(int i = 0; i < 4; i++) {
	// 	DateTime aux(2000,i+1,1,1,1);     
	// 	tests[i] = aux;
 //    } 
 //    for(int i = 0; i < 4; i++){
 //    	cout << tests[i] << endl; 
	// } 

	DateTime *tests = new DateTime[4];
	tests[0] = *(new DateTime(2000,1,1,1,1));
	tests[1] = *(new DateTime(2002,1,1,1,1));
	tests[2] = *(new DateTime(2001,1,1,1,1));
	tests[3] = *(new DateTime(2005,1,1,1,1));
	for(int i = 0; i < 4; i++) {
	//	cout << tests[i] << endl;
    }
    /////////////////////////////////////////ESTO ES PARA PROBAR LA FUNCION DE COMPARAR SIN PASAR POR COMPARABLE////////////////////////////////////////////////
    //int rlst = tests[0].comparar(&tests[3]);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    ////////////////////////////////////////////////////////////////////////ESTO ES PARA PROBAR ORDENAR////////////////////////////////////////////////////////
    Comparable *a[4];
    for(int i = 0; i < 4; i++) {
        a[i] = dynamic_cast<Comparable *>(&tests[i]);
    }
    cout << "PRint ORDER:" << endl;
	tests[0].ordenar(a, 4);
	for(int i = 0; i < 4; i++){
        //cout << a[i] << endl; 
    } 
	for(int i = 0; i < 4; i++) {
        tests[i] = *(dynamic_cast<DateTime *>(a[i]));
        cout << tests[i] << endl;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// int opcion;
	// double sumando;

	// DateTime a;
	// DateTime b;

	// do{
	// 	cout << "***************************" << endl;
	// 	cout << " 0) Resta DateTime - DateTime (-)" << endl;
	// 	cout << " 1) Suma" << endl;
	// 	cout << " 2) Resta" << endl;
	// 	cout << " 3) Asignacion (=)" << endl;
	// 	cout << " 4) Comparacion (==)" << endl;
	// 	cout << " 5) Comparacion (!=)" << endl;
	// 	cout << " 6) Comparacion (<)" << endl;
	// 	cout << " 7) Comparacion (>)" << endl;
	// 	cout << " 8) Comparacion (>=)" << endl;
	// 	cout << " 9) Comparacion (<=)" << endl;
	// 	cout << "10) Crear DateTime por Copia" << endl;
	// 	cout << "11) SALIR" << endl;
	// 	cout << "***************************" << endl << endl;
	// 	cout << "INGRESE LA OPCION DESEADA: ";
		
	// 	cin >> opcion; 
		
	// 	switch(opcion){
	// 		/************************************************************************************/
	// 		case 0:{
	// 			//Suma 
	// 			createDateTimes(a,"A");
	// 			createDateTimes(b,"B");
	// 			cout<<"A es:"<<a;
	// 			cout<<"B es:"<<b;
	// 			cout << "La diferencia A - B  " << (a - b)<<endl;
	// 			cout<<endl;
	// 			break;
	// 		}
	// 		case 1:{
	// 			//Suma 
	// 			createDateTimes(a,"A");
	// 			cout << "inserte Numero: ";
	// 			cin >> sumando;
	// 			cout << "La nueva fecha es: " << (a + sumando);
	// 			break;
	// 		}
	// 		/************************************************************************************/
	// 		case 2:{
	// 			//Resta
	// 			createDateTimes(a,"A");
	// 			cout << "inserte Numero: ";
	// 			cin >> sumando;
	// 			cout << "La nueva fecha es: " << (a - sumando);
		 
	// 			break;
	// 		}
	// 		/***********************createDateTimes(a,"a");*************************************************************/
	// 		case 3:{
	// 			//asignacion
	// 			createDateTimes(a,"A");
	// 			cout << "Asignamos 'A' a 'B'" << endl;
	// 			b = a;
	// 			cout << "Imprimimos B: " << b << endl;
	// 			break;
	// 		}
	// 		/**********************************************************************************/
	// 		case 4:{
	// 			//Comparacion (==)

	// 			createDateTimes(a,"A");
	// 			createDateTimes(b,"B");
	// 			cout<<" A == B " << ((a == b) == 0 ? "false" : "true") << endl;
	// 			break;
	// 		}
	// 		/************************************************************************************/
	// 		case 5:{
	// 			//Comparacion (!=)
	// 			createDateTimes(a,"a");
	// 			createDateTimes(b,"b");
	// 			cout<<" a!=b " << ((a != b) == 0 ? "false" : "true") << endl;
	// 			break;
	// 		}
	// 		/************************************************************************************/

	// 		case 6:{
	// 			//Comparacion (<)
	// 			createDateTimes(a,"A");
	// 			createDateTimes(b,"B");
	// 			cout << " A < B " << ((a < b) == 0 ? "false" : "true") << endl;
	// 			break;
	// 		}
	// 		/************************************************************************************/

	// 		case 7:{
	// 			//Comparacion (>)
	// 			createDateTimes(a,"A");
	// 			createDateTimes(b,"B");
	// 			cout << " A > B " << ((a > b) == 0 ? "false" : "true") << endl;
	// 			break;
	// 		}
	// 		/************************************************************************************/
	// 		case 8:{
	// 			//Comparacion (>=) 
	// 			createDateTimes(a,"A");
	// 			createDateTimes(b,"B");
	// 			cout << " A >= B " <<((a >= b) == 0 ? "false" : "true") << endl;
	// 			break;
	// 		}
	// 		/************************************************************************************/
	// 		case 9:{
	// 			//Comparacion (<=)
	// 			createDateTimes(a,"A");
	// 			createDateTimes(b,"B");
	// 			cout << " A <= B " << ((a <= b) == 0 ? "false" : "true") << endl;
	// 			break;
	// 		}
	// 		/************************************************************************************/
	// 		case 10:{
	// 			//Crear por copia
	// 			createDateTimes(a,"A");
	// 			cout << "Creamos B por copia de A" << endl;
	// 			DateTime b(a);
	// 			cout<< "Imprimimos B: " << b << endl;
	// 			break;
	// 		}
	// 		/************************************************************************************/
	// 		case 11: 

	// 			break;
	// 		/************************************************************************************/
	// 		default: cout << "Opción Invalida, vuelva a intentarlo!" << endl;
	// 	}

	// }while(opcion != 11);

	// cout << "Saliendo..." << endl;

	return 0;
}