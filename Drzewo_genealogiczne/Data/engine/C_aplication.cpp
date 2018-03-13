//**********************************************************************************************************************************************************//
//	Plik: C_aplication.cpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#include "C_aplication.hpp"

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
	M.m_view(0);
}
C_aplication::~C_aplication() {
	//delete M;
}