#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <thread>
#include <windows.h>
#define plik "plik.txt"
typedef void(*f)(int&, int&, std::vector<int>&);
void f_sterowanie(int& x,int& i_klucz, std::vector<int>& v_k);
class Menu_base {
protected:
	std::vector<std::string> V;
	std::vector<int> V_klucz;
	bool b_dinamic;
public:
	Menu_base(std::vector<std::string> v, bool b_value, std::vector<int> v_k) {
		V = v;
		b_dinamic = b_value;
		V_klucz = v_k;
	};
	virtual void m_view() = 0;
	void m_load(std::vector<std::string> v) {
		if (b_dinamic)
		{
			V = v;
		}
	}
	void m_ruch(void (*f)(int& x,int& i_klucz, std::vector<int>& v_k), int& i_klawisz,int& i_klucz, std::vector<int>& v_k) {
		
		f(i_klawisz, i_klucz, v_k);
	}
	virtual ~Menu_base() {};
};
class Menu_glowne:public Menu_base {
public:
	Menu_glowne(std::vector<std::string> V, bool b, std::vector<int> v_k):Menu_base(V, b, v_k) {}
	void m_view() {
		int i_x;
		int i_klucz;
		int ptr;
		for (int y = 0; y < 3; y++) {
			m_ruch(f_sterowanie, i_x, i_klucz, V_klucz); //dlaczego nie dziala
			ptr = 0;
			for (auto& x : V) {
				if (ptr == i_x) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					std::cout << x << "\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					continue;
				}
				std::cout << x << "\n";
				ptr++;

			}
		}
	}
	~Menu_glowne() {};
};

class Fabric_menu {
public:
	Menu_base * m_Create_menu(int i_value, bool b, std::vector<std::string> V, std::vector<int> v_k) {
		if (i_value == 1) return new Menu_glowne(V, b, v_k);
	}
};
class Menu {
	Fabric_menu f;
	int size;
	Menu_base** Tab_menu;
public:
	Menu() {
	//	Tab_menu = new Menu_base*[i_value];
	};
	void m_loader(std::vector<std::vector<std::string>> v_s, std::vector<bool> v_b, std::vector<std::vector<int>> v_k) {
		Tab_menu = new Menu_base*[v_s.size()];
		size = v_s.size();
		std::vector<bool>::iterator it = v_b.begin();
		std::vector<std::vector<int>>::iterator it_i = v_k.begin();
		int i;
		for (i = 0; i < v_s.size();i++) {
			Tab_menu[i] =f.m_Create_menu(1, *it, v_s[i], *it_i);
			it_i++;
			it++;
		}
	}
	void m_view(int i) {
		if (i >= 0 && i < size) {
			Tab_menu[i]->m_view();
		}
	}
	~Menu() {
		delete[]Tab_menu;
	}
};
class Aplication {
	Menu M;
public:
	Aplication(std::string what) {
		m_load_file(what);
	};
	void m_load_file(std::string s_file) {
		std::ifstream file;
		file.open(s_file.c_str());
		if (file.good())
		{
			int value,value_II, i,j,i_temp;
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
class A {
	int j;
public:
	A(int i) { j = i; };
	A(const A& a);
	void m_wiew() { std::cout << j << "\n"; }
	void m_update(int i) { j = i; }
	~A() {};
};
class B {
	std::vector<A*> v;
public:
	B() {}
	void m_get(int i) { v.push_back(new A(i)); }
	A* m_retu(int i) {
		std::vector<A*>::iterator it = v.begin();
		return *(it+i);
	}
	A& m_look_at(int i) { return *v[i]; }
	~B() {}
};

int main() {
	B b;
	b.m_get(1);
	b.m_get(13);
	b.m_get(120);
	A* a;
	a = b.m_retu(1);
	a->m_wiew();
	a->m_update(15);
	b.m_look_at(1).m_wiew();


	//HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//Aplication A(plik);
	//A.m_view();
	return 0;
}
void f_sterowanie(int& x,int& i_klucz,std::vector<int>& v_k) {
	int i_size = v_k.size();
	Sleep(300); //fajnie bylo by to zastapic
	while (true)
	{
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				x--;
				if (x <= -1)      // gdy wykracza wraca na koniec
					x = i_size - 1;
				return;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				x++;
				if (x >= i_size)       // gdy wykracza poza menu, znow wraca na poczatek
					x = 0;
				return;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				i_klucz = v_k[x];
				return;
			}
	}
}