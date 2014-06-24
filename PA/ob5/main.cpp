#include <iostream>
#include <limits>
#include <stdexcept>
#include <stdlib.h>
#include "ManejadorUsuario.h"
#include "Fabrica.h"
#include "DataUsuario.h"
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
bool checkSiCancelo(string s){
	int value = atoi(s.c_str());
	return (value == 1);
}


void altaUsuario(){

	string nickname;
	bool cancelar = false;
	bool existe = true;
	
	while(!cancelar && existe){
		cout<<"Ingrese Nickname o 1 para cancelar:"<<endl;
		cin>>nickname;
		cancelar = checkSiCancelo(nickname);
		if(!cancelar){
			existe = Fabrica::getInstance().getUControlador()->checkeoNickname(nickname);
		}
	}
	if(!cancelar){

		DataUsuario du;
		DateTime dt;
		cin>>du;
		du.setNickname(nickname);
		//Ingresa el usuario en memoria 
		Fabrica::getInstance().getUControlador()->ingresarDatosUsuario(du);
		//Crea y guarda el Usuario 
		Fabrica::getInstance().getUControlador()->guardarUsuario();

 

	}
}


int main(){

	int opcion;

	do{
		cout << "*****************************************" << endl;		
		cout << " 1) Cargar Datos Prueba " << endl;
		cout << " 2) Alta Usuario " << endl;
		cout << " 3) Crear Recurso " << endl;
		cout << " 4) Agregar Colaborador " << endl;
		cout << " 5) Ingresar Comentario " << endl;
		cout << " 6) Ver Informacion de un usuario " << endl;
		cout << " 7) SALIR " << endl;
		cout << "*****************************************" << endl << endl;
		cout << "INGRESE LA OPCION DESEADA: ";
		
		opcion = ingresarNumerico();
		switch(opcion){
			/******************* Cargar Datos Prueba *********************************************/			
			case 1:{
				try{

				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/********************** Alta Usuario ************************************************/
			case 2:{
				
				try{
					altaUsuario();
		 		}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/************************ Crear Recurso ********************************************/
			case 3:{
				try{

				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/***************************** Agregar Colaborador ********************************/
			case 4:{
				try{

				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/******************************* Ingresar Comentario ****************************/
			case 5:{
				try{

				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/*********************** Ver Informacion de un Usuario *************************/
			case 6:{
				try{

				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/************************************************************************************/
			case 7:{
				cout << "Saliendo..." << endl;
				break;
			}
			default: cout << "Opción Invalida, vuelva a intentarlo!" << endl;
		}
	}while(opcion != 7);

	return 0;
}
