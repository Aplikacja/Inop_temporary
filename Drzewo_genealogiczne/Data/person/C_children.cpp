//**********************************************************************************************************************************************************//
//	Plik: C_children.cpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_children.hpp"

C_children::C_children() {}
C_children::C_children(C_id ID, bool b_SEX, std::string s_First, std::string s_Secend,
	C_date Date_brith, C_date Date_death, std::vector<C_relation> V_r, std::vector<C_relationship> V_rs)
	:C_person_base(ID,b_SEX,s_First,s_Secend, Date_brith, Date_death, V_r, V_rs) {}
std::string C_children::m_view() {
	if (b_sex) {
		return "\t\t-Daughter " + m_get_content();
	}
	return "\t\t-Son " + m_get_content();
}
C_children::~C_children() {}