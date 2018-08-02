//**********************************************************************************************************************************************************//
//	Plik: C_aplication.cpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
// 15-03-2018				Lukasz			Dodanie petli nieskonczonej while(true) do metody m_view(). Utworzenie petli switch w celu umieszczenia w niej	//
//											mozliwosci wywolania metod klasy C_silnik_software. Klasa C_aplication przeladowuje klase C_menu				//
//**********************************************************************************************************************************************************//
#include "C_aplication.hpp"
void f_werification_date(std::string& s_data, int& b_what);
void f_what_good_day(int& i_month, int& i_day, int& b_what, bool b_przestepny);
void f_good_day(C_date& data_first, C_date& data_sacend, int & b_what);
void f_clean(std::list<C_person_base*>& list);
void f_analicaly_parents(std::list<C_person_base*>& L_person, bool& b_father, bool& b_mather, bool& b_parents, int& number);
void f_delete_krotka(std::vector<std::string>& V_s, std::string data);
C_aplication::C_aplication(std::string what, bool& b_mistacke) {
	m_load_file(what,b_mistacke);
};
void C_aplication::m_load_file(std::string s_file, bool& b_mistacke) {

	try
	{
		std::ifstream file;
		std::ios_base::iostate exceptionMask = file.exceptions() | std::ios::failbit;
		file.exceptions(exceptionMask);
		file.open(s_file.c_str());
		if (file.good())
		{
			b_mistacke = false;
			int value;
			int value_II;
			int i;
			int j; 
			int k;
			int i_temp;
			std::vector<std::vector<std::string>> V_string;
			std::vector<std::vector<int>> v_klucze;
			std::vector<std::vector<std::vector<int>>> V_procedur;
			std::vector<std::vector<int>> V_proces;
			std::vector<int> v_k;
			std::vector<int> v_proc;
			std::vector<bool> V_b;
			std::vector<int> V_start;
			std::vector<std::string> V_temp;
			std::vector<int> V_typ_menu;
			std::string s_temp;
			int i_temp_II;
			int i_typ_menu;
			int i_temp_procedur;
			int i_size_procedur;
			bool b_temp;
			V_str_.resize(2);
			V_str_[1].resize(size_menu);
			file >> value;
			i_size_ = value;
			for (i = 0; i < value; i++)
			{
				file >> i_typ_menu;
				file >> value_II;
				file >> b_temp;
				file >> i_temp_II;
				V_b.push_back(b_temp);
				V_typ_menu.push_back(i_typ_menu);
				V_temp.clear();
				V_proces.clear();
				v_k.clear();
				for (j = 0; j < value_II; j++)
				{
					file >> i_temp;
					file >> i_size_procedur;
					v_proc.clear();
					for (k = 0; k < i_size_procedur; k++) {
						file >> i_temp_procedur;
						v_proc.push_back(i_temp_procedur);
					}
					s_temp.clear();
					getline(file, s_temp);
					v_k.push_back(i_temp);
					V_temp.push_back(s_temp);
					V_proces.push_back(v_proc);
				}
				V_procedur.push_back(V_proces);
				v_klucze.push_back(v_k);
				V_string.push_back(V_temp);
				V_start.push_back(i_temp_II);
				V_str_[0] = V_string;
			}
			M_.m_loader(V_string, V_b, v_klucze, V_procedur, V_start, V_typ_menu); //ladowanie menu
			for (j = 0; j < value; j++) {
				M_.m_set_str(j, V_str_);
			}
			file.close();
		}
	}
	catch (std::ios_base::failure& ex)
	{
		MessageBox(nullptr, TEXT("Blad podczas wczytywania pliku."), TEXT("Blad!"), MB_OK);
		b_mistacke = true;
	}
	catch (...)
	{
		MessageBox(nullptr, TEXT("Nierozpoznany blad aplikacji."), TEXT("Blad!"), MB_OK);
		b_mistacke = true;
	}
}
void C_aplication::m_view() {
	int i_variable=0;
	int i_klucz;
	bool b_mistacke;
	long long i_id_pointer; //id persona wskaznikowego wzgledem ktorego bedzie rysowane drzewo
	long long i_id_pointer_temp;
	C_id ID_person;
	ID_person.m_active(); //aktywacja id persona wskaznikowego
	std::vector<int> V_proces;
	std::string s_tree; //nazwa drzewa wokul ktorego zachodza opcje wybierane w menu
	V_proces.push_back(Menu_glowne);
	int i_choice = 1;
	while (true) {
		for (auto& X : V_proces) {
			switch (X)
			{
			case Menu_glowne: {
				i_variable = 0;
				i_choice = 1;
				M_.m_view(id_menu_MenuGlowne, i_variable, i_klucz, V_proces, i_choice);
				break; }
			case Menu_pewnosci: {
				i_variable = 3;
				i_choice = 1;
				M_.m_set_replay(i_variable, id_menu_Menu_pewnosci, Menu_glowne);
				M_.m_view(id_menu_Menu_pewnosci, i_variable, i_klucz, V_proces, i_choice);
				break; }
			case M_zarzadzaniatree: {
				i_variable = 1;
				i_choice = 1;
				M_.m_set_replay(i_variable, id_menu_zarzadzaniadrzewem, search_tree);
				M_.m_view(id_menu_zarzadzaniadrzewem, i_variable, i_klucz, V_proces, i_choice);
				break; }
			case M_zarzadzaniapersonem: {
				i_variable = 7;
				i_choice = 1;
				M_.m_set_replay(i_variable, id_menu_zarzadzaniapersonem, searchperson);
				if (M_.m_view(id_menu_zarzadzaniapersonem, i_variable, i_klucz, V_proces, i_choice)) {

				}
				break; }
			case Edition_tree: {
				i_variable = 10;
				i_choice = 1;
				M_.m_set_replay(i_variable, id_menu_MenuEditTree, search_tree);
				M_.m_view(id_menu_MenuEditTree, i_variable, i_klucz, V_proces, i_choice);
				break; }
			case rename_tree: {
				i_variable = 11;
				i_choice = 0;
				std::vector<std::string> V_name;
				V_name.resize(2);
				V_name[0] = s_tree;
				M_.m_set_replay(i_variable, id_menu_MenuRenameTree, Edition_tree);
				if (M_.m_view(id_menu_MenuRenameTree, i_variable, V_name, i_klucz, V_proces, i_choice)) {
					e_soft_.m_edit_name_tree(V_name[1], V_name[0]);
					e_soft_.m_save_tree(b_mistacke);
					s_tree = V_name[1];
					if (b_mistacke) {
						V_proces.clear();
						V_proces.push_back(Menu_glowne);
					}
				}
				break; }
				case exit: {
					return; 
				}
				case load_files: {
					e_soft_.m_load_tree(b_mistacke);
					if (b_mistacke) {
						V_proces.clear();
						V_proces.push_back(Menu_glowne);
					}
					break; }
				case save_files: {
					e_soft_.m_save_files(s_tree, b_mistacke);
					if (b_mistacke) {
						V_proces.clear();
						V_proces.push_back(Menu_glowne);
					}
					break; }
				case save_tree:
				{
					e_soft_.m_save_tree(b_mistacke);
					if (b_mistacke) {
						V_proces.clear();
						V_proces.push_back(Menu_glowne);
					}
					break;
				}
				case choice_person: {
					std::string s_str;
					int i_position = 0;
					int i_position_old = 0;
					i_variable = 13;
					i_choice = 1;
					std::vector<C_relation> V_relation_temp;
					std::list<C_person_base*> L_Person_orgin;
					std::list<C_person_base*> L_Person_temp;
					std::vector<C_person_base*> V_person_temp;
					std::vector<C_person_base*>::iterator it;
					std::vector<std::list<C_person_base*>> V_person_result;
					V_person_result.resize(4);
					std::vector<std::vector<C_person_base*>>::iterator IT_result;
					std::vector<C_relation> V_relation;
					std::vector<C_relationship> V_relationship;
					std::vector<std::string> V_string;
					std::vector<int> V_position;
					C_fabric_person f;
					C_id id;
					C_id id_temp;
					//bool b_gender;
					std::string s_first_name;
					std::string s_last_name;
					C_date date_brith;
					C_date date_death;
					std::vector<C_relation> V_relation_copy;
					std::vector<C_relationship> V_relationship_copy;
					std::vector<C_id> V_id;
				//	C_person_base* person;
					//e_soft_.m_get_list_person_orginal(L_Person_orgin); //pobranie z silnika orginalnej listy osob
 					e_soft_.m_view(view_search, sort_id, ID_person, L_Person_orgin); //wyszukanie persona po id
					(*L_Person_orgin.begin())->m_get_V_relation(V_relation);
					V_id.push_back(ID_person);
					if (V_relation.size() != 0) {
						for (auto& relation : V_relation) {
							relation.m_get_id(id);
							e_soft_.m_view(view_search, sort_id, id, L_Person_temp);
							switch (relation.m_get_typ()) {
							case r_parents:	V_person_result[r_parents - 1].push_back(*L_Person_temp.begin()); break;
							case r_sibling: V_person_result[r_sibling - 1].push_back(*L_Person_temp.begin()); break;
							default: break;
							}
							V_id.push_back(id);
						}
					}
					(*L_Person_orgin.begin())->m_get_V_relationship(V_relationship);
					if (V_relationship.size() != 0) {
						for (auto& relationship : V_relationship) {
							relationship.m_get_id(id);
							e_soft_.m_view(view_search, sort_id, id, L_Person_temp);
							switch (relationship.m_get_typ()) {
							case r_partner:	V_person_result[r_partner - 1].push_back(*L_Person_temp.begin()); break;
							default: break;
							}
							V_id.push_back(id);
							relationship.m_get_baby(V_relation_temp);
								for (auto& relation : V_relation_temp) {
									relation.m_get_id(id);
									e_soft_.m_view(view_search, sort_id, id, L_Person_temp);
									switch (relation.m_get_typ()) {
									case r_chlidren:	V_person_result[r_chlidren - 1].push_back(*L_Person_temp.begin()); break;
									default: break;
									}
									V_id.push_back(id);
								}
						}
					}
					e_soft_.m_copy(V_person_temp);
					for (auto& X : V_person_temp) {
						X->m_get_id(id);
						for (auto& ID : V_id) {
							if (id.m_return_value() == ID.m_return_value()) {
								V_position.push_back(i_position-i_position_old);
								i_position_old++;
							}
						}
						i_position++;
						
					}
					for (auto& X : V_position) {
						it = V_person_temp.begin();
						advance(it, X);
						delete *it;
						V_person_temp.erase(it);
					}
					V_id.clear();
					for (auto& X : V_person_temp) {
						//-> resetowanie id
						X->m_get_id(id);
						V_id.push_back(id);
					}
					//V_str_[1][id_menu_MenuChoicePerson] = V_string;
					C_engine_software E;
					M_.m_set_str(i_variable, V_str_);
					M_.m_set_replay(i_variable, id_menu_MenuChoicePerson, searchperson);
					M_.m_set_content(id_menu_MenuChoicePerson, V_person_result, V_id);
					M_.m_set_data_base(id_menu_MenuChoicePerson, e_soft_);
					M_.m_elimination(id_menu_MenuChoicePerson, V_position);
					i_choice = 3;

					i_klucz = 5;
					if (M_.m_view(id_menu_MenuChoicePerson, i_variable, s_str, i_klucz, V_proces, i_choice)) {
						i_id_pointer_temp = V_id[atoi(s_str.c_str())].m_return_value();
					}
					break; }
				case add_relation:{
						i_variable = 14;
						i_choice = 4;
						int i_iterator;
						int i_typ;
						C_relation relation;
						C_relationship relationship;
						C_relation relation_temp;
						C_relationship relationship_temp;
						std::vector<C_relation> V_relation;
						std::vector<C_relation> V_relation_temp;
						std::vector<C_relation> V_relation_temp_II;
						std::vector<C_id> V_id;
						std::vector<C_id> V_id_temp;
						std::vector<C_id> ::iterator it_id;
						std::vector<C_relation>::iterator it_relation;
						std::vector<C_relationship> V_relationship;
						std::string s_str;
						std::vector<std::string> V_string;
						std::list<C_person_base*> L_Person_temp;
						std::list<C_person_base*> L_person;
						std::list<C_person_base*> L_person_orgin;
						std::list<C_person_base*>::iterator it;
						C_id id;
						C_id id_temp;
						C_id id_baby;
						//zastapic bool-e i int-y na tablice
						bool b_fisrt_parents = false;
						bool b_secend_parents = false;
						bool b_temp;
						bool b_mather=false;
						bool b_father=false;
						bool b_gender;
						//bool b_secend_gender;
						int i_first_numb_parents=0;
						int i_secend_numb_parets = 0;
						int i_first_numb_sibling = 0;
						int i_secend_numb_sibling = 0;
						int i_first_free_relationship = 0;
						//zastapic pojedyncze C_date tablica
						C_date first_brith;
						C_date first_death;
						C_date secend_brith;
						C_date secend_death;
						id.m_active();
						id.m_update(i_id_pointer_temp);
						//int i_value;
						V_string.clear();
						V_string = { "Tata", "Mama", "Brat", "Siostra", "Zona", "Maz", "Syn", "Corka" };
//-------------------------analiza osoby
						//refraktorytzacja i wrzucenie to do pojedynczej funkcji
						e_soft_.m_view(view_search, sort_id, ID_person, L_person);
						b_gender = (*L_person.begin())->m_content_gender(p_gender);
						first_brith = (*L_person.begin())->m_content_date(p_data_brith);
						first_death = (*L_person.begin())->m_content_date(p_data_death);
						for (auto& X : (*L_person.begin())->m_content_V_relation(p_relation)) {
							X.m_get_typ(i_typ);
							switch (i_typ) {
								case r_parents: {
									//Analiza osoby (parents)
									X.m_get_id(id_temp);
									e_soft_.m_view(view_search, sort_id, id_temp, L_Person_temp);
									f_analicaly_parents(L_Person_temp, b_father, b_mather, b_fisrt_parents, i_first_numb_parents);
									break; 
								}
								case r_sibling: {
									//Analiza osoby (sibling)
									i_first_numb_sibling++; break;
								}
							}
						}
						for (auto& Y : (*L_person.begin())->m_content_V_relationship(p_relationship)) {
							Y.m_get_typ(i_typ);
							switch (i_typ) {
								case r_partner: {
									Y.m_get_id(id_temp);
									if (id_temp.m_what()) {
										Y.m_get_baby(V_relation);
										for (auto& T : V_relation) {
											T.m_get_typ(i_typ);
											switch (i_typ) {
												case r_chlidren:
													break;
												default:
													//dodac informacje o bledzie
													break;
											}
										}
									}
									else
										i_first_free_relationship++;
								}
							}
						}
						//analiza wyboru relacji
						if (i_first_numb_parents) {
							f_delete_krotka(V_string, "Tata");
							f_delete_krotka(V_string, "Mama");
						}
						else {
							if(b_mather) f_delete_krotka(V_string, "Tata");
							if(b_father) f_delete_krotka(V_string, "Mama");
						}
						if (b_gender) f_delete_krotka(V_string, "Zona");//odrzucenie zony
						else f_delete_krotka(V_string, "Maz");//odrzucenie meza
//-------------------------
						L_person.clear();
						e_soft_.m_view(view_search, sort_id, id, L_person);
						secend_brith = (*L_person.begin())->m_content_date(p_data_brith);
						secend_death = (*L_person.begin())->m_content_date(p_data_death);
						b_gender = (*L_person.begin())->m_content_gender(p_gender);
						if (b_gender) {
							f_delete_krotka(V_string, "Zona");
							f_delete_krotka(V_string, "Siostra");
							f_delete_krotka(V_string, "Corka");
							f_delete_krotka(V_string, "Mama");
						}
						else {
							f_delete_krotka(V_string, "Maz");
							f_delete_krotka(V_string, "Tata");
							f_delete_krotka(V_string, "Syn");
							f_delete_krotka(V_string, "Brat");
						}
						//analiza wieku i emilinacja w razie czego
						V_str_[1][id_menu_MenuAddRelation] = V_string;
						M_.m_set_str(i_variable, V_str_);
						M_.m_set_replay(i_variable, id_menu_MenuAddRelation, searchperson);//tu ubdate					
						if (M_.m_view(id_menu_MenuAddRelation, i_variable, s_str, i_klucz, V_proces, i_choice)) { //wybor rodzaju relacji
							switch (i_klucz) {
							case 0:
							case 1: {
								//tworzenie nowej relacji
								relation.m_active(); //aktywacja relacji
								relation.m_add_typ(r_parents); //dodanie typu do relacji
								relation.m_add_id(id); //wstaweinie id do relacji
								e_soft_.m_view(view_search, sort_id, ID_person, L_Person_temp);
								 //dostaie sie do zawartosci persona
									for(auto& X: (*L_Person_temp.begin())->m_content_V_relation(p_relation)){
										X.m_get_typ(i_typ);
										switch (i_typ) {
										case r_sibling:
											X.m_get_id(id_temp);
											relation_temp.m_active();
											relation_temp.m_add_typ(r_chlidren);
											relation_temp.m_add_id(id_temp);
											V_relation_temp.push_back(relation_temp);
											e_soft_.m_add_relation(relation, id_temp);
										}
								}
								e_soft_.m_add_relation(relation, ID_person); //wstawia nowa relacje do persona i dziala poprawnie
								e_soft_.m_view(view_search, sort_id, id, L_Person_temp); //wyszukanie persona po id
								for (auto& X : L_Person_temp) { //dostaie sie do zawartosci persona
									X->m_get_V_relationship(V_relationship); //wyuskanie do persona vectora relationship
									//stworzenie nowej relacji
									relation_temp.m_active(); //aktywacja relacji
									relation_temp.m_add_typ(r_chlidren);	//ustawienie typu relacji
									relation_temp.m_add_id(ID_person); //wstaweinie w relacje id
									V_relation_temp.push_back(relation_temp);
									if (V_relationship.size() == 0) { //sprawdzanie czy vector relationship ma jakas zawartosc
										//tworzenie nowej relationship
										relationship_temp.m_active(); //aktywacja relationship
										relationship_temp.m_add_typ(r_null); //okreslenie typu relationship
										for(it_relation = V_relation_temp.begin(); it_relation != V_relation_temp.end(); it_relation++)
										relationship_temp.m_set_baby(*it_relation); //wstaweinie wczesniej stworzonej relacji do vectora relacji
										V_relationship.push_back(relationship_temp); //wstawienie relationship do vectora relationship
										e_soft_.m_add_V_relationship(V_relationship, id); //wstawienie do persona o id = id vectora relacji
										break;
									}
									else {
										i_variable = 15;
										i_choice = 4;
										V_string.clear();
										for (auto& rel : V_relationship) {
											s_str.clear();
											rel.m_get_id(id_temp);
											e_soft_.m_view(view_search, sort_id, id_temp, L_Person_temp);
											it = L_Person_temp.begin();
											(*it)->m_conwert(s_str);
											V_string.push_back(s_str);
										}
										V_str_[1][id_menu_MenuChoicePartner] = V_string;
										M_.m_set_str(i_variable, V_str_);
										M_.m_set_replay(i_variable, id_menu_MenuChoicePartner, searchperson);
										if (M_.m_view(id_menu_MenuChoicePartner, i_variable, s_str, i_klucz, V_proces, i_choice)) {
											V_relationship[i_klucz].m_set_baby(relation_temp);
											e_soft_.m_add_V_relationship(V_relationship, id); //mam nadzieje ze bedzie to kombo dzialac...
										}
									}
									//znalesc odpowiedni c relationship z rodzicem i nastepnie dodac do niego
								}
								break; } //dotad jest przetestowane i dziala dobrze:)
							case 2:
							case 3: {
								//stworzenie relacji	
								relation.m_active(); //aktywacja relacji
								relation.m_add_typ(r_sibling);	//ustawienie typu relacji
								relation.m_add_id(id); //wstawienie id do relacji
								e_soft_.m_view(view_search, sort_id, ID_person, L_Person_temp);
								//dostaie sie do zawartosci persona
								for (auto& X : (*L_Person_temp.begin())->m_content_V_relation(p_relation)) {
									X.m_get_typ(i_typ);
									switch (i_typ) {
									case r_sibling:
										X.m_get_id(id_temp);
										relation_temp.m_active();	//aktywacja relacji
										relation_temp.m_add_typ(r_sibling); //ustawienie typu relacji
										relation_temp.m_add_id(id_temp); //wstawienie id do relacji
										V_relation_temp.push_back(relation_temp);
										V_id.push_back(id_temp);
										e_soft_.m_add_relation(relation, id_temp);
										break;
									}
								}
								e_soft_.m_add_relation(relation, ID_person);
								e_soft_.m_view(view_search, sort_id, id, L_person); //wyszukanie persona po id
								relation.m_active();	//aktywacja relacji
								relation.m_add_typ(r_sibling); //ustawienie typu relacji
								relation.m_add_id(ID_person); //wstawienie id do relacji
									for (auto& X : (*L_person.begin())->m_content_V_relation(p_relation)) {
										X.m_get_typ(i_typ);
										switch (i_typ) {
										case r_sibling:
											X.m_get_id(id_temp);
											relation_temp.m_active();	//aktywacja relacji
											relation_temp.m_add_typ(r_sibling); //ustawienie typu relacji
											relation_temp.m_add_id(id_temp); //wstawienie id do relacji
											V_relation_temp_II.push_back(relation_temp);
											V_id_temp.push_back(id_temp);
										/*	for (it_relation = V_relation_temp.begin(); it_relation != V_relation_temp.end(); it_relation++)
												e_soft_.m_add_relation(*it_relation, id_temp);*/
											break;
										}
									//e_soft_.m_add_relation(relation, id);
									for (it_id = V_id_temp.begin(); it_id != V_id_temp.end(); it_id++) {
										for (it_relation = V_relation_temp.begin(); it_relation != V_relation_temp.end(); it_relation++) {
											e_soft_.m_add_relation(*it_relation, *it_id); //wstaweinie do orginalnego persona z id = id relacji
										}
									}
									for (it_id = V_id.begin(); it_id != V_id.end(); it_id++) {
										for (it_relation = V_relation_temp_II.begin(); it_relation != V_relation_temp_II.end(); it_relation++) {
											e_soft_.m_add_relation(*it_relation, *it_id); //wstaweinie do orginalnego persona z id = id relacji
										}
									}
								}
								e_soft_.m_add_relation(relation, id);
								 //wstaweinie do orginalnego persona z id = ID_person relacji 
								break; //dziala poprawnie
							}
							case 4:
							case 5: {
								i_iterator = 0;
								//stworzenie relacji
								relationship.m_active();	//aktywacja relacji
								relationship.m_add_typ(r_partner); //ustawienie typu relacji
								relationship.m_add_id(id); //wstawienie id do relacji
								e_soft_.m_view(view_search, sort_id, id, L_Person_temp);
								for (auto& X : L_Person_temp) {
									X->m_get_V_relationship(V_relationship);
									relationship_temp.m_active();
									relationship_temp.m_add_typ(r_partner);
									relationship_temp.m_add_id(ID_person);
									if (V_relationship.size() < 0) {
										for (auto& R : V_relationship) {
											R.m_get_id(id_temp);
											if (id_temp.m_return_value() == id.m_return_value()) {
												R.m_get_baby(V_relation);
												relation_temp.m_active();
												relation_temp.m_add_typ(r_parents);
												relation_temp.m_add_id(ID_person);
												for (auto& r : V_relation) {
													r.m_get_id(id_baby);
													e_soft_.m_get_list_person_orginal(L_person_orgin);
													for (it = L_person_orgin.begin(); it != L_person_orgin.end(); it++) {
														if (id_baby.m_return_value() == (*it)->m_content_id(p_id).m_return_value()) {
															(*it)->m_add_relation(relation_temp);
														}
														if (id.m_return_value() == (*it)->m_content_id(p_id).m_return_value()) {
															(*it)->m_add_relationship(relationship_temp);
														}
													}
												}
										
												//R[i_iterator] = relation_temp; //tutaj trzeba dobrze przypisac
												e_soft_.m_update_relationship(R, id, i_iterator);
											}
											i_iterator++;
										}
									}
								}
								e_soft_.m_add_relationship(relationship, ID_person);
							}
							default: break;
							}
						}
						V_proces.clear();
						V_proces.push_back(11);
						V_proces.push_back(21);
						break;}
				case add_person: {
					i_variable = 9;
					i_choice = 1;
					std::vector<std::string> V_dane;
					int i_what_1;
					int i_what_2;
					int i_what = 0;
					bool b_gender = false;
					V_dane.resize(5);
					M_.m_set_replay(i_variable, id_menu_MenuAddPerson, search_tree);
					do {
						if (M_.m_view(id_menu_MenuAddPerson, i_variable, V_dane, i_klucz, V_proces, i_choice, i_what)) { //lacze dziala wyciaga dane z interface trzeba zrobic funkcje zabezpieczajace
							i_what = 1;
							i_what_1 = 0;
							i_what_2 = 0;
							f_werification_date(V_dane[2], i_what_1);
							f_werification_date(V_dane[3], i_what_2);
							C_date date_brith, date_death;
							date_brith.m_active();
							date_death.m_active();
							date_brith.m_apped(V_dane[2]);
							date_death.m_apped(V_dane[3]);
							f_good_day(date_brith, date_death, i_what);
							switch (V_dane[4][0]) {
							case 'W':
								b_gender = true;
							case 'M':
								b_gender = false;
							}
							if (i_what_1&&i_what_2&&i_what<2) {
								e_soft_.m_add_person(b_gender, V_dane[0], V_dane[1], date_brith, date_death);
								i_what = 0;
							}
							//break;
						}
					} while (i_what != 0); 
					break; }
				case delete_person: {
					e_soft_.m_delete_person(ID_person.m_return_value()); //testy co i dalczego!!!
					break; }
				case M_menu_edycji_persona: {
					i_variable = 8;
					i_choice = 1;
					M_.m_set_replay(i_variable, id_menu_Menuedycjipersona, M_zarzadzaniapersonem);
					M_.m_view(id_menu_Menuedycjipersona, i_variable, i_klucz, V_proces, i_choice);
					break; }
				case updata_person: {
					i_variable = 12;
					i_choice = 3;
					std::vector<std::string> V_dane;
					int i_what_1; 
					int i_what_2;
					int i_what = 1;
					C_date date_brith, date_death;
					bool b_gender;
					V_dane.resize(5);
					std::list<C_person_base*> L_Person;
					C_person_base* person;
					e_soft_.m_view(view_search, sort_id, ID_person, L_Person);
					person = *(L_Person.begin()); //konwersja bez iteratora
					person->m_get_first_name(V_dane[0]);
					person->m_get_last_name(V_dane[1]);
					person->m_get_date(D_brith, date_brith);
					date_brith.m_sidle(V_dane[2]);
					person->m_get_date(D_death, date_death);
					date_death.m_sidle(V_dane[3]);
					person->m_get_sex(b_gender);
					switch (b_gender) {
					case true:
						V_dane[4] = "Woman";
					case false:
						V_dane[4] = "Man";
					}
					M_.m_set_replay(i_variable, id_menu_MenuUpdatePerson, M_menu_edycji_persona);
					do {
						if (M_.m_view(id_menu_MenuUpdatePerson, i_variable, V_dane, i_klucz, V_proces, i_choice,i_what))
						{
							i_what_1 = 0;
							i_what_2 = 0;
							f_werification_date(V_dane[2], i_what_1);
							f_werification_date(V_dane[3], i_what_2);
							date_brith.m_active();
							date_death.m_active();
							date_brith.m_apped(V_dane[2]);
							date_death.m_apped(V_dane[3]);
							f_good_day(date_brith, date_death, i_what);
							switch (V_dane[4][0]) {
							case 'W':
								b_gender = true;
							case 'M':
								b_gender = false;
							}
							if (i_what_1&&i_what_2&&i_what<2) {
								e_soft_.m_update_person(b_gender, V_dane[0], V_dane[1], date_brith, date_death, i_id_pointer);
								i_what = 0;
							}
						}
					} while (i_what != 0); 
					break;}
				case new_tree: {
					bool b_what = true;
					std::string s_str;
					i_variable =2;
					M_.m_set_replay(i_variable, id_menu_MenuNewTree, Menu_glowne);
					do {
						if (M_.m_view(id_menu_MenuNewTree, i_variable, s_str, i_klucz, V_proces, i_choice)) {
							e_soft_.m_add_tree(s_str, b_what);
							if (b_what) {
							f_option_clear(h, pos, Written);
								printf("Tworzenie nowego drzewa!\n");
							 f_clear(h, pos, Written);
								break;
							}
							f_option_clear(h, pos, Written);
							printf("Podana nazwa drezwa juz istnieje!\n");
							f_clear(h, pos, Written);
							Sleep(2000);
						}
						else
						break;
					} while (true);
					e_soft_.m_clean();
					s_tree = s_str;
				}break;
				case search_tree: {
					std::string s_str;
					std::vector<std::string> V_string;
					i_variable = 4;
					i_choice = 1;
					e_soft_.m_get_tree(V_string);
					M_.m_set_replay(i_variable, id_menu_MenuSearchTree, Menu_glowne);
					V_str_[1][id_menu_MenuSearchTree] = V_string;
					M_.m_set_str(i_variable, V_str_); //ladowanie menu nazwami drzew
					if (M_.m_view(id_menu_MenuSearchTree, i_variable, s_str, i_klucz, V_proces, i_choice)) {
						s_tree = s_str;
						s_str += ".tree";
						e_soft_.m_load_files(s_str, b_mistacke);
						if (b_mistacke) {
							V_proces.clear();
							V_proces.push_back(Menu_glowne);
							e_soft_.m_delete_tree(s_tree);
							e_soft_.m_save_tree(b_mistacke);
						}
						//s_str;
					}
				}break;
				case delete_tree: {
					e_soft_.m_delete_tree(s_tree);

				}break;
				case load_content_tree: {
					e_soft_.m_load_files(*(V_str_[1][0].begin()), b_mistacke);
					if (b_mistacke) {
						V_proces.clear();
						V_proces.push_back(Menu_glowne);
					}
					i_variable = search; //<-przelaczenie do menu wyszukiwania persona
				}break;
				case tree: {
					//----------------czytanie persona----------------------------------
					C_id data;
					std::string s_str;
					C_person_base *person;
					std::vector<std::list<C_person_base*>> V_lista;
					V_lista.resize(4);
					std::list<C_person_base*> lista_temp;
					std::list<C_person_base*> lista_t;
					C_fabric_person Fabric;
					C_id ID;
					C_id id;
					i_choice = 1;
					i_variable = id_menu_MenuViewTree;
					std::string s_first_name;
					std::string s_last_name;
					C_date d_brith;
					C_date d_death;
					bool b_sex;
					int i_typ;
					std::vector<int> V_k;
					std::vector<C_relation> V_relation;
					std::vector<C_relationship> V_relationship;
					std::vector<C_relation> V_relation_temp;
					std::vector<C_relationship> V_relationship_temp;
					data = ID_person;
					e_soft_.m_view(view_search, sort_id, data, lista_t);
					person = *lista_t.begin();
			/*		for (auto& x : lista_temp) {
						delete x;
					}*/
					V_lista.clear();
					V_lista.push_back(lista_t);
					person->m_get_V_relation(V_relation);
					person->m_get_V_relationship(V_relationship);
					person->m_get_id(ID);
					for (auto& x_relation : V_relation) {
						x_relation.m_get_id(id);
						//->V_k.push_back(id.m_return_value());
						x_relation.m_get_typ(i_typ);
						e_soft_.m_view(view_search, sort_id, id, lista_temp);
						//rozkladanie danmych persona na poszczegolne wartosci
						person = *lista_temp.begin();
						person->m_get_first_name(s_first_name);
						person->m_get_last_name(s_last_name);
						person->m_get_date(D_brith, d_brith);
						person->m_get_date(D_death, d_brith);
						person->m_get_sex(b_sex);
						person->m_get_V_relation(V_relation_temp);
						person->m_get_V_relationship(V_relationship_temp);
						//na razie wszystko jest do jednej listy trzeba to ulepszyc
						if (i_typ == r_parents)
							V_lista[0].push_back(Fabric.m_create_peron(i_typ, id, b_sex, s_first_name, s_last_name, d_brith, d_death, V_relation_temp, V_relationship)); //tworzenie nowego persona
						else
							V_lista[1].push_back(Fabric.m_create_peron(i_typ, id, b_sex, s_first_name, s_last_name, d_brith, d_death, V_relation_temp, V_relationship)); //tworzenie nowego persona

					}
					//->V_k.push_back(ID_person.m_return_value());
					for (auto& x_relationship : V_relationship) {
						std::list<C_person_base*> lista;
						x_relationship.m_get_id(id);
						//->V_k.push_back(id.m_return_value());
						x_relationship.m_get_typ(i_typ);
						e_soft_.m_view(view_search, sort_id, id, lista_temp);
						//rozkladanie danmych persona na poszczegolne wartosci
						person = *lista_temp.begin();
						person->m_get_first_name(s_first_name);
						person->m_get_last_name(s_last_name);
						person->m_get_date(D_brith, d_brith);
						person->m_get_date(D_death, d_brith);
						person->m_get_sex(b_sex);
						person->m_get_V_relation(V_relation_temp);
						person->m_get_V_relationship(V_relationship_temp);
						//na razie wszystko jest do jednej listy trzeba to ulepszyc
						V_lista[3].push_back(Fabric.m_create_peron(i_typ, id, b_sex, s_first_name, s_last_name, d_brith, d_death, V_relation_temp, V_relationship)); //tworzenie nowego persona
						x_relationship.m_get_baby(V_relation_temp);
						for (auto& x_relation : V_relation) {
							x_relation.m_get_id(id);
							//->V_k.push_back(id.m_return_value());
							x_relation.m_get_typ(i_typ);
							e_soft_.m_view(view_search, sort_id, id, lista_temp);
							//rozkladanie danmych persona na poszczegolne wartosci
							person = *lista_temp.begin();
							person->m_get_first_name(s_first_name);
							person->m_get_last_name(s_last_name);
							person->m_get_date(D_brith, d_brith);
							person->m_get_date(D_death, d_brith);
							person->m_get_sex(b_sex);
							person->m_get_V_relation(V_relation_temp);
							person->m_get_V_relationship(V_relationship_temp);
							//na razie wszystko jest do jednej listy trzeba to ulepszyc
							lista.push_back(Fabric.m_create_peron(i_typ, id, b_sex, s_first_name, s_last_name, d_brith, d_death, V_relation_temp, V_relationship)); //tworzenie nowego persona
						}
						V_lista.push_back(lista);
					}
					M_.m_set_content_person(id_menu_MenuViewTree, V_lista); // numer wskazuje na odpowiednie menu!!!
					M_.m_view(id_menu_MenuViewTree, i_variable, i_klucz, V_k, i_choice);
				}break;
				case searchperson: {
					//	case search: {
					C_id data; 
					std::string s_str;
					std::string s_temp;
					std::vector<C_id> V_id;
					data.m_update(2);
					i_variable = 5;
					std::list<C_person_base*> lista;
					e_soft_.m_get_list_person_orginal(lista);
				//	e_soft.m_view(view_search, sort_id, data, lista);
					M_.m_set_replay(i_variable, id_menu_MenuSearchPerson, search_tree);
					M_.m_set_content(id_menu_MenuSearchPerson,lista,V_id);
					M_.m_set_data_base(id_menu_MenuSearchPerson,e_soft_);
					i_choice = 3;
					i_klucz = 5; //wyjatkowo
					if (M_.m_view(id_menu_MenuSearchPerson, i_variable, s_str, i_klucz, V_proces, i_choice)) {
						i_id_pointer = atoi(s_str.c_str());
						ID_person.m_update(V_id[i_id_pointer].m_return_value()); //przepisanie wartosci id!
						//e_soft_.m_view(view_search, sort_id, ID, lista);  //do tego momentu jest dobrze
						//std::cin >> s_temp;
						break;
					}
					//-----wrazie czego------
					//for (auto& x : lista) {
					//	delete x;
				//	}
				//	lista.clear();
					//----------------------
				}break;
				default:
					break;
				}
		}
		if (i_klucz < i_size_) //zabezpiecza przed zawieszaniem menu
			i_variable = i_klucz;
	}

}
C_aplication::~C_aplication() {
	//delete M;
}
void f_clean(std::list<C_person_base*>& list) {
	for (auto& X: list) {
		delete X;
	}
	list.clear();
}
void f_werification_date(std::string& s_data, int& b_what) {
	int i_level = 0;
	std::string s_year;
	std::string s_month;
	std::string s_day;
	int i_year;
	int i_month;
	int i_day;
	bool b_przestepny = false;
	for (auto& x : s_data) {
		if (x == '-') {
			i_level++; 	continue;
		}
		switch (i_level) {
		case 0:
			s_year += x;
			break;
		case 1:
			s_month += x;
			break;
		case 2:
			s_day += x;
			break;
		}
	}
	i_year = atoi(s_year.c_str());
	i_month = atoi(s_month.c_str());
	i_day = atoi(s_day.c_str());
	//dalsza analiza
	if (i_year % 4 == 0) b_przestepny = true;
	f_what_good_day(i_month, i_day, b_what, b_przestepny);
}
void f_what_good_day(int& i_month, int& i_day, int& b_what, bool b_przestepny) {
	switch (i_month) {
	case 1: //miesiace o dlugosci 31 dni
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (i_day > 0 && i_day <= 31) {
			b_what = true;
		}
		else
			b_what = false;
		break;
	case 2: //luty 
		if (b_przestepny) {
			if (i_day > 0 && i_day <= 29) {
				b_what = true;
			}
			else
				b_what = false;
		}
		if (i_day > 0 && i_day <= 28) {
			b_what = true;
		}
		else
			b_what = false;
		break;
	case 4: //miesiac o dlugosci 30 dni
	case 6:
	case 9:
	case 11:
		if (i_day > 0 && i_day <= 30) {
			b_what = true;
		}
		else
			b_what = false;
		break;
	default:
		b_what = false;
	}
}
void f_good_day(C_date& data_first, C_date& data_sacend, int& i_what) {
	if (data_sacend < data_first) {
		i_what = 2;
	}
}
void f_analicaly_parents(std::list<C_person_base*>& X, bool& b_father, bool& b_mather, bool& b_parents, int& i_number) {
	bool b_temp;
	b_temp=(*X.begin())->m_content_gender(p_gender);
		if (b_temp) { //woman
			b_mather = true;
			i_number++;
		}
		else { //man
			b_father = true;
			i_number++;
		}
		if (i_number == 2) b_parents = true;
}
void f_delete_krotka(std::vector<std::string>& V_s, std::string data) {
	int i_position=0;
	for (auto& X : V_s) {
		if (X == data) {
			V_s.erase(V_s.begin() + i_position);
			return;
		}
		else
			i_position++;
	}
}