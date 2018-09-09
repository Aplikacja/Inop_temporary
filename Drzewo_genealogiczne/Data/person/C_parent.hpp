//**********************************************************************************************************************************************************//
//	Plik: C_parent.hpp																										Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	12.03.2018 			Damian Gwozdz						 Utworzenie klasy, konstrukorow i metody m_view()												//
//**********************************************************************************************************************************************************//
#ifndef C_PARENT_HPP
#define C_PARENT_HPP
#include "C_person_base.hpp"
class C_parent : public C_person_base {
public:
	C_parent(); //konstruktor
	C_parent(C_id ID, bool b_SEX, std::string s_First, std::string s_Secend,
		C_date Date_brith, C_date Date_death, std::vector<C_relation> V_r,
		std::vector<C_relationship> V_rs); //konstruktor parametrowy
	std::string m_view(); //metoda wyswiatlajaca (ojciec, matka) - w zalezonosci od pluci
	~C_parent(); //destruktor
};
#endif // !C_PARENT_HPP