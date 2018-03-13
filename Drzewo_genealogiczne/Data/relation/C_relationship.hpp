//**********************************************************************************************************************************************************//
//	Plik: C_relationship.hpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_RELATIONSHIP_HPP
#define C_RELATIONSHIP_HPP
#include "C_relation_base.hpp"
class C_relationship :public C_relation_base {
public:
	C_relationship();
	C_relationship(C_id& id);
	void m_wiew();
	~C_relationship();
};
#endif // !C_RELATIONSHIP_HPP