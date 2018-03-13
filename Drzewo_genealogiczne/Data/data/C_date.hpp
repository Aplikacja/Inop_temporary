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
	C_date();
	C_date(const C_date& date);
	void m_virtual();
	std::string m_return_date();
		~C_date();
};
#endif // !C_DATE_HPP



