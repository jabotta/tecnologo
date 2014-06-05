// Redes de Computadoras - Curso 1er Semestre 2014
// Tecnologo en Informatica FIng - CETP
//
// Entrega 2  - Programacion con Sockets
// Sistema básico de Mensajería 

// Integrantes:
//	Detallar aqui, nombre, apellido y documento de todos los integrantes del grupo.

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
#define MAX_LARGO_ARCHIVO 65535
#define MAX_LARGO_IP 16

using namespace std;

bool LokeImYourFather = true, LokeImYourGrandFather = true; // soyPapucho para los amigos
long puertoMensajes, puertoArchivos, puertoAuth;
char *ipAuth;
int procesoHijo, procesoNieto;
int miSocketMensajes, miSocketArchivos, miSocketAuth;
struct sockaddr_in socket_destinatario, socket_miAddr, socket_auth;
int broadcastPermission; // Socket opt para setear permission a broadcast

// declaracion de variables usadas en la entrada
bool tieneIP, esArchivo, esBroadcast;
char direccionIP[MAX_LARGO_IP];
char mensaje[MAX_LARGO_MENSAJE];
char archivo[MAX_LARGO_ARCHIVO];
char usuario[100];
char clave[100];
// declaracion de variables para fecha y hora
time_t theTime = time(NULL);
struct tm *aTime = localtime(&theTime);

// declaracion de funciones
bool autenticar(char*, char*);
string nombreArchivo(string);
void limpiarVariablesEntrada();
void imprimirMensaje();
void descargarArchivo();
bool procesarEntrada();
void enviarMensaje();
void enviarArchivo();
void enviarMensajeBroadcast();
void generarLog(string);
void manejadorSenhales(int);

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

	cout << "Usuario: ";
	cin >> usuario;
	cout << "Clave: ";
	cin >> clave;

	if(!autenticar(usuario, clave)){
		cout << "[ERROR]" << endl;
		exit(-1);
	}

	stringstream ss;
    ss << "Autenticacion - usuario: " << usuario << " clave: " << clave;
    generarLog(ss.str());
	
	// struct sigaction sa;
 //    memset (&sa, 0, sizeof (sa));
 //    sa.sa_handler = &manejadorSenhales;

 //    sigaction(SIGINT, &sa, NULL);
 //    sigaction(SIGTERM, &sa, NULL);
 //    sigaction(SIGPIPE, &sa, NULL);
 //    sigaction(SIGSEGV, &sa, NULL);
 //    sigaction(SIGKILL, &sa, NULL);
 //    signal(SIGALRM, SIG_IGN);

 //    stringstream ss;
 //    ss << "puertoMensaje " << puertoMensajes << " puertoArchivos " << puertoArchivos << " - Autenticacion [ip: " << ipAuth << " puerto: " << puertoAuth << "]";
 //    generarLog(ss.str());

    // cout << "Redes de Computadoras: Sistema de Mensajeria" << endl;
    // if ((miSocketMensajes = socket(AF_INET, SOCK_DGRAM, 0)) == -1 )
    // {
    //     cout << "Error en socket() de mensajes" << endl;
    //     exit(-1);
    // }

    // if ((miSocketArchivos = socket(AF_INET, SOCK_DGRAM, 0)) == -1 )
    // {
    //     cout << "Error en socket() de archivos" << endl;
    //     exit(-1);
    // }

    // bzero((char *)&socket_miAddr, sizeof(socket_miAddr));
    // socket_miAddr.sin_family = AF_INET;
    // socket_miAddr.sin_addr.s_addr = INADDR_ANY;

    // procesoHijo = fork();
    // if (procesoHijo < 0)
    // {
    //     cout << "[ERROR]: Imposible Bifurcar." << endl;
    // }

    // if (procesoHijo == 0) // recibe mensajes
    // {
    // 	printf("\33[34mRx\33[39m: Iniciada parte que recepciona mensajes. Pid %d\n", getpid());

    //     socket_miAddr.sin_port = htons(puertoMensajes);
    //     if (bind(miSocketMensajes, (struct sockaddr *) &socket_miAddr, sizeof(socket_miAddr)) == -1)
    //     {
    //         cout << "Error en bind()" << endl;
    //         exit(-1);
    //     }

    //     LokeImYourFather = false;

    //     ss.str("");
    //     ss << getpid() << "#1 ";
    //     generarLog(ss.str(), false);

    //     while (true)
    //     {
    //         imprimirMensaje();
    //         sleep(2);
    //     }
    // }

    // if (procesoHijo > 0)
    // {
    //     procesoNieto = fork();
    //     if (procesoNieto < 0)
    //     {
    //         cout << "[ERROR]: Imposible Bifurcar." << endl;
    //     }

    //     if (procesoNieto == 0) // envia mensajes y archivos
    //     {
    //     	printf("\33[34mTx\33[39m: Iniciada parte que transmite mensajes. Pid %d\n", getpid());        	
    //         ss.str("");
    //         ss << getpid() << "#2 ";
    //         generarLog(ss.str(), false);

    //         LokeImYourGrandFather = false;

    //         bzero((char *) &socket_destinatario, sizeof(socket_destinatario));
    //         socket_destinatario.sin_family = AF_INET;

    //         while (true)
    //         {
    //             if (procesarEntrada())
    //             {
    //                 if (esBroadcast)
    //                 {
    //                     if (esArchivo)
    //                         cout << "broadcast del archivo " << archivo << endl; // envia archivo con broadcast
    //                     else
    //                         socket_destinatario.sin_port = htons(puertoMensajes);
    //                     enviarMensajeBroadcast();
    //                 }
    //                 else
    //                 {
    //                     if (esArchivo)
    //                     {
    //                         socket_destinatario.sin_port = htons(puertoArchivos);
    //                         enviarArchivo();
    //                     }
    //                     else
    //                     {
    //                         socket_destinatario.sin_port = htons(puertoMensajes);
    //                         enviarMensaje();
    //                     }
    //                 }
    //             }
    //             limpiarVariablesEntrada();
    //             sleep (2);
    //         }
    //     }

    //     if (procesoNieto > 0) // descarga archivo
    //     {
    //         socket_miAddr.sin_port = htons(puertoArchivos);
    //         if (bind(miSocketArchivos, (struct sockaddr *) &socket_miAddr, sizeof(socket_miAddr)) == -1)
    //         {
    //             cout << "Error en bind()" << endl;
    //             exit(-1);
    //         }

    //         ss.str("");
    //         ss << getpid() << "#3 ";
    //         generarLog(ss.str(), false);

    //         while (true)
    //         {
    //             descargarArchivo();
    //             sleep(2);
    //         }
    //     }
    // }
	
}

bool autenticar(char *usuario, char  *clave){
	miSocketAuth = socket(AF_INET, SOCK_DGRAM, 0);
	if (miSocketAuth == -1 ){
        cout << "Error en socket() de autenticacion" << endl;
        return false;
    }

	// strcpy (mensaje,usuario);
	// strcat (mensaje,"-");
	// strcat (mensaje,clave);
    // bzero((char *) &socket_auth, sizeof(socket_auth));
    // socket_auth.sin_family = AF_INET;
    // socket_auth.sin_addr.s_addr = inet_addr(ipAuth);    
    // if (sendto(miSocketAuth, mensaje, strlen(mensaje), 0, (struct sockaddr *)&socket_auth, sizeof(socket_auth)) == -1){
    //     cout << "Error en sendto" << endl;
    //     return false;
    // }

    // bzero((char *)&socket_miAddr, sizeof(socket_miAddr));  
    // socket_miAddr.sin_family = AF_INET;
    // socket_miAddr.sin_addr.s_addr = INADDR_ANY;
    // socket_miAddr.sin_port = htons(puertoAuth);
    // if (bind(miSocketAuth, (struct sockaddr *) &socket_miAddr, sizeof(socket_miAddr)) == -1){
    //     cout << "Error en bind()" << endl;
    //     exit(-1);
    // }

    // char buffer[MAX_LARGO_MENSAJE];
    // struct sockaddr_in addrEmisor;
    // socklen_t addrEmisor_tamanio = sizeof(addrEmisor);
    // bzero(buffer, MAX_LARGO_MENSAJE);
    // if (recvfrom(miSocketAuth, buffer, MAX_LARGO_MENSAJE, 0, (struct sockaddr *)&addrEmisor, &addrEmisor_tamanio) != -1){
    //     cout << inet_ntoa(addrEmisor.sin_addr) << " " << buffer << endl;
    // }else{
    //     cout << "Error en recvfrom()" << endl;
    // }

    return true;
}

string nombreArchivo(string ruta)
{
    unsigned indice = ruta.find_last_of("/");
    return ruta.substr(indice + 1);
}

void enviarArchivo()
{
    char buffer[MAX_LARGO_ARCHIVO];

    FILE * pFile;
    size_t tamanio = 0;
    int resultado;

    socket_destinatario.sin_addr.s_addr = inet_addr(direccionIP);

    pFile = fopen ( "v.txt" , "rb" );
    if (pFile == NULL)
    {
        cout << "error " << endl;
    }
    else
    {
        while ((tamanio = fread(buffer, sizeof(char), sizeof(buffer), pFile)) > 0)
        {
            cout << "a1 " << tamanio << endl;
            resultado = sendto(miSocketArchivos, buffer, tamanio, 0, (struct sockaddr *)&socket_destinatario, sizeof(socket_destinatario));
            if (resultado == -1)
            {
                cout << "error en sendto" << endl;
            }
        }
    }
    fclose (pFile);
    cout << "archivo enviado";
}

void imprimirMensaje()
{
    char buffer[MAX_LARGO_MENSAJE];
    struct sockaddr_in addrEmisor;
    socklen_t addrEmisor_tamanio = sizeof(addrEmisor);
    bzero(buffer, MAX_LARGO_MENSAJE);
    if (recvfrom(miSocketMensajes, buffer, MAX_LARGO_MENSAJE, 0, (struct sockaddr *)&addrEmisor, &addrEmisor_tamanio) != -1)
    {
        // stringstream ss;
        // ss << "[" << fechaHora() << "] " << inet_ntoa(addrEmisor.sin_addr) << " " << buffer;
        // generarLog(ss.str());
        // ss.str("");
    }
    else
    {
        cout << "recvfrom" << endl;
    }
}

void descargarArchivo()
{
    FILE * pFile;
    ssize_t tamanio = 0;

    struct sockaddr_in addrEmisor;
    socklen_t addrEmisor_tamanio;

    char buffer[MAX_LARGO_MENSAJE];

    pFile = fopen("archivos.log" , "wb");

    while ((tamanio = recvfrom(miSocketArchivos, buffer, MAX_LARGO_MENSAJE, 0, (struct sockaddr *)&addrEmisor, &addrEmisor_tamanio)) > 0)
    {
        cout << tamanio << endl;
        fwrite(buffer, sizeof(char), tamanio, pFile);
        cout << "fin " << endl;
    }

    fclose (pFile);
    cout << "archivo cerrado" << endl;
}

bool procesarEntrada()
{
    int posicion = 0, n = 0;
    esBroadcast = false;
    esArchivo = false;
    char entrada[MAX_LARGO_MENSAJE + MAX_LARGO_IP];

    bzero(entrada, MAX_LARGO_MENSAJE + MAX_LARGO_IP);
    limpiarVariablesEntrada();

    fgets(entrada, MAX_LARGO_MENSAJE + MAX_LARGO_IP - 1, stdin);
    // generarLog(entrada);

    if (strlen(entrada) > 0)
    {
        // es broadcast o IP?
        if (entrada[0] == '*')
        {
            esBroadcast = true;
            posicion = 1; // posicion del supuesto espacio
        }
        else
        {
            for (int i = 0; i <=  (signed)strlen(entrada); i++)
            {
                if (entrada[i] != ' ')
                {
                    direccionIP[i] = entrada[i];
                }
                else
                {
                    posicion = i;
                    break;
                }
            }
        }

        // verifica si la entrada es valida
        if (posicion <= (signed)strlen(entrada))   // es un largo valido
        {
            if (entrada[posicion] == ' ')   // existe el espacio
            {
                posicion++; // comienzo del mensaje o &file
                // verifica si es &file
                if (posicion + 5 <= (signed)strlen(entrada))
                {
                    if (entrada[posicion] == '&' && entrada[posicion + 1] == 'f' && entrada[posicion + 2] == 'i' && entrada[posicion + 3] == 'l' && entrada[posicion + 4] == 'e' && entrada[posicion + 5] == ' ')
                    {
                        esArchivo = true;
                        posicion+=6;
                    }
                }

                // extrae el nombre del archivo o el mensaje de la entrada
                for (int i = posicion; i <= (signed)strlen(entrada); i++)
                {
                    if (esArchivo)
                        archivo[n] = entrada[i];
                    else
                        mensaje[n] = entrada[i];
                    n++;
                }
                return true;
            }
        }
    }
    return false;
}

void limpiarVariablesEntrada()
{
    bzero(direccionIP, MAX_LARGO_IP);
    bzero(mensaje, MAX_LARGO_MENSAJE);
    bzero(archivo, MAX_LARGO_ARCHIVO);
}

void enviarMensaje()
{
    socket_destinatario.sin_addr.s_addr = inet_addr(direccionIP);
    if (sendto(miSocketMensajes, mensaje, strlen(mensaje), 0, (struct sockaddr *)&socket_destinatario, sizeof(socket_destinatario)) == -1)
    {
        cout << "Error en sendto" << endl;
    }
}

void enviarMensajeBroadcast()
{
    broadcastPermission = 1;
    if (setsockopt(miSocketMensajes, SOL_SOCKET, SO_BROADCAST, (void *) &broadcastPermission, sizeof(broadcastPermission)) == -1)
    {
        cout << "Error en setsockopt" << endl;
    }
    socket_destinatario.sin_addr.s_addr = inet_addr("255.255.255.255");
    if (sendto(miSocketMensajes, mensaje, strlen(mensaje), 0, (struct sockaddr *)&socket_destinatario, sizeof(socket_destinatario)) == -1)
    {
        cout << "Error en sendto de broadcast" << endl;
    }
}

void generarLog(string texto)
{
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

void manejadorSenhales (int signal)
// Manejador de las senhales.
// Aca se debe implementar la accion a realizar cuando se recibe la senhal
// Deberia haber un manejador de senhales para cada hijo si hacen cosas distintas
{
    if (signal == SIGINT)
    {
        cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGINT CTRL+C recibido\33[00m\n";
        close(miSocketMensajes);
        close(miSocketArchivos);
    }
    if (signal == SIGTERM)
    {
        cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGTERM Terminacion de programa\33[00m\n";
    }
    if (signal == SIGSEGV)
    {
        cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGSEGV violacion de segmento\33[00m\n";
    }
    if (signal == SIGCHLD)
    {
        cout << "\33[46m\33[31m[" << "]" << " SIGCHLD \33[00m\n";
    }
    if (signal == SIGPIPE)
    {
        cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGPIPE \33[00m\n";
    }
    if (signal == SIGKILL)
    {
        cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGKILL \33[00m\n";
    }
    if (signal == SIGSEGV)
    {
        cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGSEGV violacion de segmento\33[00m\n";
    }
    exit(1);
}