//**********************************************************************************************************************************************************//
//	Plik: C_db.hpp																											Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_DB_HPP
#define C_DB_HPP
#include <vector>
#include "../person/C_person_base.hpp"
class C_db {
	std::vector<C_person_base*> V_person;
public:
	C_db();
	~C_db();
};
#endif // !C_DB_HPP