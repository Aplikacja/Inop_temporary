//**********************************************************************************************************************************************************//
//	Plik: C_fabric_person.hpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_fabric_person.hpp"

C_fabric_person::C_fabric_person() {}
C_person_base* C_fabric_person::m_create_peron() { return new C_person_null; }
C_fabric_person::~C_fabric_person() {}