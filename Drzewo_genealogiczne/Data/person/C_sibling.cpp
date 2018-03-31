//**********************************************************************************************************************************************************//
//	Plik: C_sibling.cpp																										Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_sibling.hpp"

C_sibling::C_sibling() {}
C_sibling::C_sibling(C_id ID, bool b_SEX, std::string s_First, std::string s_Secend,
	C_date Date_brith, C_date Date_death, std::vector<C_relation> V_r, std::vector<C_relationship> V_rs)
	:C_person_base(ID, b_SEX, s_First, s_Secend, Date_brith, Date_death, V_r, V_rs) {}
std::string C_sibling::m_view() {
	if (b_sex) {
		return "\t-Sister " + m_get_content();
	}
	return "\t-Brother " + m_get_content();
}
C_sibling::~C_sibling() {}