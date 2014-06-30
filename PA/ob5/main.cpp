#include <iostream>
#include <limits>
#include <stdexcept>
#include <stdlib.h>
#include "Fabrica.h"

using namespace std;

int idUsuarioControlador, idRecursoControlador;
int comentarioId = 1;

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
	//Usuarios
	DateTime fec = DateTime(1988, 12, 28, 0,0);
	DataUsuario Usuario1 = DataUsuario("James",  "James", "Masculino", 24, fec);
	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->ingresarDatosUsuario(Usuario1);
	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->guardarUsuario();

	DateTime fec2 = DateTime(1990, 1, 1, 0,0);
	DataUsuario Usuario2 = DataUsuario("Jennifer",  "Jeniffer", "Femenino", 23, fec2);
	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->ingresarDatosUsuario(Usuario2);
	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->guardarUsuario();

	DateTime fec3 = DateTime(1980, 3, 3, 0,0);
	DataUsuario Usuario3 = DataUsuario("Jhon",  "Jhon", "Masculino", 33, fec3);
	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->ingresarDatosUsuario(Usuario3);
	Fabrica::getInstance()->getUControlador(idUsuarioControlador)->guardarUsuario();

	//Carpetas
	Carpeta* temp = ManejadorRecursos::getInstance()->elegirCarpeta("/");
	DataUsuario usuarioRaiz = DataUsuario();
	DataCarpeta CarpetaRaiz = DataCarpeta(temp->getNombre(), usuarioRaiz, temp->getDescripcion(), temp->getFechaUltimoAcceso(), temp->getFechaCreacion(), temp->getUbicacion(), temp->getPath());

	DataCarpeta Carpeta1 = DataCarpeta("Deporte",Usuario3,"Almacena información de deportes.",DateTime(),DateTime(),"/Deporte","/Deporte");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(CarpetaRaiz.getPath());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Carpeta1,"carpeta");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario3.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();

	DataCarpeta Carpeta2 = DataCarpeta("Juegos",Usuario3,"Almacena información de los últimos juegos para PC.",DateTime(),DateTime(),"/Juegos","/Juegos");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(CarpetaRaiz.getPath());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Carpeta2,"carpeta");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario3.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();

	DataCarpeta Carpeta3 = DataCarpeta("Proyecto",Usuario3,"Almacena recursos relacionados con proyectos de software.",DateTime(),DateTime(),"/Proyecto","/Proyecto");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(CarpetaRaiz.getPath());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Carpeta3,"carpeta");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario3.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();

	DataCarpeta Carpeta4 = DataCarpeta("Futbol",Usuario1,"Almacena recursos relacionados con el fútbol",DateTime(),DateTime(),"/Deporte/Futbol","/Deporte/Futbol");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta("/Deporte");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Carpeta4,"carpeta");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario1.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();

	//Archivos
	DataArchivo Archivo1 = DataArchivo("CopaAm",Usuario1,"Archivo de texto que contiene las últimas noticias de la Copa América.",DateTime(),DateTime(),"/Deporte/Futbol/CopaAm","/Deporte/Futbol/CopaAm");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta("/Deporte/Futbol");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Archivo1,"archivo");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario1.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();

	DataArchivo Archivo2 = DataArchivo("Mundial",Usuario3,"Archivo de texto que contiene las últimas noticias de la Copa del Mundo.",DateTime(),DateTime(),"/Deporte/Futbol/Mundial","/Deporte/Futbol/Mundial");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Archivo2,"archivo");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario3.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();

	DataArchivo Archivo3 = DataArchivo("Salud",Usuario3,"Archivo que contiene información de la salud en los deportes.",DateTime(),DateTime(),"/Deporte/Salud","/Deporte/Salud");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta("/Deporte");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Archivo3,"archivo");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario3.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();

	DataArchivo Archivo4 = DataArchivo("Tesis",Usuario2,"Informe final de la tésis",DateTime(),DateTime(),"/Proyecto/Tesis","/Proyecto/Tesis");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta("/Proyecto");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->ingresarRecurso(Archivo4,"archivo");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario2.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarRecurso();

	//Colaboradores
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario3.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(CarpetaRaiz.getPath());
	Colaborador* Colaborador1 = new Colaborador(DateTime(), Fabrica::getInstance()->getRControlador(idRecursoControlador)->getCarpetaElegida(), Fabrica::getInstance()->getRControlador(idRecursoControlador)->getUsuarioElegido());
	ManejadorColaborador::getInstance()->agregarALista(Colaborador1);

	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario1.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(Carpeta1.getPath());
	Colaborador* Colaborador2 = new Colaborador(DateTime(), Fabrica::getInstance()->getRControlador(idRecursoControlador)->getCarpetaElegida(), Fabrica::getInstance()->getRControlador(idRecursoControlador)->getUsuarioElegido());
	ManejadorColaborador::getInstance()->agregarALista(Colaborador2);

	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario1.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(Carpeta2.getPath());
	Colaborador* Colaborador3 = new Colaborador(DateTime(), Fabrica::getInstance()->getRControlador(idRecursoControlador)->getCarpetaElegida(), Fabrica::getInstance()->getRControlador(idRecursoControlador)->getUsuarioElegido());
	ManejadorColaborador::getInstance()->agregarALista(Colaborador3);

	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario2.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(Carpeta2.getPath());
	Colaborador* Colaborador4 = new Colaborador(DateTime(), Fabrica::getInstance()->getRControlador(idRecursoControlador)->getCarpetaElegida(), Fabrica::getInstance()->getRControlador(idRecursoControlador)->getUsuarioElegido());
	ManejadorColaborador::getInstance()->agregarALista(Colaborador4);

	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario2.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirCarpeta(Carpeta3.getPath());
	Colaborador* Colaborador5 = new Colaborador(DateTime(), Fabrica::getInstance()->getRControlador(idRecursoControlador)->getCarpetaElegida(), Fabrica::getInstance()->getRControlador(idRecursoControlador)->getUsuarioElegido());
	ManejadorColaborador::getInstance()->agregarALista(Colaborador5);

	//Comentarios
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario3.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirArchivo(Archivo1.getPath());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarComentario("Me da la impresion que le falta info al archivo...", 0, comentarioId);
	comentarioId ++;

	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario1.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirArchivo(Archivo1.getPath());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarComentario("Apenas pueda lo modifico :)", 1, comentarioId);
	comentarioId ++;

	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario1.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirArchivo(Archivo1.getPath());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarComentario("Y le agrego la info de años anteriores", 1, comentarioId);
	comentarioId ++;

	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario3.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirArchivo(Archivo1.getPath());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarComentario("¡Muchas gracias!", 3, comentarioId);
	comentarioId ++;

	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario1.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirArchivo(Archivo1.getPath());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarComentario("¡De nada!", 4, comentarioId);
	comentarioId ++;

	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario3.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirArchivo(Archivo4.getPath());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarComentario("Faltaron algunas conclusiones...", 0, comentarioId);
	comentarioId ++;

	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario2.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirArchivo(Archivo4.getPath());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarComentario("Enseguida las agrego", 6, comentarioId);
	comentarioId ++;

	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(Usuario2.getNickname());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirArchivo(Archivo4.getPath());
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarComentario("¡Conclusiones agregadas!", 0, comentarioId);
	comentarioId ++;

	cout << "*****************************************" << endl;
	cout << "************ Datos Generados ************" << endl;
	cout << "*****************************************" << endl;
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

void elegirUsuario(string controlador){
	string nickname;	
	list<DataUsuario> uList = Fabrica::getInstance()->getUControlador(idUsuarioControlador)->listarUsuarios();
	list<DataUsuario>::iterator it;

	cout << "********** Seleccionar Usuario **********" << endl;
	cout << "Nickname - Nombre" << endl;

	for (it = uList.begin(); it != uList.end(); ++it){	
		cout << it->getNickname() << " - " << it->getNombre() << endl;
	}

	cout << "Ingrese el Nickname del usuario: ";
	cin >> nickname;
	if(controlador == "Usuario"){
		Fabrica::getInstance()->getUControlador(idUsuarioControlador)->elegirUsuario(nickname);
	}else{
		Fabrica::getInstance()->getRControlador(idRecursoControlador)->elegirUsuario(nickname);
	}
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
	cout << "Id - Nickname - Contenido" << endl;
	for(it = ldcma.begin(); it != ldcma.end(); ++it){
		cout << it->getCodigo() << " - " << it->getUsuario().getNickname() << " - " << it->getContenido() << endl;
	}
	cout << endl;
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
				cout<< "##################################"<<endl;
				cout<< "Ingresar contenido del Comentario:"<<endl;
				cout<< "###################################"<<endl<<endl;
				cout<<"-->";
				cin >> contenido;
				cout<<endl;
				cout<< "##########################################"<<endl;
				cout<< "Elegir Usuario que realiza el comentario :"<<endl;
				cout<< "##########################################"<<endl<<endl;
				elegirUsuario("Recurso");
				Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarComentario(contenido, 0, comentarioId);
				comentarioId ++;
				salir = true;
				break;
			}
			case 2:{
				string contenido;
				int parent;
				cout<< "########################################"<<endl;
				cout<< "Ingresar id del comentario a responder:"<<endl;
				cout<< "########################################"<<endl<<endl;
				cout<<"-->";
				cin >> parent;
				cout<< "##################################"<<endl;
				cout<< "Ingresar contenido del Comentario:"<<endl;
				cout<< "###################################"<<endl<<endl;
				cout<<"-->";
				cin >> contenido;
				cout<< "##########################################"<<endl;
				cout<< "Elegir Usuario que realiza el comentario :"<<endl;
				cout<< "##########################################"<<endl<<endl;
				elegirUsuario("Recurso");
				Fabrica::getInstance()->getRControlador(idRecursoControlador)->guardarComentario(contenido, parent, comentarioId);
				comentarioId ++;
				salir = true;
				break;
			}
		}
	}while(salir != true);
}

void crearRecurso(){
	crearTipoDeRecurso();
	elegirUsuario("Recurso");	
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
	cout<<endl;
	cout<< "#####################################"<<endl;
	cout<< "Elegir Usuario para listar Carpetas :"<<endl;
	elegirUsuario("Recurso");
	cout<<endl;
	cout<< "###########################################"<<endl;
	cout<< "Elegir Carpeta para agregarle colaborador : "<<endl;
	cout<< "###########################################"<<endl<<endl;
	elegirCarpetaPorUsuario();
	cout<<endl;
	cout<< "##############################################"<<endl;
	cout<< "Elegir Usuario para agregar como colaborador: "<<endl;
	cout<< "##############################################"<<endl<<endl;
	elegirUsuario("Recurso");
	Fabrica::getInstance()->getRControlador(idRecursoControlador)->agregarColaborador(Fabrica::getInstance()->getRControlador(idRecursoControlador)->getCarpetaElegida());
}

void ingresarComentario(){
	cout<<endl;
	cout<< "########################################"<<endl;
	cout<< "Elegir Archivo para agregar comentario :"<<endl;
	cout<< "########################################"<<endl<<endl;
	elegirArchivo();
	cout<<endl;
	cout<< "########################"<<endl;
	cout<< "Comentarios existentes:"<<endl;
	cout<< "########################"<<endl<<endl;
	listarComentariosPorArchivo();
	cout<<endl;
	cout<< "##########################"<<endl;
	cout<< "Elegir Accion a realizar :"<<endl;
	cout<< "##########################"<<endl<<endl;
	accionSobreComentario();
}

void verInformacionUsuario(){
	
	cout<<endl;
	cout<< "#####################################"<<endl;
	cout<< "Elegir Usuario para ver informacion :"<<endl;
	cout<< "#####################################"<<endl<<endl;
	elegirUsuario("Usuario");
	DataInformacionUsuario info = Fabrica::getInstance()->getUControlador(idUsuarioControlador)->obtenerInformacionUsuario();
	cout<<endl;
	cout<< "################################"<<endl;
	cout<< "INFROMACION DEL USUARIO ELEGIDO:"<<endl;
	cout<< "################################"<<endl<<endl;

	cout << "Nickname: " << info.getUsuario().getNickname() << endl;
	cout << "Sexo: " << info.getUsuario().getSexo() << endl;
	cout << "Edad: " << info.getUsuario().getEdad() << endl;
	cout << "Fecha de nacimiento: " << info.getUsuario().getFechaNac() << endl;

	cout << "************** Recursos creados **************" << endl;
	list<DataRecurso> iterdDrList = info.getRecursos();
	for(list<DataRecurso>::iterator it = iterdDrList.begin(); it != iterdDrList.end();++it){
		cout << "Recurso: " << it->getNombre() << " - Path: " << it->getPath() << endl;
	}

	cout << "***** Carpetas en las que es colaborador *****" << endl;
	list<DataColaborador> iterdDcList = info.getColaboradores();
	for(list<DataColaborador>::iterator it = iterdDcList.begin() ; it != iterdDcList.end();++it){
		cout << "Colaborando en carpeta: " << it->getCarpeta().getPath() << " desde: " << it->getFecha() << endl;
	}

	cout << "************* Acciones realizadas ************" << endl;
	list<DataAccion> iterdDaList = info.getAcciones();
	for(list<DataAccion>::iterator it = iterdDaList.begin() ; it != iterdDaList.end();++it){
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
				//delete Fabrica::getInstance();
				cout << "Saliendo..." << endl;
				break;
			}
			default: cout << "Opción Invalida, vuelva a intentarlo!" << endl;
		}
	}while(opcion != 7);

	return 0;
}
