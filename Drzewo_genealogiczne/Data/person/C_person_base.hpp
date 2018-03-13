//**********************************************************************************************************************************************************//
//	Plik: C_person_base.hpp																									Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_PERSON_BASE_HPP
#define C_PERSON_BASE_HPP
#include <vector>
#include "../data/C_id.hpp"
#include "../data/C_date.hpp"
#include "../relation/C_relationship.hpp"
#include "../relation/C_relation.hpp"
class C_person_base {
	C_id id;
	std::string first_name;
	std::string last_name;
	C_date brith;
	C_date death;
	std::vector<C_relationship> V_relationship;
	std::vector<C_relation> V_realtion;
public:
	C_person_base();
	~C_person_base();
};
#endif // !C_PERSON_BASE_HPP

