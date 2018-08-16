//**********************************************************************************************************************************************************//
//	Plik: C_menu_tree.cpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_menu_tree.hpp"

C_menu_tree::C_menu_tree(std::vector<std::vector<std::string>>& V, bool b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person) :C_menu_base(V, b, v_k,V_procedur, i_iterator,L_person) {}
C_menu_tree::~C_menu_tree() {}
bool C_menu_tree::m_view(int i_id_menu,int& i, int& i_klucz, std::vector<int>& V_proces, int& i_choice) {
	int i_x = i_start_;
	int ptr;
	int i_replay;
	std::vector<std::vector<std::string>> V_str;
	std::vector<std::string> V_str_temp;
	std::vector<int> V_input = { 0, 3, 1, 2, 4, 5 };
	std::vector<int>::iterator it = V_input.begin();
	V_str.resize(6);
		V_str[*it] = V_str_[0][i_id_menu];
		it++;
	for (auto V : V_L_person_) {
		for (auto X : V) {
			V_str_temp.push_back(X->m_view()); //popracowac nad tym
		}
		V_str[*it] = V_str_temp;
		V_str_temp.clear();
		it++;
	}
	std::vector<int> V_k;
	V_k = *V_klucz_.begin();
	switch (i_choice) {
	case 1: {
		i_klucz = -1;
		f_option_clear(h, pos, Written);
		while (true) {
			ptr = 0;
			for (auto& Y : V_str) {
				for (auto x : Y) {
					if (ptr == i_x) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						printf(x.c_str()); printf("\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						ptr++;
						continue;
					}
					printf(x.c_str()); printf("\n");
					ptr++;
				}
			}
			f_clear(h, pos, Written);
			m_ruch(f_sterowanie_tree, i_x, i_klucz, i_start_, V_k);
			switch (i_klucz) {
			case -2: {  //zaimplementowanie na powrut do porezdniego menu
				V_proces.clear();
				this->m_get_replay(i_id_menu, i_replay);
				V_proces.push_back(i_replay);
				return false;
			}
			case -10: { //strzalka w lewo

			}
			case -11: { //stralka w prawo

			}
			case -12: { //spacja

			}
			default:
				if (i_klucz > -1) {
					V_proces = V_procedur_[i_x];
					return true;
				}
			}
		};
	}break;
	case 2:
	{
		i_klucz = -1;
		f_option_clear(h, pos, Written);
		while (true) {
			ptr = i_start_;
			for (auto& Y : V_str) {
				for (auto x : Y) {
					if (ptr == i_x) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						printf(x.c_str()); printf("\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						ptr++;
						continue;
					}
					printf(x.c_str()); printf("\n");
					ptr++;
				}
			}
			f_clear(h, pos, Written);
			m_ruch(f_sterowanie_tree, i_x, i_klucz, i_start_, V_k);
			switch (i_klucz) {
			case -2: {  //zaimplementowanie na powrut do porezdniego menu
				V_proces.clear();
				this->m_get_replay(i_id_menu, i_replay);
				V_proces.push_back(i_replay);
				return false;
			}
			case -10: { //strzalka w lewo

			}
			case -11: { //stralka w prawo

			}
			case -12: { //spacja

			 }
			default:
				if (i_klucz > -1) {
					V_proces = V_procedur_[i_x];
					return true;
				}
			}
		};
	}break;
	default: break;
	}
	return false;
}
bool C_menu_tree::m_view(int i_id_menu, int& i_variable, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) { return false; }
bool C_menu_tree::m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) { return false; }
bool C_menu_tree::m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice, int& b_replay) { return false; }