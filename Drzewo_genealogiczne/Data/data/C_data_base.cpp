//**********************************************************************************************************************************************************//
//	Plik: C_date_base.cpp																									Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_data_base.hpp"

C_data_base::C_data_base() {
	ll_value = 0;
	b_pointer = false;
}
void C_data_base::m_update(long long ll_update) { 
	ll_value = ll_update; }
long long& C_data_base::m_return_value() {
	return ll_value; }
bool& C_data_base::m_what() { 
	return b_pointer; }
C_data_base::~C_data_base() {}
void C_data_base::m_deactivation() { b_pointer = false; }
void operator<<(std::ofstream &is, C_data_base &C) {
	is << C.b_pointer << " " << C.ll_value;
}
void operator>>(std::ifstream &is, C_data_base &C) {
	
	is >> C.b_pointer;
	is >> C.ll_value;
}
bool C_data_base::operator<(const C_data_base& D) {
	if (this->b_pointer&D.b_pointer) {
		if (this->ll_value < D.ll_value) {
			return true;
		}
		return false;
	}
	return false;
}
void C_data_base::m_active() { 
	b_pointer = true; }