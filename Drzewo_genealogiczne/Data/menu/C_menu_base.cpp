//**********************************************************************************************************************************************************//
//	Plik: C_menu_base.cpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_menu_base.hpp"

C_Menu_base::C_Menu_base(std::vector<std::string> v, bool b_value, std::vector<int> v_k) {
	V = v;
	b_dinamic = b_value;
	V_klucz = v_k;
};
void C_Menu_base::m_load(std::vector<std::string> v) {
	if (b_dinamic)
	{
		V = v;
	}
}
void C_Menu_base::m_ruch(void(*f)(int& x, int& i_klucz, std::vector<int>& v_k), int& i_klawisz, int& i_klucz, std::vector<int>& v_k) {

	f(i_klawisz, i_klucz, v_k);
}
C_Menu_base::~C_Menu_base() {};