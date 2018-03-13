//**********************************************************************************************************************************************************//
//	Plik: C_menu_base.hpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_MENU_BASE_HPP
#define C_MENU_BASE_HPP
#include <vector>
#include <string>
class C_Menu_base {
protected:
	std::vector<std::string> V;
	std::vector<int> V_klucz;
	bool b_dinamic;
public:
	C_Menu_base(std::vector<std::string> v, bool b_value, std::vector<int> v_k);
	virtual void m_view() = 0;
	void m_load(std::vector<std::string> v);
	void m_ruch(void(*f)(int& x, int& i_klucz, std::vector<int>& v_k), int& i_klawisz, int& i_klucz, std::vector<int>& v_k);
	virtual ~C_Menu_base();
};
#endif // !C_MENU_BASE_HPP