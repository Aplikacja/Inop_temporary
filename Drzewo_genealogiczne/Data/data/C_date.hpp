//**********************************************************************************************************************************************************//
//	Plik: C_date.hpp																										Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_DATE_HPP
#define C_DATE_HPP
#include "C_data_base.hpp"
#include <string>
class C_date :public C_data_base {
public:
	C_date(); //konstruktor
	//C_date(const C_date& date);
	void m_apped(std::string& s_date); //metoda prezkonwertujaca wartosc zawarta w stringu zmiennej long long ll_value
	void m_apped(int& i_day, int& i_month, int& i_year); //metoda przekonwertujaca wartosci z trezch intow do zmiennej long long ll_value
	void m_sidle(int& i_day, int& i_month, int& i_year); //metoda przekonwertujaca wartosc ze zmiennej long long ll_value na trzy inty
	void m_sidle(std::string& s_date); //metoda przekonwertujaca wartosc ze zmiennej long long ll_value na stringa
	void m_virtual(); //metoda odpowiadajaca za wyswietlanie danych za pomoca printf()
	~C_date(); //destruktor
};
#endif // !C_DATE_HPP



