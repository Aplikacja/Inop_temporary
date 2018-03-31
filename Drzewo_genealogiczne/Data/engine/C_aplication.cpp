//**********************************************************************************************************************************************************//
//	Plik: C_aplication.cpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
// 15-03-2018				Lukasz			Dodanie petli nieskonczonej while(true) do metody m_view(). Utworzenie petli switch w celu umieszczenia w niej	//
//											mozliwosci wywolania metod klasy C_silnik_software. Klasa C_aplication przeladowuje klase C_menu				//
//**********************************************************************************************************************************************************//
#include "C_aplication.hpp"
#include "define.hpp"

C_aplication::C_aplication(std::string what) {
	m_load_file(what);
};
void C_aplication::m_load_file(std::string s_file) {
	std::ifstream file;
	file.open(s_file.c_str());
	if (file.good())
	{
		int value, value_II, i, j, i_temp;
		std::vector<std::vector<std::string>> V_s;
		std::vector<std::vector<int>> v_klucze;
		std::vector<int> v_k;
		std::vector<bool> V_b;
		std::vector<std::string> V_temp;
		std::string s_temp;
		bool b_temp;
		file >> value;
		i_size = value;
		for (i = 0; i < value; i++)
		{
			file >> value_II;
			file >> b_temp;
			V_b.push_back(b_temp);
			V_temp.clear();
			v_k.clear();
			for (j = 0; j < value_II; j++)
			{
				file >> i_temp;
				file >> s_temp;
				v_k.push_back(i_temp);
				V_temp.push_back(s_temp);
			}
			v_klucze.push_back(v_k);
			V_s.push_back(V_temp);
		}
		M.m_loader(V_s, V_b, v_klucze); //ladowanie menu
		file.close();
	}
}
void C_aplication::m_view() {
	int i_variable=0;
	int i_klucz;
	int i_choice = 1;
	while (true) {
		M.m_view(i_variable, i_klucz,i_choice);
		switch (i_klucz)
		{
			case load_files:
				e_soft.m_load_files();
				break;
			case save_files:
				e_soft.m_save_files();	
				break;
			case add_person:
			//	e_soft.m_add_person(); 
				break;
			case delete_person:
			//	e_soft.m_delete_person(); 
				break;
			case update_person:
			//	e_soft.m_update_person();
				break;
			case 70: {
				C_id data;
				data.m_update(2);
				std::list<C_person_base*> lista;
				e_soft.m_view(view_search, sort_id,data, lista);
					M.m_set_content(lista);
					i_choice = 2;
			}break;
			default:
				if(i_klucz<i_size) //zabezpiecza przed zawieszaniem menu
				i_variable = i_klucz;
		}
	}

}
C_aplication::~C_aplication() {
	//delete M;
}