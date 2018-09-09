//**********************************************************************************************************************************************************//
//	Plik: C_date.cpp																										Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	12.03.2018 			Damian Gwozdz						 Utworzenie klasy, konstrukorow i metody m_view()												//
//**********************************************************************************************************************************************************//
#pragma once
#ifndef C_PERSON_NULL_HPP
#define C_person_NULL_HPP
#include "C_person_base.hpp"
class C_person_null :public C_person_base {
public:
	C_person_null(); //konstruktor
	C_person_null(C_id ID, bool b_sex, std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth); //konstruktor parametrowy
	C_person_null(C_id ID, bool b_SEX, std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth, std::vector<C_relation> V_r, std::vector<C_relationship> V_rs); //konstruktor parametrowy
	C_person_null(std::string& s_first, std::string& s_last, C_date& d_brith, C_date& d_deadth); //konstruktor parametrowy
	std::string m_view(); //metoda wyswietlajaca imie i nazwisko
	~C_person_null(); //destruktor
};
#endif // !C_PERSON_NULL_HPP
