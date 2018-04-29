//**********************************************************************************************************************************************************//
//	Plik: C_relation.cpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_relation.hpp"

C_relation::C_relation() { b_value = false; }
C_relation::C_relation(C_id& ID) { id = ID; b_value = false; }
C_relation::C_relation(C_id& ID, int i_TYP, bool b_active) { id = ID; i_typ = i_TYP, b_value = b_active; }
void operator<<(std::ofstream &is, C_relation &C) {
	is << C.b_value;
	is << C.i_typ;
	is << C.id;
}
void operator>>(std::ifstream& is, C_relation &C) {
	long long ll_temp;
	is >> C.b_value;
	is >> C.i_typ;
	is >> ll_temp;
	C.id.m_giving(ll_temp);
}
void C_relation::m_wiew() {}
C_relation::~C_relation() {}
void C_relation::m_active() { b_value = true; }
void C_relation::m_deactive() { b_value = false; }
void C_relation::m_add_typ(int& i_variable) { i_typ = i_variable; }
void C_relation::m_get_typ(int& i_variable) { i_variable = i_typ; }
void C_relation::m_add_id(C_id& ID) { id = ID; }
void C_relation::m_get_id(C_id& ID) { ID = id; }

