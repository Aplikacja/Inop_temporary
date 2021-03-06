//**********************************************************************************************************************************************************//
//	Plik: C_menu_base.hpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	13-03-2018		Lukasz Witek vel Witkowski			Dodanie metody m_view()																				//
//	15-03-2018		Lukasz Witek vel Witkowski			Dodanie metody m_view(), o dodatkowy argument int& i_klucz											//
//	18-03-2018		Lukasz Witek vel Witkowski			Dodanie metod:																						//										//
//																	- m_load																				//
//																	- m_ruch umozliwiajacy ruch w menu														//
//														Dodanie funkcji:																					//
//																	- f_sterowanie																			//
//																	- f_option_clear																		//
//																	- f_clear																				//
//	22-03-2018		Lukasz Witek vel Witkowski			Dodanie metod:																						//
//																	- m_view() umożliwiajace wybieranie Persona												//
//																	- m_ruch umozliwiajacy wybranie Persona													//
//																	- m_get_content																			//
//																	- m_set_content																			//
//																	- m_set_str																				//
//																	- m_get_str																				//
//																	- m_set_replay																			//
//																	- m_get_replay																			//
//	28-03-2018		Lukasz Witek vel Witkowski			Dodanie metod:																						//
//																	- m_view() umożliwiajace edycje Persona	i nazwy drzewa									//
//																	- m_ruch umozliwiajacy edycje Persona i drzewo											//
//																	- m_get_data																			//
//																	- m_add_perosons																		//
//	15-04-2018		Lukasz Witek vel Witkowski			Dodanie metod:																						//
//																	- m_view pobierajacego stringa															//
//																	- m_view pobierajacego vector id														//
//	15-04-2018		Lukasz Witek vel Witkowski			Naprava metod																						//
//**********************************************************************************************************************************************************//
#ifndef C_MENU_BASE_HPP
#define C_MENU_BASE_HPP
#include <vector>
#include <string>
#include <list>
#include "../person/C_fabric_person.hpp"
#include "../engine/C_engine_tree.hpp"
#include <windows.h>
class C_menu_base {
protected:
	std::vector<std::vector<std::vector<std::string>>> V_str_;
	std::vector<std::list<C_person_base*>> V_L_person_; //lista personow
	std::vector<std::vector<int>> V_klucz_; //listaklucyz
	std::vector<std::vector<int>> V_procedur_;
	std::vector<int> V_replay_;
	int i_start_;
	bool b_dinamic_;
	short is_color;
	C_engine_tree E_soft;
public:
	C_menu_base( std::vector<std::vector<std::string>>& v, bool b_value,  std::vector<std::vector<int>>& v_k, std::vector<std::vector<int>>& V_procedur, int& i_iterator, std::vector<std::list<C_person_base*>>& L_person); //konstruktor parametrowy
	virtual bool m_view(int i_id_menu,int& i_variable,int& i_klucz, std::vector<int>& V_proces, int& i_choice) = 0; //metoda powodujaca ze klasa C_menu_base jest klasa abstrakcyjna
	virtual bool m_view(int i_id_menu,int& i_variable,std::string& s_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) = 0; //metoda powodujaca ze klasa C_menu_base jest klasa abstrakcyjna
	virtual bool m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice) = 0; //metoda powodujaca ze klasa C_menu_base jest klasa abstrakcyjna
	virtual bool m_view(int i_id_menu, int& i_variable, std::vector<std::string>& V_result, int& i_klucz, std::vector<int>& V_proces, int& i_choice, int& b_replay) = 0;
	virtual bool m_view(int i_id_menu, int& i, int& i_klucz, std::vector<long long>& V_proces, int& i_choice, std::vector<std::vector<C_id>>& V_id) = 0;
	void m_load( std::vector<std::vector<std::vector<std::string>>> v); //metoda lafujaca danych
	void m_ruch(void(*f)(int& x, std::string& i_klucz, int& i_start, std::vector<std::string>& v_k), int& i_klawisz, std::string& i_klucz, int& i_start, std::vector<std::string>& v_k);
	void m_ruch(void(*f)(int& x, std::string& i_klucz, int& i_start, std::vector<std::string>& v_k, bool& b_search, int i_position), int& i_klawisz, std::string& i_klucz, int& i_start, std::vector<std::string>& v_k, bool& b_search, int i_position);
	void m_ruch(void(*f)(int& x, int& i_klucz, int& i_start, std::vector<int>& v_k), int& i_klawisz, int& i_klucz, int& i_start, std::vector<int>& v_k); //metoda umozliwiajaca ruch w menu
	void m_ruch(void(*f)(int& x, int& i_y, int& i_klucz, int& i_start, std::vector<int>& v_k, std::vector<int>& v_size, std::vector<std::vector<C_id>>& V_id), int& i_klawisz, int& i_y, int& i_klucz, int& i_start, std::vector<int>& v_k, std::vector<int>& V_size, std::vector<std::vector<C_id>>& V_id);
	void m_ruch(void(*f)(int& x, int& i_klucz, int& i_start, std::vector<int>& v_k, bool& b_search, int i_position), int& i_klawisz, int& i_klucz, int& i_start, std::vector<int>& v_k, bool& b_search, int i_position); //metoda umozliwiajaca ruch w menu
	void m_ruch(void(*f)(int& x, std::string& i_klucz, std::string& s_message, int& i_start, std::vector<std::string>& v_k, int i_size, int i_start_), int& i_klawisz, std::string& i_klucz, std::string& s_message, int& i_start, std::vector<std::string>& v_k, int i_size, int i_start_);
	void m_get_content( std::vector<std::vector<std::vector<std::string>>>& V_CONTENT); //metoda do wyciagania vektor typu string
	void m_set_content( std::vector<std::vector<std::vector<std::string>>>& V_CONTENT); //metoda do dodawania vektor typu string
	void m_set_str(int i_choice, std::vector<std::string>& v_str);
	void m_get_str(int i_choice, std::vector<std::string>& v_str);
	void m_set_replay(int i_choice,int i_replay);
	void m_get_replay(int i_choice,int& i_replay);
	void m_get_data(C_engine_software& e_soft);
	void m_add_perosons(std::vector<std::list<C_person_base*>>& L_person);
	void m_elimination(std::vector<int>& L_person);
	void m_configuration(int i);
	virtual ~C_menu_base(); //destruktor
};
void f_sterowanie(int& x, int& i_klucz,int& i_start, std::vector<int>& v_k, bool& b_search, int i_position);
void f_sterowanie_tree(int& x, int& i_y, int& i_klucz, int& i_start, std::vector<int>& v_k, std::vector<int>& v_size, std::vector<std::vector<C_id>>& V_id);
void f_sterowanie(int& x, std::string& s_klucz, int& i_start, std::vector<std::string>& v_k, bool& b_search, int i_position);
void f_option_clear(HANDLE& h, COORD& pos, DWORD& Written);
void f_clear(HANDLE& h, COORD& pos, DWORD& Written);
static char C_massage[2];
//zmienne do lepszego obslugiwania konsoli
static HANDLE h;
static COORD pos = { 0,0 };
static DWORD Written;
static 	HWND Active = GetForegroundWindow();
static 	HWND Stan;
static HANDLE HandleConsol;
#endif // !C_MENU_BASE_HPP