//**********************************************************************************************************************************************************//
//	Plik: C_menu.hpp																										Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_MENU_HPP
#define C_MENU_HPP
#include "C_fabric_menu.hpp"
#include <list>
class C_menu {
	C_fabric_menu f;
	std::list<C_person_base*> lista;
	int size;
	C_Menu_base** Tab_menu;
public:
	C_menu(); //konstruktor
	void m_loader(std::vector<std::vector<std::string>> v_s, std::vector<bool> v_b, std::vector<std::vector<int>> v_k); 
	void m_view(int& i_variable, int& i_klucz, int i_choice);
	void m_set_content(std::list<C_person_base*>& lista);
	//void m_get_content(std::list<C_person_base*> lista);
	~C_menu(); //destruktor
};
#endif // !C_MENU_HPP