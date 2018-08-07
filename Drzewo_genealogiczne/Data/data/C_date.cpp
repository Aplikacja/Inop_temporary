//**********************************************************************************************************************************************************//
//	Plik: C_date.cpp																										Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//		21-03-2018			Marcin				Dodanie i rozwiniecie metod:																				//
//												-	void C_date::m_apped(int& i_day, int& i_month, int& i_year);											//
//												-	void C_date::m_sidle(int& i_day, int& i_month, int& i_year);											//
//												-	void C_date::m_apped(std::string& s_date);																//
//												-	void C_date::m_sidle(std::string& s_date);																//
//**********************************************************************************************************************************************************//
#include "C_date.hpp"

C_date::C_date() :C_data_base() {};
void C_date::m_virtual() { //tymczasowo
	std::string str;
	m_sidle(str);
	printf(str.c_str());
}
void C_date::m_apped(int& i_day, int& i_month, int& i_year) {
	ll_value_ = i_day;
	ll_value_ += i_month * 100;
	ll_value_ += i_year * 10000;
}
void C_date::m_sidle(int& i_day, int& i_month, int& i_year) {
	i_day = ll_value_ % 100;
	i_month = (ll_value_ % 10000)/ 100;
	i_year = (ll_value_ % 100000000)/ 10000;
}
void C_date::m_apped(std::string& s_date) {
	ll_value_ = 0;
	int i_iterator;
	int i_cykl = 0;
	for (i_iterator = (int)s_date.size() - 1; i_iterator >= 0; i_iterator--) {
		if (s_date[i_iterator] == '-') {
			continue;
		}
		ll_value_ += ((int)(s_date[i_iterator]) - (int)'0')*(int)pow(10,i_cykl);
		i_cykl++;
	}
}
void C_date::m_sidle(std::string& s_date) {
	s_date.clear();
	long long i_variable = ll_value_;
	int i_cykl;
	int i_cykl_1 = 7;
	for (i_cykl = 8; i_cykl > 0; i_cykl--) {
		s_date += (char)(int)((i_variable % (int)pow(10, i_cykl)) / pow(10, i_cykl_1)) % 10 + (int)'0';
		switch (i_cykl) {
		case 5:
		case 3:
			s_date += '-';
		}
		if (i_cykl_1 >= 1)
			i_cykl_1--;
	}
}
int C_date::m_old() {
	int data = (ll_value_ % 100000000) / 10000; return data;
}
C_date::C_date(long long data) {
	ll_value_ = data;
}
C_date C_date::operator+(const int& i) {
	return C_date (this->ll_value_ + i* 10000); //return data;
}
C_date C_date::operator+(C_date& i)  {
	return C_date (this->ll_value_ + i.m_old()* 10000);
}
C_date C_date::operator-(const int& i) {
	return C_date (this->ll_value_ - i*10000);
}
C_date C_date::operator-(C_date& i) {
	return C_date (this->ll_value_ - i.m_old()* 10000);
}
bool C_date::operator<(const int& i) {
	return m_old() < i;
}
bool C_date::operator>(const int& i) {
	return m_old() > i;
}
bool C_date::operator<(const C_date& D) {
	if (b_pointer_ && D.b_pointer_)
		return ll_value_ < D.ll_value_;
		return false;
}
bool C_date::operator>(const C_date& D) {
	if (b_pointer_ && D.b_pointer_)
		return ll_value_ > D.ll_value_;
	return false;
}
C_date::~C_date() {}