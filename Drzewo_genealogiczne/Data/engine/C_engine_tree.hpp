//**********************************************************************************************************************************************************//
//	Plik: C_engine_tree.hpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	12-04-2018		Lukasz Witek vel Witkowski			Dodanie metody:																						//
//																	-	m_elimination_person																//
//																	-	m_giving																			//
//**********************************************************************************************************************************************************//
#ifndef C_ENGINE_TREE_HPP
#define C_ENGINE_TREE_HPP
#include "C_engine_software.hpp"
class C_engine_tree: public C_engine_software {
	void m_giving(std::list<C_person_base*>& L_person);
public:
	C_engine_tree(); //konstruktor
	C_engine_tree& operator=(C_engine_software& E_soft);
	void m_elimination_person(std::vector<int>& V_person);
	//void m_give(C_engine_software& e_soft);
	~C_engine_tree(); //destruktor
};
#endif // !C_ENGINE_TREE_HPP