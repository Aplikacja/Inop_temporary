//**********************************************************************************************************************************************************//
//	Plik: C_parent.cpp																										Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	12.03.2018 			Damian Gwozdz						 Utworzenie klasy, konstrukorow i metody m_view()												//
//**********************************************************************************************************************************************************//
#include "C_parent.hpp"

C_parent::C_parent() {}
C_parent::C_parent(C_id ID, bool b_SEX, std::string s_First, std::string s_Secend,
	C_date Date_brith, C_date Date_death, std::vector<C_relation> V_r, std::vector<C_relationship> V_rs)
	:C_person_base(ID, b_SEX, s_First, s_Secend, Date_brith, Date_death, V_r, V_rs) {}
std::string C_parent::m_view() {
	if (b_sex_) {
		return "-Mather " + m_get_content();
	}
	return "-Father " + m_get_content();
}
C_parent::~C_parent() {}