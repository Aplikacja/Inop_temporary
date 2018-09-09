//**********************************************************************************************************************************************************//
//	Plik: C_person_null.cpp																									Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	12.03.2018 			Damian Gwozdz						 Utworzenie klasy, konstrukorow i metody m_view()												//
//**********************************************************************************************************************************************************//
#include "C_person_null.hpp"
C_person_null::C_person_null() {}
C_person_null::C_person_null(C_id ID,bool b_SEX, std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth):C_person_base(ID,b_SEX,s_first, s_last, d_brith, d_deadth) {}
C_person_null::C_person_null(C_id ID,bool b_SEX ,std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth, std::vector<C_relation> V_r, std::vector<C_relationship> V_rs) :C_person_base(ID,b_SEX, s_first, s_last, d_brith, d_deadth, V_r, V_rs) {}
C_person_null::C_person_null(std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth):C_person_base(s_first,s_last, d_brith, d_deadth) {}
std::string C_person_null::m_view() {
	return ' ' + first_name_ + ' ' + last_name_ + '\n';
}
C_person_null::~C_person_null() {}
