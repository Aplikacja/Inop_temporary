//**********************************************************************************************************************************************************//
//	Plik: C_fabric_person.hpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_fabric_person.hpp"

C_fabric_person::C_fabric_person() {}
C_person_base* C_fabric_person::m_create_peron(int i_variable,
												C_id ID,
												bool b_SEX,
												std::string s_First,
												std::string s_Secend,
												C_date Date_brith,
												C_date Date_death,
												std::vector<C_relation> V_r,
												std::vector<C_relationship> V_rs) {
	switch (i_variable) {
	case r_parents:
		return new C_parent(ID, b_SEX, s_First, s_Secend, Date_brith, Date_death, V_r, V_rs); break;
	case r_sibling:
		return new C_sibling(ID, b_SEX, s_First, s_Secend, Date_brith, Date_death, V_r, V_rs); break;
	case r_partner:
		return new C_partner(ID, b_SEX, s_First, s_Secend, Date_brith, Date_death, V_r, V_rs); break;
	case r_chlidren:
		return new C_children(ID, b_SEX, s_First, s_Secend, Date_brith, Date_death, V_r, V_rs); break;
	default:
		return new C_person_null(ID, b_SEX,s_First, s_Secend, Date_brith, Date_death); break;
	} 
}
C_fabric_person::~C_fabric_person() {}