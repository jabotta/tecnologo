#include "DataUsuario.h"

// Constructores
DataUsuario::DataUsuario(){
    setNickname(""); 
    setNombre("");
    setSexo("");
	setEdad(0);
	setFechaNac(DateTime());
};

DataUsuario::DataUsuario(string nck, string nm, string sx, int edad, DateTime fn){
	setNickname(nck);
	setNombre(nm);
	setSexo(sx);
	setEdad(edad);
	setFechaNac(fn);
}

// Instancia por copia
DataUsuario::DataUsuario(const DataUsuario& du){
	setNickname(du.getNickname());
    setNombre(du.getNombre());
    setSexo(du.getSexo());
    setEdad(du.getEdad());
    setFechaNac(du.getFechaNac());
}

// Destructor
DataUsuario::~DataUsuario(){}

// Selectores
string DataUsuario::getNickname () const{
	return nickname;
}

string DataUsuario::getNombre () const{
	return nombre;
}

string DataUsuario::getSexo () const{
	return sexo;
}

int DataUsuario::getEdad () const{
	return edad;
}

DateTime DataUsuario::getFechaNac () const{
	return fechaNac;
}

// Modificadores
void DataUsuario::setNickname(string nm){
	nickname = nm;
}

void DataUsuario::setNombre(string nm){
	nombre = nm;
}

void DataUsuario::setSexo(string sx){
	sexo = sx;
}

void DataUsuario::setEdad(int ed){
	edad = ed;
}

void DataUsuario::setFechaNac(DateTime fn){
	fechaNac = fn;
}

ostream& operator<< (ostream& out,const DataUsuario& o){
    out << o.getNickname() << " - " << o.getNombre() << " - " << o.getFechaNac() << endl;
    return out;
}

istream& operator>> (istream &input,DataUsuario& o){
	string nombretmp, sexotmp;
	int anio,dia,mes;

	cout << "Ingrese Nombre: " << endl;
    input >> nombretmp;
	cout << "Ingrese Sexo: " << endl;
    input >> sexotmp;

	cout << "Ingrese Fecha de Nacimiento" << endl;    
	cout << "Ingrese Año: " << endl;
    input >> anio;
	cout << "Ingrese Mes: " << endl;
    input >> mes;
	cout << "Ingrese Dia: " << endl;
    input>>dia;

    DateTime fechanactmp(anio,mes,dia);
    o.setNombre(nombretmp);
	o.setSexo(sexotmp);
    o.setFechaNac(fechanactmp);
    
    return input;
}