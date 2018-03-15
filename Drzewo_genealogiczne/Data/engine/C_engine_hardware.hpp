//**********************************************************************************************************************************************************//
//	Plik: C_engine_hardware.hpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_ENGINE_HARDWARE_HPP
#define C_ENGINE_HARDWARE_HPP
#include "C_db.hpp"
#include "C_tree.hpp"
class C_engine_hardware {
	C_db d_Database;
	C_tree t_tree;
public:
	C_engine_hardware();
	~C_engine_hardware();
};
#endif // !C_ENGINE_HARDWARE_HPP