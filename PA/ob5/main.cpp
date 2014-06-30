#include <iostream>
#include <limits>
#include <stdexcept>
#include <stdlib.h>
#include "Fabrica.h"

using namespace std;

int idUsuarioControlador, idRecursoControlador;

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

void agregarDatosDePrueba(){
	cout << "********** Usuarios **********" << endl;
	DateTime fec = DateTime(1988, 12, 28, 0,0);
	DataUsuario Usuario1 = DataUsuario("James",  "James", "Masculino", 24, fec);
	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->ingresarDatosUsuario(Usuario1);
	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->guardarUsuario();
	cout << Usuario1 << endl;

	DateTime fec2 = DateTime(1990, 1, 1, 0,0);
	DataUsuario Usuario2 = DataUsuario("Jennifer",  "Jeniffer", "Femenino", 23, fec2);
	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->ingresarDatosUsuario(Usuario2);
	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->guardarUsuario();
	cout << Usuario2 << endl;

	DateTime fec3 = DateTime(1980, 3, 3, 0,0);
	DataUsuario Usuario3 = DataUsuario("Jhon",  "Jhon", "Masculino", 33, fec3);
	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->ingresarDatosUsuario(Usuario3);
	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->guardarUsuario();
	cout << Usuario3 << endl;

	cout << "********** Carpetas **********" << endl;
	DataCarpeta Carpeta;
	Carpeta.setNombre("/");
	Carpeta.setDescripcion("Carpeta Raiz");
	Carpeta.setUbicacion("/");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Carpeta,"carpeta");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();
	cout << Carpeta << endl;

	DataCarpeta Carpeta1 = DataCarpeta("Deporte",Usuario3,"Almacena información de deportes.",DateTime(),DateTime(),"/Deporte","/Deporte");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Carpeta1,"carpeta");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();
	cout << Carpeta1 << endl;

	DataCarpeta Carpeta2 = DataCarpeta("Juegos",Usuario3,"Almacena información de los últimos juegos para PC.",DateTime(),DateTime(),"/Juegos","/Juegos");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Carpeta2,"carpeta");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();
	cout << Carpeta2 << endl;

	DataCarpeta Carpeta3 = DataCarpeta("Proyecto",Usuario3,"Almacena recursos relacionados con proyectos de software.",DateTime(),DateTime(),"/Proyecto","/Proyecto");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Carpeta3,"carpeta");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();
	cout << Carpeta3 << endl;

	DataCarpeta Carpeta4 = DataCarpeta("Futbol",Usuario1,"Almacena recursos relacionados con el fútbol",DateTime(),DateTime(),"/Deporte/Futbol","/Deporte/Futbol");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Carpeta4,"carpeta");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();
	cout << Carpeta4 << endl;

	DataCarpeta Carpeta5 = DataCarpeta("CopaAm",Usuario1,"Archivo de texto que contiene las últimas noticias de la Copa América.",DateTime(),DateTime(),"/Deporte/Futbol/CopaAm","/Deporte/Futbol/CopaAm");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Carpeta5,"carpeta");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();
	cout << Carpeta5 << endl;

	DataCarpeta Carpeta6 = DataCarpeta("Mundial",Usuario3,"Archivo de texto que contiene las últimas noticias de la Copa del Mundo.",DateTime(),DateTime(),"/Deporte/Futbol/Mundial","/Deporte/Futbol/Mundial");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Carpeta6,"carpeta");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();
	cout << Carpeta6 << endl;

	DataCarpeta Carpeta7 = DataCarpeta("Salud",Usuario3,"Archivo que contiene información de la salud en los deportes.",DateTime(),DateTime(),"/Deporte/Salud","/Deporte/Salud");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Carpeta7,"carpeta");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();
	cout << Carpeta7 << endl;

	DataCarpeta Carpeta8 = DataCarpeta("Tesis",Usuario2,"Informe final de la tésis",DateTime(),DateTime(),"/Proyecto/Tesis","/Proyecto/Tesis");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Carpeta8,"carpeta");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();
	cout << Carpeta8 << endl;

	//Colaboradores
	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->elegirUsuario(Usuario3.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(Carpeta.getPath());
	Colaborador* Colaborador1 = new Colaborador(DateTime(), Fabrica::getInstance()->getRControlador(idRecursoControlador)->getCarpetaElegida(), Fabrica::getInstance()->getUControlador(idUsuarioControlador)->getUsuarioElegido());
	ManejadorColaborador::getInstance()->agregarALista(Colaborador1);

	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->elegirUsuario(Usuario1.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(Carpeta1.getPath());
	Colaborador* Colaborador2 = new Colaborador(DateTime(), Fabrica::getInstance()->getRControlador(idRecursoControlador)->getCarpetaElegida(), Fabrica::getInstance()->getUControlador(idUsuarioControlador)->getUsuarioElegido());
	ManejadorColaborador::getInstance()->agregarALista(Colaborador2);

	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->elegirUsuario(Usuario1.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(Carpeta2.getPath());
	Colaborador* Colaborador3 = new Colaborador(DateTime(), Fabrica::getInstance()->getRControlador(idRecursoControlador)->getCarpetaElegida(), Fabrica::getInstance()->getUControlador(idUsuarioControlador)->getUsuarioElegido());
	ManejadorColaborador::getInstance()->agregarALista(Colaborador3);

	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->elegirUsuario(Usuario2.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(Carpeta2.getPath());
	Colaborador* Colaborador4 = new Colaborador(DateTime(), Fabrica::getInstance()->getRControlador(idRecursoControlador)->getCarpetaElegida(), Fabrica::getInstance()->getUControlador(idUsuarioControlador)->getUsuarioElegido());
	ManejadorColaborador::getInstance()->agregarALista(Colaborador4);

	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->elegirUsuario(Usuario2.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(Carpeta3.getPath());
	Colaborador* Colaborador5 = new Colaborador(DateTime(), Fabrica::getInstance()->getRControlador(idRecursoControlador)->getCarpetaElegida(), Fabrica::getInstance()->getUControlador(idUsuarioControlador)->getUsuarioElegido());
	ManejadorColaborador::getInstance()->agregarALista(Colaborador5);
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
		cout << "Ingrese el Tipo de Recurso: ";
		tipo = ingresarNumerico();
		salir = false;
		switch(tipo){
			case 1:{
				DataCarpeta dc;
				string tmp;
				cout << "Nombre de la Carpeta: ";
				cin >> tmp;
				dc.setNombre(tmp);
				cout << "Descripcion de la Carpeta: ";
				cin >> tmp;
				dc.setDescripcion(tmp);
				Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(dc,"carpeta");
				salir = true;
				break;
			}
			case 2:{
				DataArchivo da;
				string tmp;
				cout << "Nombre del Archivo: ";
				cin >> tmp;
				da.setNombre(tmp);
				cout << "Descripcion del Archivo: ";
				cin >> tmp;
				da.setDescripcion(tmp);
				Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(da,"archivo");
				salir = true;
				break;
			}
		}
	}while(salir != true);
}

void elegirUsuario(){
	string nickname;	
	list<DataUsuario> uList = Fabrica::getInstance()->getUControlador(idUsuarioControlador)->listarUsuarios();
	list<DataUsuario>::iterator it;

	cout << "********** Seleccionar Usuario **********" << endl;
	cout << "Nickname - Nombre" << endl;

	for (it = uList.begin(); it != uList.end(); ++it){	
		cout << (*it).getNickname() << " - " << (*it).getNombre() << endl;
	}

	cout << "Ingrese el Nickname del usuario: ";
	cin >> nickname;
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(nickname);
}

void elegirCarpeta(){
	string carp;
	list<DataCarpeta> drl = Fabrica::getInstance()->getRControlador(idRecursoControlador)->listarCarpetas();
	list<DataCarpeta>::iterator it;
	
	cout << "********** Seleccionar Carpeta **********" << endl;
	cout << "Ubicacion - Nombre" << endl;
	for(it = drl.begin(); it!= drl.end(); ++it){
		cout << it->getUbicacion() << " - " << it->getNombre() <<endl;
	}	
	cout << "Ingrese la ubicacion de la carpeta: ";
	cin >> carp;
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(carp);
}

void elegirCarpetaPorUsuario(){
	string carp;
	list<DataCarpeta> drl = Fabrica::getInstance()->getRControlador(idRecursoControlador)->listarCarpetasPorUsuario();
	list<DataCarpeta>::iterator it;	
	
	cout << "********** Seleccionar Carpeta **********" << endl;
	cout << "Ubicacion - Nombre"<<endl;
	for(it = drl.begin(); it!= drl.end(); ++it){
		cout << it->getUbicacion() << " - " << it->getNombre() << endl;
	}	
	cout << "Ingrese la ubicacion de la carpeta: ";
	cin >> carp;
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(carp);
}

void elegirArchivo(){
	string archivo;
	list<DataArchivo> drl = Fabrica::getInstance()->getRControlador(idRecursoControlador)->listarArchivos();
	list<DataArchivo>::iterator it;
	
	cout << "********** Seleccionar Archivo **********" << endl;
	cout << "Ubicacion - Nombre" << endl;
	for(it = drl.begin(); it!= drl.end(); ++it){
		cout << it->getUbicacion() << " - " << it->getNombre() <<endl;
	}	
	cout << "Ingrese la ubicacion del archivo: ";
	cin >> archivo;
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirArchivo(archivo);
}

void listarComentariosPorArchivo(){
	list<DataComentario> ldcma = Fabrica::getInstance()->getRControlador(idRecursoControlador)->listarComentariosPorArchivo();
	list<DataComentario>::iterator it;	
	
	cout << "************* Comentarios *************" << endl;
	cout << "Id - Nickname - Contenido"<<endl;
	for(it = ldcma.begin(); it != ldcma.end(); ++it){
		DataUsuario u = DataUsuario(it->getUsuario());
		cout << it->getCodigo() << " - " << it->getContenido() << endl;
	}
}

void accionSobreComentario(){
	int tipo;
	bool salir;
	
	do{
		cout << "1 - Agregar Comentario" << endl;
		cout << "2 - Responder Comentario" << endl;
		cout << "Ingrese la accion a realizar: ";
		tipo = ingresarNumerico();
		salir = false;
		switch(tipo){
			case 1:{
				string contenido;
				cout << "Comentario: ";
				cin >> contenido;
				elegirUsuario();
				Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarComentario(contenido, 0);
				salir = true;
				break;
			}
			case 2:{
				string contenido;
				int parent;
				cout << "Id comentario a responder: ";
				cin >> parent;
				cout << "Comentario: ";
				cin >> contenido;
				elegirUsuario();
				Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarComentario(contenido, parent);
				salir = true;
				break;
			}
		}
	}while(salir != true);
}

void crearRecurso(){
	crearTipoDeRecurso();
	elegirUsuario();	
	elegirCarpeta();

	Fabrica::getInstance()->getRControlador(idRecursoControlador)->controlDeErrores();
	list<DataErrores> dtErrores = Fabrica::getInstance()->getRControlador(idRecursoControlador)->imprimirErroresGenerados();

	if(dtErrores.size() != 0){		
		list<DataErrores>::iterator ite ;
		for(ite = dtErrores.begin(); ite!=dtErrores.end(); ++ite){
			cout << (*ite) << endl;
		}
	}else{
		Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();
	}
}

void agregarColaborador(){
	elegirUsuario();
	elegirCarpetaPorUsuario();
	elegirUsuario();
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->agregarColaborador();
}

void ingresarComentario(){
	elegirArchivo();
	listarComentariosPorArchivo();
	accionSobreComentario();
}

void verInformacionUsuario(){
	elegirUsuario();
	DataInformacionUsuario info = Fabrica::getInstance()->getUControlador(idUsuarioControlador)->obtenerInformacionUsuario();
	cout << "Nickname: " << info.getUsuario().getNickname() << endl;
	cout << "Sexo: " << info.getUsuario().getSexo() << endl;
	cout << "Edad: " << info.getUsuario().getEdad() << endl;
	cout << "Fecha de nacimiento: " << info.getUsuario().getFechaNac() << endl;

	cout << "************** Recursos creados **************" << endl;
	for(list<DataRecurso>::iterator it = info.getRecursos().begin() ; it != info.getRecursos().end();++it){
		cout << "Recurso: " << it->getNombre() << endl;
	}

	cout << "***** Carpetas en las que es colaborador *****" << endl;
	for(list<DataColaborador>::iterator it = info.getColaboradores().begin() ; it != info.getColaboradores().end();++it){
		cout << "Colaborando en carpeta: " << it->getCarpeta().getNombre() << " desde: " << it->getFecha() << endl;
	}

	cout << "************* Acciones realizadas ************" << endl;
	for(list<DataAccion>::iterator it = info.getAcciones().begin() ; it != info.getAcciones().end();++it){
		cout << "Accion: " << it->getTipo() << " en: " << it->getFecha() << " sobre: " << it->getArchivo().getNombre() << endl;
	}
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
					agregarDatosDePrueba();	
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
					crearRecurso();
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
					ingresarComentario();
				}catch(const invalid_argument& ia){
					cerr << ia.what() << endl;
				}
				break;
			}
			/*********************** Ver Informacion de un Usuario *************************/
			case 6:{
				try{
					verInformacionUsuario();
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
