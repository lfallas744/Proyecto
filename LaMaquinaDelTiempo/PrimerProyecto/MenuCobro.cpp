#include "MenuCobro.h"

MenuCobro::MenuCobro(IMaquinaVendedora* maquinaVende){
	this->maquina = maquinaVende;
}

void MenuCobro::InvocarMenu(){
	const char opcionSalida = '3';
	char opcion;
	do {
		opcion = MostrarOpciones();
		switch (opcion)
		{
		case '1':
			this->MostrarProductos();
			break;
		case '2':
			this->SeleccionarProducto();
			break;
		case opcionSalida:
			break;
		default:
			cerr << "Opcion invalida, digite otra vez" << endl;
		}
	} while (opcion != opcionSalida);

}

char MenuCobro::MostrarOpciones(){
	char opcion;
	system("cls");
	cout << "Menu Cobro:" << endl;
	cout << "1) Mostrar Productos" << endl;
	cout << "2) Seleccionar Producto" << endl;
	cout << "3) Salir" << endl;
	cin >> opcion;
	system("cls");
	return opcion;
}

void MenuCobro::MostrarProductos(){

	this->maquina->toString();

}

void MenuCobro::SeleccionarProducto() {
	string idPro;
	int si;

	cout << "Ingrese el Id del producto a seleccionar" << endl;
	cin >> idPro;
	
	if (this->maquina->consultar(idPro)!=nullptr) {
		cout << "Desea comprar el producto" << endl;
		cout << "1- Si "<< endl;
		cout << "2- No" << endl;
		cin >> si;
		if (si == 1) {
			RealizarCompra(idPro);
		}
	}

}

void MenuCobro::RealizarCompra(string id) {
	int cantidad;
	int montoPag;
	cout << "Digite la cantidad de productos que va a comprar" << endl;
	cin >> cantidad;
	cout << "Digite el monto con el que va a cancelar" << endl;
	cin >> montoPag;
	cout<<this->maquina->realizarCompra(id, cantidad, montoPag)<<endl;
}