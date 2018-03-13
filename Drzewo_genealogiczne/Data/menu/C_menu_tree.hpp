//**********************************************************************************************************************************************************//
//	Plik: C_menu_tree.hpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_MENU_TREE_HPP
#define C_MENU_TREE_HPP
#include "C_menu_base.hpp"
class C_menu_tree :public C_Menu_base {
	C_menu_tree(std::vector<std::string> V, bool b, std::vector<int> v_k);
	~C_menu_tree();
};
#endif // !C_MENU_TREE_HPP