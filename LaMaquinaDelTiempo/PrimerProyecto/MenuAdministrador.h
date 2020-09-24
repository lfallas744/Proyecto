#pragma once
#include"IMaquinaAdministradora.h"

class MenuAdministrador {
private:
	IMaquinaAdministradora* maquinaAdministradora;
public:
	MenuAdministrador(IMaquinaAdministradora* maquinaA);
	void invocarMenu();
private:
	char mostrarOpciones();
	void insertarProducto();
	void modificarProducto();
	void borrarInformacion();
	void ingresarDinero();
	void retirarDinero();
	void mostrar();

	Producto* crearProducto();
	ProductoPerecedero* crearProducPerecedero();
	ProductoNoPerecedero* crearProducNoPerecedero();
	
};