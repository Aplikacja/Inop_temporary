//**********************************************************************************************************************************************************//
//	Plik: C_menu.hpp																										Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_MENU_HPP
#define C_MENU_HPP
#include "C_fabric_menu.hpp"
class C_menu {
	C_fabric_menu f;
	int size;
	C_Menu_base** Tab_menu;
public:
	C_menu();
	void m_loader(std::vector<std::vector<std::string>> v_s, std::vector<bool> v_b, std::vector<std::vector<int>> v_k);
	void m_view(int i);
	~C_menu();
};
#endif // !C_MENU_HPP