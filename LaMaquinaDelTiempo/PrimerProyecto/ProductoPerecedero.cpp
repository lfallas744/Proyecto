#include "ProductoPerecedero.h"

ProductoPerecedero::ProductoPerecedero(string nomPro, string cod, float prec, int canti):Producto(nomPro, cod, prec, canti) {


}

float ProductoPerecedero::getPrecio() {
	return this->precio - calcularDescuento();
}

Fecha ProductoPerecedero::getFecha() {
	return this->fechaDeVencimiento;
}
void ProductoPerecedero::setFecha(Fecha fech) {
	this->fechaDeVencimiento = fech;
}
float ProductoPerecedero::calcularDescuento() {
	if (fechActual->difDias(this->fechaDeVencimiento)<=7) {
		return this->precio * (0.5);
	}
	return 0;
}
string ProductoPerecedero::toString() {

	stringstream s;
	s << Producto::toString();
	s << "Descuento por aplicar al producto: " << calcularDescuento() << endl;
	s << "Precio total del Producto: " << this->getPrecio() << endl;
	s << "Fecha de vencimiento del producto: " << this->fechaDeVencimiento.toString() << endl;
	return s.str();
}
