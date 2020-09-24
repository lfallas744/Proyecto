#pragma once
#include"IMaquinaAdministradora.h"
#include"IMaquinaVendedora.h"
#include"MonderoElectronico.h"
#include"Iterador.h"

class Maquina :public IMaquinaAdministradora, public IMaquinaVendedora {
private:
	int identificador;
	string nombre;
	Producto** coleccion;
	int cantidad, capacidadActual;
	MonderoElectronico* monedero;
public:
	Maquina(int id = 0, string nom = "",MonderoElectronico* mone=nullptr);
	void asegurarCapacidad();
	virtual ~Maquina();

	int getIdentificador() override;
	string getNombre() override;
	void setNombre(string) override;
	string toString() override;
	void insertar(Producto*) override;
	void agregarProvisiones(string idProducto, int cantidad) override;
	void disminuirProvisiones(string idProducto, int cantidad) override;
	void borrar(string id) override;
	Producto* consultar(string id) override;
	void ingresarDinero() override;
	void retirarDinero(int cantidad) override;


	
	string realizarCompra(string id, int cantidad, int montoPago) override;

};