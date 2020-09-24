#pragma once
#include <iostream>
#include "Vista.h"
#include "MenuAdministrador.h"
#include "MenuCobro.h"
using namespace std;

class MenuPrincipal{
private:
	MenuAdministrador* ptrMenuAdmi;
	MenuCobro* ptrMenuCobro;

public:
	MenuPrincipal(MenuAdministrador*, MenuCobro*);

	void invocarMenu();

	void menuAdministrador();
	void menuCobro();
};

