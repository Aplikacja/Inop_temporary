//**********************************************************************************************************************************************************//
//	Plik: C_date_base.cpp																									Data_utworzenia: 11-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//**********************************************************************************************************************************************************//
#ifndef C_DATA_BASE_HPP
#define C_DATA_BASE_HPP
class C_data_base {
protected:
	long long ll_value;
	bool b_pointer;
public:
	C_data_base();
	void m_update(long long ll_update);
	long long& m_return_value();
	virtual void m_virtual() = 0;
	bool& m_what();
	~C_data_base();
};
#endif // !C_DATA_BASE_HPP
