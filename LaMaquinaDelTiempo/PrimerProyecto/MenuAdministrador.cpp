#include"MenuAdministrador.h"
MenuAdministrador::MenuAdministrador(IMaquinaAdministradora* maquinaA) {
	maquinaAdministradora = maquinaA;
}
void MenuAdministrador::invocarMenu() {
	const char opcionSalida = '7';
	char opcion;
	do {
		opcion = mostrarOpciones();
		switch (opcion)
		{
		case '1':
			this->insertarProducto();
			break;
		case '2':
			this->modificarProducto();
			break;
		case '3':
			this->borrarInformacion();
			break;
		case '4':
			this->ingresarDinero();
			break;
		case '5':
			this->retirarDinero();
			break;
		case '6':
			this->mostrar();
			break;
		case opcionSalida:
			break;
		default:
			cerr << "Opcion invalida, digite otra vez" << endl;
		}
	} while (opcion != opcionSalida);
}

char MenuAdministrador::mostrarOpciones() {
	char opcion;
	system("cls");
	cout << "Menu Administrador:" << endl;
	cout << "1) Ingresar Producto" << endl;
	cout << "2) Modificar Producto" << endl;
	cout << "3) Borrar informacion de producto" << endl;
	cout << "4) Ingresar Dinero" << endl;
	cout << "5) Retirar Dinero" << endl;
	cout << "6) Mostrar Productos" << endl;
	cout << "7) Salir" << endl;
	cin >> opcion;
	system("cls");
	return opcion;
}
void MenuAdministrador::insertarProducto() {

	Producto* producto = crearProducto();
	this->maquinaAdministradora->insertar(producto);
}
Producto* MenuAdministrador::crearProducto() {
	int opc = 0;
	while (opc <= 2) {
		system("cls");
		cout << "Crear producto:" << endl;
		cout << "[1] Perecedero" << endl;
		cout << "[2] No Perecedero" << endl;
		switch (opc) {
		case 1:
			return crearProducPerecedero();
			break;
		case 2:
			return crearProducNoPerecedero();
			break;
		default:
			cerr << "¡No se encuentra la opcion ingresada! \n Intentelo de nuevo";
			system("pause");
			break;
		}
	}
	
}
ProductoPerecedero* MenuAdministrador::crearProducPerecedero() {
	string nombre, id;
	float precio;
	int cantidad, dia, mes, anho;
	cout << "Nombre:";
	cin >> nombre;
	cout << "ID:";
	cin >> id;
	cout << "Precio:";
	cin >> precio;
	cout << "Cantidad:";
	cin >> cantidad;
	cout << "Fecha de vencimiento: " << endl;
	cout << "Dia: ";
	cin >> dia;
	cout << "Mes: ";
	cin >> mes;
	cout << "Año: ";
	cin >> anho;
	ProductoPerecedero* produc = new ProductoPerecedero(nombre, id, precio, cantidad);
	produc->setFecha(new Fecha(dia,mes,anho));
	return produc;
}
ProductoNoPerecedero* MenuAdministrador::crearProducNoPerecedero() {
	string nombre, id;
	float precio,porcentaje;
	int cantidad;
	cout << "Nombre:" << endl;
	cin >> nombre;
	cout << "ID:" << endl;
	cin >> id;
	cout << "Precio:" << endl;
	cin >> precio;
	cout << "Cantidad:" << endl;
	cin >> cantidad;
	cout << "Porcentaje:" << endl;
	cin >> porcentaje;
	return new ProductoNoPerecedero(nombre,id,precio,cantidad,porcentaje);
}
void MenuAdministrador::modificarProducto() {
	string nombre, id;
	float precio;
	int cantidad;
	cout << "Ingrese el codigo del producto: ";
	cin >> id;
	cout << "Nuevo Nombre:" << endl;
	cin >> nombre;
	maquinaAdministradora->consultar(id)->setNombre(nombre);

	cout << "Nuevo Precio:" << endl;
	cin >> precio;
	maquinaAdministradora->consultar(id)->setPrecio(precio);

	cout << "Nuevo Cantidad:" << endl;
	cin >> cantidad;
	maquinaAdministradora->consultar(id)->setCantidad(cantidad);
	
}
void MenuAdministrador::borrarInformacion() {
	string id;
	cout << "Ingrese el codigo del producto: ";
	cin >> id;
	maquinaAdministradora->borrar(id);
}
void MenuAdministrador::ingresarDinero() {
	maquinaAdministradora->ingresarDinero();
}
void MenuAdministrador::retirarDinero() {
	int can;
	cout << "Ingrese la cantidad de dinero que desea retirar: ";
	cin >> can;
	maquinaAdministradora->retirarDinero(can);
}
void MenuAdministrador::mostrar() {
	cout << maquinaAdministradora->toString() << endl;
}