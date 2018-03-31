//**********************************************************************************************************************************************************//
//	Plik: C_person_base.hpp																									Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_person_base.hpp"

C_person_base::C_person_base() {}
//	first_name = "";
//	last_name = "";
//}
C_person_base::C_person_base(C_id ID, bool b_SEX, std::string s_First, std::string s_Secend,
	C_date Date_brith, C_date Date_death, std::vector<C_relation> V_r, std::vector<C_relationship> V_rs) {
	id = ID;
	first_name = s_First;
	last_name = s_Secend;
	b_sex = b_SEX;
	brith = Date_brith;
	death = Date_death;
	V_realtion = V_r;
	V_relationship = V_rs;
}
C_person_base::C_person_base(C_id ID,bool b_SEX,std::string& s_FIRSTNAME, std::string& s_LASTNAME, C_date& date_brith, C_date& date_death) {
	id = ID;
	b_sex = b_SEX;
	first_name = s_FIRSTNAME;
	last_name = s_LASTNAME;
	brith = date_brith;
	death = date_death;
}
C_person_base::C_person_base(std::string& s_FIRSTNAME, std::string& s_LASTNAME,C_date& date_brith, C_date& date_death ) {
	first_name = s_FIRSTNAME;
	last_name = s_LASTNAME;
	brith = date_brith;
	death = date_death;
}
C_person_base::~C_person_base() {}
void operator<<(std::ofstream &is, C_person_base &C) {
	is << ' ';
	is << C.b_sex;
	is << ' ';
	is << C.id;
	is << C.first_name<<"\n";
	is << C.last_name << "\n";
	is << C.brith;
	is << "\n";
	is << C.death;
	is <<' ' <<C.V_realtion.size();
	for (auto& X : C.V_realtion) {
		is << X;
	}
	is <<' ' << C.V_relationship.size();
	for (auto& X : C.V_relationship) {
		is << X;
	}
}
void C_person_base::m_add_id(C_id& ID) {
	id = ID;
}
void C_person_base::m_get_id(C_id& ID) {
	ID = id;
}
void C_person_base::m_add_sex(bool& SEX) {
	b_sex = SEX;
}
void C_person_base::m_get_sex(bool& SEX) {
	SEX = b_sex;
}
void C_person_base::m_add_date(int i_choice, C_date& DATE) {
	switch (i_choice)
	{
	case D_brith:
		brith = DATE;	return;
	case D_death:
		death = DATE;	return;
	default:
		return;
	}
}
void C_person_base::m_get_date(int i_choice, C_date& DATE) {
	switch (i_choice)
	{
	case D_brith:
		DATE = brith; return;
	case D_death:
		DATE = death; return;
	default: return;
	}
}
std::string C_person_base::m_get_content() {
	return ' ' + first_name + ' ' + last_name + '\n';
}
void C_person_base::m_add_relation(C_relation& relation) {
	V_realtion.push_back(relation);
}
void C_person_base::m_add_relationship(C_relationship& relation) {
	V_relationship.push_back(relation);
}
void C_person_base::m_get_V_relation(std::vector<C_relation>& V_r) {
	V_r = V_realtion;
}
void C_person_base::m_get_V_relationship(std::vector<C_relationship>& V_rs) {
	V_rs = V_relationship;
}
void C_person_base::m_add_V_relation(std::vector<C_relation>& V_r) {
	V_realtion = V_r;
}
void C_person_base::m_add_V_relationship(std::vector<C_relationship>& V_rs) {
	V_relationship = V_rs;
}
bool f_sort_first_name(C_person_base* _left, C_person_base* _right) {
	if (_left->first_name<_right->first_name)
		return true;
	return false;
}
bool f_sort_last_name(C_person_base* _left, C_person_base* _right) {
	if (_left->last_name<_right->last_name)
		return true;
	return false;
}
bool f_sort_date_brith(C_person_base* _left, C_person_base* _right) {
	if (_left->brith<_right->brith)
		return true;
	return false;
}
bool f_sort_date_death(C_person_base* _left, C_person_base* _right) {
	if (_left->death<_right->death)
		return true;
	return false;
}
bool f_sort_id(C_person_base* _left, C_person_base* _right) {
	if (_left->id<_right->id)
		return true;
	return false;
}
void C_person_base::m_add_first_name(std::string& first) {
	first_name = first;
}
void C_person_base::m_get_first_name(std::string& first) {
	first = first_name;
}
void C_person_base::m_add_last_name(std::string& last) {
	last_name = last;
}
void C_person_base::m_get_last_name(std::string& last) {
	last = last_name;
}
void C_person_base::m_conwert(std::string& s_str) {
	std::string data_brith,
				data_death;
	brith.m_sidle(data_brith);
	death.m_sidle(data_death);
	s_str += " , " + first_name + " , " + last_name + " , " + data_brith + " , " + data_death + ";";
}