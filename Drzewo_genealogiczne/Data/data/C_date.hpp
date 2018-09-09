//**********************************************************************************************************************************************************//
//	Plik: C_date.hpp																										Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	22-03-2018			Marcin Jezionek				Dodanie i rozwiniecie metod:																			//
//												-	void C_date::m_apped(int& i_day, int& i_month, int& i_year);											//
//												-	void C_date::m_sidle(int& i_day, int& i_month, int& i_year);											//
//												-	void C_date::m_apped(std::string& s_date);																//
//												-	void C_date::m_sidle(std::string& s_date);																//
//	02-04-2018 Lukasz Witek vel Witkowski	Dodanie i rozbudowanie metody m_old																				//
//	26-04-2018 Lukasz Witek vel Witkowski	Dodanie operatorow:																								//
//												-> operator +																								//
//												-> operator -																								//
//												-> operator <																								//
//												-> operator >																								//
//**********************************************************************************************************************************************************//
#ifndef C_DATE_HPP
#define C_DATE_HPP
#include "C_data_base.hpp"
#include <xtgmath.h> //w code bloksie jest tgmath.h
#include <string>
class C_date :public C_data_base {
public:
	C_date(); //konstruktor
	C_date(long long data);
	//C_date(const C_date& date);
	void m_apped(std::string& s_date); //metoda przekonwertujaca wartosc zawarta w stringu na zmiennej long long ll_value
	void m_apped(int& i_day, int& i_month, int& i_year); //metoda przekonwertujaca wartosci z trezch intow do zmiennej long long ll_value
	void m_sidle(int& i_day, int& i_month, int& i_year); //metoda przekonwertujaca wartosc ze zmiennej long long ll_value na trzy inty
	void m_sidle(std::string& s_date); //metoda przekonwertujaca wartosc ze zmiennej long long ll_value na stringa
	void m_virtual(); //metoda odpowiadajaca za wyswietlanie danych za pomoca printf()
	int m_old();
	//C_date operator+(const int& i);
	//C_date operator+(C_date& i);
	int operator+(const int& i);
	int operator+(C_date& i);
	int operator-(const int& i);
	int operator-(C_date& i);
	bool operator<(const int& i);
	bool operator>(const int& i);
	bool operator<(const C_date& D);
	bool operator>(const C_date& D);
	bool operator==(const C_date& D);
	//C_date operator-(const int& i);
	//C_date operator-(C_date& i);
	~C_date(); //destruktor
};
#endif // !C_DATE_HPP



