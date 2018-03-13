//**********************************************************************************************************************************************************//
//	Plik: C_relation_base.cpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_relation_base.hpp"

C_relation_base::C_relation_base() { b_value = false; }
C_relation_base::C_relation_base(C_id data) {
	id = new C_id;
	*id = data;
};
C_relation_base::C_relation_base(C_id data, C_date Date) {
	id = new C_id;
	date = new C_date;
	*id = data; *date = Date;
}
C_data_base* C_relation_base::m_return(int i_value) {
	switch (i_value)
	{
	case 1: return id;
	case 2: return date;
	default: break;
	}
}
void C_relation_base::m_active() { b_value = true; }
void C_relation_base::m_set_baby(C_relation_base* relation) { V.push_back(relation); }
C_relation_base::~C_relation_base() {
	if (id) delete id;
	if (date) delete date;
}
