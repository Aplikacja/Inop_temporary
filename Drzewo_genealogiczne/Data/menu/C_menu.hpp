//**********************************************************************************************************************************************************//
//	Plik: C_menu.hpp																										Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
// 15-03-2018 Lukasz Witek vel Witkowski	Dodanie i rozbudowa metod:																						//
//														-> Konstruktor																						//
//														-> m_loader																							//
// 24-03-2018 Lukasz Witek vel Witkowski	Dodanie i rozbudowa metod:																						//
//														-> m_view																							//
//														-> m_set_content																					//
//														-> m_set_str																						//
//														-> m_get_replay																						//
//														-> m_set_replay																						//
//														-> m_set_content_person																				//
//														-> m_set_data_base																					//
//														-> m_elimination																					//
// 02-04-2018 Lukasz Witek vel Witkowski	Naprawa metod																									//
// 22-04-2018 Lukasz Witek vel Witkowski	Naprawa metod																									//
// 05-09-2018 Lukasz Witek vel Witkowski	Dodanie i rozbudowa metody m_cofiguration																		//
//**********************************************************************************************************************************************************//
#ifndef C_MENU_HPP
#define C_MENU_HPP
#include "C_fabric_menu.hpp"
#include <list>
class C_menu {
	C_fabric_menu f_;
	int i_size;
	std::vector<std::string> V_str_;
	C_menu_base** Tab_menu_;
public:
	C_menu(); //konstruktor
	void m_loader(std::vector<std::vector<std::string>>& v_s, std::vector<bool>& v_b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<std::vector<int>>>& V_procedur,std::vector<int>& i_iterator, std::vector<int>& V_typ_menu); 
	bool m_view(int i_id_menu,int& i_variable, int& i_klucz, std::vector<int>& V_proces, int& i_choice);
	bool m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice, int& b_replay);
	bool m_view(int i_id_menu,int& i_variable, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice);
	bool m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice);
	bool m_view(int i_id_menu, int& i, int& i_klucz, std::vector<long long>& V_proces, int& i_choice, std::vector<std::vector<C_id>>& V_id);
	void m_set_content(int i_choice,std::vector<std::list<C_person_base*>>& Lista, std::vector<C_id>& V_id);
	void m_set_content(int i_choice, std::list<C_person_base*>& Lista, std::vector<C_id>& V_id);
	void m_set_str(int i_variable,std::vector<std::vector<std::vector<std::string>>>& v_str);
	void m_get_str(int i_variable,std::vector<std::vector<std::vector<std::string>>>& v_str);
	void m_get_replay(int i_variable, int i_choice, int& i_replay);
	void m_set_replay(int i_variable, int i_choice, int i_replay);
	void m_set_content_person(int i_choice,std::vector<std::list<C_person_base*>>& lista);
	void m_set_data_base(int i_choice, C_engine_software& E_SOFT);
	void m_elimination(int i_choice, std::vector<int>& V_position);
	void m_cofiguration(int i); //do pliku inicjalizacyjnego
	~C_menu(); //destruktor
};
#endif // !C_MENU_HPP