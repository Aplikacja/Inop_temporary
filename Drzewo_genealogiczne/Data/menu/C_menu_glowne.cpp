//**********************************************************************************************************************************************************//
//	Plik: C_menu_glowne.cpp																									Data_utworzenia: 13-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_menu_glowne.hpp"
void f_sterowanie(int& x, int& i_klucz, std::vector<int>& v_k);
C_Menu_glowne::C_Menu_glowne(std::vector<std::string> V, bool b, std::vector<int> v_k) :C_Menu_base(V, b, v_k) {}
void C_Menu_glowne::m_view(int& i) {
	int i_x=0;
	int i_klucz=-10;
	int ptr;
	system("cls");
	HANDLE h;
	COORD pos = { 0,0 };
	DWORD Written;
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int y = 0; y < 10; y++) {
		ptr = 0;
		for (auto& x : V) {
			if (ptr == i_x) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				printf(x.c_str()); printf("\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				ptr++;
				continue;
			}
			printf(x.c_str()); printf("\n");
			ptr++;

		}
		FillConsoleOutputCharacter(h, ' ', 0 * 0, pos, &Written);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		m_ruch(f_sterowanie, i_x, i_klucz, V_klucz); //dlaczego nie dziala
		if (i_klucz > -1&&i_klucz<10) {
			i = i_klucz; return;
		}
		else {
			switch (i_klucz) {
			case 10:
				system("cls"); //tylko na testy
				std::cout << "wczytywanie\n";
			}
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