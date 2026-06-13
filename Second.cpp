#include <iostream>
#include "Windows.h"
#include <fstream>
#include <string>
class adress {
	std::string City;
	std::string Street;
	int house_number;
	int flat_number;
public:
	adress(std::string city, std::string street, int num1, int num2) {
		this->City = city;
		this->Street = street;
		house_number = num1;
		flat_number = num2;
	}
	adress() {

	}
	std::string get_city(){
		return City;
	}
	std::string get_street() {
		return Street;
	}
	int get_house_number() {
		return house_number;
	}
	int get_flat_number() {
		return flat_number;
	}
};

void my_sort(adress* adresses, int size) {
	for (int i = 0; i < size-1; i++) {
		for (int j = 0; j < size-1-i; j++) {
			adress value;
			if (adresses[j].get_city()[0] > adresses[j+1].get_city()[0]) {
				value = adresses[j];
				adresses[j] = adresses[j+1];
				adresses[j + 1] = value;
			}
		}
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::ifstream in("C:\\Users\\Линар\\OneDrive\\Desktop\\Новый текстовый документ (3).txt");
	if (!in.is_open()) {
		std::cout << "Ошибка чтения файла" << std::endl;
	}
	else {
		int N, house_num, flat_num;
		std::string city, street;
		in >> N;
		in.ignore();
		adress* arr = new adress[N];
		for (int i = 0; i < N; i++) {
			getline(in, city);
			getline(in, street);
			in >> house_num;
			in.ignore();
			in >> flat_num;
			in.ignore();
			arr[i]=adress(city, street, house_num, flat_num);
		}
		in.close();
		std::ofstream out("C:\\Users\\Линар\\OneDrive\\Desktop\\Новый текстовый документ (4).txt");
		if (!out.is_open()) {
			std::cout << "Ошибка открытия файла" << std::endl;
		}
		my_sort(arr, N);
		out << N << std::endl;
		for (int i = 0; i < N; i++) {
			out << arr[i].get_city() << ", " << arr[i].get_street() << ", " << arr[i].get_house_number() << ", " 
				<< arr[i].get_flat_number() << std::endl;
		}
		std::cout << "Файл успешно обновлен" << std::endl;
	}
	return EXIT_SUCCESS;
}
