//**********************************************************************************************************************************************************//
//	Plik: C_date_base.cpp																									Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_data_base.hpp"

C_data_base::C_data_base() {
	ll_value = 0;
	b_pointer = false;
}
void C_data_base::m_update(long long ll_update) { ll_value = ll_update; }
long long& C_data_base::m_return_value() { return ll_value; }
bool& C_data_base::m_what() { return b_pointer; }
C_data_base::~C_data_base() {}