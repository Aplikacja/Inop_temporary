//**********************************************************************************************************************************************************//
//	Plik: C_engine_software.hpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-03-2018				Lukasz			Dodanie metody:																									//
//											- void m_add_person() <- do dodawania nowych osob do drzewa														//
//											- void m_delete_person() <- do usuwania osob z drzewa															//
//											- void m_update_person() <- do edycji danych osob z drzewa														//
//**********************************************************************************************************************************************************//
#ifndef C_ENGINE_SOFTWARE_HPP
#define C_ENGINE_SOFTWARE_HPP
#include "C_engine_hardware.hpp"
class C_engine_software :public C_engine_hardware {
public:
	C_engine_software();
	void m_add_person(); //meoda do przebudowania
	void m_delete_person(); //metoda do przebudowania
	void m_update_person(); //metoda do przebudowy
	~C_engine_software();
};
#endif // !C_ENGINE_SOFTWARE_HPP