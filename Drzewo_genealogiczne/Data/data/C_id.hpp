//**********************************************************************************************************************************************************//
//	Plik: C_id.hpp																											Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	23-03-2018 Lukasz Witek vel Witkowski	Dodanie i rozbudowa metod:																						//
//														-> m_giving																							//
//														-> m_virtual																						//
//														-> m_down																							//
//	10-04-2018 Lukasz Witek vel Witkowski	Dodanie i rozbudowa operatorow:																					//
//														-> operator ==																						//
//														-> operator !=																						//
//**********************************************************************************************************************************************************//

#ifndef C_ID_HPP
#define C_ID_HPP
#include "C_data_base.hpp"
class C_id :public C_data_base {
public:
	C_id(); //konstruktor
	C_id(long long ll_var); //konstruktor parametrowy wstawia wartosc z long long ll_var do long long ll_value
	void m_giving(long long& ll_iterator); //metoda przepisujaca wartosc z long long ll_iterator do long long ll_value
	void m_virtual(); //klasa do rozbudowy
	void m_down();
	bool operator==(const C_id& id);
	bool operator!=(const C_id& id);
	~C_id(); //destruktor
};
#endif // !C_ID_HPP
