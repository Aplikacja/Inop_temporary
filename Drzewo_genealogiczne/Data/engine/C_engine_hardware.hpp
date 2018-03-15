//**********************************************************************************************************************************************************//
//	Plik: C_engine_hardware.hpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-03-2018				Lukasz			Dodanie metody:																									//
//											- void m_load_files() <- do wczytywania drzewa z pliku															//
//											- void m_save_files() <- do zapisywania drzewa do pliku															//
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
	void m_load_files(); //metoda do przebudowy
	void m_save_files();	//metoda do przebudowy
	~C_engine_hardware();
};
#endif // !C_ENGINE_HARDWARE_HPP