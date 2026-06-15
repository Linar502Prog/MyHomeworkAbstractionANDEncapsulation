#include <iostream>
#include <fstream>
#include <string>
#include "Windows.h"
class Space {
	std::string City;
	std::string Street;
	int house_number;
	int  flat_number;
	std::string get_output_address(std::string adress) {
		return adress;
	}
public:
	Space(std::string City, std::string Street, int num1, int num2) {
		this->City = City;
		this->Street = Street;
		house_number = num1;
		flat_number = num2;
	}
	Space() {
	}
	~Space(){
	}
	std::string get_City() {
		return City;
	}
	std::string get_Street() {
		return Street;
	}
	int get_house_number() {
		return house_number;
	}
	int get_flat_number() {
		return flat_number;
	}
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream file("C:\\Users\\Ëèíàð\\OneDrive\\Desktop\\Íîâûé òåêñòîâûé äîêóìåíò (3).txt");
	if (!file.is_open()) {
		std::cout << "Îøèáêà ÷òåíèÿ ôàéëà " << std::endl;
	}
	else {
		std::string city, street;
		int house_num, flat_num, N;
		file >> N;
		file.ignore();
		std::string line;
		Space* arr = new  Space[N];
		for (int i = 0; i < N; i++) {
			std::getline(file, city);
			std::getline(file, street);
			file >> house_num; file.ignore();
			file >> flat_num; file.ignore();
			arr[i] = Space(city, street, house_num, flat_num);
		}
		file.close();
		std::ofstream out_file("C:\\Users\\Ëèíàð\\OneDrive\\Desktop\\Íîâûé òåêñòîâûé äîêóìåíò (4).txt");
		if (!out_file.is_open()) {
			std::cout << "Îøèáêà îòêðûòèÿ ôàéëà " << std::endl;
		}
		else {
			out_file << N << std::endl;
			for (int i = N-1; i >= 0; i--) {
				out_file << arr[i].get_City() << ", " << arr[i].get_Street() << ", "
					<< arr[i].get_house_number() << ", " << arr[i].get_flat_number() << std::endl;
			}
			std::cout << "Ôàéë óñïåøíî îáíîâëåí. " << std::endl;
		}
		out_file.close();
	}
	delete[] arr;
	return EXIT_SUCCESS;
}
