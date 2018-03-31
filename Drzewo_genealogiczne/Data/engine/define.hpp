//**********************************************************************************************************************************************************//
//	Plik: definition.hpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-03-2018				Lukasz			Dodanie satlych predefiniowalnych:																				//
//											- load_files - do odczytu z pliku																				//
//											- save_files - do zapisu do pliku																				//
//											- add_person - do dodawania nowych osob do drzewa																//
//											- delete_person - do usuwania osob z drzewa																		//
//											- update_person - do edytowania osob w drezwie																	//
//**********************************************************************************************************************************************************//
#ifndef DEFINITION_HPP
#define DEFINITION_HPP
#define load_files		10
#define save_files		11
#define add_person		12
#define delete_person	13
#define update_person	14
//nazwa pliku do zapisu
#define file_save "plik2.txt"
#define file_load "plik1.txt"
//stale typow relacji
#define r_parents 1
#define r_sibling 2
#define r_partner 3
#define r_null 4
#define r_chlidren 5
//stale odnosnie dat
#define D_brith 1
#define D_death 2
//stale odnoscie pluci
#define woman 1
#define man 0
//satle odnosnie sterowania wyswietleniem
#define view_sort 1
#define view_search 2
#define sort_first_name 3
#define sort_last_name 4
#define sort_id 0
#define sort_date_brith 5
#define sort_date_death 6
#endif // !DEFINITION_HPP
