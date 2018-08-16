//**********************************************************************************************************************************************************//
//	Plik: C_sibling.hpp																										Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_SIBLING_HP
#define C_SIBLING_HPP
#include "C_person_base.hpp"
class C_sibling : public C_person_base {
public:
	C_sibling(); //konstruktor
	C_sibling(C_id ID, bool b_SEX, std::string s_First, std::string s_Secend,
				C_date Date_brith, C_date Date_death, std::vector<C_relation> V_r, 
				std::vector<C_relationship> V_rs); //konstruktor parametrowy
	std::string m_view(); //metoda wyswietlajaca (brat/ siostra) - w zaleznosci od pluci
	~C_sibling(); //destruktor
};
#endif // !C_SIBLING_HP