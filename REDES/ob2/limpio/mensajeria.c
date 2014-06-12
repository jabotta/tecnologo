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
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <sstream>
#include <fstream>

#define MAX_LARGO_MENSAJE 255
#define MAX_LARGO_ARCHIVO 65535
#define MAX_LARGO_IP 16

using namespace std;

//variables
int messageSocket, fileSocket, authSocket;
struct sockaddr_in tramsmissorSocket, receptorSocket, authorizationSocket;
bool isFile, isBroadcast;
char ipAddress[MAX_LARGO_IP];
char myMessage[MAX_LARGO_MENSAJE];
char myFile[MAX_LARGO_ARCHIVO];
char user[100];
char password[100];
long messagePort, filePort, puertoAuth,authPort;
char *ipAuth;
int broadcastPermission; // Socket opt para setear permission a broadcast

bool autenticar();
void downloadFile();
void cleanEntries();
void sendMessage();
void sendFile();
void sendBroadcastMessage();
bool processEntry();
void printMessage();

void WriteLogFile(string texto){
	time_t t;
	struct tm * now;

	t = time(NULL);	
	now = localtime (&t);

	stringstream fecha;
    fecha.str("");
    fecha << "[" << now->tm_mday << "/" << now->tm_mon + 1 << "/" << now->tm_year + 1900<< " " << now->tm_hour << ":" << now->tm_min << "] - ";

	ofstream archivo_log("logFile.txt", ios::out | ios::app);
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
		stringstream ss;
		ss << "\33[46m\33[31m[" << getpid() << "]" << " SIGINT CTRL+C recibido\33[00m\n";
		WriteLogFile(ss.str());
	}
	if (signal == SIGTERM)
	{
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGTERM Terminacion de programa\33[00m\n";
		stringstream ss;
		ss << "\33[46m\33[31m[" << getpid() << "]" << " SIGTERM Terminacion de programa\33[00m\n";
		WriteLogFile(ss.str());
	}
	if (signal == SIGSEGV)
	{
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGSEGV violacion de segmento\33[00m\n";
		stringstream ss;
		ss << "\33[46m\33[31m[" << getpid() << "]" << " SIGSEGV violacion de segmento\33[00m\n";
		WriteLogFile(ss.str());
	}
	if (signal == SIGCHLD)
	{
		cout << "\33[46m\33[31m[" << "]" << " SIGCHLD \33[00m\n";
		stringstream ss;
		ss << "\33[46m\33[31m[" << "]" << " SIGCHLD \33[00m\n";
		WriteLogFile(ss.str());
	}
	if (signal == SIGPIPE)
	{
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGPIPE \33[00m\n";
		stringstream ss;
		ss << "\33[46m\33[31m[" << getpid() << "]" << " SIGPIPE \33[00m\n";
		WriteLogFile(ss.str());
	}
	if (signal == SIGKILL)
	{
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGKILL \33[00m\n";
		stringstream ss;
		ss << "\33[46m\33[31m[" << getpid() << "]" << " SIGKILL \33[00m\n";
		WriteLogFile(ss.str());
	}
	if (signal == SIGSEGV)
	{
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGSEGV violacion de segmento\33[00m\n";
		stringstream ss;
		ss << "\33[46m\33[31m[" << getpid() << "]" << " SIGSEGV violacion de segmento\33[00m\n";
		WriteLogFile(ss.str());
	}
	exit(1);
}

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

	messagePort = atoi(argv[1]);
	filePort = messagePort + 1;
	ipAuth = argv[2];
	authPort = atoi(argv[3]);	

	/*if(!autenticar()){
		cout << "Usuario o clave incorrectos" << endl;
		stringstream ss;
		ss << "Usuario o clave incorrectos";
		WriteLogFile(ss.str());
		exit(-1);
	}	*/
	
	// Estructuras para el manejo de Senhales
	// Deberia haber un manejador de señales para cada hijo si hacen cosas distintas
	// *********************************
	struct sigaction sa;
	memset (&sa, 0, sizeof (sa));
	sa.sa_handler = &manejadorSenhales;

	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL);
	sigaction(SIGPIPE, &sa, NULL);
	sigaction(SIGSEGV, &sa, NULL);
	sigaction(SIGKILL, &sa, NULL);
	signal(SIGALRM, SIG_IGN);
	// **********************************
	
	cout << "\33[34mRedes de Computadoras 2014\33[39m: Sistema de Mensajeria.\nEscuchando en el puerto " << argv[1] << ".\nProceso de pid: " << getpid() << ".\n";
	
	// Se debe Bifurcar el Programa
	// Al iniciar la parte que recibe imprimir lo siguiente descomentandolo
	//printf("\33[34mRx\33[39m: Iniciada parte que recepciona mensajes. Pid %d\n", getpid());  
	// Al iniciar la parte que transmite imprimir lo siguiente descomentandolo
	//printf("\33[34mTx\33[39m: Iniciada parte que transmite mensajes. Pid %d\n", getpid());
	
	// Es indistinto si el padre transmite y el hijo recibe, o viceversa, lo que si al ser distintos porcesos, deben tener distinto pid.
	
	// Familiarizarse con los comandos de UNIX ps, ps -as, kill, etc.
	
	if ((messageSocket = socket(AF_INET, SOCK_DGRAM, 0)) == -1 ){
		cout << "Error en socket() de mensajes" << endl;
		exit(-1);
	}
   	if ((fileSocket = socket(AF_INET, SOCK_DGRAM, 0)) == -1 ){
		cout << "Error en socket() de archivos" << endl;
		exit(-1);
	}

	bzero((char *)&tramsmissorSocket, sizeof(tramsmissorSocket));
	tramsmissorSocket.sin_family = AF_INET;
	tramsmissorSocket.sin_addr.s_addr = INADDR_ANY;

	int accion = fork();	
	if (accion < 0){

		printf ("\33[34mSERVIDOR\33[39m: \33[31mError al bifurcar.\33[39m\n");
		stringstream ss;
		ss << "\33[34mSERVIDOR\33[39m: \33[31mError al bifurcar.\33[39m\n";
		WriteLogFile(ss.str());
		exit (1);
	}	

	//lector
	if (accion == 0){

		printf("\33[34mRx\33[39m: Iniciada parte que recepciona mensajes. Pid %d\n", getpid());
		stringstream ss;
		ss << "\33[34mRx\33[39m: Iniciada parte que recepciona mensajes. Pid " << getpid();
		WriteLogFile(ss.str());
		tramsmissorSocket.sin_port = htons(messagePort);

		if (bind(messageSocket, (struct sockaddr *) &tramsmissorSocket, sizeof(tramsmissorSocket)) == -1){
			cout << "Error en bind()" << endl;
			exit(-1);
		}

		while (true){
			printMessage();
			sleep(2);
		}
	}

	//escritor

	if (accion > 0)
	{
    	printf("\33[34mTx\33[39m: Iniciada parte que transmite mensajes. Pid %d\n", getpid());
		stringstream ss;
		ss << "\33[34mRx\33[39m: Iniciada parte que transmite mensajes. Pid " << getpid();
		WriteLogFile(ss.str());
		
		int escritura = fork();
		if (escritura < 0){
			cout << "[ERROR]: Imposible Bifurcar." << endl;
			ss << "[ERROR]: Imposible Bifurcar.";
			WriteLogFile(ss.str());
		}

		if (escritura == 0){ // envia mensajes y archivos
			bzero((char *) &receptorSocket, sizeof(receptorSocket));
			receptorSocket.sin_family = AF_INET;
			while (true){
				if (processEntry()){
					if (isBroadcast){
						if (isFile)
							cout << "broadcast del archivo " << myFile << endl; // envia archivo con broadcast
						else
							receptorSocket.sin_port = htons(messagePort);
						sendBroadcastMessage();
					}else{
						if (isFile){
							receptorSocket.sin_port = htons(fileSocket);
							sendFile();
						}else{
							receptorSocket.sin_port = htons(messagePort);
							sendMessage();
						}
					}
				}
				cleanEntries();
				sleep (2);
			}
		}

		if (escritura > 0){ // descarga archivo
			tramsmissorSocket.sin_port = htons(filePort);
			if (bind(fileSocket, (struct sockaddr *) &tramsmissorSocket, sizeof(tramsmissorSocket)) == -1){
				cout << "Error en bind()" << endl;
				exit(-1);
			}
			while (true){
				downloadFile();
				sleep(2);
			}
		}
	}
	
}

bool autenticar(){
	authSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (authSocket == -1 ){
        cout << "Error en socket() de autenticacion" << endl;
        return false;
    }


    cout << "Usuario: ";
    cin >> user;
    cout << "Clave: ";
    cin >> password;
	strcpy (myMessage,user);

    bzero((char *) &authorizationSocket, sizeof(authorizationSocket));
    authorizationSocket.sin_family = AF_INET;
    authorizationSocket.sin_port = htons(puertoAuth);
    authorizationSocket.sin_addr.s_addr = inet_addr(ipAuth);

	int status;
	status = connect(authSocket, (struct sockaddr *)&authorizationSocket, sizeof(authorizationSocket));
	if (status == -1)  std::cout << "connect error" ;

    if (sendto(authSocket, user, sizeof(user), MSG_EOR, (struct sockaddr *)&authorizationSocket, sizeof(authorizationSocket)) == -1){
        cout << "Error en sendto" << endl;
        return false;
    }    

    stringstream ss;
    ss << "Autenticacion - usuario: " << user << " clave: " << password;
    WriteLogFile(ss.str());
	close(authSocket);
    return true;
}

void downloadFile(){
    FILE * pFile;
    ssize_t fileSize = 0;

    struct sockaddr_in addrEmisor;
    socklen_t addrEmisor_size;

    char buffer[MAX_LARGO_MENSAJE];

    pFile = fopen("archivos.log" , "wb");

    while ((fileSize = recvfrom(fileSocket, buffer, MAX_LARGO_MENSAJE, 0, (struct sockaddr *)&addrEmisor, &addrEmisor_size)) > 0)
    {
        cout << fileSize << endl;
        fwrite(buffer, sizeof(char), fileSize, pFile);
        cout << "fin " << endl;
    }

    fclose (pFile);
    cout << "archivo cerrado" << endl;
}

void cleanEntries(){
    bzero(ipAddress, MAX_LARGO_IP);
    bzero(myMessage, MAX_LARGO_MENSAJE);
    bzero(myFile, MAX_LARGO_ARCHIVO);
}

void sendMessage(){
    receptorSocket.sin_addr.s_addr = inet_addr(ipAddress);
    if (sendto(messageSocket, myMessage, strlen(myMessage), 0, (struct sockaddr *)&receptorSocket, sizeof(receptorSocket)) == -1)
    {
        cout << "Error en sendto" << endl;
    }
}

void sendFile(){
    char buffer[MAX_LARGO_ARCHIVO];

    FILE * pFile;
    size_t fileSize = 0;
    int result;

    receptorSocket.sin_addr.s_addr = inet_addr(ipAddress);
    pFile = fopen ( &myFile[0] , "rb" );
    if (pFile == NULL)
    {
        cout << "error " << endl;
    }
    else
    {
        while ((fileSize = fread(buffer, sizeof(char), sizeof(buffer), pFile)) > 0)
        {
            cout << "a1 " << fileSize << endl;
            result = sendto(fileSocket, buffer, fileSocket, 0, (struct sockaddr *)&receptorSocket, sizeof(receptorSocket));
            if (result == -1)
            {
                cout << "error en sendto" << endl;
            }
        }
    }
    fclose (pFile);
    cout << "archivo enviado";
}

void sendBroadcastMessage(){
    broadcastPermission = 1;
    if (setsockopt(messageSocket, SOL_SOCKET, SO_BROADCAST, (void *) &broadcastPermission, sizeof(broadcastPermission)) == -1)
    {
        cout << "Error en setsockopt" << endl;
    }
    receptorSocket.sin_addr.s_addr = inet_addr("255.255.255.255");
    if (sendto(messageSocket, myMessage, strlen(myMessage), 0, (struct sockaddr *)&receptorSocket, sizeof(receptorSocket)) == -1)
    {
        cout << "Error en sendto de broadcast" << endl;
    }
}

bool processEntry(){

    int position = 0, n = 0;
    isBroadcast = false;
    isFile = false;
    char inputString[MAX_LARGO_MENSAJE + MAX_LARGO_IP];

    bzero(inputString, MAX_LARGO_MENSAJE + MAX_LARGO_IP);
    cleanEntries();
    fgets(inputString, MAX_LARGO_MENSAJE + MAX_LARGO_IP - 1, stdin);
    if (strlen(inputString) > 0)
    {
        // es broadcast o IP?
        if (inputString[0] == '*')
        {
            isBroadcast = true;
            position = 1; // posicion del supuesto espacio
        }
        else
        {
            for (int i = 0; i <=  (signed)strlen(inputString); i++)
            {
                if (inputString[i] != ' ')
                {
                    ipAddress[i] = inputString[i];
                }
                else
                {
                    position = i;
                    break;
                }
            }
        }

        // verifica si la entrada es valida
        if (position <= (signed)strlen(inputString))   // es un largo valido
        {
            if (inputString[position] == ' ')   // existe el espacio
            {
                position++; // comienzo del mensaje o &file
                // verifica si es &file
                if (position + 5 <= (signed)strlen(inputString))
                {
                    if (inputString[position] == '&' && inputString[position + 1] == 'f' && inputString[position + 2] == 'i' && inputString[position + 3] == 'l' && inputString[position + 4] == 'e' && inputString[position + 5] == ' ')
                    {
                        isFile = true;
                        position+=6;
                    }
                }

                // extrae el nombre del archivo o el mensaje de la entrada
                for (int i = position; i <= (signed)strlen(inputString); i++)
                {
                    if (isFile)
                        myFile[n] = inputString[i];
                    else
                        myMessage[n] = inputString[i];
                    n++;
                }
                return true;
            }
        }
    }
    return false;
}

string fechaHora()
{
	time_t t;
	struct tm * now;

	t = time(NULL);	
	now = localtime (&t);
    stringstream ss;
    ss << now->tm_year + 1900 << "." << now->tm_mon + 1 << "." << now->tm_mday << " " << now->tm_hour << ":" << now->tm_min;
    return ss.str();
}

void printMessage(){
    char buffer[MAX_LARGO_MENSAJE];
    struct sockaddr_in addrEmisor;
    socklen_t addrEmisor_size = sizeof(addrEmisor);
    bzero(buffer, MAX_LARGO_MENSAJE);

    if (recvfrom(messageSocket, buffer, MAX_LARGO_MENSAJE, 0, (struct sockaddr *)&addrEmisor, &addrEmisor_size) != -1)
    {
        cout << "[" << fechaHora() << "] " << inet_ntoa(addrEmisor.sin_addr) << " " << buffer;
    }
    else
    {
        cout << "recvfrom" << endl;
    }
}
