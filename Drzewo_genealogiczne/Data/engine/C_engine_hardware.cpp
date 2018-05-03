//**********************************************************************************************************************************************************//
//	Plik: C_engine_hardware.cpp																								Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-03-2018				Lukasz			Dodanie metody:																									//
//											- void m_load_files() <- do wczytywania drzewa z pliku															//
//											- void m_save_files() <- do zapisywania drzewa do pliku															//
//**********************************************************************************************************************************************************//
#include "C_engine_hardware.hpp"

C_engine_hardware::C_engine_hardware() {}
void C_engine_hardware::m_load_files(std::string& s_str) {
	std::ifstream file;
	file.open(s_str.c_str());
	if (file.good()) {
		d_Database_.m_load(file);
		file.close();
	}
} //metoda do przebudowy
void C_engine_hardware::m_save_files() {
	int i_size;
	d_Database_.m_size(i_size);
	//d_Database.m_sort(f_sort_last_name); //test na sortowanie po imieniach! (Test zakonczony sukcesem!)
	//d_Database.m_sort(f_sort_last_name); //test na sortowanie po nazwiskach! (Test zakonczony sukcesem!)
	//d_Database.m_sort(f_sort_id); //test na sortowanie po id! (Test zakonczony sukcesem!)
	//d_Database.m_sort(f_sort_date_brith); //test na sortowanie po dacie urodzenia! (Test zakonczony sukcesem!)
	//d_Database.m_sort(f_sort_date_death); //test na sortowanie po dacie smierci! (Test zakonczony sukcesem!)
	std::ofstream file;
	file.open(file_save);
	if (file.good()) {
		file << i_size;
		std::list<C_person_base*> LISTA;
		d_Database_.m_get(LISTA);
		for (auto& x : LISTA) {
			file << *x;
		}
		file.close();
	}
}	//metoda do przebudowy
void C_engine_hardware::m_sort(bool(*F)(C_person_base* _left, C_person_base* _right)) {
	d_Database_.m_sort(F);
}
void C_engine_hardware::m_add_tree(std::string s_data, bool b_what) {

	if (S_tree_.count(s_data)!=0) {//tu naprawic
		S_tree_.insert(s_data);
		f_creative_file_tree(s_data);
	}
	else {
		b_what = false; //element juz istnieje
	}
}
void C_engine_hardware::m_load_tree() {
	std::string s_data;
	std::ifstream file;
	int i_size;
	int i_iterator;
	file.open(file_list_tree);
	if (file.good()) {
		file >> i_size;
		for (i_iterator = 0; i_iterator < i_size; i_iterator++) {
			getline(file, s_data);
			S_tree_.insert(s_data);
		}
		file.close();
	}
}
void C_engine_hardware::m_save_tree() {
	std::string s_data;
	std::ofstream file;
	file.open(file_list_tree);
	if (file.good()) {
		for (auto& x : S_tree_) {
			file << x;
		}
		file.close();
	}
}
C_engine_hardware::~C_engine_hardware() {}
//bool f_sort_tree(std::string _Left, std::string _Right) {
//	if (_Left < _Right) return true;
//	return false;
//}
void C_engine_hardware::m_delete_tree(std::string s_data) {
	S_tree_.erase(s_data);
	s_data = cmd_del_tree + s_data + ".tree"; //<- powinien nadac komende do usuniecia drzewa
	system(s_data.c_str());
}
void C_engine_hardware::m_edit_name_tree(std::string _new, std::string _old) {
//	std::set<std::string>::iterator it;
	if (S_tree_.count(_old)!=0) {
		S_tree_.erase(S_tree_.find(_old));
		S_tree_.insert(_new);
	}
}
void f_creative_file_tree(std::string s_data) {
	s_data = s_data + ".tree";
	std::ifstream file;
	file.open(s_data.c_str());
	if (file.good()) {
		file.close();
	}
}
void C_engine_hardware::m_get_tree(std::vector<std::string>& V_str) {
	V_str.resize(S_tree_.size());
	int i_iterator = 0;
	for (auto& x : S_tree_) {
		V_str[i_iterator] = x;
		i_iterator++;
	}
}
