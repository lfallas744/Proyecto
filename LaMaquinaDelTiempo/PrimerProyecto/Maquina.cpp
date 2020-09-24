#include"Maquina.h"

Maquina::Maquina(int id , string nom ,MonderoElectronico* mone) {
	identificador = id;
	nombre = nom;
	monedero = mone;

	this->capacidadActual = 20;
	this->cantidad = 0;
	this->coleccion = new Producto * [this->capacidadActual];

	for (int i = 0; i < this->capacidadActual; i++)
	{
		this->coleccion[i] = nullptr;
	}
}

int Maquina::getIdentificador() {
	return identificador;
}
string Maquina::getNombre() {
	return nombre;
}
void Maquina::setNombre(string n) {
	this->nombre = n;
}
string Maquina::toString() {
	stringstream s;
	s << this->nombre << " numero de identificador: " << this->identificador << '\n';
	Iterador* ite =  obtenerIterador();
	while (ite->haySiguiente()) {
		s << ite->obtenerProducto()->toString() << '\n';
	}
	delete ite;
	return s.str();
}
void Maquina::insertar(Producto* produc) {
	asegurarCapacidad();
	this->coleccion[this->cantidad++] = produc;
}
void Maquina::agregarProvisiones(string idProducto, int cantidad) {
	int cantActual = this->consultar(idProducto)->getCantidad();
	this->consultar(idProducto)->setCantidad(cantActual+cantidad);
}
void Maquina::disminuirProvisiones(string idProducto, int cantidad) {
	int cantActual = this->consultar(idProducto)->getCantidad();
	this->consultar(idProducto)->setCantidad(cantActual - cantidad);
}
void Maquina::borrar(string id) {
	int pos = 0;
	for (int i = 0; i < cantidad; i++) {
		if (id == coleccion[i]->getCodigo()) {
			delete this->coleccion[i];
			pos = i;
		}
	}
	for (int i = pos; i < this->cantidad - 1; i++) {
		this->coleccion[i] = coleccion[i + 1];
	}

	this->coleccion[this->cantidad - 1] = nullptr;
	this->cantidad--;

}
Producto* Maquina::consultar(string id) {
	for (int i = 0; i < cantidad; i++) {
		if (id == coleccion[i]->getCodigo())
			return coleccion[i];
		
	}
	return nullptr;
}
void Maquina::ingresarDinero() {
	int dinero = 0;
	cout << "Ingrese la cantidad de dinero " << endl;
	cin >> dinero;
	monedero->setDinero(dinero);
}
void Maquina::retirarDinero(int cantidad) {
	int dinero = monedero->getDinero();
	monedero->setDinero(dinero - cantidad);
}
string Maquina::realizarCompra(string id, int cantidad, int montoPago) {
	this->disminuirProvisiones(id, cantidad);
	return monedero->desgloceVuelto(montoPago);
}

Iterador* Maquina::obtenerIterador()
{
	return new Iterador(this->coleccion,this->cantidad);
}

Maquina::~Maquina() {
	delete[] this->coleccion;
	delete monedero;
}
void Maquina::asegurarCapacidad()
{
	if (this->cantidad == this->capacidadActual)
	{
		
		this->capacidadActual = capacidadActual * 2;
		Producto** nuevoArreglo = new Producto * [this->capacidadActual];

		
		for (int i = 0; i < this->cantidad; i++)
		{
			nuevoArreglo[i] = this->coleccion[i];
		}

		
		delete[] this->coleccion;
		this->coleccion = nuevoArreglo;


		for (int i = this->cantidad; i < this->capacidadActual; i++)
		{
			this->coleccion[i] = nullptr;
		}
	}
}