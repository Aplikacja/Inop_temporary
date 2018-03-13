//**********************************************************************************************************************************************************//
//	Plik: C_relation_base.hpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_RTELATION_BASE_HPP
#define C_RTELATION_BASE_HPP
#include <vector>
#include "../data/C_id.hpp"
#include "../data/C_date.hpp"
class C_relation_base {
protected:
	C_id * id;
	C_date* date;
	std::vector<C_relation_base*> V;
	bool b_value;
public:
	C_relation_base();
	C_relation_base(C_id data);
	C_relation_base(C_id data, C_date Date);
	C_relation_base(const C_relation_base& relation);
	C_data_base* m_return(int i_value);
	void m_active();
	void m_set_baby(C_relation_base* relation);
	virtual void m_wiew() = 0;
	~C_relation_base();
};
#endif // !C_RTELATION_BASE_HPP