//**********************************************************************************************************************************************************//
//	Plik: C_engine_hardware.cpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-03-2018				Lukasz			Dodanie metody:																									//
//											- void m_load_files() <- do wczytywania drzewa z pliku															//
//											- void m_save_files() <- do zapisywania drzewa do pliku															//
//**********************************************************************************************************************************************************//
#include "C_engine_hardware.hpp"

C_engine_hardware::C_engine_hardware() {}
void C_engine_hardware::m_load_files() {
	std::ifstream file;
	file.open(file_load);
	if (file.good()) {
		d_Database.m_load(file);
		file.close();
	}
} //metoda do przebudowy
void C_engine_hardware::m_save_files() {
	int i_size;
	d_Database.m_size(i_size);
	//d_Database.m_sort(f_sort_last_name); //test na sortowanie po imieniach! (Test zakonczony sukcesem!)
	//d_Database.m_sort(f_sort_last_name); //test na sortowanie po nazwiskach! (Test zakonczony sukcesem!)
	//d_Database.m_sort(f_sort_id); //test na sortowanie po id! (Test zakonczony sukcesem!)
	//d_Database.m_sort(f_sort_date_brith); //test na sortowanie po dacie urodzenia! (Test zakonczony sukcesem!)
	//d_Database.m_sort(f_sort_date_death); //test na sortowanie po dacie smierci! (Test zakonczony sukcesem!)
	std::ofstream file;
	file.open(file_save);
	if (file.good()) {
		file << i_size;
		std::list<C_person_base*> LISTA;
		d_Database.m_get(LISTA);
		for (auto& x : LISTA) {
			file << *x;
		}
		file.close();
	}
}	//metoda do przebudowy
void C_engine_hardware::m_sort(bool(*F)(C_person_base* _left, C_person_base* _right)) {
	d_Database.m_sort(F);
}
C_engine_hardware::~C_engine_hardware() {}