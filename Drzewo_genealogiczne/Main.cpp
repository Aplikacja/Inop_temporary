
#include "Data\engine\C_aplication.hpp"
//---------------------------------------------------------------------------------------------------------------------------------------
//Przykladowe klasy do rozdzielenia na plii

int main() {

	C_date D,T;
	D.m_active();
	T.m_active();
	int day = 12;
	int month = 10;
	int year = 0;
	std::string str;
	D.m_apped(day, month, year);
	str = "dupa";
	D.m_sidle(str);
	D.m_sidle(day, month, year);
	C_aplication A("plik.txt");
	A.m_view();
	return 0;
}
