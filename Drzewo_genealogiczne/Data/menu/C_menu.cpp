//**********************************************************************************************************************************************************//
//	Plik: C_menu.cpp																										Data_utworzenia: 13-03-2018		//
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
#include "C_menu.hpp"

C_menu::C_menu() {
	//	Tab_menu = new Menu_base*[i_value];
};
void C_menu::m_loader(std::vector<std::vector<std::string>>& v_s, std::vector<bool>& v_b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<std::vector<int>>>& V_procedur, std::vector<int>& V_iterator, std::vector<int>& V_typ_menu) {
	Tab_menu_ = new C_menu_base*[v_s.size()];
	i_size = (int)v_s.size(); // przepisanie rozmiaru vectora
	std::vector<bool>::iterator it = v_b.begin(); //stworzenie iteratora od vectora boola
	std::vector<std::vector<int>>::iterator it_i = v_k.begin(); //stworzenie iteratora do vectorów typu int
	std::vector<std::vector<std::vector<int>>>::iterator it_proc = V_procedur.begin();
	std::vector<std::list<C_person_base*>> V_L_person;
	std::vector<int>::iterator it_start = V_iterator.begin();
	std::vector<int>::iterator it_typ_menu = V_typ_menu.begin();
	std::vector<std::vector<std::string>> V_temp;
	std::vector<std::vector<int>> V_temp_i;
	int i; //int iterator fora
	for (i = 0; i < (int)v_s.size(); i++) {
		V_temp.push_back(v_s[i]);
		V_temp_i.push_back(*it_i);
		//V_L_person.push_back(L_peron);
		Tab_menu_[i] = f_.m_Create_menu(*it_typ_menu, *it, V_temp, V_temp_i,*it_proc, *it_start, V_L_person);
		V_temp.clear();
		V_temp_i.clear();
		it_start++;
		it_typ_menu++;
		it_proc++;
		it_i++;
		it++;
	}
}
bool C_menu::m_view(int i_id_menu,int& i_variable, int& i_klucz,std::vector<int>& V_proces, int& i_choice) {
	
	if (i_variable >= 0 && i_variable < i_size) {
		return Tab_menu_[i_variable]->m_view(i_id_menu,i_variable, i_klucz, V_proces, i_choice); //do rozwoju trza zaprojektowac lejalt menu
		}
	return false;
}
bool C_menu::m_view(int i_id_menu,int& i_variable, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) {
	if (i_variable >= 0 && i_variable < i_size) {
		return Tab_menu_[i_variable]->m_view(i_id_menu,i_variable,s_result, i_klucz, V_proces, i_choice); //do rozwoju trza zaprojektowac lejalt menu
	}
	return false;
}
bool C_menu::m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice, int& b_replay) {
	if (i_variable >= 0 && i_variable < i_size) {
		return Tab_menu_[i_variable]->m_view(i_id_menu, i_variable, V_result, i_klucz, V_proces, i_choice, b_replay); //do rozwoju trza zaprojektowac lejalt menu
	}
	return false;
}
bool C_menu::m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) {
	if (i_variable >= 0 && i_variable < i_size) {
		return Tab_menu_[i_variable]->m_view(i_id_menu, i_variable, V_result, i_klucz, V_proces, i_choice); //do rozwoju trza zaprojektowac lejalt menu
	}
	return false;
}
bool C_menu::m_view(int i_id_menu, int& i, int& i_klucz, std::vector<long long>& V_proces, int& i_choice, std::vector<std::vector<C_id>>& V_id) {
	if (i >= 0 && i < i_size) {
		return Tab_menu_[i]->m_view(i_id_menu, i, i_klucz, V_proces, i_choice, V_id); //do rozwoju trza zaprojektowac lejalt menu
	}
	return false;
}
void C_menu::m_set_content(int i_choice,std::vector<std::list<C_person_base*>>& Lista, std::vector<C_id>& V_id) {
	std::string s_data;
	C_id id;
	std::vector<std::string> V_content;
	int i_iter;
	for (auto person : Lista) {
		for (auto& X : person) {
			s_data.clear();
			X->m_conwert(s_data);
			X->m_get_id(id);
			V_id.push_back(id);
			V_content.push_back(s_data);
		}
	}
	for (i_iter = 0; i_iter < i_size; i_iter++) {
		Tab_menu_[i_iter]->m_set_str(i_choice,V_content);
	}
	V_str_.clear();
	m_set_content_person(i_choice, Lista);
}
void C_menu::m_set_content(int i_choice, std::list<C_person_base*>& Lista, std::vector<C_id>& V_id) {
	std::string s_data;
	C_id id;
	std::vector<std::string> V_content;
	int i_iter;
	if (Lista.size() == 0) {
		V_content.push_back("Brak osob w drzewie!!");
		V_id.clear();
	}
		for (auto& X : Lista) {
			s_data.clear();
			X->m_conwert(s_data);
			X->m_get_id(id);
			V_id.push_back(id);
			V_content.push_back(s_data);
		}
	for (i_iter = 0; i_iter < i_size; i_iter++) {
		Tab_menu_[i_iter]->m_set_str(i_choice, V_content);
	}
	V_str_.clear();
}
C_menu::~C_menu() {
	delete[]Tab_menu_;
}
void C_menu::m_set_content_person(int i_choice,std::vector<std::list<C_person_base*>>& lista) {
		if (i_choice >= 0 && i_choice < i_size) {
			Tab_menu_[i_choice]->m_add_perosons(lista);
		}
}
void C_menu::m_set_str(int i_varaible,std::vector<std::vector<std::vector<std::string>>>& v_str) {
	if (i_varaible >= 0 && i_varaible < i_size) {
		Tab_menu_[i_varaible]->m_set_content(v_str);
	}
}
void C_menu::m_get_str(int i_variable,std::vector<std::vector<std::vector<std::string>>>& v_str) {
	if (i_variable >= 0 && i_variable<i_size)
		Tab_menu_[i_variable]->m_get_content(v_str);
}
void C_menu::m_get_replay(int i_variable, int i_choice, int& i_replay) {
	if (i_variable >= 0 && i_variable<i_size)
	Tab_menu_[i_variable]->m_get_replay(i_choice, i_replay);
}
void C_menu::m_set_replay(int i_variable, int i_choice, int i_replay) {
	if (i_variable >= 0 && i_variable<i_size)
		Tab_menu_[i_variable]->m_set_replay(i_choice, i_replay);
}
void C_menu::m_set_data_base(int i_choice, C_engine_software& E_SOFT) {
	if (i_choice >= 0 && i_choice < i_size)
		Tab_menu_[i_choice]->m_get_data(E_SOFT);
}
void C_menu::m_elimination(int i_choice, std::vector<int>& L_person) {
	if (i_choice >= 0 && i_choice < i_size)
		Tab_menu_[i_choice]->m_elimination(L_person);
}
void C_menu::m_cofiguration(int i) {
	int i_choice;
	for (i_choice = 0; i_choice < i_size; i_choice++)
		Tab_menu_[i_choice]->m_configuration(i);
}