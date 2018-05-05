//**********************************************************************************************************************************************************//
//	Plik: C_menu_edition.hpp																								Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_menu_edition.hpp"
void f_sterowanie(int& x, std::string& s_klucz, std::string& s_message, int& i_start, std::string* v_k, int i_Size);
C_menu_edition::C_menu_edition(std::vector<std::vector<std::string>>& V, bool& b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person) :C_menu_base(V, b, v_k,V_procedur, i_iterator,L_person) {}
bool C_menu_edition::m_view(int i_id_menu,int& i_variable, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) {
	int i_x = i_start_; //udalo nam sie wejsc w ta metode :)
	int i_sta = i_start_;
	int ptr = 0;
	int i_replay;
	int i;
	int i_size = V_str_[0][i_id_menu].size() + 1;
	std::vector<int> V_k;
	std::string s_word_user;
	std::string s_working;
	std::string *s_Tab=NULL;
	s_Tab = new std::string[i_size];
	std::vector<std::vector<std::string>>::iterator it_s;
	V_str_[1][0].clear(); //czyszceznie tablicy w razie czego
	//V_str_[1][0].push_back(s_working);
	for (auto& Y : V_str_[0][i_id_menu]) {
		s_Tab[ptr] = Y;
		if(ptr==0)
		s_Tab[++ptr] = s_word_user;
		ptr++;
	}
	V_k = *V_klucz_.begin();
	switch (i_choice) {
	case 1: {
		f_option_clear(h, pos, Written);
		while (true) {
			ptr = 0;
			for (i = 0; i < i_size;i++) {
				if (ptr == i_x) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					printf(s_Tab[ptr].c_str()); printf("\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					ptr++;
					continue;
				}
				printf(s_Tab[ptr].c_str()); printf("\n");
				ptr++;

			}
			f_clear(h, pos, Written);
			m_ruch(f_sterowanie, i_x, s_working, s_word_user, i_sta, s_Tab, i_size);
				switch (i_sta) {
					case 0: {
						switch (i_x) {
						case 1:
							s_result = s_word_user;
							V_proces.clear();
							V_proces.push_back(25);
							V_proces.push_back(12);
							return true;

						case 2:
							V_proces = V_procedur_[i_x-i_start_];
							return false;
						}
					case -2: {
						//zaimplementowane do cofania sie do poprzedniego menu
						V_proces.clear();
						this->m_get_replay(i_id_menu, i_replay);
						V_proces.push_back(i_replay);
						return false; }
					}
					case 2: {
						if(s_Tab[1].size()>0)
						s_Tab[1]= s_word_user+" ";
						break;
					}
					default:
						s_Tab[1] = s_word_user;
						break;
					}
				}
			
		};
	}
	return false;
}
C_menu_edition::~C_menu_edition() {}
bool C_menu_edition::m_view(int i_id_menu,int& i, int& i_klucz, std::vector<int>& V_procedur, int& i_choice) {
	std::cout << "dupa\n";
	return false;
}