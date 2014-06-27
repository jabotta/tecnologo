 #include "UsuarioControlador.h"

//Constructores
UsuarioControlador::UsuarioControlador(){
	
}

UsuarioControlador::UsuarioControlador(int iduc){
	id = iduc;
}

UsuarioControlador::~UsuarioControlador(){
	//debemos liberar la memoria de todos los pseudoatributos 
}
UsuarioControlador::UsuarioControlador(const UsuarioControlador& i){
	//debemos liberar la memoria de todos los pseudoatributos 
}

//Setters
void UsuarioControlador::setRecCreados(list<Recurso> r){
	recCreados = r;
}

void UsuarioControlador::setcolaboracionList(list<Colaborador> c){
	colaboracionList = c ;
}

void UsuarioControlador::setAccList(list<Accion> a){
	accList = a;
}

void UsuarioControlador::setUsuarioElegido(Usuario *u){
	usuarioElegido = u;
}

void UsuarioControlador::setDataUsuarioIngresar(DataUsuario du){
	dataUsuarioIngresar = du;
}

void UsuarioControlador::setNickname(string n){
	nickname = n;
}

//Getters
list<Recurso> UsuarioControlador::getRecCreados(){
	return recCreados;
}

list<Colaborador> UsuarioControlador::getcolaboracionList(){
	return colaboracionList;
}

list<Accion>UsuarioControlador::getAccList(){
	return accList;
}

Usuario* UsuarioControlador::getUsuarioElegido(){
 	return usuarioElegido;
}

DataUsuario& UsuarioControlador::getDataUsuarioIngresar(){
	return dataUsuarioIngresar;
}

string UsuarioControlador::getNickname(){ 
	return nickname;
}

bool UsuarioControlador::checkeoNickname(string nickname){
	return ManejadorUsuario::getInstance()->checkeoNickname(nickname);
}

void UsuarioControlador::ingresarDatosUsuario(DataUsuario d){
	dataUsuarioIngresar = DataUsuario(d);
}

void UsuarioControlador::guardarUsuario(){
	Usuario us = Usuario(dataUsuarioIngresar);
	ManejadorUsuario::getInstance()->guardarUsuario(us);
}
int UsuarioControlador::getId(){
	return id;
}
DataInformacionUsuario UsuarioControlador::obtenerInformacionUsuario(){
	list<Recurso*> recList = ManejadorRecursos::getInstance()->listarRecursos();
	for (list<Recurso*>::iterator it = recList.begin(); it != recList.end(); ++it){
		Recurso* r = *it;
		Usuario* usuario = r->getUsuarioCrea();
		list<Recurso*> recCreados = list<Recurso*>();
		if(usuarioElegido->getNickname() == usuario->getNickname()){
			recCreados.push_back(r);
		}
	}
	// crear ListDataRecursos
	list<Colaborador*> cList = ManejadorColaborador::getInstance()->listarColaboradores();
	for (list<Colaborador*>::iterator it = cList.begin(); it != cList.end(); ++it){
		Colaborador* c = *it;
		//Usuario* uc = c->getUsuario();
		//string uc_nickname = uc->getNickname();
		//list<Colaborador*> colaboracionList = list<Colaborador*>();
		//if(usuarioElegido->getNickname() == uc_nickname){
		//	colaboracionList.push_back(r);
		//}
	}
	// crear ListDataColaborador
	//list<Accion*> accList = ManejadorUsuario::getInstance()->obtenerAcciones();
}

list<DataUsuario> UsuarioControlador::listarUsuarios(){
	list<DataUsuario> du = ManejadorUsuario::getInstance()->listarUsuarios();
	return du;
}

void UsuarioControlador::elegirUsuario(string nickname){
	usuarioElegido = ManejadorUsuario::getInstance()->elegirUsuario(nickname);
}