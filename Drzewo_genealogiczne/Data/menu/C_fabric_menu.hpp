//**********************************************************************************************************************************************************//
//	Plik: C_fabrica_menu.hpp																								Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_FABRICA_MENU_HPP
#define C_FABRICA_MENU_HPP
#include "C_menu_base.hpp"
#include "C_menu_edition.hpp"
#include "C_menu_glowne.hpp"
#include "C_menu_tree.hpp"
#include "../person/C_person_base.hpp"
#include <vector>
#include <string>
class C_fabric_menu {
public:
	C_Menu_base * m_Create_menu(int i_value, bool b, std::vector<std::string> V, std::vector<int> v_k);
};
#endif // !C_FABRICA_MENU_HPP