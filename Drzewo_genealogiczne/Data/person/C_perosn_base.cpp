//**********************************************************************************************************************************************************//
//	Plik: C_person_base.hpp																									Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: 26.03.2018 |	Autor: Damian Gwozdz	|					Opis: Dodanie funkcji sortujacych po imieniu i nazwisku						//
//**********************************************************************************************************************************************************//
#include "C_person_base.hpp"

C_person_base::C_person_base() {}
C_person_base::~C_person_base() {}

// Funkcja porownujaca dwa stringi nieczula na wielkosc liter - Imiona
bool NoCaseNameComparison(C_person_base& left, C_person_base& right)
{
	std::string leftName = left.GetFirstName();
	std::string rightName = right.GetFirstName();

	unsigned int i = 0;
	while ((i < leftName.length()) && (i < rightName.length()))
	{
		if (tolower(leftName[i]) < tolower(rightName[i])) return true;
		else if (tolower(leftName[i]) > tolower(rightName[i])) return false;
		++i;
	}
	return (leftName.length() < rightName.length());
}

// Funkcja porownujaca dwa stringi nieczula na wielkosc liter - Nazwiska
bool NoCaseLastNameComparison(C_person_base& left, C_person_base& right)
{
	std::string leftLastName = left.GetLastName();
	std::string rightLastName = right.GetLastName();

	unsigned int i = 0;
	while ((i < leftLastName.length()) && (i < rightLastName.length()))
	{
		if (tolower(leftLastName[i]) < tolower(rightLastName[i])) return true;
		else if (tolower(leftLastName[i]) > tolower(rightLastName[i])) return false;
		++i;
	}
	return (leftLastName.length() < rightLastName.length());
}

void C_person_base::SortByName(std::list<C_person_base> list)
{
	list.sort(NoCaseNameComparison);
}

void C_person_base::SortBySurname(std::list<C_person_base> list)
{
	list.sort(NoCaseLastNameComparison);
}
