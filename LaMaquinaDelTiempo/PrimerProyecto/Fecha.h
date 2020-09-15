#pragma once
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

static time_t ahora = time(NULL); //Fecha y hora actual basado en el sistema;


//Para que esto funcione.. Hay que ir a Depurar -> Propiedades de la depuracion del proyecto ->C/C++ -> Procesador
//y en la primera linea donde sale Definiciones de Procesador agregar lo siguiente: ;_CRT_SECURE_NO_WARNINGS

static struct tm * _fecha = localtime(&ahora); //objeto de estructura tiempo con fecha y hora local.


class Fecha{
private:
	int dia;
	int mes;
	int annio;
	bool fechavalida(int ndia, int nmes, int nanio) { //método que realiza la comprobacion de fecha correcta
		if (ndia < 1 || ndia>31) return false;
		else if (nmes < 1 || nmes>12) return false;
		else switch (nmes)
		{
		case 4: case 6: case 9: case 11:
			if (ndia > 30) return false;
			break;
		case 2:
			if (ndia > 28)return false;
			break;
		}
		return true;
	}

public:
	Fecha(int = _fecha->tm_mday, int = _fecha->tm_mon + 1, int = 1900 + _fecha->tm_year);
	~Fecha();
	
	void setDia(int);
	void setMes(int);
	void setAnnio(int);

	int getDia();
	int getMes();
	int getAnnio();

	int difDias(Fecha);

	string toString();

};

