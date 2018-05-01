//**********************************************************************************************************************************************************//
//	Plik: C_aplication.hpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_APLICATION_HPP
#define C_APLICATION_HPP
#include "../menu/C_menu.hpp"
#include "C_engine_software.hpp"
#include "define.hpp"
#include <fstream>
#include <cstdio>
class C_aplication {
	C_menu M_;
	C_engine_software e_soft_;
	std::vector<std::vector<std::vector<std::string>>> V_str; //vector vectorow stringow pomocniczy
	int i_size_;
public:
	C_aplication(std::string what); //konstruktor
	void m_load_file(std::string s_file); //metoda wczytujaca dane
	void m_view(); //metoda do wyswietlania
	~C_aplication(); //destruktor
};
#endif // !C_APLICATION_HPP