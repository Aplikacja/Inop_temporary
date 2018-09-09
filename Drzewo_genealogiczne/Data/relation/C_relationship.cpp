//**********************************************************************************************************************************************************//
//	Plik: C_relationship.cpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	13-03-2018		Lukasz Witek vel Witkowski			Dodanie metod:																						//
//														-	m_view																							//
//														-	m_ative																							//
//														-	m_deactive																						//
//														-	operator==																						//
//	16-03-2018		Lukasz Witek vel Witkowski			Dodanie metod:																						//
//														-	operator<<																						//
//														-	operator>>																						//
//														-	m_add_typ																						//
//														-	m_get_typ																						//
//														-	m_set_baby																						//
//														-	m_get_baby																						//
//														-	m_return																						//
//	18-03-2018		Lukasz Witek vel Witkowski			Dodanie metod:																						//
//														-	m_add_id																						//
//														-	m_get_id																						//
//**********************************************************************************************************************************************************//
#include "C_relationship.hpp"

C_relationship::C_relationship() {}
C_relationship::C_relationship(C_id& ID, C_date& Date) {
	id_ = ID; date_ = Date;
}
void operator<<(std::ofstream &is, C_relationship &C) {
	is << C.b_value_<<' ';
	is << C.i_typ_<<' ';
	is << C.id_;
	is << ' ';
	is << C.V_.size()<<' ';
	for (auto& x : C.V_) {
		is << '\n';
		is << x;
	}
	is << ' ';
}
void operator>>(std::ifstream& is, C_relationship &C) {
	long long ll_temp;
	int i_iterator;
	C_relation relation;
	is >> C.b_value_;
	is >> C.i_typ_;
	is >> C.id_;
	is >> ll_temp; //ilosc elementow relacje (dzieci)
	for (i_iterator = 0; i_iterator < ll_temp; i_iterator++) {
		is >> relation;
		C.m_set_baby(relation);
	}
}
void C_relationship::m_wiew() {}
C_relationship::~C_relationship() {}
void C_relationship::m_active() { b_value_ = true; }
void C_relationship::m_deactive() { b_value_ = false; }
void C_relationship::m_add_typ(int i_variable) { i_typ_ = i_variable; }
void C_relationship::m_get_typ(int& i_variable) { i_variable = i_typ_; }
void C_relationship::m_add_id(C_id& ID) { id_ = ID; }
void C_relationship::m_get_id(C_id& ID) { ID = id_; }
C_relation C_relationship::m_return(int i_value) {
	if(i_value<(int)V_.size())
	return V_[i_value];
	else {
		C_relation relation;
		return relation;
	}
}
void C_relationship::m_set_baby(C_relation& relation) {
	for (auto& X : V_)
		if (X == relation) return;
	V_.push_back(relation);
}
void C_relationship::m_get_baby(std::vector<C_relation>& relation) {
	relation = V_;
}
int C_relationship::m_get_typ() { return i_typ_; }
bool C_relationship::operator==(const C_relationship& re) {
	if (id_ == re.id_&&date_ == re.date_&&b_value_ == re.b_value_&&i_typ_ == re.i_typ_) {
		std::vector<C_relation> V_relation = re.V_;
		if (V_relation.size() == V_.size()) {
			for (auto X : V_relation) {
				for (auto Y : V_) {
					if (X == Y)  return false;
				}
			}
			return true;
		}
		
	}
	return false;
}