//**********************************************************************************************************************************************************//
//	Plik: C_engine_hardware.hpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-03-2018				Lukasz			Dodanie metody:																									//
//											- void m_load_files() <- do wczytywania drzewa z pliku															//
//											- void m_save_files() <- do zapisywania drzewa do pliku															//
//**********************************************************************************************************************************************************//
#ifndef C_ENGINE_HARDWARE_HPP
#define C_ENGINE_HARDWARE_HPP
#include "define.hpp"
#include "../person/C_person_base.hpp"
#include "C_db.hpp"
#include "C_tree.hpp"
class C_engine_hardware {
protected:
	C_db d_Database; //baza danych
	C_tree t_tree; //drzewo - to cos bedzie realizowac algorytm poruszania sie po drzewie
public:
	C_engine_hardware(); //konstruktor
	void m_load_files(); //metoda do przebudowy
	void m_save_files();	//metoda do przebudowy
	void m_sort(bool(*F)(C_person_base* _left, C_person_base* _right)); //metoda do sortowania bazy danych
	~C_engine_hardware(); //destruktor
};
#endif // !C_ENGINE_HARDWARE_HPP