//**********************************************************************************************************************************************************//
//	Plik: C_menu_edition.hpp																								Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_MENU_EDITION_HPP
#define C_MENU_EDITION_HPP
#include "C_menu_base.hpp"
class C_menu_edition :public C_Menu_base {
	C_menu_edition(std::vector<std::string> V, bool b, std::vector<int> v_k); //konstruktor
	void m_view(int& i) {} //metoda do wyswietlania
	~C_menu_edition(); //destruktor
};
#endif // !C_MENU_EDITION_HPP