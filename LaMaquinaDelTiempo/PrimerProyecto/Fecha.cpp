#include "Fecha.h"

Fecha::Fecha(int d, int m, int a) {

    if (fechavalida(d, m, a)) {
        this->dia = d; this->mes = m; this->annio = a;
    }
    else {
        cout << "ERROR: Se trato de introducir fecha incorrecta" << endl;
    }
}

Fecha::~Fecha() {
}

void Fecha::setDia(int a) {
	this->annio = a;
}
void Fecha::setMes(int m) {
	this->mes = m;
}
void Fecha::setAnnio(int a) {
	this->annio = a;
}

int Fecha::getDia() {
	return this->dia;
}
int Fecha::getMes() {
	return this->mes;
}
int Fecha::getAnnio() {
	return this->annio;
}

int Fecha::difDias(Fecha* b) {

	int d, m, a, dif = 0;

	//No se calcula si la fecha del producto es menor a la fecha actual
	if (this->annio > b->annio) {
		return -1;
	}
	else {
		if (this-> annio == b->annio && this->mes > b->mes) {
			return -1;
		}
		else {
			if (this->annio == b->annio && this->mes == b->mes && this->dia > b->dia) {
				return -1;
			}
		}
	}

	//Mismo año
    if (this->annio == b->annio) {
        if (this->mes == b->mes) return b->dia - this->dia;
        // Dias por meses completos:   
        for (a = this->mes + 1; a < b->mes; a++){
            switch (a) {
            case 4: case 6: case 9: case 11:
                dif += 30;
                break;
            case 2:
                dif += 28;
                break;
            default:
                dif += 31;
            }
        }

        // Dias que faltan para terminar el mes de A:
        switch (this->mes) {
        case 4: case 6: case 9: case 11:
            dif += 30 - this->dia;
            break;
        case 2:
            dif += 28 - this->dia;
            break;
        default:
            dif += 31 - this->dia;
        }
        // Dias del mes de B:
        dif += b->dia;

        return dif;

    } else dif = (b->annio - (this->annio + 1)) * 365;

    for (a = this->mes + 1; a <= 12; a++)
    {
        switch (a) {
        case 4: case 6: case 9: case 11:
            dif += 30;
            break;
        case 2:
            dif += 28;
            break;
        default:
            dif += 31;
        }
    }

    // Y los meses desde ppio del año de B:   
    for (a = 1; a < b->mes; a++)
    {
        switch (a) {
        case 4: case 6: case 9: case 11:
            dif += 30;
            break;
        case 2:
            dif += 28;
            break;
        default:
            dif += 31;
        }
    }
    // Dias que faltan para terminar el mes de A:
    switch (a) {
    case 4: case 6: case 9: case 11:
        dif += 30 - this->dia;
        break;
    case 2:
        dif += 28 - this->dia;
        break;
    default:
        dif += 31 - this->dia;
    }
    // Dias del mes de B:
    dif += b->dia;

    return dif;

}

string Fecha::toString() {
	stringstream s;

	s << this->dia << "/" << this->mes << "/" << this->annio << endl;

	return s.str();
}
