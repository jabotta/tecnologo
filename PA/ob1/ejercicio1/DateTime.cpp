#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "DateTime.h"

using namespace std;

// Constructores
// Instancia DateTime con fecha y hora del sistema;
DateTime::DateTime(){
	time_t t;
	struct tm * now;

	t = time(NULL);	
	now = localtime (&t);

    y = now->tm_year + 1900;
    m = now->tm_mon + 1;
    d = now->tm_mday;
    h = now->tm_hour;
    i = now->tm_min;
};

// ESTATICA: DateTime d(2014,3,28,15,10);
// DINAMICA: DateTime d = new DateTime(2014,3,28,15,10);
DateTime::DateTime(int yy, int mm, int dd, int hh, int ii){
    y = yy;
    m = mm;
    d = dd;
    h = hh;
    i = ii;
}

// Instancia por copia
DateTime::DateTime(DateTime &dt){
	y = dt.getAnio();
    m = dt.getMes();
    d = dt.getDia();
    h = dt.getHora();
    i = dt.getMinuto();
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
void DateTime::printComp(Comparable * c){
    DateTime *a = dynamic_cast<DateTime *>(c);
	 cout <<"fecha es: " <<(*a) << endl;
}
//Operacion abstracta de Comparable
int DateTime::comparar(Comparable *c){
    DateTime *a = dynamic_cast<DateTime *>(c);
    cout << (*this);
    cout << (*a) << endl;
  /*  cout << "FECHAS: ";
    cout << " ";
    cout << (this->getAnio() < a->getAnio())<<endl;
    cout << "Igual: " << ((*this) == (*a)) << endl;
    cout << "Menor: " << ((*this) < (*a)) << endl;
    cout << "Mayor: " << ((*this) > (*a)) << endl;
    */
	if((*this) == (*a))
		return 0;	
	else if((*this) < (*a))
		return -1;	
	else if ((*this) > (*a))
		return 1;
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
			else if (this->getDia() == dt.getDia()){
			 	if (this->getHora() < dt.getHora())
					return true;
				else if (this->getHora() == dt.getHora())
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
	int dias = (int)d;

	double decimalValFact = d-(double)dias;
	//calculos minutos totales
	double mFact = decimalValFact*24*60;
	//calculo de la cantidad de horas
	int hora = mFact/60;
	//calulo de la cantidad de minutos restantes que no completan la hora
	res[0] = dias;
	res[1] = hora;
	res[2] = round((mFact/60-(double)hora)*60);
	return res;
} 

bool DateTime::esBiciesto(int anio){
	//calculo del anio biciesto segun algoritmo
	return (anio % 4 == 0 && ( anio % 100 != 0  || anio % 400 == 0 ));
}

int DateTime::obtenerMaximoDiaDelMes(int mes, int anio){
	
	if(mes == 2)
		return (esBiciesto(anio)) ? 29 : 28;
	else{
		if(mes<8)
			return (mes % 2 == 0) ? 30 : 31;
		else
			return (mes % 2 == 0) ? 31 : 30;
	}
}

DateTime DateTime::operator + (double d){

	int maxDias = obtenerMaximoDiaDelMes(this->getMes(),this->getAnio());

	int* listaDeValoresSegunDecimal= obtenerDiaHoraMinutoDesdeNumero(d);
	int anio = this->getAnio();
	int mes = this->getMes();
	//guardo en dia ya la suma de los dias que tengo con los que voy a agregar
	int dia = this->getDia()+listaDeValoresSegunDecimal[0];
	//guardo en hora ya la suma de las horas que tengo con las que voy a agregar
	int hora = this->getHora()+listaDeValoresSegunDecimal[1];
	//guardo en minuto ya la suma de los minutos que tengo con los que voy a agregar
	int minuto = this->getMinuto() + listaDeValoresSegunDecimal[2];
	
	//cout<< " "<<listaDeValoresSegunDecimal[0]<<  " "<<listaDeValoresSegunDecimal[1] << " "<<listaDeValoresSegunDecimal[2]<<endl;
	double diffDeDias = 0;
	
	// me fijo en el rango de minutos para saber si no agrego horas
	// repito el algoritmo de manera analoga para horas y dias 
	if(minuto >= 60){

		int horasParaAgregar = (int)(minuto / 60);
		minuto = minuto-(60*horasParaAgregar);
		hora += horasParaAgregar;
	}

	if(hora >= 24){
		
		int diasParaAgregar = (int)(hora / 24);
		hora = hora-(24*diasParaAgregar);
		dia += diasParaAgregar;
	}

	if(dia > maxDias){
		
		diffDeDias = dia-maxDias-1;
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

DateTime& DateTime::operator = (const DateTime& d){
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
	
		int horasParaQuitar = (int)(minuto / 60);
		minuto = (int)(60+minuto);
		hora -= horasParaQuitar;
	}
	if(hora < 0){
		
		int diasParaQuitar= (int)(hora / 24);
		hora = (int)(24+hora);
		dia --;
	} 

	if(dia < 1){
	
		int prevMes = (this->getMes()==1)?12:this->getMes()-1;
		int lastDayOfPrevMonth = obtenerMaximoDiaDelMes(prevMes,this->getAnio());	
		diffDeDias = dia; 
		dia = lastDayOfPrevMonth;
		mes--;
	}

	if(mes < 1){
		mes = 12;
		anio--;
	}

	DateTime resultado (anio,mes,dia,hora,minuto);

	if(diffDeDias<0){
		resultado = ((resultado) - -diffDeDias);
	}
	return (resultado);
}

double DateTime::operator - (DateTime d){
	
	//if the DateTime are equals the difference between them
	if( this->getAnio()==d.getAnio() && this->getMes()==d.getMes() && this->getDia()==d.getDia())return 0;
	
	DateTime start;
    DateTime end;
    
    if((*this) > d){

        start = d;
        end = (*this);
 
    }else{

        end = d;
        start = (*this);

    } 
	
	if(end.getAnio() == start.getAnio()){

		int daysDiff = 0 ;
		if(start.getMes()!=end.getMes()){
			
			int currentMonth = start.getMes()+1;

			while(currentMonth != end.getMes()){

				daysDiff += DateTime::obtenerMaximoDiaDelMes(currentMonth,start.getAnio());
				currentMonth++;

			}

			int dayDiffToEndMonth = DateTime::obtenerMaximoDiaDelMes(start.getMes(),start.getAnio())-start.getDia();
			daysDiff += dayDiffToEndMonth + end.getDia();

	 		return daysDiff;
		
		}else{

			daysDiff += end.getDia()-start.getDia();

			return daysDiff;
		}
 
	}else{

		
		int daysDiff = 0 ;
		int currentMonth = start.getMes()+1;

		while(currentMonth <= 12){

			daysDiff += DateTime::obtenerMaximoDiaDelMes(currentMonth,start.getAnio());
			currentMonth++;

		}

 		currentMonth = 1;
		while(currentMonth != end.getMes()){

			daysDiff += DateTime::obtenerMaximoDiaDelMes(currentMonth,end.getAnio());
			currentMonth++;

		}

		int dayDiffToEndMonth = DateTime::obtenerMaximoDiaDelMes(start.getMes(),start.getAnio())-start.getDia();

		daysDiff += dayDiffToEndMonth+end.getDia();
		
		int currentYear = start.getAnio()+1;

		while(currentYear != end.getAnio()){

			daysDiff += (DateTime::esBiciesto(currentYear))? 366 : 365 ;
			currentYear++;
		}
		

		return daysDiff;
	} 
}
 
std::ostream& operator << (std::ostream& stream, const DateTime& d) {
	const char* pref1 = "0";
	const char* pref2 = "00";
    return cout << ((d.getAnio() < 100) ? pref2 : (d.getAnio() < 1000) ? pref1 : "") << d.getAnio() << "/" <<
    	((d.getMes() < 10) ? pref1 : "") << d.getMes() << "/" << 
		((d.getDia() < 10) ? pref1 : "") << d.getDia() << " " << 
		((d.getHora() < 10)? pref1 : "") << d.getHora() << ":" <<  
		((d.getMinuto() < 10) ? pref1 : "") << d.getMinuto() << endl;

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
