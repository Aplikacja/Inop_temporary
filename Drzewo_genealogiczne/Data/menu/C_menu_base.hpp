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
	std::vector<std::string> V_content;
	std::vector<int> V_klucz;
	bool b_dinamic;
public:
	C_Menu_base(std::vector<std::string> v, bool b_value, std::vector<int> v_k); //konstruktor parametrowy
	C_Menu_base(std::vector<std::string> v,std::vector<std::string> V_content, bool b_value, std::vector<int> v_k); //konstruktor parametrowy
	virtual void m_view(int& i_variable,int& i_klucz, int i_choice) = 0; //metoda powodujaca ze klasa C_menu_base jest klasa abstrakcyjna
	void m_load(std::vector<std::string> v); //metoda lafujaca danych
	void m_ruch(void(*f)(int& x, int& i_klucz, std::vector<int>& v_k), int& i_klawisz, int& i_klucz, std::vector<int>& v_k); //metoda umozliwiajaca ruch w menu
	void m_get_content(std::vector<std::string>& V_CONTENT); //metoda do wyciagania vektor typu string
	void m_set_content(std::vector<std::string>& V_CONTENT); //metoda do dodawania vektor typu string
	virtual ~C_Menu_base(); //destruktor
};
#endif // !C_MENU_BASE_HPP