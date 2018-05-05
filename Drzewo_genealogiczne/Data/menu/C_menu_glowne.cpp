//**********************************************************************************************************************************************************//
//	Plik: C_menu_glowne.cpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-03-2018				Lukasz			Uporzadkowanie kodu i wrzucenie czyszczenia ekranu do dwochfunkcji typu void (f_option_clear() i f_clear);		//
//											Przebudowa metody m_view() o dodatkowy argument int& i_klucz, umozliwiajacy waczenie opcji silnika w klasie		//	
//											C_aplikation.																									//
//**********************************************************************************************************************************************************//
#include "C_menu_glowne.hpp"
C_menu_glowne::C_menu_glowne(std::vector<std::vector<std::string>>& V, bool& b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person) :C_menu_base(V, b, v_k,V_procedur, i_iterator, L_person) {}
bool C_menu_glowne::m_view(int i_id_menu,int& i, int& i_klucz, std::vector<int>& V_proces,int& i_choice) {
	int i_x = i_start_;
	int ptr;
	int i_replay;
	std::vector<int> V_k;
	//std::vector<std::vector<std::string>>::iterator it_s;
	V_k = *V_klucz_.begin();
	switch (i_choice) {
		case 1: {
			i_klucz = -1;
			f_option_clear(h, pos, Written);
			while (true) {
				ptr = 0;
				for (auto& x : V_str_[0][i_id_menu]) {
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
				m_ruch(f_sterowanie, i_x, i_klucz,i_start_, V_k); 
				switch (i_klucz) {
				case -2: {  //zaimplementowanie na powrut do porezdniego menu
					V_proces.clear();
					this->m_get_replay(i_id_menu, i_replay);
					V_proces.push_back(i_replay);
					return false;
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
				for (auto& x : V_str_[0][i_id_menu]) {
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
				m_ruch(f_sterowanie, i_x, i_klucz,i_start_, V_k); 
				switch (i_klucz) {
				case -2: {  //zaimplementowanie na powrut do porezdniego menu
					V_proces.clear();
					this->m_get_replay(i_id_menu, i_replay);
					V_proces.push_back(i_replay);
					return false;
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
bool C_menu_glowne::m_view(int i_id_menu, int& i_variable, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) { return false; }
C_menu_glowne::~C_menu_glowne() {};
