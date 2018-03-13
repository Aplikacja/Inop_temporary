//**********************************************************************************************************************************************************//
//	Plik: C_relation.hpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_RELATION_HPP
#define C_RELATION_HPP
#include "C_relation_base.hpp"
class C_relation :public C_relation_base {
public:
	C_relation();
	C_relation(C_id& id);
	void m_wiew();
	~C_relation();
};
#endif // !C_RELATION_HPP