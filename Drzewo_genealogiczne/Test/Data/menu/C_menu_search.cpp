#include "C_menu_search.hpp"
void f_edge(unsigned int& i_iter_down, unsigned int& i_iter_up, int i_x, int i_size, int i_start);
void f_search(std::list<std::string>& L_string, std::string& s_szukana, std::list<std::string>& L_orginal);
bool f_sort(std::string _left, std::string _right);
inline void f_type_search(int& i_typ, int& i_sort);
bool f_komperator(std::string& s_L, std::string& s_R);
C_menu_search::C_menu_search(std::vector<std::vector<std::string>>& V, bool& b, std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person):C_menu_base(V, b, v_k, V_procedur, i_iterator, L_person) {}
bool C_menu_search::m_view(int i_id_menu,int& i_variable, std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) { //dopasowac zwracanie stringa z metody!!
	int i_x = i_start_;
	int i_sta = i_start_;
	int ptr;
	unsigned int i_iter_down;
	unsigned int i_iter_up;
	bool b_search = false;
	bool b_choice;
	bool b_begin = true; //okresla czy od poczatku czy od konca
	int i_replay;
	int i_typ_soft = 1;
	int i_typ_sort = 0;
	std::vector<int> V_k;
	std::string s_temp;
	std::string s_temp_;
	std::string s_message;
	std::vector<std::string> V_string;
	std::vector<std::string> V_string_head;
	std::vector<std::string> V_string_final;
	std::list<std::string> L_string;
	std::list<std::string> L_string_orgin;
	std::list<C_person_base*> L_PERSON;
	std::vector<std::vector<std::string>> V_string_data = { { "\tWyszukiwanie po imionu","\tWyszukiwanie po nazwisku", "\tWyszukiwanie po dacie urodzenia", "\tWyszukiwanie po dacie smierci"},
	{"\tSortowanie po kolejnosci dodania","\tSortowanie po imieniu", "\tSortowanie po nazwisku", "\tSortowanie po dacie urodzenia", "\tSortowanie po dacie smierci"} };
	std::vector<std::vector<std::string>>::iterator it_s;
	for (auto& Y : V_str_[0][i_id_menu]) { //eksperymeny bylo i_klucz
		V_string.push_back(Y);
		V_string_head.push_back(Y);
	}
	for (auto& Y : V_str_[1][i_id_menu]) {
		L_string.push_back(Y); //dopisywanie zawartosci do listy potrzebnej do wyszukiwania
		L_string_orgin.push_back(Y);
		V_string.push_back(Y);
	}
	V_k = *V_klucz_.begin();
	V_string_final = V_string;
	switch (i_choice) {
	case 1: {
		while (true) {
			f_type_search(i_typ_soft, i_typ_sort);
			if (!b_search&&V_string_final.size() != V_string.size()) { //gdy == false;
				V_string_final.clear();
				V_string_final = V_string;
			}
			else if (b_search) {
				if (s_message.size() > 0 && s_message[0] != ' ')
					L_string.clear();
				else
					L_string = L_string_orgin;
				f_search(L_string, s_message, L_string_orgin);
				V_string_final.clear();
				V_string_final = V_string_head;
				V_string_final.push_back("");
				if (i_sta == -20) {
					V_string_final[V_string_final.size() - 1] = s_message + " ";
				}
				V_string_final[V_string_final.size() - 1] = s_message;
				for (auto Y : L_string) {
					V_string_final.push_back(Y);
				}
			}
			b_choice = true;
			while (b_choice) {
				f_option_clear(h, pos, Written);
				ptr = 0;
				f_edge(i_iter_down, i_iter_up, i_x, (int)V_string_final.size(), (int)(i_start_ + b_search));
				for (auto& x : V_string_final) {
					{
						if (ptr < (int)(i_start_ + b_search)) {
							printf(x.c_str()); printf("\n");
							ptr++; continue;
						}
						else if (ptr < (int)i_iter_down) { ptr++; continue; }
						else if (ptr >= (int)i_iter_up) break;
						if (ptr == i_x) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), is_color);
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
				m_ruch(f_sterowanie, i_x, s_temp, i_sta, V_string_final, b_search, V_string_head.size());
				if (b_search) { // gdy == true
					if (i_sta <= 0) {
						switch (i_sta) {
						case 0: {
							s_result = s_temp;
							V_proces = V_procedur_[0];
							return true; }
						case -2: {
							//zaimplementowane do cofania sie do poprzedniego menu
							V_proces.clear();
							this->m_get_replay(i_id_menu, i_replay);
							V_proces.push_back(i_replay);
							return false; }
						case -10: { //zaimplementowane do wlaczenia wyszukiwania z listy
							if (b_search) {
								i_x--;
								b_search = false;
							}
							else {
								i_x++;
								b_search = true;
							}
							b_choice = false;
							break;
						}
						case -20: {
							if (s_message.size() > 0) {
								if (s_message[s_message.size() - 1] == ' ')
									s_message.pop_back();
								s_message.pop_back();
							}
							else
								s_message = "";
							b_choice = false;
							break;
						}
						case -100: {
							s_message = V_string_final[V_string_head.size()];
							b_choice = false;
							break;
						}
						default:
							break;
						}
					}
				}
				else {
					if (i_sta <= 0) {
						switch (i_sta) {
						case 0: {
							s_result = s_temp;
							V_proces = V_procedur_[0];
							return true; }
						case -2: {
							//zaimplementowane do cofania sie do poprzedniego menu
							V_proces.clear();
							this->m_get_replay(i_id_menu, i_replay);
							V_proces.push_back(i_replay);
							return false; }
						case -10: { //zaimplementowane do wlaczenia wyszukiwania z listy
							if (b_search) {
								i_x--;
								b_search = false;
							}
							else {
								i_x++;
								b_search = true;
							}
							b_choice = false;
							break;
						}
						default:
							break;
						}
					}
				}
			};
		};
	}break;
	case 3: { //WYSZUKIWANIE OSOB I DODAWANIE RELACJI
		i_x++;
		//		char * c_temp;
				//f_option_clear(h, pos, Written);
		while (true) {
			f_type_search(i_typ_soft, i_typ_sort);
			L_PERSON.clear();
			//	if (!b_search&&V_string_final.size() != V_string.size()) { //gdy == false;
			if (!b_search) {
				V_string_final.clear();
				V_string_final = V_string_head;
				V_string_final.push_back(V_string_data[1][i_typ_sort]);
				switch (i_typ_sort) {
				case 0:
					E_soft.m_view(view_sort, sort_id, L_PERSON); break;
				case 1:
					E_soft.m_view(view_sort, sort_first_name, L_PERSON); break;
				case 2:
					E_soft.m_view(view_sort, sort_last_name, L_PERSON); break;
				case 3:
					E_soft.m_view(view_sort, sort_date_brith, L_PERSON); break;
				case 4:
					E_soft.m_view(view_sort, sort_date_death, L_PERSON); break;
				}
				if (b_begin) {
					for (auto& X : L_PERSON) {
						s_temp_.clear();
						X->m_conwert(s_temp_);
						V_string_final.push_back(s_temp_);
					}
				}
				else
				{
					for (std::list<C_person_base*>::reverse_iterator it = L_PERSON.rbegin(); it != L_PERSON.rend(); it++) {
						s_temp_.clear();
						(*it)->m_conwert(s_temp_);
						V_string_final.push_back(s_temp_);
					}
				}
			}
			else {
				//wyszukiwanie 
				if (i_typ_sort > 0)
					i_typ_soft = i_typ_sort;
				switch (i_typ_soft) {
				case 1: {
					L_string.clear();
					E_soft.m_view(view_search, sort_first_name, s_message, L_PERSON);	break; }
				case 2: {
					L_string.clear();
					E_soft.m_view(view_search, sort_last_name, s_message, L_PERSON);	break; }
				case 3: {
					L_string.clear();
					E_soft.m_view(view_search, sort_date_brith, s_message, L_PERSON);	break; }
				case 4: {
					L_string.clear();
					E_soft.m_view(view_search, sort_date_death, s_message, L_PERSON);	break; }
				}
				if ((int)L_PERSON.size() == 0) {
					switch (i_typ_soft) {
					case 0:
						E_soft.m_view(view_sort, sort_id, L_PERSON); break;
					case 1:
						E_soft.m_view(view_sort, sort_first_name, L_PERSON); break;
					case 2:
						E_soft.m_view(view_sort, sort_last_name, L_PERSON); break;
					case 3:
						E_soft.m_view(view_sort, sort_date_brith, L_PERSON); break;
					case 4:
						E_soft.m_view(view_sort, sort_date_death, L_PERSON); break;
					}
				}
				if (b_begin) {
					for (auto& X : L_PERSON) {
						s_temp_.clear();
						X->m_conwert(s_temp_);
						L_string.push_back(s_temp_);
					}
				}
				else
				{
					for (std::list<C_person_base*>::reverse_iterator it = L_PERSON.rbegin(); it != L_PERSON.rend(); it++) {
						s_temp_.clear();
						(*it)->m_conwert(s_temp_);
						L_string.push_back(s_temp_);
					}
				}

				//----
				V_string_final.clear();
				V_string_final = V_string_head;
				V_string_final.push_back(V_string_data[0][i_typ_soft - 1]);
				V_string_final.push_back("");
				if (i_sta == -20) {
					V_string_final[V_string_final.size() - 1] = s_message + " ";
				}
				V_string_final[V_string_final.size() - 1] = s_message;
				for (auto Y : L_string) {
					V_string_final.push_back(Y);
				}
			}
			b_choice = true;
			while (b_choice) {
				f_option_clear(h, pos, Written);
				ptr = 0;
				f_edge(i_iter_down, i_iter_up, i_x, (int)V_string_final.size(), (int)i_start_ + 1 + b_search);
				for (auto& x : V_string_final) {
					if (ptr < i_start_ + 1 + b_search) {
						printf(x.c_str()); printf("\n");
						ptr++; continue;
					}
					else if (ptr < (int)i_iter_down) { ptr++; continue; }
					else if (ptr >= (int)i_iter_up) break;
					if (ptr == i_x) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), is_color);
						printf(x.c_str()); printf("\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						ptr++;
						continue;
					}
					printf(x.c_str()); printf("\n");
					ptr++;

				}
				f_clear(h, pos, Written);
				m_ruch(f_sterowanie, i_x, s_temp, i_sta, V_string_final, b_search, V_string_head.size() + b_search);
				if (b_search) { // gdy == true
					if (i_sta <= 0) {
						switch (i_sta) {
						case 0: {
							i_x -= 2; //korekta!
							std::ostringstream ss;
							ss << i_x;
							s_result = ss.str();
							V_proces = V_procedur_[0];
							return true; }
						case -2: {
							//zaimplementowane do cofania sie do poprzedniego menu
							V_proces.clear();
							this->m_get_replay(i_id_menu, i_replay);
							V_proces.push_back(i_replay);
							s_result = "";
							return false; }
						case -10: { //zaimplementowane do wlaczenia wyszukiwania z listy
							if (b_search) {
								i_x--;
								b_begin = true;
								b_search = false;
							}
							else {
								i_x++;
								b_begin = true;
								b_search = true;
							}
							b_choice = false;
							break;
						}
						case -20: {
							if (s_message.size() > 0) {
								if (s_message[s_message.size() - 1] == ' ')
									s_message.pop_back();
								s_message.pop_back();
							}
							else
								s_message = "";
							b_choice = false;
							break;
						}
						case -30: 	i_typ_soft--;	b_choice = false;	break;
						case -35: 	i_typ_soft++;	b_choice = false;	break;
						case -40:
						case -45: 	b_begin = !b_begin;	b_choice = false;	break;
						case -100: {
							s_message = V_string_final[V_string_head.size() + 1];
							b_choice = false;
							break;
						}
						default:
							break;
						}
					}
				}
				else {
					if (i_sta <= 0) {
						switch (i_sta) {
						case 0: {
							i_x -= 2; //korekta!
							std::ostringstream ss;
							ss << i_x;
							s_result = ss.str();
							V_proces = V_procedur_[0];
							return true; }
						case -2: {
							//zaimplementowane do cofania sie do poprzedniego menu
							V_proces.clear();
							this->m_get_replay(i_id_menu, i_replay);
							V_proces.push_back(i_replay);
							return false; }
						case -10: { //zaimplementowane do wlaczenia wyszukiwania z listy
							if (b_search) {
								i_x--;
								b_begin = true;
								b_search = false;
							}
							else {
								i_x++;
								b_begin = true;
								b_search = true;
							}
							b_choice = false;
							break;
						}
						case -30:	i_typ_sort++;	b_choice = false;	break;
						case -35:	i_typ_sort--;	b_choice = false;	break;
						case -40:
						case -45: 	b_begin = !b_begin;	b_choice = false;	break;
						default:
							break;
						}
					}
				}
			};
		};
	}break;
	case 2:
	{
		//f_option_clear(h, pos, Written);
		while (true) {
			f_option_clear(h, pos, Written);
			ptr = i_start_;
			f_edge(i_iter_down, i_iter_up, i_x, (int)it_s->size(), i_start_);
			it_s = V_str_[1].begin();
			for (auto& x : *it_s) {
				if (ptr < i_start_) {

					printf(x.c_str()); printf("\n");
					ptr++; continue;
				}
				else if (ptr < (int)i_iter_down) { ptr++; continue; }
				else if (ptr >= (int)i_iter_up) { break; }
				if (ptr == i_x) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), is_color);
					printf(x.c_str()); printf("\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					ptr++;
					continue;
				}
				printf(x.c_str()); printf("\n");
				ptr++;
			}
			f_clear(h, pos, Written);
			m_ruch(f_sterowanie, i_x, s_temp, i_sta, V_string, b_search, V_string_head.size());
			//if (!b_search) { // gdy == false
			if (i_sta <= 0) {
				switch (i_sta) {
				case 0: {
					s_result = s_temp;
					V_proces = V_procedur_[0];
					return true; }
				case -2: {
					//zaimplementowane do cofania sie do poprzedniego menu
					V_proces.clear();
					this->m_get_replay(i_id_menu, i_replay);
					V_proces.push_back(i_replay);
					return false; }
				case -10: { //zaimplementowane do wlaczenia wyszukiwania z listy
					if (b_search) {
						i_x--;
						b_search = false;
					}
					else {
						i_x++;
						b_search = true;
					}
					b_choice = false;
					break;
				}
				default:
					break;
				}
			}
			//	}
			//	else {

			//	}
		};
	}break;
	case 4: { //nazwy typow do wyboru w relacjach
		while (true) {
			f_type_search(i_typ_soft, i_typ_sort);
			if (!b_search&&V_string_final.size() != V_string.size()) { //gdy == false;
				V_string_final.clear();
				V_string_final = V_string;
			}
			else if (b_search) {
				V_string_final.clear();
				V_string_final = V_string_head;
				V_string_final.push_back("");
				if (i_sta == -20) {
					V_string_final[V_string_final.size() - 1] = s_message + " ";
				}
				V_string_final[V_string_final.size() - 1] = s_message;
				for (auto Y : L_string) {
					V_string_final.push_back(Y);
				}
			}
			b_choice = true;
			while (b_choice) {
				f_option_clear(h, pos, Written);
				ptr = 0;
				f_edge(i_iter_down, i_iter_up, i_x, (int)V_string_final.size(), i_start_);
				for (auto& x : V_string_final) {
					{
						if (ptr < i_start_) {
							printf(x.c_str()); printf("\n");
							ptr++; continue;
						}
						else if (ptr < (int)i_iter_down) { ptr++; continue; }
						else if (ptr >= (int)i_iter_up) break;
						if (ptr == i_x) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), is_color);
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
				m_ruch(f_sterowanie, i_x, s_temp, i_sta, V_string_final, b_search, V_string_head.size());
				if (b_search) { // gdy == true
					if (i_sta <= 0) {
						switch (i_sta) {
						case 0: { //przebudowac!!!
							i_klucz = i_x;
							//for (auto X : L_string_orgin) {
							//		switch (X[0]) {
							//			case 'M':
							//				if (X.size() > 3)	i_klucz = r_parents;			//jak mama
							//				else				i_klucz = r_partner; 	break;	//jak maz
							//			case 'T': 				i_klucz = r_parents;	break;	//jak tata
							//			case 'B':				i_klucz = r_sibling;	break;	//jak brat
							//			case 'S':
							//				if (X.size() > 3)	i_klucz = r_chlidren;			//jak syn
							//				else				i_klucz = r_sibling;	break;	//jak siostra
							//			case 'Z': 				i_klucz = r_partner;	break;	//jak zona
							//			case 'C':				i_klucz = r_chlidren;	break;	//jak corka
							//		}
							//	}
								V_proces = V_procedur_[0];
								return true;
							}
						case -2: {
							//zaimplementowane do cofania sie do poprzedniego menu
							V_proces.clear();
							this->m_get_replay(i_id_menu, i_replay);
							V_proces.push_back(i_replay);
							return false; }
						case -10: { //zaimplementowane do wlaczenia wyszukiwania z listy
							if (b_search) {
								i_x--;
								b_search = false;
							}
							else {
								i_x++;
								b_search = true;
							}
							b_choice = false;
							break;
						}
						case -20: {
							if (s_message.size() > 0) {
								if (s_message[s_message.size() - 1] == ' ')
									s_message.pop_back();
								s_message.pop_back();
							}
							else
								s_message = "";
							b_choice = false;
							break;
						}
						case -100: {
							s_message = V_string_final[V_string_head.size()];
							b_choice = false;
							break;
						}
						default:
							break;
						}
						}
					}
					else {
						if (i_sta <= 0) {
							switch (i_sta) {
							case 0: {
								i_klucz = i_x;
								//for (auto X : L_string_orgin) {
								//		switch (X[0]) {
								//			case 'M':
								//				if (X.size() > 3)	i_klucz = r_parents;			//jak mama
								//				else				i_klucz = r_partner; 	break;	//jak maz
								//			case 'T': 				i_klucz = r_parents;	break;	//jak tata
								//			case 'B':				i_klucz = r_sibling;	break;	//jak brat
								//			case 'S': 
								//				if (X.size() > 3)	i_klucz = r_chlidren;			//jak syn
								//				else				i_klucz = r_sibling;	break;	//jak siostra
								//			case 'Z': 				i_klucz = r_partner;	break;	//jak zona
								//			case 'C':				i_klucz = r_chlidren;	break;	//jak corka
								//		}
								//	}
									V_proces = V_procedur_[0];
									return true;
								}
							case -2: {
								//zaimplementowane do cofania sie do poprzedniego menu
								V_proces.clear();
								this->m_get_replay(i_id_menu, i_replay);
								V_proces.push_back(i_replay);
								return false; }
							case -10: { //zaimplementowane do wlaczenia wyszukiwania z listy
								if (b_search) {
									i_x--;
									b_search = false;
								}
								else {
									i_x++;
									b_search = true;
								}
								b_choice = false;
								break;
							}
							default:
								break;
							}
							}
						}
					};
				};
			}break;
	default: break;
		}
		return false;
} //metoda wysiwetlajaca
bool C_menu_search::m_view(int i_id_menu, int& i, int& i_klucz, std::vector<int>& V_procedur, int& i_choice) { return false; }
bool C_menu_search::m_view(int i_id_menu, int& i, int& i_klucz, std::vector<long long>& V_proces, int& i_choice, std::vector<std::vector<C_id>>& V_id) { return false; }
bool C_menu_search::m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) { return false; }
bool C_menu_search::m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice, int& b_replay) { return false; }
C_menu_search::~C_menu_search() {} //destruktor
void f_edge(unsigned int& i_iter_down, unsigned int& i_iter_up, int i_x, int i_size, int i_start) {
	if (i_size > size_list_view * 2) {
		if (i_x < size_list_view+i_start) {
			i_iter_down = i_start;
			i_iter_up = 2 * size_list_view+i_start;
			return;
		}
		else if (i_x < i_size - size_list_view)
		{
			if (0 < i_x - size_list_view)
				i_iter_down = i_x - size_list_view;
				i_iter_up = i_x + size_list_view;
		}
		else {
			i_iter_down = i_size - 2* size_list_view;
			i_iter_up = i_size;
		}
	}
	else
	{
		i_iter_down = 0;
		i_iter_up = i_size;
		return;
	}
}
inline void f_type_search(int& i_typ, int& i_sort) {
	switch (i_typ) {
		case 0:
			i_typ = 4;
			break;
		case 5:
			i_typ = 1;
			break;
	}
	switch (i_sort) {
		case -4:
		case -3:
		case -2:
		case -1:
			i_sort = 4;
			break;
		case 5:
		case 6:
		case 7:
		case 8:
			i_sort = 0;
			break;
	}
}
bool f_sort(std::string _left, std::string _right) {
	return (_left < _right);
	//return true;
}
void f_search(std::list<std::string>& L_string, std::string& s_szukana, std::list<std::string>& L_orginal) {
	int i_size = (int)L_orginal.size() - 1;
	int i_iterator = 0;
	std::string s_pointer;
	L_orginal.sort(f_sort);
	std::list<std::string>::iterator it = L_orginal.begin();
	std::list<std::string>::iterator it_start = L_orginal.begin();
	while (i_iterator <= i_size)
	{
		it = it_start;
		advance(it, i_iterator);
		s_pointer = *it ;
		if (f_komperator(s_pointer, s_szukana)) { //zwraca person odpowiednia wartosc
			L_string.push_back(*it);
		}
		i_iterator++;
	}
}
bool f_komperator(std::string& s_L, std::string& s_R) {
	std::string s_l; //string krutszy
	std::string s_r; //string wiekszy
	int i_iter_l = 0;
	int i_iter_r = 0;
	int i_inter_max = 0;
	bool b_var = false;
	bool b_value = false;
	if (s_L.size() > s_R.size()) {
		s_r = s_L;
		s_l = s_R;
	}
	else if (s_R.size() > s_L.size()) {
		s_r = s_R;
		s_l = s_L;
	}
	else {
		return s_R == s_L;
	}
	do {
		if (b_value) {
			i_inter_max++;
			for (i_iter_r = i_inter_max; i_iter_r < (int)s_r.size(); i_iter_r++) {
				if (s_r[i_iter_r] == ' ' || s_r[i_iter_r] == '-') {
					i_inter_max = i_iter_r;
					break;
				}
			}
			i_iter_r = i_inter_max + 1;
		}
		if (i_iter_r > ((int)s_r.size() - (int)s_l.size())) return false; //nic nie znalazl
		for (i_iter_l = 0; i_iter_l < (int)s_l.size(); i_iter_l++) {
			if (s_l[i_iter_l] == s_r[i_iter_r]) b_var = true;
			else {
				b_var = false;
				break;
			}
			i_iter_r++;
		}
		if (b_var) return true;
		else {
			b_value = true;
		}
	} while (b_value);
	return false; //usuniecie waringu
}