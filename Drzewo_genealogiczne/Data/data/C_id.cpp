//**********************************************************************************************************************************************************//
//	Plik: C_id.cpp																											Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_id.hpp"
C_id::C_id() :C_data_base() {}
C_id::C_id(long long ll_var) :C_data_base() { ll_value = ll_var; }
void C_id::m_active() { b_pointer = true; }
void C_id::m_virtual() {}; //klasa do rozbudowy
C_id::~C_id() {};