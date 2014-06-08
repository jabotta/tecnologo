#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sstream>
#include <string>
#include <fstream>
#include <time.h>

#define MAX_LARGO_MENSAJE 255
#define MAX_LARGO_IP 16

using namespace std;

long puertoMensajes, puertoArchivos, puertoAuth;
char *ipAuth;
int miSocketAuth;
struct sockaddr_in socket_miAddr, socket_auth;

// declaracion de variables usadas en la entrada
char mensaje[MAX_LARGO_MENSAJE];
char usuario[100];
char clave[100];

// declaracion de funciones
void generarLog(string);


int main(int argc, char * argv[])
// En argc viene la cantidad de argumentos que se pasan,
// si se llama solo al programa, el nombre es el argumento 0
// En nuestro caso:
//      - argv[0] es el string "mensajeria", puede cambiar si se llama con otro path.
//      - argv[1] es el puerto de escucha de mensajeria.
//      - argv[2] es el ip del servidor de autenticacion.
//      - argv[3] es el puerto del servidor de autenticación.
{

    if (argc < 4)
    {
        cout << "\33[46m\33[31m[ERROR]:" << " Faltan argumentos: port, ipAuth, portAuth.\33[00m\n";
	 exit (1);
    }

    puertoMensajes = atoi(argv[1]);
    puertoArchivos = puertoMensajes + 1;
    ipAuth = argv[2];
    puertoAuth = atoi(argv[3]);	

    miSocketAuth = socket(AF_INET, SOCK_STREAM, 0);
    if (miSocketAuth == -1 ){
        cout << "Error en socket() de autenticacion" << endl;
        return false;
    }    

    //strcpy (mensaje,"aturing-35ecb6586f632e010e2347cd37b8e196"); 

    socket_auth.sin_family = AF_INET;
    socket_auth.sin_port = htons(puertoAuth);
    socket_auth.sin_addr.s_addr = inet_addr(ipAuth);
    bzero(&(socket_auth.sin_zero),8);

    if (connect(miSocketAuth, (struct sockaddr *)&socket_auth, sizeof(socket_auth)) == -1){
        cout << "connect error" ;
    }

    cout << "Usuario: ";
    cin >> usuario;
    cout << "Clave: ";
    cin >> clave;
	
    strcpy (mensaje,usuario);
    strcat (mensaje,"-");
    strcat (mensaje,clave);

    //if (send(miSocketAuth, mensaje, sizeof(mensaje), 0) == -1){
    //    cout << "Error en send" << endl;
    //    return false;
    //}

    //char buffer[MAX_LARGO_MENSAJE];
    //struct sockaddr_in addrEmisor;
    //socklen_t addrEmisor_tamanio = sizeof(addrEmisor);
    //bzero(buffer, MAX_LARGO_MENSAJE);
    //if (recvfrom(miSocketAuth, buffer, MAX_LARGO_MENSAJE, 0, (struct sockaddr *)&addrEmisor, &addrEmisor_tamanio) != -1){
    //   cout << inet_ntoa(addrEmisor.sin_addr) << " " << buffer << endl;
    //}else{
    //    cout << "Error en recv()" << endl;
    //}

    if (write(miSocketAuth, mensaje, sizeof(mensaje)) == -1){
        cout << "Error en write()" << endl;
        return false;
    }

    char buffer[MAX_LARGO_MENSAJE];
    bzero(buffer, MAX_LARGO_MENSAJE);
    if (read(miSocketAuth, buffer, MAX_LARGO_MENSAJE) != -1){
        cout << buffer << endl;
    }else{
        cout << "Error en read()" << endl;
    }

    stringstream ss;
    ss << "Autenticacion - " << mensaje << endl;
    ss << buffer << endl;
    generarLog(ss.str());
    
    close(miSocketAuth);    
	
}

void generarLog(string texto)
{
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);
    	time_t t;
	struct tm * now;

	t = time(NULL);	
	now = localtime (&t);

	stringstream fecha;
       fecha.str("");
       fecha << "[" << now->tm_mday << "/" << now->tm_mon + 1 << "/" << now->tm_year + 1900<< " " << aTime->tm_hour << ":" << aTime->tm_min << "] - ";

	ofstream archivo_log("mensajeria.log", ios::out | ios::app);
       archivo_log << fecha.str() << texto << endl;
       archivo_log.close();
}

