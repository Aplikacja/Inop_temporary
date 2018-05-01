//**********************************************************************************************************************************************************//
//	Plik: C_menu_tree.hpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_MENU_TREE_HPP
#define C_MENU_TREE_HPP
#include "C_menu_base.hpp"
class C_menu_tree :public C_menu_base {
	C_menu_tree(std::vector<std::vector<std::string>>& V, bool b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person); //konstruktor
	bool m_view(int i_id_menu,int& i, int& i_klucz, std::vector<int>& V_prosec, int& i_choice); //metoda do wyswietlania
	bool m_view(int i_id_menu,int& i_variable, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice);
	~C_menu_tree(); //destruktor
};
#endif // !C_MENU_TREE_HPP