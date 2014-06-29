#ifndef USUARIOCONTROLADOR_H
#define USUARIOCONTROLADOR_H
#include "IUsuarioControlador.h"
#include "Usuario.h"
#include "Recurso.h"
#include "Accion.h"
// #include "DataUsuario.h"
#include "Colaborador.h"
#include "DataInformacionUsuario.h"
#include "ManejadorUsuario.h"
#include "ManejadorRecursos.h"
#include "ManejadorColaborador.h"
#include "DataAccion.h"

using namespace std;

class UsuarioControlador : public IUsuarioControlador{
	private:
		list<Recurso> recCreados;
		list<Colaborador> colaboracionList;
		list<Accion> accList;
		Usuario * usuarioElegido;
		bool existe;
		DataUsuario dataUsuarioIngresar;
		string nickname;
		int id;

	public:
		//Constructores
		UsuarioControlador();
		UsuarioControlador(int);
		UsuarioControlador(const UsuarioControlador&);

		//Destructor	
		~UsuarioControlador();

		//Setters
		void setRecCreados(list<Recurso>);
		void setcolaboracionList(list<Colaborador>);
		void setAccList(list<Accion>);
		void setUsuarioElegido(Usuario *);
		void setDataUsuarioIngresar(DataUsuario);
		void setNickname(string);

		//Getters
		list<Recurso> getRecCreados();
		list<Colaborador> getcolaboracionList();
		list<Accion>getAccList();
		Usuario* getUsuarioElegido();
		DataUsuario& getDataUsuarioIngresar();
		string getNickname();

		bool checkeoNickname(string);
		void ingresarDatosUsuario(DataUsuario);
		void guardarUsuario();
		DataInformacionUsuario obtenerInformacionUsuario();
		list<DataUsuario> listarUsuarios();
		void elegirUsuario(string);
		int getId();
};
#endif