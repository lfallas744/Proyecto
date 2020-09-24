#pragma once
#include "MenuPrincipal.h"
#include "MenuAdministrador.h"
#include "IMaquinaAdministradora.h"
#include "IMaquinaVendedora.h"
#include "MenuCobro.h"
#include "Maquina.h"
class Bootstrapper {
public:
	static void correrApp() {
		
		IMaquinaAdministradora* IMaquinaAd = new Maquina;
		IMaquinaVendedora* IMaquinaVende = new Maquina;

		MenuAdministrador* menuAdmi = new MenuAdministrador(IMaquinaAd);
		MenuCobro* menuCo = new MenuCobro(IMaquinaVende);

		MenuPrincipal* menuPrincipal = new MenuPrincipal(menuAdmi, menuCo);
		menuPrincipal->invocarMenu();

		delete IMaquinaAd;
		delete IMaquinaVende;
		delete menuAdmi;
		delete menuCo;
		delete menuPrincipal;
	}
};
