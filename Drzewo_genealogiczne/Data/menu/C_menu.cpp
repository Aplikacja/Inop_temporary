//**********************************************************************************************************************************************************//
//	Plik: C_menu.cpp																										Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_menu.hpp"

C_menu::C_menu() {
	//	Tab_menu = new Menu_base*[i_value];
};
void C_menu::m_loader(std::vector<std::vector<std::string>> v_s, std::vector<bool> v_b, std::vector<std::vector<int>> v_k) {
	Tab_menu = new C_Menu_base*[v_s.size()];
	size = v_s.size();
	std::vector<bool>::iterator it = v_b.begin();
	std::vector<std::vector<int>>::iterator it_i = v_k.begin();
	int i;
	for (i = 0; i < v_s.size(); i++) {
		Tab_menu[i] = f.m_Create_menu(1, *it, v_s[i], *it_i);
		it_i++;
		it++;
	}
}
void C_menu::m_view(int i) {
	if (i >= 0 && i < size) {
		Tab_menu[i]->m_view();
	}
}
C_menu::~C_menu() {
	delete[]Tab_menu;
}