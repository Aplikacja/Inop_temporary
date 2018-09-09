//**********************************************************************************************************************************************************//
//	Plik: C_children.hpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	12.03.2018 			Damian Gwozdz						 Utworzenie klasy, konstrukorow i metody m_view()												//
//**********************************************************************************************************************************************************//
#ifndef C_CHILDREN_HPP
#define C_CHILDREN_HPP
#include "C_person_base.hpp"
class C_children : public C_person_base {
public:
	C_children(); //konstruktor
	C_children(C_id ID, bool b_SEX, std::string s_First, std::string s_Secend,
				C_date Date_brith, C_date Date_death, std::vector<C_relation> V_r,
				std::vector<C_relationship> V_rs); //konstruktor parametrowy
	std::string m_view(); //metoda wyswiatlajaca (syn, corka) - w zalezonosci od pluci
	~C_children(); //destruktor
};
#endif // !C_CHILDREN_HPP