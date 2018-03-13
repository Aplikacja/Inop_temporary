//**********************************************************************************************************************************************************//
//	Plik: C_menu_glowne.cpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_menu_glowne.hpp"
void f_sterowanie(int& x, int& i_klucz, std::vector<int>& v_k);
C_Menu_glowne::C_Menu_glowne(std::vector<std::string> V, bool b, std::vector<int> v_k) :C_Menu_base(V, b, v_k) {}
void C_Menu_glowne::m_view() {
	int i_x;
	int i_klucz;
	int ptr;
	for (int y = 0; y < 3; y++) {
		m_ruch(f_sterowanie, i_x, i_klucz, V_klucz); //dlaczego nie dziala
		ptr = 0;
		for (auto& x : V_klucz) {
			if (ptr == i_x) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				std::cout << x << "\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
				continue;
			}
			std::cout << x << "\n";
			ptr++;

		}
	}
}
C_Menu_glowne::~C_Menu_glowne() {};
void f_sterowanie(int& x, int& i_klucz, std::vector<int>& v_k) {
	int i_size = v_k.size();
	Sleep(300); //fajnie bylo by to zastapic
	while (true)
	{
		if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
		{
			x--;
			if (x <= -1)      // gdy wykracza wraca na koniec
				x = i_size - 1;
			return;
		}
		else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
		{
			x++;
			if (x >= i_size)       // gdy wykracza poza menu, znow wraca na poczatek
				x = 0;
			return;
		}
		else if (GetAsyncKeyState(VK_RETURN) != 0)
		{
			i_klucz = v_k[x];
			return;
		}
	}
}