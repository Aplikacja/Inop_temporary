
#include "Data\engine\C_aplication.hpp"
#include <ctime>
void f_read_file_inicjalizer(std::string data, std::string& File);
int main() {
	std::string File;
	f_read_file_inicjalizer("plik_inicjalizacyjny.txt",File);
	C_aplication A(File);
	A.m_view();
	return 0;
}
void f_read_file_inicjalizer(std::string data, std::string& File) {
	std::ifstream file;
	file.open(data.c_str());
	if (file.good()) {
		file >> File;
		file.close();
	}
	else
	{
		std::cout << "\tProblem z plikiem inicjalizacyjnym\n\tzamykanie programu...\n";
			Sleep(3000);
	}

}
