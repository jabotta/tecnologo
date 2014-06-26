#include "RecursoControlador.h"

RecursoControlador::RecursoControlador(){

}

RecursoControlador::RecursoControlador(int iduc){


	id = iduc;


}

RecursoControlador::~RecursoControlador(){


//debemos liberar la memoria de todos los pseudoatributos 
}
RecursoControlador::RecursoControlador(const RecursoControlador& i){


//debemos liberar la memoria de todos los pseudoatributos 
}

int RecursoControlador::RecursoControlador::getId(){


	return id;
}

 

list<DataCarpeta> RecursoControlador::ListarCarpetasPorUsuario(){

}
void RecursoControlador::agregarColaborador(){

}
void RecursoControlador::ingresarRecurso(DataRecurso recurso,string tipo ){

}
void RecursoControlador::controlDeErrores(){

}
void RecursoControlador::guardarRecurso(){

}
list<DataErrores> RecursoControlador::imprimirErroresGenerados(){

}
list<DataCarpeta> RecursoControlador::ListarCarpetas(){

}
void RecursoControlador::elegirCarpeta(string path){

}
list<DataArchivo> RecursoControlador::ListarArchivos(){

}
void RecursoControlador::elegirArchivo(string path){

}
//list<DataComentario> listarComentario(){}
void RecursoControlador::accionSobreComentario(string acc){

}
void RecursoControlador::agregarComentario(string comentario){

}
void RecursoControlador::responderComentario(string c,int id ){

}


string RecursoControlador::getAccionTipo()const{
	return accionTipo;
}
Comentario RecursoControlador::getNuevoComentario() const{
	return nuevoComentario;
}
Comentario RecursoControlador::getPadreComentario()const{
	return padreComentario;
}
Carpeta RecursoControlador::getCarpetaElegida()const{
	return carpetaElegida;
}
Archivo RecursoControlador::getArchivoElegido()const{
	return archivoElegido;
}
Colaborador RecursoControlador::getColaboradorCreado()const{
	return colaboradorCreado;
}
list<DataErrores> RecursoControlador::getErrores()const{
	list<DataErrores> errores;
	return errores;
}
list<Recurso> RecursoControlador::getRecursosLista()const{

	return recursosLista;
}

Usuario RecursoControlador::getUsuarioElegido()const{
	return usuarioElegido;
}
Usuario RecursoControlador::getUsuarioColaborador()const{
	return usuarioColaborador;
}

void RecursoControlador::setAccionTipo (string at){
	accionTipo = at;
}
void RecursoControlador::setNuevoComentario (Comentario c){
	nuevoComentario = c;
}
void RecursoControlador::setPadreComentario (Comentario pc){
	padreComentario = pc;
}
void RecursoControlador::setCarpetaElegida (Carpeta c){
	carpetaElegida = c;
}
void RecursoControlador::setArchivoElegido (Archivo a){
	archivoElegido = a;

}
void RecursoControlador::setColaboradorCreado(Colaborador cc){
	colaboradorCreado = cc;
}
void RecursoControlador::setErrores(list<DataErrores> del){
	errores = del;
}
void RecursoControlador::setRecursosLista(list<Recurso> rl){
	recursosLista = rl;
}
void RecursoControlador::setUsuarioElegido(Usuario& u){
	usuarioElegido = u;
}
void RecursoControlador::setUsuarioColaborador(Usuario& uc){
	usuarioColaborador = uc;
}
void RecursoControlador::setExisten(bool e){
	existen = e;
}