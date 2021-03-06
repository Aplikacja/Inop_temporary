#pragma once
//**********************************************************************************************************************************************************//
//	Plik: C_menu_glowne.hpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	22-03-2018		Lukasz Witek vel Witkowski			Dodanie metod m_view() umożliwiajace wybieranie Persona												//
//	10-04-2015		Lukasz Witek vel Witkowski			Naprawa metod																						//
//	25-04-2015		Lukasz Witek vel Witkowski			Naprawa metod																						//
//	15-06-2015		Lukasz Witek vel Witkowski			Rozbudowanie metody o nowe cechy																	//
//	05-07-2015		Lukasz Witek vel Witkowski			Rozbudowanie metody o nowe cechy i naprawa metod													//									//
//----------------------------------------------------------------------------------------------------------------------------------------------------------//
#ifndef C_MENU_SEARCH_HPP
#define C_MENU_SEARCH_HPP
#include <iostream>
#include "C_menu_base.hpp"
class C_menu_search:public C_menu_base {
public:
	C_menu_search(std::vector<std::vector<std::string>>& V, bool& b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person); //konstruktor
	bool m_view(int i_id_menu,int& i, std::string& s_klucz, int& i_klucz, std::vector<int>& V_procedur, int& i_choice); //metoda wysiwetlajaca
	bool m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice);
	bool m_view(int i_id_menu,int& i, int& i_klucz, std::vector<int>& V_procedur, int& i_choice);
	bool m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice, int& b_replay);
	bool m_view(int i_id_menu, int& i, int& i_klucz, std::vector<long long>& V_proces, int& i_choice, std::vector<std::vector<C_id>>& V_id);
	~C_menu_search(); //destruktor
};
#endif // !C_MENU_SEARCH_HPP
