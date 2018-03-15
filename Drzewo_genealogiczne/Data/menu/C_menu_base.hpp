//**********************************************************************************************************************************************************//
//	Plik: C_menu_base.hpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-03-2018				Lukasz			Rozbudowa metody wirtualnej m_view(), o dodatkowy argument int& i_klucz											//
//**********************************************************************************************************************************************************//
#ifndef C_MENU_BASE_HPP
#define C_MENU_BASE_HPP
#include <vector>
#include <string>
#include <Windows.h>
class C_Menu_base {
protected:
	std::vector<std::string> V;
	std::vector<int> V_klucz;
	bool b_dinamic;
public:
	C_Menu_base(std::vector<std::string> v, bool b_value, std::vector<int> v_k);
	virtual void m_view(int& i_variable,int& i_klucz) = 0;
	void m_load(std::vector<std::string> v);
	void m_ruch(void(*f)(int& x, int& i_klucz, std::vector<int>& v_k), int& i_klawisz, int& i_klucz, std::vector<int>& v_k);
	virtual ~C_Menu_base();
};
#endif // !C_MENU_BASE_HPP