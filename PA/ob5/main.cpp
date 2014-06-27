#include <iostream>
#include <limits>
#include <stdexcept>
#include <stdlib.h>
#include "Fabrica.h"

using namespace std;

int idUsuarioControlador,idRecursoControlador;

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
void crearCarpetaRaiz(){
	DataCarpeta dc;
	dc.setNombre("/");
	dc.setDescripcion("Carpeta Raiz");
	dc.setUbicacion("/");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(dc,"carpeta");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();
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
		cout << "Ingrese Nickname o 1 para cancelar:" << endl;
		cin >> nickname;
		cancelar = checkSiCancelo(nickname);
		if(!cancelar){
			existe = Fabrica::getInstance()->getUControlador(idUsuarioControlador)->checkeoNickname(nickname);
		}
	}
	if(!cancelar){
		DataUsuario du;
		du.setNickname(nickname);
		//Ingresa al datatype para completar los datos
		cin >> du;
		//Ingresa el usuario en memoria 
		Fabrica::getInstance()->getUControlador(idUsuarioControlador)->ingresarDatosUsuario(du);
		//Crea y guarda el Usuario 
		Fabrica::getInstance()->getUControlador(idUsuarioControlador)->guardarUsuario();
	}

}
void crearTipoDeRecurso(){
	int tipo;
	bool salir;
	do{
		cout << "1 - Carpeta" << endl;
		cout << "2 - Archivo" << endl;
		cout << "Ingrese el Tipo de Recurso:" << endl;
		tipo = ingresarNumerico();
		salir = false;
		switch(tipo){
			case 1:{
				DataCarpeta dc;
				string tmp;
				cout << "Nombre de la Carpeta:" << endl;
				cin >> tmp;
				dc.setNombre(tmp);
				cout << "Descripcion de la Carpeta:" << endl;
				cin >> tmp;
				dc.setDescripcion(tmp);

				cout << dc;
				salir = true;
				Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(dc,"");
				break;
			}
			case 2:{
				DataArchivo da;
				string tmp;
				cout << "Nombre del Archivo:" << endl;
				cin >> tmp;
				da.setNombre(tmp);
				cout << "Descripcion del Archivo:" << endl;
				cin >> tmp;
				da.setDescripcion(tmp);
				
				cout << da;
				salir = true;
				Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(da,"");
				break;
			}
		}
	}while(salir != true);


}
void elegirUsuario(){
	string nickname;	
	list<DataUsuario> uList = Fabrica::getInstance()->getUControlador(idUsuarioControlador)->listarUsuarios();
	
	cout << "*****************************************" << endl;
	cout << "********** Seleccionar Usuario **********" << endl;
	cout << "*****************************************" << endl;
	cout << "Nickname - Nombre" << endl;

	for (list<DataUsuario>::iterator it = uList.begin(); it != uList.end(); ++it){	
		cout << (*it).getNickname() << " - " << (*it).getNombre() << endl;
	}

	cout << "Ingrese el Nickname del usuario seleccionado: " << endl;
	cin >> nickname;
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(nickname);
}
void elegirCarpeta(){
	list<DataCarpeta> drl = Fabrica::getInstance()->getRControlador(idRecursoControlador)->ListarCarpetas();
	list<DataCarpeta>::iterator it;
	
	string carp;
	cout<<"Listado de Carpetas: "<<endl;
	for(it = drl.begin(); it!= drl.end();++it){
		cout<<(*it)<<endl;
	}	

	//cin>>carp;
	//Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(carp);
}


void agregarColaborador(){
	
	DataRecurso dc = Fabrica::getInstance()->getRControlador(idRecursoControlador)->ListarCarpetas().front();
	cout<< (&dc) ;
}

int main(){

	int opcion;
	idUsuarioControlador = Fabrica::getInstance()->getUControlador(-1)->getId();
	idRecursoControlador = Fabrica::getInstance()->getRControlador(-1)->getId();
	crearCarpetaRaiz();

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
					
					crearTipoDeRecurso();
					elegirUsuario();	
					elegirCarpeta();

				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/***************************** Agregar Colaborador ********************************/
			case 4:{

					agregarColaborador();
				try{

				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/******************************* Ingresar Comentario ****************************/
			case 5:{
				try{
					elegirCarpeta();
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
