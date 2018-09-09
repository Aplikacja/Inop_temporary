//**********************************************************************************************************************************************************//
//	Plik: C_menu_tree.cpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-04-2018		Lukasz Witek vel Witkowski			Dodanie metody m_view pobierajacego vector id														//
//	10-07-2018		Lukasz Witek vel Witkowski			Naprawa metody																						//
//	18-08-2018		Lukasz Witek vel Witkowski			Naprawa metody																						//
//	22-08-2018		Lukasz Witek vel Witkowski			Naprawa metody																						//
//	05-08-2018		Lukasz Witek vel Witkowski			Naprawa metody																						//
//----------------------------------------------------------------------------------------------------------------------------------------------------------//
#include "C_menu_tree.hpp"

C_menu_tree::C_menu_tree(std::vector<std::vector<std::string>>& V, bool b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person) :C_menu_base(V, b, v_k,V_procedur, i_iterator,L_person) {}
C_menu_tree::~C_menu_tree() {}
bool C_menu_tree::m_view(int i_id_menu, int& i, int& i_klucz, std::vector<int>& V_prosec, int& i_choice) { return false; };
bool C_menu_tree::m_view(int i_id_menu, int& i, int& i_klucz, std::vector<long long>& V_proces, int& i_choice, std::vector<std::vector<C_id>>& V_id) {
	int i_x = 0;
	int i_y;
	int i_ptr;
	int i_i;
	int i_replay;
	int i_level;
	int i_sizes;
	std::vector<std::vector<std::string>> V_str;
	std::vector<std::string> V_str_temp;
	std::vector<int> V_input = { 0, 1, 2, 3,4, 5, 6 }; //0,3,1,2,4,5,6
	std::vector<int> V_size;
	std::vector<bool> V_b;
	std::vector<int>::iterator it = V_input.begin();
	V_str.resize(7);
		V_str[*it] = V_str_[0][i_id_menu];
		it++;
		//it = V_input.begin();
	for (auto V : V_L_person_) {
		i_sizes = 0;
		for (auto X : V) {
			V_str_temp.push_back(X->m_view());	i_sizes++; //popracowac nad tym
		}
		V_size.push_back(i_sizes);
		V_str[*it] = V_str_temp;
		V_str_temp.clear();
		it++;
	}
	std::vector<int> V_k;
	V_k = *V_klucz_.begin();
	for (auto& X : V_L_person_) {
			V_b.push_back((bool)X.size());
	}
	for (i_i = 0; i_i < V_b.size(); i_i++) {
		if (V_b[i_i]) {
			i_y = i_i+1; break;
		}
	}
	switch (i_choice) {
	case 1: {
		f_option_clear(h, pos, Written);
		while (true) {
			i_klucz = -1;
			i_level = 0;
			for (auto& Y : V_str) {
				i_ptr = 0;
				for (auto x : Y) {
					if (i_ptr == i_x&& i_level == i_y) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), is_color);
						printf(x.c_str()); printf("\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						i_ptr++;
						continue;
					}
					printf(x.c_str()); printf("\n");
					i_ptr++;
				}
				i_level++;
			}
			f_clear(h, pos, Written);
			m_ruch(f_sterowanie_tree, i_x,i_y, i_klucz, i_start_, V_k,V_size,V_id);
			switch (i_klucz) {
			case -2: {  //zaimplementowanie na powrut do porezdniego menu
				V_proces.clear();
				this->m_get_replay(i_id_menu, i_replay);
				V_proces.push_back(i_replay);
				return false;
			}
			case -10: { //strzalka w lewo
				i_y--;
				i_x = 0;
				if (i_y < 1) {
					i_y = V_L_person_.size();
					while (true) {
						if (i_y < 1) {
							i_y = V_L_person_.size();
							while (true) {
								if (!V_b[i_y - 1]) {
									i_y--;
									if (i_y == 3) {
										i_y--;
										while (true) {
											if (!V_b[i_y - 1]) {
												i_y--;
											}
											else break;
										}
									}
								}
								else break;
							}
						}
						if (!V_b[i_y - 1]) {
							i_y--;
						}
						else break;
					}
				}
				else if (i_y == 3) {
					i_y--;
					while (true) {
						if (i_y < 1) {
							i_y = V_L_person_.size();
							while (true) {
								if (!V_b[i_y - 1]) {
									i_y--;
									if (i_y == 3) {
										i_y--;
										while (true) {
											if (!V_b[i_y - 1]) {
												i_y--;
											}
											else break;
										}
									}
								}
								else break;
							}
						}
						if (!V_b[i_y - 1]) {
							i_y--;
						}
						else break;
					}
				}
				break;
			}
			case -11: { //stralka w prawo
				i_y++;
				i_x = 0;
				if (i_y >= V_L_person_.size()) {
					i_y = 1;
					while (true) {
						if (!V_b[i_y - 1]) {
							i_y++;
						}
						else break;
					}
				}
				else if (i_y == 3) {
					i_y++;
					while (true) {
						if (!V_b[i_y - 1]) {
							i_y++;
						}
						else break;
					}
				}
				break;
			}
			case -12: { //spacja

			}
			default:
				if (i_klucz > -1) {
					V_proces.clear();
					V_proces.push_back(V_id[i_y-1][i_x].m_return());
					return true;
				}
			}
		};
	}break;
	case 2:
	{
		f_option_clear(h, pos, Written);
		while (true) {
			i_klucz = -1;
			i_ptr = i_start_;
			for (auto& Y : V_str) {
				for (auto x : Y) {
					if (i_ptr == i_x) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), is_color);
						printf(x.c_str()); printf("\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						i_ptr++;
						continue;
					}
					printf(x.c_str()); printf("\n");
					i_ptr++;
				}
			}
			f_clear(h, pos, Written);
			m_ruch(f_sterowanie_tree, i_x,i_y, i_klucz, i_start_, V_k, V_size,V_id);
			switch (i_klucz) {
			case -2: {  //zaimplementowanie na powrut do porezdniego menu
				V_proces.clear();
				this->m_get_replay(i_id_menu, i_replay);
				V_proces.push_back(i_replay);
				return false;
			}
			case -10: { //strzalka w lewo
				i_y--;
				i_x = 0;
				if (i_y < 1) {
					i_y = V_L_person_.size();
					while (true) {
						if (i_y < 1) {
							i_y = V_L_person_.size();
							while (true) {
								if (!V_b[i_y - 1]) {
									i_y--;
								 if (i_y == 3) {
									i_y--;
									while (true) {
										if (!V_b[i_y - 1]) {
											i_y--;
										}
										else break;
									}
								}
								}
								else break;
							}
						}
						if (!V_b[i_y - 1]) {
							i_y--;
						}
						else break;
					}
				}
				else if (i_y == 3) { i_y--; 
				while (true) {
					if (i_y < 1) {
						i_y = V_L_person_.size();
						while (true) {
							if (!V_b[i_y - 1]) {
								i_y--;
								if (i_y == 3) {
									i_y--;
									while (true) {
										if (!V_b[i_y - 1]) {
											i_y--;
										}
										else break;
									}
								}
							}
							else break;
						}
					}
					if (!V_b[i_y - 1]) {
						i_y--;
					}
					else break;
				}
				}
				break;
			}
			case -11: { //stralka w prawo
				i_y++;
				i_x = 0;
				if (i_y >= V_L_person_.size()) {
					i_y = 1;
					while (true) {
						if (i_y >= V_L_person_.size()) {
							i_y = 1;
						}
						if (!V_b[i_y - 1]) {
							i_y++;
						if (i_y == 3) {
							i_y++;
							while (true) {
								if (!V_b[i_y - 1]) {
									i_y++;
								}
								else break;
							}
						}
						}
						else break;
					}
				}
				else if (i_y == 3) {
					i_y++;
					while (true) {
						if (!V_b[i_y - 1]) {
							i_y++;
							if (i_y >= V_L_person_.size()) {
								i_y = 1;
							}
							if (i_y == 3) {
								i_y++;
								while (true) {
									if (!V_b[i_y - 1]) {
										i_y++;
									}
									else break;
								}
							}
						}
						else break;
					}
				}
				break;
			}
			case -12: { //spacja

			 }
			default:
				if (i_klucz > -1) {
					V_proces.clear();
					V_proces.push_back(V_id[i_y-1][i_x].m_return());
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