//**********************************************************************************************************************************************************//
//	Plik: C_db.cpp																											Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_db.hpp"

C_db::C_db() {}
void C_db::m_size(int& i_var) {
	i_var = L_person.size();
}
void C_db::m_get(std::list<C_person_base*>& lista)
{
	lista = L_person;
}
void C_db::m_load(std::ifstream& is) {
	m_delete_base();
	int i_iterator;
	int i_iterator_integral;
	int i_variable;
	int i_var_relation;
	int i_var_relationship;
	bool b_SEX;
	std::string s_first;
	std::string s_secend;
	C_id id;
	C_date dat_first;
	C_date dat_secend;
	C_relation relation;
	C_relationship relationship;
	std::vector<C_relation> V_r;
	std::vector<C_relationship> V_rs;
	is >> i_variable;
	for (i_iterator = 0; i_iterator < i_variable ; i_iterator++) {
		V_r.clear();
		V_rs.clear();
		is >> b_SEX;
		is >> id;
		getline(is, s_first);
		getline(is, s_secend);
		is >> dat_first;
		is >> dat_secend;
		is >> i_var_relation;
		for (i_iterator_integral = 0; i_iterator_integral < i_var_relation; i_iterator_integral++) {
			is >> relation;
			V_r.push_back(relation);
		}
		is >> i_var_relation;
		for (i_iterator_integral = 0; i_iterator_integral < i_var_relation; i_iterator_integral++) {
			is >> relationship;
			V_rs.push_back(relationship);
		}
		L_person.push_back(new C_person_null(id,b_SEX, s_first, s_secend, dat_first, dat_secend,V_r,V_rs));
	}
}
C_db::~C_db() {}
void C_db::m_delete_base() {
	for (auto& x : L_person) {
		delete x;
	}
	L_person.clear();
}
void C_db::m_sort(bool(*F)(C_person_base* _left, C_person_base* _right)) {
	L_person.sort(F);
}
void C_db::m_add_person(bool b_SEX,std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth) {
	L_person.push_back(new C_person_null(ID_MAIN,b_SEX,s_first, s_last, d_brith, d_deadth));
}
void C_db::m_update_person(bool b_SEX,std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth, int& i_variable) { //do szcegolnego przetestowania
	std::list<C_person_base*>::iterator it = L_person.begin();
	advance(it, i_variable); //przesuwa iterator listy o wartosc i_variable
	//std::vector<C_relation> V_r;
	//std::vector<C_relationship> V_rs;
	//(*it)->m_get_V_relation(V_r);
	//(*it)->m_get_V_relationship(V_rs);
	//delete *it;
	//L_person.erase(it);
	//L_person.insert(it, new C_person_null(s_first, s_last, d_brith, d_deadth));
	(*it)->m_add_first_name(s_first);
	(*it)->m_add_last_name(s_last);
	(*it)->m_add_sex(b_SEX);
	(*it)->m_add_date(D_brith, d_brith);
	(*it)->m_add_date(D_death, d_deadth);
//	(*it)->m_add_V_relationship(V_rs);
}
void C_db::m_add_relationship(C_relationship& relation, int& i_variable) { //do szcegolnego przetestowania
	std::list<C_person_base*>::iterator it = L_person.begin();
	advance(it, i_variable); //przesuwa iterator listy o wartosc i_variable
	(*it)->m_add_relationship(relation);
}
void C_db::m_delete_person(int& i_variable) { //do szcegolnego przetestowania
	std::list<C_person_base*>::iterator it = L_person.begin();
	advance(it, i_variable); //przesuwa iterator listy o wartosc i_variable
	delete *it;
	L_person.erase(it);
}
void C_db::m_add_relation(C_relation& relation, int& i_variable) { //do szcegolnego przetestowania
	std::list<C_person_base*>::iterator it = L_person.begin();
	advance(it, i_variable); //przesuwa iterator listy o wartosc i_variable
	(*it)->m_add_relation(relation);
}
void C_db::m_delete_relation(int& i_variable, int& i_var) { //do szcegolnego przetestowania
	std::list<C_person_base*>::iterator it = L_person.begin();
	advance(it, i_variable); //przesuwa iterator listy o wartosc i_variable
	std::vector<C_relation> V_r;
	(*it)->m_get_V_relation(V_r);
	std::vector<C_relation>::iterator IT = V_r.begin();
	advance(IT, i_variable); //przesuwa iterator listy o wartosc i_variable
	V_r.erase(IT);
	(*it)->m_add_V_relation(V_r);
}
void C_db::m_delete_relationship(int& i_variable, int& i_var) {//do szcegolnego przetestowania
	std::list<C_person_base*>::iterator it = L_person.begin();
	advance(it, i_variable); //przesuwa iterator listy o wartosc i_variable
	std::vector<C_relationship> V_rs;
	(*it)->m_get_V_relationship(V_rs);
	std::vector<C_relationship>::iterator IT = V_rs.begin();
	advance(IT, i_variable); //przesuwa iterator listy o wartosc i_variable
	V_rs.erase(IT);
	(*it)->m_add_V_relationship(V_rs);
}
void C_db::m_update_relation(C_relation& relation, int& i_variable, int& i_var) { //do szcegolnego przetestowania
	std::list<C_person_base*>::iterator it = L_person.begin();
	advance(it, i_variable); //przesuwa iterator listy o wartosc i_variable
	std::vector<C_relation> V_r;
	(*it)->m_get_V_relation(V_r);
	std::vector<C_relation>::iterator IT = V_r.begin();
	advance(IT, i_variable); //przesuwa iterator listy o wartosc i_variable
	(*IT) = relation;
	//V_r.erase(IT);
	//V_r.insert(IT, relation);
	(*it)->m_add_V_relation(V_r);
}
void C_db::m_update_relationship(C_relationship& relation, int& i_variable, int& i_var) { //do szcegolnego przetestowania
	std::list<C_person_base*>::iterator it = L_person.begin();
	advance(it, i_variable); //przesuwa iterator listy o wartosc i_variable
	std::vector<C_relationship> V_rs;
	(*it)->m_get_V_relationship(V_rs);
	std::vector<C_relationship>::iterator IT = V_rs.begin();
	advance(IT, i_variable); //przesuwa iterator listy o wartosc i_variable
	(*IT) = relation;
	//V_rs.erase(IT);
	//V_rs.insert(IT, relation);
	(*it)->m_add_V_relationship(V_rs);
}
void C_db::m_search(int i_choice, std::string s_szukana, std::list<C_person_base*>& List){
	int i_iterator = 0;
	int i_size = L_person.size() - 1;
	int i_SIZE = i_size;
	int i_sr =0;
	int i_var=0;
	std::string s_pointer;
	switch(i_choice) {
		case sort_first_name: {
			L_person.sort(f_sort_first_name);
			std::list<C_person_base*>::iterator it = L_person.begin();
			std::list<C_person_base*>::iterator it_start = L_person.begin();
			while (i_iterator < i_size)
			{
				i_sr = (i_iterator + i_size) / 2;
				it = it_start;
				advance(it, i_sr);
				f_typ(i_choice, s_pointer, it);
				if (f_comparison(s_pointer,s_szukana)) { //zwraca person odpowiednia wartosc
					List.push_back(*it); //nie mam pojecia czy to bedzie dzialac
					i_size = i_sr;
					i_iterator = i_sr;
					f_szukaj<std::string>(sort_first_name,i_SIZE, i_var, i_iterator, i_size, List, it, it_start, s_pointer, s_szukana);
					return;
				}
				if (s_pointer > s_szukana)
					i_size = i_sr - 1;
				else
					i_iterator = i_sr + 1;
			}break;
		}
		case sort_last_name: {
			L_person.sort(f_sort_last_name);
			std::list<C_person_base*>::iterator it = L_person.begin();
			std::list<C_person_base*>::iterator it_start = L_person.begin();
				while (i_iterator <= i_size)
				{
					it = it_start;
					advance(it, i_iterator);
					f_typ(i_choice, s_pointer, it);
					if (f_comparison(s_pointer, s_szukana)) { //zwraca person odpowiednia wartosc
						List.push_back(*it); //nie mam pojecia czy to bedzie dzial
					}
				i_iterator++;
				}
			break;
		}
		case sort_date_brith:	{
			L_person.sort(f_sort_date_brith);
			std::list<C_person_base*>::iterator it = L_person.begin();
			std::list<C_person_base*>::iterator it_start = L_person.begin();
			while (i_iterator <= i_size)
			{
				advance(it, i_iterator);
				f_typ(i_choice, s_pointer, it);
				if (f_comparison(s_pointer, s_szukana)) { //zwraca person odpowiednia wartosc
					List.push_back(*it); //nie mam pojecia czy to bedzie dzialac
				}
				i_iterator++;
			}break;
		}
		case sort_date_death: {
			L_person.sort(f_sort_date_death);
			std::list<C_person_base*>::iterator it = L_person.begin();
			std::list<C_person_base*>::iterator it_start = L_person.begin();
			while (i_iterator <= i_size)
			{
				advance(it, i_iterator);
				f_typ(i_choice, s_pointer, it);
				if (f_comparison(s_pointer, s_szukana)) { //zwraca person odpowiednia wartosc
					List.push_back(*it); //nie mam pojecia czy to bedzie dzialac
				}
				i_iterator++;
			}break;
		}
		default: return; //zwracamy -1, gdy nie znajdziemy elementu
	}
}
void C_db::m_search(int i_choice, C_id& id_szukana, std::list<C_person_base*>& List) {
	int i_iterator = 0;
	int i_size = L_person.size() - 1;
	int i_SIZE = i_size;
	int i_sr=0;
	int i_var = 0;
	long long ll_szukana;
	long long ll_pointer;
	std::string s_szukana;
	std::string s_pointer;
	switch (i_choice) {
	case sort_id: {
		L_person.sort(f_sort_id);
		std::list<C_person_base*>::iterator it = L_person.begin();
		std::list<C_person_base*>::iterator it_start = L_person.begin();
		ll_szukana = id_szukana.m_return_value();
		while (i_iterator < i_size)
		{
			i_sr = (i_iterator + i_size) / 2;
			advance(it, i_sr);
			f_typ(i_choice, ll_pointer, it);
			if (ll_pointer == ll_szukana) { //zwraca person odpowiednia wartosc
				List.push_back(*it); //nie mam pojecia czy to bedzie dzialac
				i_size = i_sr;
				i_iterator = i_sr;
				f_szukaj<long long>(sort_id,i_SIZE, i_var, i_iterator, i_size, List, it, it_start, ll_pointer, ll_szukana);
			return;
			}
			if (ll_pointer > ll_szukana)
				i_size = i_sr - 1;
			else
				i_iterator = i_sr + 1;
		}break;
	}
	default: return; //zwracamy -1, gdy nie znajdziemy elementu
	}
}
bool f_comparison(long long& ll_L, long long& ll_R) {
	if (ll_L == ll_R) return true;
	return false;
}
bool f_comparison(std::string& s_L, std::string& s_R) {
	std::string s_l; //string krutszy
	std::string s_r; //string wiekszy
	int i_iter_l=0;
	int i_iter_r=0;
	int i_inter_max =0;
	bool b_var = false;
	bool b_value = false;
	if (s_L.size() > s_R.size()) {
		s_r = s_L;
		s_l = s_R;
	}
	else if (s_R.size() > s_L.size()){
		s_r = s_R;
		s_l = s_L;
	}
	else {
		if (s_R == s_L) return true;
		return false;
	}
	do {
		if(b_value) {
			i_inter_max++;
			for (i_iter_r = i_inter_max; i_iter_r < s_r.size(); i_iter_r++) {
				if (s_r[i_iter_r] == ' ' || s_r[i_iter_r] == '-') {
					i_inter_max = i_iter_r;
					break;
				}
			}
			i_iter_r = i_inter_max + 1;
		}
		if (i_iter_r > s_r.size() - s_l.size()) return false; //nic nie znalazl
		for (i_iter_l = 0; i_iter_l < s_l.size(); i_iter_l++) {
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
}
template<class T>
void f_szukaj(int i_typ,int& i_SIZE,int& i_var,int& i_iterator, int& i_size, std::list<C_person_base*>& List,std::list<C_person_base*>::iterator& it, std::list<C_person_base*>::iterator& it_start, T& s_pointer, T& s_szukana) {
	while (true) {
		switch (i_var) {
		case 0: {
			while (i_var == 0) {
				switch (f_sprawdzanie(i_SIZE, i_iterator, i_size)) {
				case 1: {
					it = it_start;
					advance(it, i_size);
					f_typ(i_typ, s_pointer,it);
					if (f_comparison(s_pointer, s_szukana)) //zwraca person odpowiednia wartosc
						List.push_back(*it);
					else {
						i_size = i_iterator;
						i_var = 1;
						break;
					}
					it = it_start;
					advance(it, i_iterator);
					f_typ(i_typ, s_pointer, it);
					if (f_comparison(s_pointer, s_szukana)) //zwraca person odpowiednia wartosc
						List.push_back(*it);
					else {
						if (i_var == 0) {
							i_iterator = i_size;
							i_var = 2; break;
						}
						else {
							i_var = 3; break;
						}
					}
				}break;
				case 2: {
					it = it_start;
					advance(it, i_size);
					f_typ(i_typ, s_pointer, it);
					if (f_comparison(s_pointer, s_szukana)) //zwraca person odpowiednia wartosc
						List.push_back(*it);
					else {
						if (i_var == 0) {
							i_iterator = i_size;
							i_var = 2; break;
						}
						else {
							i_var = 3; break;
						}
					}
				}
				case 3: {
					it = it_start;
					advance(it, i_iterator);
					f_typ(i_typ, s_pointer, it);
					if (f_comparison(s_pointer, s_szukana)) //zwraca person odpowiednia wartosc
						List.push_back(*it);
					else {
						if (i_var == 0) {
							i_iterator = i_size;
							i_var = 2; break;
						}
						else {
							i_var = 3; break;
						}
					}
				}
				default: return;
				}
			}break;
		}
		case 1: {
			while (i_var == 1) {
				switch (f_sprawdzanie_gora(i_SIZE, i_iterator, i_size)) {
				case 1:{
					it = it_start;
					advance(it, i_iterator);
					f_typ(i_typ, s_pointer, it);
					if (f_comparison(s_pointer, s_szukana)) //zwraca person odpowiednia wartosc
						List.push_back(*it);
					else {
						i_var = 3; break;
					}
					it = it_start;
					advance(it, i_size);
					f_typ(i_typ, s_pointer, it);
					if (f_comparison(s_pointer, s_szukana)) //zwraca person odpowiednia wartosc
						List.push_back(*it);
					else {
						i_var = 3; break;
					}
				}break;
				case 2: {
					it = it_start;
					advance(it, i_size);
					f_typ(i_typ, s_pointer, it);
					if (f_comparison(s_pointer, s_szukana)) //zwraca person odpowiednia wartosc
						List.push_back(*it);
					else {
						i_var = 3; break;
					}
				}
				default: return;
				}
			}break;
		}
		case 2: {
			while (i_var == 2) {
				switch (f_sprawdzanie_dol(i_SIZE, i_iterator, i_size)) {
				case 1: {
					it = it_start;
					advance(it, i_size);
					f_typ(i_typ, s_pointer, it);
					if (f_comparison(s_pointer, s_szukana)) //zwraca person odpowiednia wartosc
						List.push_back(*it);
					else {
						i_var = 3; break;
					}
					it = it_start;
					advance(it, i_iterator);
					f_typ(i_typ, s_pointer, it);
					if (f_comparison(s_pointer, s_szukana)) //zwraca person odpowiednia wartosc
						List.push_back(*it);
					else {
						i_var = 3; break;
					}
				}break;
				case 2: {
					it = it_start;
					advance(it, i_iterator);
					f_typ(i_typ, s_pointer, it);
					if (f_comparison(s_pointer, s_szukana)) //zwraca person odpowiednia wartosc
						List.push_back(*it);
					else {
						i_var = 3; break;
					}
				}
				default: return;
				}
			}break;
		}
		default: return;
		}
	}
}
void f_typ(int i_typ,long long& ll_data, std::list<C_person_base*>::iterator& it) {
	C_id ID;
	switch (i_typ) {
		case sort_id:
			(*it)->m_get_id(ID);
			ll_data = ID.m_return_value();
			break;
		default: break;
	}
}
void f_typ(int i_typ, std::string& s_data, std::list<C_person_base*>::iterator& it) {
	C_date D_date;
	switch (i_typ){
		case sort_first_name:
			(*it)->m_get_first_name(s_data); break;
		case sort_last_name:
			(*it)->m_get_last_name(s_data); break;
		case sort_date_brith:
			(*it)->m_get_date(D_brith,D_date);
			D_date.m_sidle(s_data);
			break;
		case sort_date_death:
			(*it)->m_get_date(D_death, D_date);
			D_date.m_sidle(s_data); 
			break;
		default: break;
	}
}
int f_sprawdzanie(int& i_SIZE, int& i_iterator, int& i_size) {
	if (i_size >= 1 && i_iterator <= i_SIZE - 1) {
		i_size--; //wychodzenie poza zakres listy!!
		i_iterator++;
		return 1;
	}
	else{
		if (i_size >= 1) {
			i_size--;
			return 2;
		}
		else if (i_iterator <= i_SIZE - 1) {
			i_iterator++;
			return 3;
		}
		else
			return 4;
	}
}
int f_sprawdzanie_dol(int& i_SIZE, int& i_iterator, int& i_size) {
	if (i_size >= 1 && i_iterator >= 2) {
		i_size--;
		i_iterator -= 2;
		return 1;
	}
	else{
		if (i_iterator >= 1) {
			i_iterator--;
			return 2;
		}
		else
			return 3;
	}
}
int f_sprawdzanie_gora(int& i_SIZE, int& i_iterator, int& i_size) {
	if (i_size <= i_SIZE - 2 && i_iterator <= i_SIZE - 1) {
		i_size += 2;
		i_iterator++;
		return 1;
	}
	else {
		if (i_size <= i_SIZE - 1) {
			i_size++;
			return 2;
		}
		else
			return 3;
	}
}
void C_db::m_search_specjal(C_id Person, std::list<C_person_base*>& List) { //metoda do wyszukiwania specjalnego
	//wyszukiwanie id desaktywnego!!!


}