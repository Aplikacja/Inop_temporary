//**********************************************************************************************************************************************************//
//	Plik: C_partner.cpp																										Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	12.03.2018 			Damian Gwozdz						 Utworzenie klasy, konstrukorow i metody m_view()												//
//**********************************************************************************************************************************************************//
#include "C_partner.hpp"

C_partner::C_partner() {}
C_partner::C_partner(C_id ID, bool b_SEX, std::string s_First, std::string s_Secend,
	C_date Date_brith, C_date Date_death, std::vector<C_relation> V_r, std::vector<C_relationship> V_rs)
	:C_person_base(ID, b_SEX, s_First, s_Secend, Date_brith, Date_death, V_r, V_rs) {}
std::string C_partner::m_view() {
	if (b_sex_) {
		return "\t- + Wife " + m_get_content();
	}
	return "\t- + Husband " + m_get_content();
}
C_partner::~C_partner() {}