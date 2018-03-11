#include <iostream>
#include <string>
#include <vector>
//---------------------------------------------------------------------------------------------------------------------------------------
//Przykladowe klasy do rozdzielenia na plii
class C_data_base {
protected:
	long long ll_value;
	bool b_pointer;
public:
	C_data_base() {}
	C_data_base(const C_data_base& d);
	void m_update(long long ll_update) { ll_value = ll_update; }
	long long& m_return_value() { return ll_value; }
	virtual void m_virtual() = 0;
	bool& m_what() { return b_pointer; }
	~C_data_base() {}
};
class C_id:public C_data_base {
public:
	C_id():C_data_base(){}
	C_id(const C_id& id);
	void m_virtual() {}; //klasa do rozbudowy
	~C_id() {};
};
class C_date :public C_data_base {
public:
	C_date() :C_data_base() {};
	C_date(const C_date& date);
	void m_virtual() {};
	std::string m_return_date() { std::string str; //dodanie algorytmu konwersji
	return str;
	}
	~C_date() {}
};
class C_relation_base{
protected:
	C_id* id;
	C_date* date;
	std::vector<C_relation_base*> V;
	bool b_value;
public:
	C_relation_base(C_id data) { id = new C_id;
	*id = data;
	};
	C_relation_base(C_id data, C_date Date) {
		id = new C_id;
		date = new C_date;
		*id = data; *date = Date;
	}
	C_data_base* m_return(int i_value) {
		switch (i_value)
		{
		case 1: return id;
		case 2: return date;
		default: break;
		}
	}
	void m_set_baby(C_relation_base* relation) { V.push_back(relation); }
	virtual void m_wiew() = 0;
	~C_relation_base() {
		if (id) delete id;
		if (date) delete date;
	}
};


int main() {
	return 0;
}