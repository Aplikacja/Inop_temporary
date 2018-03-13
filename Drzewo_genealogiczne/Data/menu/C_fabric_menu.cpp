//**********************************************************************************************************************************************************//
//	Plik: C_fabrica_menu.cpp																								Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_fabric_menu.hpp"

C_Menu_base * C_fabric_menu::m_Create_menu(int i_value, bool b, std::vector<std::string> V, std::vector<int> v_k) {
	if (i_value == 1) return new C_Menu_glowne(V, b, v_k);
}