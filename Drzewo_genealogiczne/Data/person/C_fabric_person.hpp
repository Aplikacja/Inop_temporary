//**********************************************************************************************************************************************************//
//	Plik: C_fabric_person.hpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_FABRIC_PERSON_HPP
#define C_FABRIC_PERSON_HPP
#include "C_person_base.hpp"
#include "C_person_null.hpp"
#include "C_partner.hpp"
#include "C_children.hpp"
class C_fabric_person {
public:
	C_fabric_person();
	C_person_base* m_create_peron();
	~C_fabric_person();
};
#endif // !C_FABRIC_PERSON_HPP