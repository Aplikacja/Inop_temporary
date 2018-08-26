//**********************************************************************************************************************************************************//
//	Plik: C_date_base.cpp																									Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_data_base.hpp"

C_data_base::C_data_base() {
	ll_value_ = 0;
	b_pointer_ = false;
}
void C_data_base::m_update(long long ll_update) { 
	ll_value_ = ll_update; }
long long& C_data_base::m_return_value() {
	return ll_value_; }
long long C_data_base::m_return() {
	return ll_value_;
}
bool& C_data_base::m_what() { 
	return b_pointer_; }
C_data_base::~C_data_base() {}
void C_data_base::m_deactivation() { b_pointer_ = false; }
void operator<<(std::ofstream &is, C_data_base &C) {
	is << C.b_pointer_ << " " << C.ll_value_;
}
void operator>>(std::ifstream &is, C_data_base &C) {
	
	is >> C.b_pointer_;
	is >> C.ll_value_;
}
bool C_data_base::operator<(const C_data_base& D) {
	if (this->b_pointer_&&D.b_pointer_)
		return this->ll_value_ < D.ll_value_;
	return false;
}
void C_data_base::m_active() { 
	b_pointer_ = true; }