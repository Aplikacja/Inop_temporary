//**********************************************************************************************************************************************************//
//	Plik: C_menu_edition.hpp																								Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_menu_edition.hpp"

C_menu_edition::C_menu_edition(std::vector<std::vector<std::string>>& V, bool& b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person) :C_menu_base(V, b, v_k,V_procedur, i_iterator,L_person) {}
bool C_menu_edition::m_view(int i_id_menu,int& i_variable, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) {
	int i_x = i_start_; //udalo nam sie wejsc w ta metode :)
	int i_sta = i_start_;
	int ptr;
	int i_replay;
	std::vector<int> V_k;
	std::string s_temp;
	std::string s_working;
	std::vector<std::string> V_string;
	std::vector<std::vector<std::string>>::iterator it_s;
	V_str_[1][0].clear(); //czyszceznie tablicy w razie czego
	V_str_[1][0].push_back(s_working);
	for (auto& Y : V_str_[0][i_klucz])
		V_string.push_back(Y);
	for (auto& Y : V_str_[1][i_id_menu])
		V_string.push_back(Y);
	V_k = *V_klucz_.begin();
	switch (i_choice) {
	case 1: {
		f_option_clear(h, pos, Written);
		while (true) {
			ptr = 0;
			for (auto& x : V_string) {
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
			m_ruch(f_sterowanie, i_x, s_working, i_sta, V_string);
			if (i_sta <= 0) {
				switch (i_sta) {
				case 0: {
					s_result = s_working;
					V_proces = V_procedur_[0];
					return true;
				case -2: {
					//zaimplementowane do cofania sie do poprzedniego menu
					V_proces.clear();
					this->m_get_replay(i_id_menu, i_replay);
					V_proces.push_back(i_replay);
					return false;
				}
				default:
					break;
				}
				}
			}
			
		};
	}break;

	}
}
C_menu_edition::~C_menu_edition() {}
bool C_menu_edition::m_view(int i_id_menu,int& i, int& i_klucz, std::vector<int>& V_procedur, int& i_choice) {
	std::cout << "dupa\n";
	return false;
}