//**********************************************************************************************************************************************************//
//	Plik: C_engine_tree.cpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_engine_tree.hpp"

C_engine_tree::C_engine_tree() {}
C_engine_tree& C_engine_tree::operator=(C_engine_software& E_soft) {
	std::list<C_person_base*> L_person;
	E_soft.m_copy(L_person);
	this->d_Database_.m_delete_protected(protect); //<- zdjecie zabezpieczenia
	this->d_Database_.m_giving(L_person);
	return *this;
}
void C_engine_tree::m_elimination_person(std::vector<int>& V_position) {
	std::list<C_person_base*> L_person_temp;
	std::list<C_person_base*>::iterator it;
	m_copy(L_person_temp);
	for (auto& X : V_position) {
		it = L_person_temp.begin();
		advance(it, X);
		delete *it;
		L_person_temp.erase(it);
	}
	m_giving(L_person_temp);
}
void C_engine_tree::m_giving(std::list<C_person_base*>& L_person) {
	this->d_Database_.m_delete_protected(protect);
	this->d_Database_.m_giving(L_person);
}
C_engine_tree::~C_engine_tree() {}