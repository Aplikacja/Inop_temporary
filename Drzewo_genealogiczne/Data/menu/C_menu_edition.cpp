//**********************************************************************************************************************************************************//
//	Plik: C_menu_edition.hpp																								Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_menu_edition.hpp"
void f_sterowanie(int& x, std::string& s_klucz, std::string& s_message, int& i_start, std::vector<std::string>& v_k);
C_menu_edition::C_menu_edition(std::vector<std::vector<std::string>>& V, bool& b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person) :C_menu_base(V, b, v_k,V_procedur, i_iterator,L_person) {}
void C_menu_edition::m_view(int& i_variable, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) {
	int i_x = i_start; //udalo nam sie wejsc w ta metode :)
	int i_sta = i_start;
	int ptr;
	HANDLE h;
	COORD pos = { 0,0 };
	DWORD Written;
	std::vector<int> V_k;
	std::string s_temp;
	std::string s_working;
	std::string s_message;
	std::vector<std::string> V_string;
	std::vector<std::vector<std::string>>::iterator it_s;
	V_str[1][0].clear(); //czyszceznie tablicy w razie czego
	V_str[1][0].push_back(s_working);
	for (auto& Y : V_str[0][i_klucz])
		V_string.push_back(Y);
	for (auto& Y : V_str[1][0])
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
			m_ruch(f_sterowanie, i_x, s_working,s_message, i_sta, V_string); //dlaczego nie dziala
			if (i_sta <= 0) {
				//i = i_klucz; //tu sie zawieszalo 
				s_result = s_working;
				V_proces = V_procedur[0];
				return;
			}
		};
	}break;

	}
}
C_menu_edition::~C_menu_edition() {}
void C_menu_edition::m_view(int& i, int& i_klucz, std::vector<int>& V_procedur, int& i_choice) {
	std::cout << "dupa\n";
}