//**********************************************************************************************************************************************************//
//	Plik: C_id.cpp																											Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_id.hpp"
C_id::C_id() :C_data_base() {}
C_id::C_id(long long ll_var) :C_data_base() { ll_value_ = ll_var; }
void C_id::m_giving(long long& ll_iterator) { ll_value_ = ll_iterator; }
void C_id::m_virtual() {  //tymczasowo
	std::cout << ll_value_; }; //klasa do rozbudowy
C_id::~C_id() {};