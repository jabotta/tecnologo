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
	list<DataRecurso> recCreados = list<DataRecurso>();
	for (list<Recurso*>::iterator it = recList.begin(); it != recList.end(); ++it){
		Recurso* r = *it;
		Usuario* usuario = r->getUsuarioCreo();
		
		if(usuarioElegido->getNickname() == usuario->getNickname()){
			DataUsuario usuarioCreo = DataUsuario(r->getUsuarioCreo()->getNickname(), r->getUsuarioCreo()->getNombre(), r->getUsuarioCreo()->getSexo(), r->getUsuarioCreo()->getEdad(), r->getUsuarioCreo()->getFechaNac());
			DataRecurso dr = DataRecurso(r->getNombre(), usuarioCreo, r->getDescripcion(), r->getFechaUltimoAcceso(), r->getFechaCreacion(), r->getUbicacion());
			recCreados.push_back(dr);
		}
	}
	// crear ListDataRecursos
	list<Colaborador*> cList = ManejadorColaborador::getInstance()->listarColaboradores();
	list<DataColaborador> colaboracionList = list<DataColaborador>();
	for (list<Colaborador*>::iterator it = cList.begin(); it != cList.end(); ++it){
		Colaborador* c = *it;
		Usuario* uc = c->getUsuario();
		string uc_nickname = uc->getNickname();
		if(usuarioElegido->getNickname() == uc_nickname){
			DataUsuario du = DataUsuario(c->getUsuario()->getNickname(), c->getUsuario()->getNombre(), c->getUsuario()->getSexo(), c->getUsuario()->getEdad(), c->getUsuario()->getFechaNac());
			DataUsuario duc = DataUsuario(c->getCarpeta()->getUsuarioCreo()->getNickname(), c->getCarpeta()->getUsuarioCreo()->getNombre(), c->getCarpeta()->getUsuarioCreo()->getSexo(), c->getCarpeta()->getUsuarioCreo()->getEdad(), c->getCarpeta()->getUsuarioCreo()->getFechaNac());
			DataCarpeta dc = DataCarpeta(c->getCarpeta()->getNombre(), duc, c->getCarpeta()->getDescripcion(), c->getCarpeta()->getFechaUltimoAcceso(), c->getCarpeta()->getFechaCreacion(), c->getCarpeta()->getUbicacion());
			DataColaborador result = DataColaborador(du, dc, c->getFechaIngreso());
			colaboracionList.push_back(result);
		}
	}
	// crear ListDataColaborador
	list<Accion*> accList = usuarioElegido->obtenerAcciones();
}

list<DataUsuario> UsuarioControlador::listarUsuarios(){
	list<DataUsuario> du;
	list<Usuario> uList = ManejadorUsuario::getInstance()->listarUsuarios();

	for (list<Usuario>::iterator it = uList.begin(); it != uList.end(); ++it){
		DataUsuario tmp_du = DataUsuario((*it).getNickname(), (*it).getNombre(), (*it).getSexo(), (*it).getEdad(), (*it).getFechaNac());
		du.push_back(tmp_du);
	}

	return du;
}

void UsuarioControlador::elegirUsuario(string nickname){
	usuarioElegido = ManejadorUsuario::getInstance()->elegirUsuario(nickname);
}