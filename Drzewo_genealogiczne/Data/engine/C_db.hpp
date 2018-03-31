//**********************************************************************************************************************************************************//
//	Plik: C_db.hpp																											Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_DB_HPP
#define C_DB_HPP
#include <list>
#include "../person/C_person_null.hpp"
bool f_sort_first_name(C_person_base* _left, C_person_base* _right);
bool f_sort_last_name(C_person_base* _left, C_person_base* _right);
bool f_sort_date_brith(C_person_base* _left, C_person_base* _right);
bool f_sort_date_death(C_person_base* _left, C_person_base* _right);
bool f_sort_id(C_person_base* _left, C_person_base* _right);
bool f_comparison(std::string& s_L, std::string& s_R);
bool f_comparison(long long& ll_L, long long& ll_R);
template<class T>
void f_szukaj(int i_typ, int& i_SIZE, int& i_var, int& i_iterator,
	int& i_size, std::list<C_person_base*>& List, std::list<C_person_base*>::iterator& it,
	std::list<C_person_base*>::iterator& it_start, T& s_pointer, T& s_szukana);
void f_typ(int i_typ, long long& t_data, std::list<C_person_base*>::iterator& it);
void f_typ(int i_typ, std::string& s_data, std::list<C_person_base*>::iterator& it);
int f_sprawdzanie_gora(int& i_SIZE, int& i_iterator, int& i_size);
int f_sprawdzanie_dol(int& i_SIZE, int& i_iterator, int& i_size);
int f_sprawdzanie(int& i_SIZE, int& i_iterator, int& i_size);
class C_db {
	std::list<C_person_base*> L_person;
	long long ID_MAIN;
	void m_delete_base();
public:
	C_db();
	void m_size(int& i_var);
	void m_add_person(bool b_SEX,std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth);
	void m_update_person(bool b_SEX,std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth, int& i_variable);
	void m_add_relation(C_relation& relation, int& i_variable);
	void m_add_relationship(C_relationship& relation, int& i_variable);
	void m_delete_person(int& i_variable);
	void m_delete_relation(int& i_variable, int& i_var);
	void m_delete_relationship(int& i_variable, int& i_var);
	void m_update_relation(C_relation& relation, int& i_variable, int& i_var); 
	void m_update_relationship(C_relationship& relation, int& i_variable, int& i_var); 
	void m_get(std::list<C_person_base*>& lista);
	void m_load(std::ifstream& is);
	void m_sort(bool(*F)(C_person_base* _left, C_person_base* _right));
	void m_search(int i_choice, C_id& Person, std::list<C_person_base*>& List);
	void m_search(int i_choice, std::string s_szukana, std::list<C_person_base*>& List);
	~C_db();
};
#endif // !C_DB_HPP