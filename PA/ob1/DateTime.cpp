#include <iostream>
#include <stdio.h>
#include <time.h>
#include "DateTime.h"

using namespace std;

// Constructores
// Instancia DateTime con fecha y hora del sistema;
DateTime::DateTime(){
	time_t t = time(0);
	struct tm * now = localtime (&t);

    this->y = now->tm_year + 1900;
    this->m = now->tm_mon + 1;
    this->d = now->tm_mday;
    this->h = now->tm_hour;
    this->i = now->tm_min;
};

// ESTATICA: DateTime d(2014,3,28,15,10);
// DINAMICA: DateTime d = new DateTime(2014,3,28,15,10);
DateTime::DateTime(int y, int m, int d, int h, int i){
    this->y = y;
    this->m = m;
    this->d = d;
    this->h = h;
    this->i = i;
}

// Instancia por copia
DateTime::DateTime( DateTime& d){
	
	this->y = d.getAnio();
    this->m = d.getMes();
    this->d = d.getDia();
    this->h = d.getHora();
    this->i = d.getMinuto();
}

// Destructor
DateTime::~DateTime(){}

// Selectores
int DateTime::getAnio () const{
	return y;
}

int DateTime::getMes () const{
	return m;
}

int DateTime::getDia () const{
	return d;
}

int DateTime::getHora () const{
	return h;
}

int DateTime::getMinuto () const{
	return i;
}

// Modificadores
void DateTime::setAnio(int yy){
	y = yy;
}

void DateTime::setMes(int mm){
	m = mm;
}

void DateTime::setDia(int dd){
	d = dd;
}

void DateTime::setHora(int hh){
	h = hh;
}

void DateTime::setMinuto(int ii){
	i = ii;
}


		// Operaciones
bool DateTime::operator == (DateTime dt){
	return (this->getAnio()==dt.getAnio() && this->getMes()==dt.getMes() && this->getDia()==dt.getDia() &&
		this->getHora()==dt.getHora() && this->getMinuto()==dt.getMinuto());
}
bool DateTime::operator != (DateTime dt){
	return (this->getAnio()!=dt.getAnio() || this->getMes()!=dt.getMes() || this->getDia()!=dt.getDia() ||
		this->getHora()!=dt.getHora() || this->getMinuto()!=dt.getMinuto());
}

bool DateTime::operator < (DateTime dt){

	if(this->getAnio() < dt.getAnio())
	
		return true;
	
	else if (this->getAnio() == dt.getAnio()){
	
			if(this->getMes()< dt.getMes())

				return true;

			else if(this->getMes() == dt.getMes()){
				
				if (this->getDia() < dt.getDia())
					
					return true;

				else if (this->getDia() == dt.getDia())

					 if (this->getHora() < dt.getHora())

						return true;

					else if (this->getHora() == dt.getHora()){

						return this->getMinuto() < dt.getMinuto();

					}
			} 
	}

	return	false; 
		 	
}
bool DateTime::operator > (DateTime dt){

	return (dt < *this);
}
bool DateTime::operator <= (DateTime dt){
	
	return (*this == dt || *this < dt); 
}

bool DateTime::operator >= (DateTime dt){

	return (*this == dt || *this > dt); 
}

int* obtenerDiaHoraMinutoDesdeNumero(double d){

	int* res = new int [3];
	int days = (int)d;
	int hours = (int) ((d-days > 0)? (d-days)*10 : 0);
    int diff = (d-days)*10;
	int minutes = (int)((diff-hours > 0)? (diff-hours)*10 : 0);
	res[0] = days;
	res[1] = hours;
	res[2] = minutes;
	
	return res;
} 


bool DateTime::esBiciesto(){

	return (this->getAnio() % 4 == 0 || this->getAnio() % 100 != 0  || this->getAnio() % 400 == 0 );
}

int DateTime::obtenerMaximoDiaDelMes(){
	
	int month = this->getMes();

	if(month == 2){

		return (this->esBiciesto())?29:28;

	}else{

		if(month<8){
	
			return (month % 2 == 0)?30:31;
		
		}else{
			
			return (month % 2 == 0)?31:30;
		}

	}


}
DateTime DateTime::operator + (double d){

	int maxDays = this->obtenerMaximoDiaDelMes();
	
	int* listaDeValoresSegunDecimal= obtenerDiaHoraMinutoDesdeNumero(d);
	 
	int anio = this->getAnio();
	int mes = this->getMes();
	//guardo en dia ya la suma de los dias que tengo con los que voy a agregar
	int dia = this->getDia()+listaDeValoresSegunDecimal[0];
	//guardo en hora ya la suma de las horas que tengo con las que voy a agregar
	int hora = this->getHora()+listaDeValoresSegunDecimal[1];
	//guardo en minuto ya la suma de los minutos que tengo con los que voy a agregar
	int minuto = this->getMinuto() + listaDeValoresSegunDecimal[2];
	
	double diffDeDias = 0;
	// me fijo en el rango de minutos para saber si no agrego horas
	if( minuto > 60){
		
		int horasParaAgregar = (int)(minuto / 60);
		minuto = minuto-(60*horasParaAgregar);
		hora += horasParaAgregar;
	}
	if(hora > 24){

		int diasParaAgregar = (int)(hora / 24);
		hora = hora-(24*diasParaAgregar);
		dia += diasParaAgregar;
	}
	if(dia > maxDays){

		diffDeDias = dia-maxDays;
		dia = 1;
		mes++;
	}
	if(mes > 12){
		mes = 1;
		anio++;
	}
	DateTime resultado (anio,mes,dia,hora,minuto);
	if(diffDeDias>0){

		resultado = ((resultado) + diffDeDias);

	}
	return (resultado);
}
DateTime& DateTime::operator= (const DateTime& d){
	
		this->setMinuto(d.getMinuto());
		this->setHora(d.getHora());
		this->setDia(d.getDia());
		this->setMes(d.getMes());
		this->setAnio(d.getAnio());

	return (*this);
}



DateTime DateTime::operator - (double d){

	int* listaDeValoresSegunDecimal= obtenerDiaHoraMinutoDesdeNumero(d);

	int anio = this->getAnio();
	int mes = this->getMes();
	//guardo en dia ya la suma de los dias que tengo con los que voy a agregar
	int dia = this->getDia()-listaDeValoresSegunDecimal[0];
	//guardo en hora ya la suma de las horas que tengo con las que voy a agregar
	int hora = this->getHora()-listaDeValoresSegunDecimal[1];
	//guardo en minuto ya la suma de los minutos que tengo con los que voy a agregar
	int minuto = this->getMinuto() - listaDeValoresSegunDecimal[2];
	
	double diffDeDias = 0;
	// me fijo en el rango de minutos para saber si no agrego horas
	if( minuto < 0){
		
		int horasParaAgregar = (int)(minuto / 60);
		minuto = (unsigned int)(minuto-(60*horasParaAgregar));
		hora -= horasParaAgregar;
	}
	if(hora < 0){

		int diasParaAgregar = (int)(hora / 24);
		hora = (int)(hora-(24*diasParaAgregar));
		dia -= diasParaAgregar;
	}
	if(dia < 0){

		diffDeDias = dia;
		dia = 1;
		mes++;
	}
	if(mes < 1){
		mes = 12;
		anio--;
	}
	DateTime resultado (anio,mes,dia,hora,minuto);
	if(diffDeDias<0){

		resultado = ((resultado) + (int)diffDeDias);

	}
	return (resultado);
}
/*
double DateTime::operator - (DateTime d){

	//(this->getAnio() - d->getAnio());


	


}*/



std::ostream& operator <<(std::ostream& stream, const DateTime& d) {
	
	const char* pref1 = "0";
	const char* pref2 = "00";
    
    return cout<<((d.getAnio()<100)?pref2:(d.getAnio()<1000)?pref1:"")<<d.getAnio()<<"/"<<
    	((d.getMes()<10)?pref1:"")<<d.getMes()<<"/"<< 
		 ((d.getDia()<10)?pref1:"")<<d.getDia()<<" "<< 
		  ((d.getHora()<10)?pref1:"")<<d.getHora()<<":"<<  
		   ((d.getMinuto()<10)?pref1:"")<<d.getMinuto()<<endl;

}

/*
	#define DEBUG__

	#ifdef DEBUG__
void Log(char* c){
	cout << c << endl;
}

	#endif

#ifndef DEBUG__
void Log(char *c){}
#endif
*/