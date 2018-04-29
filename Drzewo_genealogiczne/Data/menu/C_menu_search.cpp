#include "C_menu_search.hpp"
C_menu_search::C_menu_search(std::vector<std::vector<std::string>>& V, bool& b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person):C_menu_base(V, b, v_k, V_procedur, i_iterator, L_person) {}
void C_menu_search::m_view(int& i, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) { //dopasowac zwracanie stringa z metody!!
	int i_x = i_start;
	int i_sta = i_start;
	int ptr;
	HANDLE h;
	COORD pos = { 0,0 };
	DWORD Written;
	std::vector<int> V_k;
	std::string s_temp;
	std::vector<std::string> V_string;
	std::vector<std::vector<std::string>>::iterator it_s;
	for (auto& Y : V_str[0][i_klucz])
		V_string.push_back(Y);
	for  (auto& Y: V_str[1][0])
		V_string.push_back(Y);
	V_k = *V_klucz.begin();
	switch (i_choice) {
	case 1: {
		//i_klucz = -1;
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
			m_ruch(f_sterowanie, i_x, s_temp, i_sta, V_string); //dlaczego nie dziala
			if (i_sta <= 0) {
				//i = i_klucz; //tu sie zawieszalo 
				s_result = s_temp;
				V_proces = V_procedur[0];
				return;
			}
		};
	}break;
	case 3: {
		//i_klucz = -1;
		char *c_temp=NULL;
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
			m_ruch(f_sterowanie, i_x, s_temp, i_sta, V_string); //dlaczego nie dziala
			if (i_sta <= 0) {
				std::ostringstream ss;
				ss << i_x;
				s_result = ss.str();
				V_proces = V_procedur[0];
				return;
			}
		};
	}break;
	case 2:
	{
		//i_klucz = -1;
		f_option_clear(h, pos, Written);
		while (true) {
			ptr = i_start;
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
			m_ruch(f_sterowanie, i_x, s_temp, i_sta, V_string); //dlaczego nie dziala
			if (i_sta <= 0) {
				//i = i_klucz; //tu sie zawieszalo
				s_result = s_temp;
				V_proces = V_procedur[0];
				return;
			}
		};
	}break;
	default: break;
	}
} //metoda wysiwetlajaca
void C_menu_search::m_view(int& i, int& i_klucz, std::vector<int>& V_procedur, int& i_choice) {}
C_menu_search::~C_menu_search() {} //destruktor