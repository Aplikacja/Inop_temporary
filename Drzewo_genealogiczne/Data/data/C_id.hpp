//**********************************************************************************************************************************************************//
//	Plik: C_id.hpp																											Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//

#ifndef C_ID_HPP
#define C_ID_HPP
#include "C_data_base.hpp"
class C_id :public C_data_base {
public:
	C_id();
	C_id(long long ll_var);
	void m_active();
	void m_virtual(); //klasa do rozbudowy
	~C_id();
};
#endif // !C_ID_HPP
