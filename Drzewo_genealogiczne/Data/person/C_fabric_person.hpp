//**********************************************************************************************************************************************************//
//	Plik: C_fabric_person.hpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	12.03.2018 			Damian Gwozdz						 Utworzenie klasy, konstrukorow i metody m_create_person										//
//**********************************************************************************************************************************************************//
#ifndef C_FABRIC_PERSON_HPP
#define C_FABRIC_PERSON_HPP
#include "C_person_base.hpp"
#include "C_person_null.hpp"
#include "C_parent.hpp"
#include "C_partner.hpp"
#include "C_sibling.hpp"
#include "C_children.hpp"
class C_fabric_person {
public:
	C_fabric_person();
	C_person_base* m_create_peron(int i_variable, C_id ID, bool b_SEX, std::string s_First, std::string s_Secend,
								  C_date Date_brith, C_date Date_death, std::vector<C_relation> V_r, 
								  std::vector<C_relationship> V_rs); //do rozbudowy
	~C_fabric_person();
};
#endif // !C_FABRIC_PERSON_HPP