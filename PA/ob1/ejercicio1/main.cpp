#include <iostream>
#include "DateTime.h"
#include <limits>
#include <stdexcept>

using namespace std;

int ingresarNumerico(){
	int res;
	cin >> res;
	while(cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Valor incorrecto.  Ingrese un numero: ";
		cin >> res;
	}
	return res;
}

double ingresarDouble(){
	double res;
	cin >> res;
	while(cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Valor incorrecto.  Ingrese un numero: ";
		cin >> res;
	}
	return res;
}

int ingresarValor(){
	bool res = false;
	int val;
	while(!res){
		val = ingresarNumerico();
		res = true;		
	}
	return val;
}

void createDateTimes(DateTime& d, const char* c){
	int dato;
	cout << "Crear DateTime : " << c << endl;	
	cout << "Insertar Anio: ";
	dato = ingresarValor();
	d.setAnio(dato);
	cout << "Insertar Mes: ";
	dato = ingresarValor();
	d.setMes(dato);
	cout << "Insertar Dia: ";
	dato = ingresarValor();
	d.setDia(dato);
	cout << "Insertar Hora: ";
	dato = ingresarValor();
	d.setHora(dato);
	cout << "Insertar Minuto: ";
	dato = ingresarValor();
	d.setMinuto(dato);
	cout << "la fecha es : " << d;	
}

void ordenarLista(){
	int largo;
	cout << "Ingrese el largo: ";
	largo = ingresarNumerico();

	cout << "Ingresar lista de DateTimes" << endl;
	DateTime temp;
	DateTime *tests = new DateTime[largo];
	 for(int i = 0; i < largo; i++) {
		createDateTimes(temp," ");
		tests[i] = (temp);
		cout<<endl;
	}

	//Casteo dinamico a lista de comparables
    Comparable *a[largo];
    for(int i = 0; i < largo; i++) {
        a[i] = dynamic_cast<Comparable *>(&tests[i]);
    }

    //Llama a ordenar 
	tests[0].ordenar(a, largo);

	//imprime lista ordenada
	cout << "Lista Ordenada : " << endl;
	for(int i = 0; i < largo; i++){
       DateTime::printComp(a[i]);
    }  
}

int main(){

	int opcion;
	double sumando;

	DateTime a;
	DateTime b;

	do{
		cout << "***************************" << endl;		
		cout << " 1) Suma DateTime + double" << endl;
		cout << " 2) Resta DateTime - double" << endl;
		cout << " 3) Resta DateTime - DateTime" << endl;
		cout << " 4) Asignacion (=)" << endl;
		cout << " 5) Comparacion (==)" << endl;
		cout << " 6) Comparacion (!=)" << endl;
		cout << " 7) Comparacion (<)" << endl;
		cout << " 8) Comparacion (>)" << endl;
		cout << " 9) Comparacion (>=)" << endl;
		cout << "10) Comparacion (<=)" << endl;
		cout << "11) Crear DateTime con fecha del sistema" << endl;
		cout << "12) Crear DateTime por Copia" << endl;
		cout << "13) Ordenar lista de DatTimes" << endl;
		cout << "14) SALIR" << endl;
		cout << "***************************" << endl << endl;
		cout << "INGRESE LA OPCION DESEADA: ";

		opcion = ingresarNumerico();
		switch(opcion){
			/************************************************************************************/			
			case 1:{
				//Suma de double
				try{
					cout << "Suma DateTime + double" << endl;
					createDateTimes(a,"A");
					cout << "inserte Numero: ";
					sumando = ingresarDouble();
					cout << "La nueva fecha es: " << (a + sumando);					
				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/************************************************************************************/
			case 2:{
				//Resta de double
				try{
					cout << "Resta DateTime - double" << endl;
					createDateTimes(a,"A");
					cout << "inserte Numero: ";
					sumando = ingresarDouble();
					cout << "La nueva fecha es: " << (a - sumando);
		 		}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/************************************************************************************/
			case 3:{
				//Resta de 2 DateTime 
				try{
					cout << "Resta DateTime - double" << endl;
					createDateTimes(a,"A");
					createDateTimes(b,"B");
					cout << "A es:"<< a;
					cout << "B es:"<< b;
					cout << "La diferencia A - B  " << (a - b) << endl;
					cout << endl;
				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/************************************************************************************/
			case 4:{
				//asignacion
				try{
					cout << "Asignacion (=)" << endl;
					createDateTimes(a,"A");
					cout << "Asignamos A a B" << endl;
					b = a;
					cout << "B: " << b << endl;
				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/**********************************************************************************/
			case 5:{
				//Comparacion (==)
				try{
					cout << "Comparacion (==)" << endl;
					createDateTimes(a,"A");
					createDateTimes(b,"B");
					cout << " A == B " << ((a == b) == 0 ? "false" : "true") << endl;
				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/************************************************************************************/
			case 6:{
				//Comparacion (!=)
				try{
					cout << "Comparacion (!=)" << endl;
					createDateTimes(a,"a");
					createDateTimes(b,"b");
					cout<< " A != B " << ((a != b) == 0 ? "false" : "true") << endl;
				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/************************************************************************************/
			case 7:{
				//Comparacion (<)
				try{
					cout << "Comparacion (<)" << endl;
					createDateTimes(a,"A");
					createDateTimes(b,"B");
					cout << " A < B " << ((a < b) == 0 ? "false" : "true") << endl;
				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/************************************************************************************/
			case 8:{
				//Comparacion (>)
				try{
					cout << "Comparacion (>)" << endl;
					createDateTimes(a,"A");
					createDateTimes(b,"B");
					cout << " A > B " << ((a > b) == 0 ? "false" : "true") << endl;
				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/************************************************************************************/
			case 9:{
				//Comparacion (>=) 
				try{
					cout << "Comparacion (>=)" << endl;
					createDateTimes(a,"A");
					createDateTimes(b,"B");
					cout << " A >= B " <<((a >= b) == 0 ? "false" : "true") << endl;
				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/************************************************************************************/
			case 10:{
				//Comparacion (<=)
				try{
					cout << "Comparacion (<=)" << endl;
					createDateTimes(a,"A");
					createDateTimes(b,"B");
					cout << " A <= B " << ((a <= b) == 0 ? "false" : "true") << endl;
				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/************************************************************************************/
			case 11:{
				//Crear con fecha y hora del sistema
				try{
					cout << "Crear DateTime con fecha del sistema" << endl;
					DateTime a;
					cout << "A: " << a << endl;
				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/************************************************************************************/
			case 12:{
				//Crear por copia
				try{
					cout << "Crear DateTime por copia" << endl;
					createDateTimes(a,"A");
					cout << "Creamos B por copia de A" << endl;
					DateTime b(a);
					cout << "B: " << b << endl;
				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/************************************************************************************/
			case 13:{
				try{
					cout << "Ordenar lista de DatTimes" << endl;
					ordenarLista();	
				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}		
				break;
			}
			/************************************************************************************/
			case 14:{
				cout << "Saliendo..." << endl;
				break;
			}
			default: cout << "Opción Invalida, vuelva a intentarlo!" << endl;
		}
	}while(opcion != 14);

	return 0;
}