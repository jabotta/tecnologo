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

#define MAX_LARGO_MENSAJE 255
#define MAX_LARGO_ARCHIVO 65535


using namespace std;


void WriteLogFile(const char* szString)
{
	time_t t;
	struct tm * now;

	t = time(NULL);	
	now = localtime (&t);
	FILE* pFile = fopen("logFile.txt", "a");
	fprintf(pFile, "%i/%i/%i %i:%i - %s\n",now->tm_mday, now->tm_mon + 1, now->tm_year + 1900, now->tm_hour, now->tm_min, szString);
	fclose(pFile);
 }

void manejadorSenhales (int signal)
// Manejador de las senhales.
// Aca se debe implementar la accion a realizar cuando se recibe la senhal
// Deberia haber un manejador de senhales para cada hijo si hacen cosas distintas
{
	if (signal == SIGINT)
	{
        WriteLogFile("SIGINT CTRL+C recibido");
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGINT CTRL+C recibido\33[00m\n"; 
	}
	if (signal == SIGTERM)
	{
		WriteLogFile("SIGTERM Terminacion de programa");
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGTERM Terminacion de programa\33[00m\n";
	}
	if (signal == SIGSEGV)
	{
		WriteLogFile("SIGSEGV violacion de segmento");
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGSEGV violacion de segmento\33[00m\n";
	}
	if (signal == SIGCHLD)
	{
		WriteLogFile("SIGCHLD");
		cout << "\33[46m\33[31m[" << "]" << " SIGCHLD \33[00m\n";
	}
	if (signal == SIGPIPE)
	{
		WriteLogFile("SIGPIPE");
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGPIPE \33[00m\n";
	}
	if (signal == SIGKILL)
	{
		WriteLogFile("SIGKILL");
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGKILL \33[00m\n";
	}
	if (signal == SIGSEGV)
	{
		WriteLogFile("SIGSEGV violacion de segmento");
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGSEGV violacion de segmento\33[00m\n";
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
	
	int pid = fork();	
	if (pid < 0)
	{
		WriteLogFile("Error al bifurcar.");
		printf ("\33[34mSERVIDOR\33[39m: \33[31mError al bifurcar.\33[39m\n");
		exit (1);
	}		
	
	//lector
	if (pid == 0)
	{
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
		printf("\33[34mRx\33[39m: Iniciada parte que recepciona mensajes. Pid %d\n", getpid());
		WriteLogFile("Iniciada parte que recepciona mensajes.");
		while (true)
		{
					
		}
	}
	
	//escritor
	if (pid > 0)
	{
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
		printf("\33[34mTx\33[39m: Iniciada parte que transmite mensajes. Pid %d\n", getpid());
		WriteLogFile("Iniciada parte que transmite mensajes.");
		while (true)
		{
					
		}
	}


	
	
	
	
	// Se debe Bifurcar el Programa
	// Al iniciar la parte que recibe imprimir lo siguiente descomentandolo
	//printf("\33[34mRx\33[39m: Iniciada parte que recepciona mensajes. Pid %d\n", getpid());  
	// Al iniciar la parte que transmite imprimir lo siguiente descomentandolo
	//printf("\33[34mTx\33[39m: Iniciada parte que transmite mensajes. Pid %d\n", getpid());
	
	// Es indistinto si el padre transmite y el hijo recibe, o viceversa, lo que si al ser distintos porcesos, deben tener distinto pid.
	
	// Familiarizarse con los comandos de UNIX ps, ps -as, kill, etc.
	
}
