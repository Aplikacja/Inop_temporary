//**********************************************************************************************************************************************************//
//	Plik: C_aplication.hpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_APLICATION_HPP
#define C_APLICATION_HPP
#include "../menu/C_menu.hpp"
#include "C_engine_software.hpp"
#include <fstream>
class C_aplication {
	C_menu M;
	C_engine_software e_soft;
	int i_size;
public:
	C_aplication(std::string what);
	void m_load_file(std::string s_file);
	void m_view();
	~C_aplication();
};
#endif // !C_APLICATION_HPP