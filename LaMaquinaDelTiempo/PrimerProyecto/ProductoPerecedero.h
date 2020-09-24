#pragma once
#include <stdio.h>
#include <ctime>
#include "Producto.h"
#include "Fecha.h"

static Fecha* fechActual = new Fecha();

class ProductoPerecedero : public Producto{
private:
	Fecha* fechaDeVencimiento;
public:
	ProductoPerecedero(string = "No definido", string = "No definido", float = 0.0, int = 0);
	float getPrecio();
	Fecha* getFecha();
	void setFecha(Fecha*);
	float calcularDescuento();
	string toString() override;
};

