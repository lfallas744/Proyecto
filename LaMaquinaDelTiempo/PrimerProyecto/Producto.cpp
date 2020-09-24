#include "Producto.h"

Producto::Producto(string nombrepro, string id, float prec, int cant) {

	this->nombre = nombrepro;
	this->codigo = id;
	this->precio = prec;
	this->cantidad = cant;

}

Producto::~Producto() {

}

string Producto::getNombre() {
	return this->nombre;
}

string Producto::getCodigo() {
	return this->codigo;
}

int Producto::getCantidad() {
	return this->cantidad;
}

void Producto::setNombre(string nombrepro) {
	this->nombre = nombrepro;
}

void Producto::setCodigo(string id) {
	this->codigo = id;
}

void Producto::setPrecio(float prec) {
	this->precio = prec;
}

void Producto::setCantidad(int cant) {
	this->cantidad = cant;
}

string Producto::toString() {

	stringstream s;
	s << "******** Informacion del producto ********" << endl;
	s << "Nombre del Producto: " << this->nombre<<endl;
	s << "Codigo del producto: " << this->codigo<<endl;
	s << "Precio del producto: " << this->getPrecio() << endl;
	s << "Cantidad de productos en inventario: " << this->cantidad << endl;
	return s.str();
}