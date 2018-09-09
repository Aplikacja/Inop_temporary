//**********************************************************************************************************************************************************//
//	Plik: C_id.cpp																											Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	23-03-2018 Lukasz Witek vel Witkowski	Dodanie i rozbudowa metod:																						//
//														-> m_giving																							//
//														-> m_virtual																						//
//														-> m_down																							//
//	10-04-2018 Lukasz Witek vel Witkowski	Dodanie i rozbudowa operatorow:																					//
//														-> operator ==																						//
//														-> operator !=																						//
//**********************************************************************************************************************************************************//
#include "C_id.hpp"
C_id::C_id() :C_data_base() {}
C_id::C_id(long long ll_var) :C_data_base() { ll_value_ = ll_var; }
void C_id::m_giving(long long& ll_iterator) { ll_value_ = ll_iterator; }
void C_id::m_virtual() {  //tymczasowo
	std::cout << ll_value_; }; //klasa do rozbudowy
void C_id::m_down() {
	--ll_value_;
}
C_id::~C_id() {};
bool C_id::operator==(const C_id& id) {
	return (ll_value_ == id.ll_value_&&b_pointer_ == id.b_pointer_);
}
bool C_id::operator!=(const C_id& id) {
	return (ll_value_ != id.ll_value_||b_pointer_ != id.b_pointer_);
}
