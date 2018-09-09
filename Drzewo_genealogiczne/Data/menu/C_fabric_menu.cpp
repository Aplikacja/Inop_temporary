//**********************************************************************************************************************************************************//
//	Plik: C_fabrica_menu.cpp																								Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
// 20-03-2018 Luksz Witek vel Witkowski	Dodaniew i rozbudowa metody m_Create_menu																			//
//**********************************************************************************************************************************************************//
#include "C_fabric_menu.hpp"

C_menu_base * C_fabric_menu::m_Create_menu(int& i_value, bool b, std::vector<std::vector<std::string>>& V, std::vector<std::vector<int>>& v_k,std::vector<std::vector<int>>& V_procedur, int& i_iterator,std::vector<std::list<C_person_base*>>& L_person) {
	switch (i_value) {
	case 1:
		return new C_menu_glowne(V, b, v_k, V_procedur, i_iterator, L_person);
	case 2:
		return new C_menu_search(V, b, v_k, V_procedur, i_iterator, L_person);
	case 3:
		return new C_menu_edition(V, b, v_k, V_procedur, i_iterator, L_person);
	case 4:
		return new C_menu_tree(V, b, v_k, V_procedur, i_iterator, L_person);
	default:
		return new C_menu_glowne(V, b, v_k, V_procedur, i_iterator, L_person);
	}
}