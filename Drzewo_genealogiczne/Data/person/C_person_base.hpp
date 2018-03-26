//**********************************************************************************************************************************************************//
//	Plik: C_person_base.hpp																									Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: 26.03.2018 |	Autor: Damian Gwozdz	|				Opis: Dodanie funkcji sortujacych												//
//**********************************************************************************************************************************************************//
#ifndef C_PERSON_BASE_HPP
#define C_PERSON_BASE_HPP
#include <vector>
#include "../data/C_id.hpp"
#include "../data/C_date.hpp"
#include "../relation/C_relationship.hpp"
#include "../relation/C_relation.hpp"
#include <list>
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

	// Funkcje wyciagajace zmienne do sortowania
	std::string GetFirstName () { return first_name; }
	std::string GetLastName () { return last_name; }
	C_date GetBirthDate () { return brith; }
	C_date GetDeathDate() { return death; }
	
	// Sortowania
	void SortByName (std::list<C_person_base>);
	void SortBySurname (std::list<C_person_base>);
	void SortByBirthDate (std::list<C_person_base>);
	void SortByDeathDate (std::list<C_person_base>);
};
#endif // !C_PERSON_BASE_HPP

