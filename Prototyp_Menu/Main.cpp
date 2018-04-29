#include <iostream>
#include "../Drzewo_genealogiczne/Data/engine/define.hpp"
#include <windows.h>
#include <string>
void f_obsluga_zadrzen_alfabetycznych(int& i_message);
void f_sterowanie(std::string& s_message);
inline void f(int i_klawisz, int i_value, unsigned int& i_return);
int main() {
	std::string data;
	int i = 0;
	char c_message;
	while (true) {
		i++;
		f_sterowanie(data);
		system("cls");
		std::cout << data;
	}

	return 0;
}
void f_obsluga_zadrzen_alfabetycznych(int& i_message) {
	unsigned int i_result;
	int i_tab_value[35] = { vkdown,vkup,vkreturn,vkescape,vklshift,vkrshift,vkcapslook,vkdelete,vkspace,vka,
		vkb,vkc,vkd,vke,vkf,vkg,vkh,vki,vkj,vkk,vkl,vkm,vkn,vko,vkp,vkq,vkr,vks,vkt,vku,
		vkv,vkw,vkx,vky,vkz };
	int i_tab_key[35] = { VK_DOWN,VK_UP,VK_RETURN,VK_ESCAPE,VK_LSHIFT,VK_RSHIFT,VK_CAPITAL,VK_BACK,VK_SPACE,
		0x041, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x04B, 0x4C, 0x4D,
		0x4E, 0x4F, 0x50, 0x51,	0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A };
	int i;
	do {
		i_result = 0;
		for (i = 0; i<35; i++)
			f(i_tab_key[i], i_tab_value[i], i_result);
	} while (i_result == 0);
	i_message = i_result;
}
inline void f(int i_klawisz, int i_value, unsigned int& i_return) {
	i_return += ((bool)GetAsyncKeyState(i_klawisz)) * i_value;
}
void f_sterowanie(std::string& s_message) {
	int i_message;
	while (true)
	{
		Sleep(150);
		f_obsluga_zadrzen_alfabetycznych(i_message);
		switch (i_message) {
		case vkup:
			s_message = "< w gore >";
			return;
		case vkdown:
			s_message = "< w dol >";
			return;
		case vkreturn:
			s_message = "< enter >";
			return;
		case vkescape: return; //miejsce na zaimplementowanie powrotu
		case vkdelete:
			s_message.pop_back();	return;
		case vkspace:
			s_message += ' ';	return;
		case vka:
		case vka1:
		case vka2:
			s_message += 'a';	return;
		case vkb:
		case vkb1:
		case vkb2:
			s_message += 'b';	return;
		case vkc:
		case vkc1:
		case vkc2:
			s_message += 'c';	return;
		case vkd:
		case vkd1:
		case vkd2:
			s_message += 'd';	return;
		case vke:
		case vke1:
		case vke2:
			s_message += 'e';	return;
		case vkf:
		case vkf1:
		case vkf2:
			s_message += 'f';	return;
		case vkg:
		case vkg1:
		case vkg2:
			s_message += 'g';	return;
		case vkh:
		case vkh1:
		case vkh2:
			s_message += 'h';	return;
		case vki:
		case vki1:
		case vki2:
			s_message += 'i';	return;
		case vkj:
		case vkj1:
		case vkj2:
			s_message += 'j';	return;
		case vkk:
		case vkk1:
		case vkk2:
			s_message += 'k';	return;
		case vkl:
		case vkl1:
		case vkl2:
			s_message += 'l';	return;
		case vkm:
		case vkm1:
		case vkm2:
			s_message += 'm';	return;
		case vkn:
		case vkn1:
		case vkn2:
			s_message += 'n';	return;
		case vko:
		case vko1:
		case vko2:
			s_message += 'o';	return;
		case vkp:
		case vkp1:
		case vkp2:
			s_message += 'p';	return;
		case vkq:
		case vkq1:
		case vkq2:
			s_message += 'q';	return;
		case vkr:
		case vkr1:
		case vkr2:
			s_message += 'r';	return;
		case vks:
		case vks1:
		case vks2:
			s_message += 's';	return;
		case vkt:
		case vkt1:
		case vkt2:
			s_message += 't';	return;
		case vku:
		case vku1:
		case vku2:
			s_message += 'u';	return;
		case vkw:
		case vkw1:
		case vkw2:
			s_message += 'w';	return;
		case vkv:
		case vkv1:
		case vkv2:
			s_message += 'v';	return;
		case vkx:
		case vkx1:
		case vkx2:
			s_message += 'x';	return;
		case vky:
		case vky1:
		case vky2:
			s_message += 'y';	return;
		case vkz:
		case vkz1:
		case vkz2:
			s_message += 'z';	return;
		case vkA:
			s_message += 'A';	return;
		case vkB:
			s_message += 'B';	return;
		case vkC:
			s_message += 'C';	return;
		case vkD:
			s_message += 'D';	return;
		case vkE:
			s_message += 'E';	return;
		case vkF:
			s_message += 'F';	return;
		case vkG:
			s_message += 'G';	return;
		case vkH:
			s_message += 'H';	return;
		case vkI:
			s_message += 'I';	return;
		case vkJ:
			s_message += 'J';	return;
		case vkK:
			s_message += 'K';	return;
		case vkL:
			s_message += 'L';	return;
		case vkM:
			s_message += 'M';	return;
		case vkN:
			s_message += 'N';	return;
		case vkO:
			s_message += 'O';	return;
		case vkP:
			s_message += 'P';	return;
		case vkQ:
			s_message += 'Q';	return;
		case vkR:
			s_message += 'R';	return;
		case vkS:
			s_message += 'S';	return;
		case vkT:
			s_message += 'T';	return;
		case vkU:
			s_message += 'U';	return;
		case vkW:
			s_message += 'W';	return;
		case vkV:
			s_message += 'V';	return;
		case vkX:
			s_message += 'X';	return;
		case vkY:
			s_message += 'Y';	return;
		case vkZ:
			s_message += 'Z';	return;
		default:	break;
		}
	}
}