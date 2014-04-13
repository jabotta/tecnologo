#include <iostream>
#include "DateTime.h"
#include <limits>

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

bool esBiciesto(int anio){
	//calculo del anio biciesto segun algoritmo
	return (anio % 4 == 0 && ( anio % 100 != 0  || anio % 400 == 0 ));
}

int obtenerMaximoDiaDelMes(int mes, int anio){
	
	if(mes == 2)
		return (esBiciesto(anio)) ? 29 : 28;
	else{
		if(mes<8)
			return (mes % 2 == 0) ? 30 : 31;
		else
			return (mes % 2 == 0) ? 31 : 30;
	}
}

int ingresarValor(int tipo, int mes, int anio){
	bool res = false;
	int val;
	while(!res){
		val = ingresarNumerico();
		if(tipo == 1){//Tipo Anio
			if(val >= 0 && val < 10000){
				res = true;
			}else{
				cout << "Anio invalido. Ingrese Anio: ";
			}
		}else if(tipo == 2){//Tipo Mes
			if(val >= 1 && val <= 12){
				res = true;
			}else{
				cout << "Mes invalido. Ingrese Mes: ";
			}
		}else if(tipo == 3){//Tipo Dia
			if(val >= 1 && val <= obtenerMaximoDiaDelMes(mes, anio)){
				res = true;
			}else{
				cout << "Dia invalido. Ingrese Dia: ";
			}
		}else if(tipo == 4){//Tipo Hora
			if(val >= 0 && val < 24){
				res = true;
			}else{
				cout << "Hora invalido. Ingrese Hora: ";
			}
		}else if(tipo == 5){//Tipo Minuto
			if(val >= 0 && val < 60){
				res = true;
			}else{
				cout << "Minuto invalido. Ingrese Minuto: ";
			}
		}
	}
	return val;
}
int ingresarValor(int tipo){
	return ingresarValor(tipo, 0, 0);
}

void createDateTimes(DateTime& d, const char* c){	
	int dato;
	cout << "Crear DateTime : " << c << endl;	
	cout << "Insertar Anio: ";
	dato = ingresarValor(1);
	d.setAnio(dato);
	cout << "Insertar Mes: ";
	dato = ingresarValor(2);
	d.setMes(dato);
	cout << "Insertar Dia: ";
	dato = ingresarValor(3,d.getMes(),d.getAnio());
	d.setDia(dato);
	cout << "Insertar Hora: ";
	dato = ingresarValor(4);
	d.setHora(dato);
	cout << "Insertar Minuto: ";
	dato = ingresarValor(5);
	d.setMinuto(dato);
	cout << "la fecha es : " << d;
}

void ordenarLista(){
	cout<<"Ingresar lista de DateTimes"<<endl;
	DateTime temp;
	DateTime *tests = new DateTime[4];
	 for(int i = 0; i < 4; i++) {
		createDateTimes(temp," ");
		tests[i] = (temp);
		cout<<endl;
	}
	//Casteo dinamico a lista de comparables
    Comparable *a[4];
    for(int i = 0; i < 4; i++) {
        a[i] = dynamic_cast<Comparable *>(&tests[i]);
    }
    //Llama a ordenar 
	tests[0].ordenar(a, 4);

	//imprime lista ordenada
	cout<< "Lista Ordenada : "<<endl;
	for(int i = 0; i < 4; i++){
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
		cout << " 0) Resta DateTime - DateTime (-)" << endl;
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
		cout << "11) Ordenar Lista de DatTimes" << endl;
		cout << "12) SALIR" << endl;
		cout << "***************************" << endl << endl;
		cout << "INGRESE LA OPCION DESEADA: ";

		opcion = ingresarNumerico();
		switch(opcion){
			/************************************************************************************/
			case 0:{
				//Suma 
				createDateTimes(a,"A");
				createDateTimes(b,"B");
				cout<<"A es:"<<a;
				cout<<"B es:"<<b;
				cout << "La diferencia A - B  " << (a - b)<<endl;
				cout<<endl;
				break;
			}
			case 1:{
				//Suma 
				createDateTimes(a,"A");
				cout << "inserte Numero: ";
				sumando = ingresarNumerico();
				cout << "La nueva fecha es: " << (a + sumando);
				break;
			}
			/************************************************************************************/
			case 2:{
				//Resta
				createDateTimes(a,"A");
				cout << "inserte Numero: ";
				sumando = ingresarNumerico();
				cout << "La nueva fecha es: " << (a - sumando);
		 
				break;
			}
			/***********************createDateTimes(a,"a");*************************************************************/
			case 3:{
				//asignacion
				createDateTimes(a,"A");
				cout << "Asignamos 'A' a 'B'" << endl;
				b = a;
				cout << "Imprimimos B: " << b << endl;
				break;
			}
			/**********************************************************************************/
			case 4:{
				//Comparacion (==)

				createDateTimes(a,"A");
				createDateTimes(b,"B");
				cout<<" A == B " << ((a == b) == 0 ? "false" : "true") << endl;
				break;
			}
			/************************************************************************************/
			case 5:{
				//Comparacion (!=)
				createDateTimes(a,"a");
				createDateTimes(b,"b");
				cout<<" a!=b " << ((a != b) == 0 ? "false" : "true") << endl;
				break;
			}
			/************************************************************************************/

			case 6:{
				//Comparacion (<)
				createDateTimes(a,"A");
				createDateTimes(b,"B");
				cout << " A < B " << ((a < b) == 0 ? "false" : "true") << endl;
				break;
			}
			/************************************************************************************/

			case 7:{
				//Comparacion (>)
				createDateTimes(a,"A");
				createDateTimes(b,"B");
				cout << " A > B " << ((a > b) == 0 ? "false" : "true") << endl;
				break;
			}
			/************************************************************************************/
			case 8:{
				//Comparacion (>=) 
				createDateTimes(a,"A");
				createDateTimes(b,"B");
				cout << " A >= B " <<((a >= b) == 0 ? "false" : "true") << endl;
				break;
			}
			/************************************************************************************/
			case 9:{
				//Comparacion (<=)
				createDateTimes(a,"A");
				createDateTimes(b,"B");
				cout << " A <= B " << ((a <= b) == 0 ? "false" : "true") << endl;
				break;
			}
			/************************************************************************************/
			case 10:{
				//Crear por copia
				createDateTimes(a,"A");
				cout << "Creamos B por copia de A" << endl;
				DateTime b(a);
				cout<< "Imprimimos B: " << b << endl;
				break;
			}
			/************************************************************************************/
			case 11:{
				ordenarLista();			
				break;
			}
			/************************************************************************************/
			case 12:{
				cout << "Saliendo..." << endl;
				break;
			}
			default: cout << "Opción Invalida, vuelva a intentarlo!" << endl;
		}
	}while(opcion != 12);

	return 0;
}