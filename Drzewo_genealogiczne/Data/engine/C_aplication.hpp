//**********************************************************************************************************************************************************//
//	Plik: C_aplication.hpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//																						//
//	14-03-2018			Piotr Kulik			Rozwiniêcie metody m_load_files która odczytuje  z pliku dane dotycz¹ce menu i przekazuje je do obiektu menu	//
//  15-03-2018				£ukasz			Dodanie petli nieskonczonej while(true) do metody m_view(). Utworzenie petli switch w celu umieszczenia w niej	//
//											mozliwosci wywolania metod klasy C_silnik_software. Klasa C_aplication przeladowuje klase C_menu				//
//  20-03-2018			Piotr Kulik			Dokoñczenie metody m_load_file która odczytuje  z pliku dane dotycz¹ce menu i przekazuje je do obiektu menu		//
//	25-03-2018	Lukasz Witek vel Witkowski	Dodanie case w metodzie m_view:																					//
//														-> Menu_Glowne																						//
//														-> Menu_pewnosci																					//
//														-> Load_file																						//
//														-> Save_file																						//
//														-> Exit																								//
//	01-04-2018	Lukasz Witek vel Witkowski	Dodanie case w metodzie m_view:																					//
//														-> Search_tree																						//
//														-> New_tree																							//
//														-> M_zarzadzanie_tree																				//
//														-> Delete_person																					//
//	10-04-2018	Lukasz Witek vel Witkowski	Dodanie case w metodzie m_view:																					//
//														-> Load_content_tree																				//
//														-> Search_person																					//
//  15-04-2018	Lukasz Witek vel Witkowski	Dodanie case w metodzie m_view:																					//
//														-> Edition_tree																						//
//														-> Rename_tree																						//
//														-> Add_person																						//
//  24-04-2018	Lukasz Witek vel Witkowski	Dodanie case w metodzie m_view:																					//
//														-> Update_person																					//
//														-> M_zarzadzanie_personem																			//
//														-> M_menu_edycji_persona																			//
//														-> Delete_person																					//
//  25-04-2018			Damian Gwozdz		Zabezpieczania w metodzie m_load_file																			//
//  01-05-2018	Lukasz Witek vel Witkowski	Dodanie case Choice_person w metoidzie m_view																	//
//	10-05-2018	Lukasz Witek vel Witkowski	Refraktoryzacja i naprawa bledow																				//
//	25-05-2018	Lukasz Witek vel Witkowski	Poczatek case Add_relation w metodzie m_view																	//
//	08-06-2018	Lukasz Witek vel Witkowski	Wstepne dodanie case r_partner i r_sibling case Add_relation w metodzie m_view									//
//	21-06-2018	Lukasz Witek vel Witkowski	Wstepne dodanie case r_partner i r_children case Add_relation w metodzie m_view									//
//	26-06-2018	Lukasz Witek vel Witkowski	Naprawa bledow																									//
//	02-07-2018	Lukasz Witek vel Witkowski	Naprawa bledow																									//
//	15-07-2018	Lukasz Witek vel Witkowski	Naprawa bledow																									//
//	29-07-2018	Lukasz Witek vel Witkowski	Naprawa bledow																									//
//	10-08-2018	Lukasz Witek vel Witkowski	Naprawa bledow																									//
//	20-08-2018	Lukasz Witek vel Witkowski	Rozbudowa caseow w case Add_relation w metodzie m_view															//
//	31-08-2018	Lukasz Witek vel Witkowski	Naprawa bledow																									//
//	05-09-2018	Lukasz Witek vel Witkowski	Dodanie metody m_config i przebudowa konstruktora klasy															//
//**********************************************************************************************************************************************************//
#ifndef C_APLICATION_HPP
#define C_APLICATION_HPP
#include "../menu/C_menu.hpp"
#include "C_engine_software.hpp"
#include "define.hpp"
#include <fstream>
#include <cstdio>
#include <map>
class C_aplication {
	C_menu M_;
	C_engine_software e_soft_;
	std::map<std::string, int> M_init;
	std::vector<std::vector<std::vector<std::string>>> V_str_; //vector vectorow stringow pomocniczy
	int i_size_;
public:
	C_aplication(std::string what, bool& b_mistacke); //konstruktor
	void m_load_file(std::string s_file, bool& b_mistacke); //metoda wczytujaca dane
	void m_view(); //metoda do wyswietlania
	void m_configuration(bool& b_mistacke); //do pliku inicjalizacyjnego
	~C_aplication(); //destruktor
};
#endif // !C_APLICATION_HPP