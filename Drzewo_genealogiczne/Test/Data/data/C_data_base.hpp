//**********************************************************************************************************************************************************//
//	Plik: C_date_base.cpp																									Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_DATA_BASE_HPP
#define C_DATA_BASE_HPP
#include <fstream>
#include "../engine/define.hpp"
#include <iostream>
class C_data_base {
protected:
	long long ll_value_; //wartosc przechowywana jako long long by latwiej go porownywac i wyszukiwac (optymalizacja)
	bool b_pointer_;  //wartosc bool okreslajaca czy obiekt klasy(klas pochodnych: C_id i C_date) jest aktywny (brany pod uwage!)
public:
	C_data_base(); //konstruktor
	void m_update(long long ll_update); // metoda pozwalajaca podmienic wartosc jaka znajduje sie w obiekcie na podana jako argument metody
	long long& m_return_value(); //metoda zwracajaca adres do zmiennej (long long ll_value)
	long long m_return();
	virtual void m_virtual() = 0; //metoda wirtualna sprawia ze klasa C_data_base jest klasa abstrakcyjna
	void m_deactivation(); //metoda ustwaia w zmiennej bool b_pointer wartosc false (sprawia ze obiekt staje NIE aktywny)
	void m_active(); //metoda ustwaia w zmiennej bool b_pointer wartosc true (sprawia ze obiekt staje sie aktywny)
	friend void operator<<(std::ofstream &is, C_data_base &C); //przeciazony operator przesuniecia bitowego na output (dzieki niej mozliwe jest zapisywanie danych do pliku)
	friend void operator>>(std::ifstream &is, C_data_base &C); //przeciazony operator przesuniecia bitowego na input (dzieki niej mozliwe jest wczytywanie danych z pliku)
	bool operator<(const C_data_base& D); //przeciazony operator porownania (specjalnie dla sortowania danych)
	bool& m_what(); //metoda zwraca wartosc (bool b_pointer) mozna dzieki niej sprawdzic czy obiekt (pochodny) jest aktywny
	~C_data_base(); //destruktor
};
#endif // !C_DATA_BASE_HPP
