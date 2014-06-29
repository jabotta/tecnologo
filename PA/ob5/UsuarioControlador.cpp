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

DataUsuario generarDataUsuario(Usuario* usu){
	return DataUsuario(usu->getNickname(), usu->getNombre(), usu->getSexo(), usu->getEdad(), usu->getFechaNac());
}

DataRecurso generarDataRecurso(Recurso* rec){
	DataUsuario usuarioCreo = generarDataUsuario(rec->getUsuarioCreo());
	return DataRecurso(rec->getNombre(), usuarioCreo, rec->getDescripcion(), rec->getFechaUltimoAcceso(), rec->getFechaCreacion(), rec->getUbicacion(), rec->getPath());
}

DataCarpeta generarDataCarpeta(Carpeta* car){
	DataUsuario usuarioCreo = generarDataUsuario(car->getUsuarioCreo());
	return DataCarpeta(car->getNombre(), usuarioCreo, car->getDescripcion(), car->getFechaUltimoAcceso(), car->getFechaCreacion(), car->getUbicacion(), car->getPath());
}

DataArchivo generarDataArchivo(Archivo* arc){
	DataUsuario usuarioCreo = generarDataUsuario(arc->getUsuarioCreo());
	return DataArchivo(arc->getNombre(), usuarioCreo, arc->getDescripcion(), arc->getFechaUltimoAcceso(), arc->getFechaCreacion(), arc->getUbicacion(), arc->getPath());
}

DataAccion generarDataAccion(Accion* acc){
	DataUsuario du = generarDataUsuario(acc->getUsuario());
	DataArchivo da = generarDataArchivo(acc->getArchivo());
	return  DataAccion(acc->getFecha(),acc->getTipo(),du,da);
}

DataColaborador generarDataColaborador(Colaborador* col){
	DataUsuario du = generarDataUsuario(col->getUsuario());
	DataCarpeta dc = generarDataCarpeta(col->getCarpeta());
	return DataColaborador(du, dc, col->getFechaIngreso());
}

DataInformacionUsuario UsuarioControlador::obtenerInformacionUsuario(){
	// crear ListDataRecurso
	list<Recurso*> recList = ManejadorRecursos::getInstance()->listarRecursos();
	list<DataRecurso> recCreados = list<DataRecurso>();
	for (list<Recurso*>::iterator it = recList.begin(); it != recList.end(); ++it){
		Recurso* r = *it;
		Usuario* usuario = r->getUsuarioCreo();
		
		if(usuarioElegido->getNickname() == usuario->getNickname()){
			DataRecurso dr = generarDataRecurso(r);
			recCreados.push_back(dr);
		}
	}
	
	// crear ListDataColaborador
	list<Colaborador*> cList = ManejadorColaborador::getInstance()->listarColaboradores();
	list<DataColaborador> colaboracionList = list<DataColaborador>();
	for (list<Colaborador*>::iterator it = cList.begin(); it != cList.end(); ++it){
		Colaborador* c = *it;
		Usuario* uc = c->getUsuario();
		string uc_nickname = uc->getNickname();
		if(usuarioElegido->getNickname() == uc_nickname){
			DataColaborador result = generarDataColaborador(c);
			colaboracionList.push_back(result);
		}
	}

	// crear ListDataAccion
	list<Accion*> accList = usuarioElegido->obtenerAcciones();
	list<DataAccion> accionesList = list<DataAccion>();
	for (list<Accion*>::iterator it = accList.begin(); it != accList.end(); ++it){
		Accion* a = *it;
		DataAccion da = generarDataAccion(a);
		accionesList.push_back(da);
	}

	// crear DataUsuario
	DataUsuario dataUsuarioElegido = generarDataUsuario(usuarioElegido);

	return DataInformacionUsuario(dataUsuarioElegido,recCreados,colaboracionList,accionesList);
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