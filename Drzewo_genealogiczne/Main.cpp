#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include "Data\data\C_data_base.hpp"
#include "Data\data\C_id.hpp"
#include "Data\data\C_date.hpp"
#include "Data\person\C_person_base.hpp"
#include "Data\relation\C_relation_base.hpp"
#include "Data\relation\C_relation.hpp"
#include "Data\relation\C_relationship.hpp"
#include "Data\menu\C_fabric_menu.hpp"
#include "Data\menu\C_menu.hpp"
//---------------------------------------------------------------------------------------------------------------------------------------
//Przykladowe klasy do rozdzielenia na plii


typedef void(*f)(int&, int&, std::vector<int>&);
void f_sterowanie(int& x, int& i_klucz, std::vector<int>& v_k);






class Aplication {
	C_menu M;
public:
	Aplication(std::string what) {
		m_load_file(what);
	};
	void m_load_file(std::string s_file) {
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
	void m_view() {
		M.m_view(0);
	}
	~Aplication() {
		//delete M;
	}


};
class C_engine_hardware {
public:
	C_engine_hardware(){}
	~C_engine_hardware(){}
};
class C_engine_software:public C_engine_hardware {
public:	
	C_engine_software(){}
	~C_engine_software() {}
};
class C_engine_tree {
public:	
	C_engine_tree() {}
	~C_engine_tree() {}
};
class C_tree {
public:	
	C_tree() {}
	~C_tree() {}
};
class C_db {
	std::vector<C_person_base*> V_person;
public:
	C_db(){}
	~C_db() {}
};
int main() {

	return 0;
}
