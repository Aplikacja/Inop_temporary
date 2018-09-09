//**********************************************************************************************************************************************************//
//	Plik: C_menu_edition.hpp																								Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	28-03-2018		Lukasz Witek vel Witkowski			Dodanie metod m_view() umo¿liwiajace edycje Persona	i nazwy drzewa									//
//	29-03-2018		Lukasz Witek vel Witkowski			Dodanie funkcji void f_sterowanie																	//
//														Rozbudowanie metody o nowe cechy																	//
//	05-03-2018		Lukasz Witek vel Witkowski			Dodanie funkcji void f_sterowanie_add_person														//
//														Rozbudowanie metody o nowe cechy																	//
//	15-03-2018		Lukasz Witek vel Witkowski			Dodanie funkcji:																					//
//																	- void f_sterowanie_edit_tree															//
//																	- void f_protected_data																	//
//														Rozbudowanie metody o nowe cechy																	//
//	21-04-2015		Lukasz Witek vel Witkowski			Naprawa metod																						//
//	10-06-2015		Lukasz Witek vel Witkowski			Rozbudowanie metody o nowe cechy																	//
//----------------------------------------------------------------------------------------------------------------------------------------------------------//
#ifndef C_MENU_EDITION_HPP
#define C_MENU_EDITION_HPP
#include "C_menu_base.hpp"
class C_menu_edition :public C_menu_base {
public:
	C_menu_edition(std::vector<std::vector<std::string>>& V, bool& b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person); //konstruktor
	bool m_view(int i_id_menu,int& i_variable, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice);
	bool m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice, int& b_replay);
	bool m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice); //metoda powodujaca ze klasa C_menu_base jest klasa abstrakcyjna
	bool m_view(int i_id_menu,int& i, int& i_klucz, std::vector<int>& V_procedur, int& i_choice); //metoda wysiwetlajaca
	bool m_view(int i_id_menu, int& i, int& i_klucz, std::vector<long long>& V_proces, int& i_choice, std::vector<std::vector<C_id>>& V_id);
	~C_menu_edition(); //destruktor
};
#endif // !C_MENU_EDITION_HPP
