//**********************************************************************************************************************************************************//
//	Plik: C_menu_tree.cpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_menu_tree.hpp"

C_menu_tree::C_menu_tree(std::vector<std::vector<std::string>>& V, bool b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person) :C_menu_base(V, b, v_k,V_procedur, i_iterator,L_person) {}
C_menu_tree::~C_menu_tree() {}
void C_menu_tree::m_view(int& i, int& i_klucz, std::vector<int>& V_proces, int& i_choice) {
	int i_x = 0;
	int ptr;
	HANDLE h;
	COORD pos = { 0,0 };
	DWORD Written;

	std::vector<int> V_k;
	std::vector<std::vector<std::string>>::iterator it_s;
	V_k = *V_klucz.begin();
	switch (i_choice) {
	case 1: {
		i_klucz = -1;
		f_option_clear(h, pos, Written);
		while (true) {
			ptr = 0;
			it_s = V_str[1].begin();
			for (auto& x : *it_s) {
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
			f_clear(h, pos, Written);
			m_ruch(f_sterowanie, i_x, i_klucz, i_start, V_k); //dlaczego nie dziala
			if (i_klucz > -1) {
				//i = i_klucz; //tu sie zawieszalo
				return;
			}
		};
	}break;
	case 2:
	{
		i_klucz = -1;
		f_option_clear(h, pos, Written);
		while (true) {
			ptr = 0;
			it_s = V_str[1].begin();
			for (auto& x : *it_s) {
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
			f_clear(h, pos, Written);
			m_ruch(f_sterowanie, i_x, i_klucz,i_start, V_k); //dlaczego nie dziala
			if (i_klucz > -1) {
				//i = i_klucz; //tu sie zawieszalo
				return;
			}
		};
	}break;
	default: break;
	}
}
void C_menu_tree::m_view(int& i_variable, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) {}