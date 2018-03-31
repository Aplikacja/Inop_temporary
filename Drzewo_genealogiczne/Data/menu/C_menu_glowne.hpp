//**********************************************************************************************************************************************************//
//	Plik: C_menu_glowne.hpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-03-2018				Lukasz			Rozbudowa metody m_view() o dodatkowy argument int& i_klucz														//
//**********************************************************************************************************************************************************//
#ifndef C_MENU_GLOWNE_HPP
#define C_MENU_GLOWNE_HPP
#include <iostream>
#include "C_menu_base.hpp"
class C_Menu_glowne :public C_Menu_base {
public:
	C_Menu_glowne(std::vector<std::string> V, bool b, std::vector<int> v_k); //konstruktor
	void m_view(int& i, int& i_klucz, int i_choice); //metoda wysiwetlajaca
	~C_Menu_glowne(); //destruktor
};
#endif // !C_MENU_GLOWNE_HPP