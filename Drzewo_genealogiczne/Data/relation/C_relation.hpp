//**********************************************************************************************************************************************************//
//	Plik: C_relation.hpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	13-03-2018		Lukasz Witek vel Witkowski			Dodanie metod:																						//
//														-	m_view																							//
//														-	m_ative																							//
//														-	m_deactive																						//
//														-	operator==																						//
//	16-03-2018		Lukasz Witek vel Witkowski			Dodanie metod:																						//
//														-	operator<<																						//
//														-	operator>>																						//
//														-	m_add_typ																						//
//														-	m_get_typ																						//
//	18-03-2018		Lukasz Witek vel Witkowski			Dodanie metod:																						//
//														-	m_add_id																						//
//														-	m_get_id																						//
//**********************************************************************************************************************************************************//
#ifndef C_RELATION_HPP
#define C_RELATION_HPP
#include "../data/C_id.hpp"
class C_relation {
	C_id id_; //zmienna przechowujaca id
	bool b_value_; //zmienna przechowujaca czy relaca jest aktywna czy tez nie
	int i_typ_; //zmienna charakteryzujacy typ relacji
public:
	C_relation(); //konstruktor
	C_relation(C_id& id); //konstruktor parametrowy
	C_relation(C_id& id,int i_typ, bool b_active); //konstruktor parametrowy
	friend void operator<<(std::ofstream& is, C_relation &C); //operator do zapisywaia danych
	friend void operator>>(std::ifstream& is, C_relation &C); //operator do wczytywania dancyh
	bool operator==(const C_relation& re);
	void m_wiew(); //mozna pominac
	void m_active(); //metoda aktywujaca relacje
	void m_deactive(); //metoda powodujaca ze dana relacja jest niekatywna
	void m_add_typ(int i_variable); //metoda pozwalajaca dodawac do obiektu typu C_relation wartosc okreslajaca typ relacji
	void m_get_typ(int& i_variable); //metoda pozwalajaca wyciagac informacje o typie relacji z obiektu typu C_relation
	void m_add_id(C_id& ID); //metoda pozwalajaca dodawac id od relacji
	void m_get_id(C_id& ID); //metoda pozwalajaca do pozyskiwania id z relacji
	int m_get_typ(); //metoda zwraca informacje o typie
	~C_relation(); //destruktor
};
#endif // !C_RELATION_HPP