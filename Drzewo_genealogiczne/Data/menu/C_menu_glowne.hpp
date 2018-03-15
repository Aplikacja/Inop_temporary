//**********************************************************************************************************************************************************//
//	Plik: C_menu_glowne.hpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_MENU_GLOWNE_HPP
#define C_MENU_GLOWNE_HPP
#include <iostream>
#include "C_menu_base.hpp"
class C_Menu_glowne :public C_Menu_base {
public:
	C_Menu_glowne(std::vector<std::string> V, bool b, std::vector<int> v_k);
	void m_view(int& i);
	~C_Menu_glowne();
};
#endif // !C_MENU_GLOWNE_HPP