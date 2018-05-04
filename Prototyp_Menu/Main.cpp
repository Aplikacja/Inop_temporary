#include "../Drzewo_genealogiczne/Data/engine/C_aplication.hpp"
#include <windows.h>
#include <string.h>
int main() {

	std::cout << "Test 1: testowanie poprawnej konwersji danych z na long longa na std::stringa w klasie C_date\n";
	C_date Data;
	std::string s_result="";
	Data.m_sidle(s_result);
	std::cout <<"Data przy braku wartosci:\t"<< s_result<<"\n";
	int i_day = 21;
	int i_month = 03;
	int i_year = 2018;
	Data.m_apped(i_day, i_month, i_year);
	Data.m_sidle(s_result);
	std::cout << "Po wprowadzeniu daty 21.03.2018:\t" << s_result << "\n";
	return 0;
}