//**********************************************************************************************************************************************************//
//	Plik: C_menu_edition.hpp																								Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_menu_edition.hpp"
void f_sterowanie(int& x, std::string& s_klucz, std::string& s_message, int& i_start, std::vector<std::string>& v_k, int i_Size, int i_start_);
void f_sterowanie_add_person(int& x, std::string& s_klucz, std::string& s_message, int& i_start, std::vector<std::string>& v_k, int i_Size, int i_start_);
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
	std::vector<std::string> V_string;
	V_string.resize(i_size);
	std::vector<std::vector<std::string>>::iterator it_s;
	//V_str_[1][0].clear(); //czyszceznie tablicy w razie czego
	//V_str_[1][0].push_back(s_working);
	for (auto& Y : V_str_[0][i_id_menu]) {
		V_string[ptr] = Y;
		if(ptr==0)
		V_string[++ptr] = s_word_user;
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
					printf(V_string[ptr].c_str()); printf("\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					ptr++;
					continue;
				}
				printf(V_string[ptr].c_str()); printf("\n");
				ptr++;

			}
			f_clear(h, pos, Written);
			m_ruch(f_sterowanie, i_x, s_working, s_word_user, i_sta, V_string, i_size, i_start_);
				switch (i_sta) {
					case 0: {
						switch (i_x) {
						case 1:
							s_result = s_word_user;
							V_proces.clear();
							//wlaczenie kolejnych odwolan
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
						if(V_string[1].size()>0)
						V_string[1]= s_word_user+" ";
						break;
					}
					default:
						V_string[1] = s_word_user;
						break;
					}
				}
		break;
		};
	}
	return false;
}
C_menu_edition::~C_menu_edition() {}
bool C_menu_edition::m_view(int i_id_menu,int& i, int& i_klucz, std::vector<int>& V_procedur, int& i_choice) {return false;}
bool C_menu_edition::m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) {
	int i_x = i_start_; //udalo nam sie wejsc w ta metode :)
	int i_sta = i_start_;
	int ptr = 0;
	int i_replay;
	int i=0;
	int i_position=0;
	std::vector<int> V_k;
	std::string s_working;
	std::vector<std::string> V_user_world;
	std::vector<std::vector<std::string>>::iterator it_s;
	std::vector<std::string> V_string;
	V_k = *V_klucz_.begin();
	switch (i_choice) {
	case 1: {
		int i_size = V_str_[0][i_id_menu].size() + 10;
		std::vector<std::string> V_name_option = { "Imie:\n", "Nazwisko:\n", "Data urodzenia:\n", "Data smierci:\n", "Plec:\n" };
		V_string.resize(13);
		V_user_world.resize(6);
		for (auto& Y : V_str_[0][i_id_menu]) {
			V_string[ptr] = Y;
			if (ptr == 0) {
				for (auto& P : V_name_option) {
					ptr++;
					V_string[ptr] = P;
					ptr++;
					V_string[ptr] = V_user_world[i];
					i++;
				}
			}
		}
		f_option_clear(h, pos, Written);
		while (true) {
			ptr = 0;
			for (i = 0; i < i_size; i++) {
				if (ptr == i_x) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					printf(V_string[ptr].c_str()); printf("\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					ptr++;
					continue;
				}
				printf(V_string[ptr].c_str()); printf("\n");
				ptr++;

			}
			f_clear(h, pos, Written);
			m_ruch(f_sterowanie_add_person, i_x, s_working, V_user_world[i_position], i_sta, V_string, i_size, i_start_);
			switch (i_sta) {
			case 0: {
				switch (i_x) {
				case 1:
					//s_result = s_word_user;
					V_proces.clear();
					//wlaczenie kolejnych odwolan
					V_proces.push_back(25);
					V_proces.push_back(12);
					return true;

				case 2:
					V_proces = V_procedur_[i_x - i_start_];
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
				if (V_string[1].size()>0)
				//	s_Tab[1] = s_word_user + " ";
				break;
			}
			default:
			//	s_Tab[1] = s_word_user;
				break;
			}
		}
		break;
	};
	case 2: {
		std::string _new_name;
		int i_size = V_str_[0][i_id_menu].size() + 2;
		V_string.resize(4);
		V_user_world.resize(1);
		for (auto& Y : V_str_[0][i_id_menu]) {
			V_string[ptr] = Y;
			if (ptr == 0) {
				for (auto& P : V_result) {
					ptr++;
					V_string[ptr] = P;
				}
			}
			ptr++;
		}
		f_option_clear(h, pos, Written);
		while (true) {
			ptr = 0;
			for (i = 0; i < i_size; i++) {
				if (ptr == i_x) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					printf(V_string[ptr].c_str()); printf("\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					ptr++;
					continue;
				}
				printf(V_string[ptr].c_str()); printf("\n");
				ptr++;

			}
			f_clear(h, pos, Written);
			m_ruch(f_sterowanie, i_x, s_working, _new_name, i_sta, V_string, i_size, i_start_);
			switch (i_sta) {
			case 0: {
				switch (i_x) {
				case 2:
					//s_result = s_word_user;
					V_proces.clear();
					//wlaczenie kolejnych odwolan
					V_proces.push_back(26);
					V_result[1] = V_string[2];
					return true;
				case 3:
					V_proces.clear();
					this->m_get_replay(i_id_menu, i_replay);
					V_proces.push_back(i_replay);
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
				if (V_string[2].size()>0)
					V_string[2] = _new_name + " ";
					break;
			}
			default:
					V_string[2] = _new_name;
				break;
			}
		}
		break;
	}
	}
	return false;
}

