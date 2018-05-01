//**********************************************************************************************************************************************************//
//	Plik: C_menu_glowne.hpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-03-2018				Lukasz			Rozbudowa metody m_view() o dodatkowy argument int& i_klucz														//
//**********************************************************************************************************************************************************//
#ifndef C_MENU_GLOWNE_HPP
#define C_MENU_GLOWNE_HPP
#include <iostream>
#include "C_menu_base.hpp"
class C_menu_glowne :public C_menu_base {
public:
	C_menu_glowne(std::vector<std::vector<std::string>>& V, bool& b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person); //konstruktor
	bool m_view(int i_id_menu, int& i, int& i_klucz, std::vector<int>& V_procedur, int& i_choice); //metoda wysiwetlajaca
	bool m_view(int i_id_menu,int& i_variable, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice);
	~C_menu_glowne(); //destruktor
};
#endif // !C_MENU_GLOWNE_HPP