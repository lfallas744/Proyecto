#pragma once
#include <iostream>
#include <sstream>
#include "IMaquinaVendedora.h"
#include "Iterador.h"


class MenuCobro{
private:
	IMaquinaVendedora* maquina;
	
public:
	MenuCobro(IMaquinaVendedora*);
	void InvocarMenu();
	
private:
	char MostrarOpciones();
	void MostrarProductos();
	void SeleccionarProducto();
	void RealizarCompra(string);
};
