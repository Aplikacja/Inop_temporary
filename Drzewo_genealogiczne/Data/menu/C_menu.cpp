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
	size = v_s.size(); // przepisanie rozmiaru vectora
	std::vector<bool>::iterator it = v_b.begin(); //stworzenie iteratora od vectora boola
	std::vector<std::vector<int>>::iterator it_i = v_k.begin(); //stworzenie iteratora do vectorów typu int
	int i; //int iterator fora
	for (i = 0; i < v_s.size(); i++) {
		Tab_menu[i] = f.m_Create_menu(1, *it, v_s[i], *it_i);
		it_i++;
		it++;
	}
}
void C_menu::m_view(int& i_variable, int& i_klucz, int i_choice) {
		if (i_variable >= 0 && i_variable < size) {
			Tab_menu[i_variable]->m_view(i_variable, i_klucz, i_choice); //do rozwoju trza zaprojektowac lejalt menu
		}
}
void C_menu::m_set_content(std::list<C_person_base*>& Lista) {
	lista = Lista;
	std::string s_data;
	std::vector<std::string> V_content;
	int i_iter;
	for (auto& X : lista) {
		s_data.clear();
		X->m_conwert(s_data);
		V_content.push_back(s_data);
	}
	for (i_iter = 0; i_iter < size; i_iter++) {
		Tab_menu[i_iter]->m_set_content(V_content);
	}
}
C_menu::~C_menu() {
	delete[]Tab_menu;
}