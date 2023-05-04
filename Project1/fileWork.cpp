#include "fileWork.h"
#include "enum.h"
#include "inputValidation.h"
#include "interface.h"
#include "apartment.h"
#include "algorithms.h"

#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
using namespace filesystem;

bool saveInFile(Apartment* apartments, int size) {

	bool isDataSaved = false;

	do {
		string filePath = "";
		string currentPath = std::filesystem::current_path().string() + "\\";

		cout << "Введите название файла:";
		cin >> filePath;

		filePath = currentPath + filePath + ".txt";

		if (ifstream(filePath)) {
			cout << "Файл сущетсвует. Хотите его перезаписать?" << endl;
			CHOICE userChoice = static_cast<CHOICE>(0);

			showChoice();
			userChoice = getChoice();

			if (userChoice == CHOICE::NO) {
				continue;
			}
		}

		ofstream file;

		if (!file) {
			cout << "Попробуйте снова!";
			file.close();
			continue;
		}

		file.open(filePath);

		file << size << endl;
		
		if (file.is_open()) {
			for (int i = 0; i < size; i++) {
				file << apartments[i];
			}
		}

		file.close();
		isDataSaved = true;
		cout << "Данные сохранены" << endl;
	} while (isDataSaved == false);

	return true;
}

bool saveByNumbersOfRooms(Apartment* aprtmentsResult, int size, int numberOfRooms) {
	bool isDataSaved = false;

	do {
		string filePath = "";
		string currentPath = std::filesystem::current_path().string() + "\\";

		cout << "Введите название файла:";
		cin >> filePath;

		filePath = currentPath + filePath + ".txt";

		if (ifstream(filePath)) {
			cout << "Файл сущетсвует. Хотите его перезаписать?" << endl;
			CHOICE userChoice = static_cast<CHOICE>(0);

			showChoice();
			userChoice = getChoice();

			if (userChoice == CHOICE::NO) {
				continue;
			}
		}

		ofstream file;

		if (!file) {
			cout << "Попробуйте снова!";
			file.close();
			continue;
		}

		file.open(filePath);

		file << "Информация о квартирах, имеющих заданное число комнат" << endl;

		for (int i = 0; i < size; i++) {
			file << "Информация о квартире #" << aprtmentsResult[i].getId() << std::endl << std::endl;
			file << "Адрес: " << aprtmentsResult[i].getAddress() << std::endl;
			file << "Этаж: " << aprtmentsResult[i].getFloor() << std::endl;
			file << "Количество комнат: " << aprtmentsResult[i].getNumberOfRooms() << std::endl;
			file << "Площадь: " << aprtmentsResult[i].getSquare() << std::endl;
		}

		file.close();
		isDataSaved = true;
		cout << "Данные сохранены" << endl;
	} while (isDataSaved == false);

	return true;
}

bool saveByNumbersOfRoomsAndInterval(Apartment* aprtmentsResult, int size, int numberOfRooms, int intervalLow, int intervalUp) {
	bool isDataSaved = false;

	do {
		string filePath = "";
		string currentPath = std::filesystem::current_path().string() + "\\";

		cout << "Введите название файла:";
		cin >> filePath;

		filePath = currentPath + filePath + ".txt";

		if (ifstream(filePath)) {
			cout << "Файл сущетсвует. Хотите его перезаписать?" << endl;
			CHOICE userChoice = static_cast<CHOICE>(0);

			showChoice();
			userChoice = getChoice();

			if (userChoice == CHOICE::NO) {
				continue;
			}
		}

		ofstream file;

		if (!file) {
			cout << "Попробуйте снова!";
			file.close();
			continue;
		}

		file.open(filePath);

		file << "Информация о квартирах, имеющих заданное число комнат" << endl;

		for (int i = 0; i < size; i++) {
			file << "Информация о квартире #" << aprtmentsResult[i].getId() << std::endl << std::endl;
			file << "Адресс: " << aprtmentsResult[i].getAddress() << std::endl;
			file << "Этаж: " << aprtmentsResult[i].getFloor() << std::endl;
			file << "Количество комнат: " << aprtmentsResult[i].getNumberOfRooms() << std::endl;
			file << "Площадь: " << aprtmentsResult[i].getSquare() << std::endl;
		}

		file.close();
		isDataSaved = true;
		cout << "Данные сохранены" << endl;
	} while (isDataSaved == false);

	return true;
}

bool saveBySquare(Apartment* aprtmentsResult, int size, double square) {
	bool isDataSaved = false;

	do {
		string filePath = "";
		string currentPath = std::filesystem::current_path().string() + "\\";

		cout << "Введите название файла:";
		cin >> filePath;

		filePath = currentPath + filePath + ".txt";

		if (ifstream(filePath)) {
			cout << "Файл сущетсвует. Хотите его перезаписать?" << endl;
			CHOICE userChoice = static_cast<CHOICE>(0);

			showChoice();
			userChoice = getChoice();

			if (userChoice == CHOICE::NO) {
				continue;
			}
		}

		ofstream file;

		if (!file) {
			cout << "Попробуйте снова!";
			file.close();
			continue;
		}

		file.open(filePath);

		file << "Информация о квартирах, имеющих площадь, превосходящую заданную" << endl;

		for (int i = 0; i < size; i++) {
			file << "Информация о квартире #" << aprtmentsResult[i].getId()<< std::endl;
			file << "Адресс: " << aprtmentsResult[i].getAddress() << std::endl;
			file << "Этаж: " << aprtmentsResult[i].getFloor() << std::endl;
			file << "Количество комнат: " << aprtmentsResult[i].getNumberOfRooms() << std::endl;
			file << "Площадь: " << aprtmentsResult[i].getSquare() << std::endl << std::endl;;
		}

		file.close();
		isDataSaved = true;
		cout << "Данные сохранены" << endl;
	} while (isDataSaved == false);

	return true;
}

Apartment* uploadFromFile(Apartment* apartments, int size, std::ifstream& file)
{
	bool isDataLoaded = false;

	apartments = new Apartment[size];

	do {
		int i = 0;
		for (; i < size; ++i)
		{
			if (!(file >> apartments[i]))
			{
				std::cout << "Некорректные данные." << std::endl;
				delete[] apartments;
				apartments = nullptr;
				return apartments;
			}
		}
		if (i == size) {
			cout << "Загрузка завершена." << endl;
			isDataLoaded = true;
		}
		else {
			delete[] apartments;
			apartments = nullptr;
		}

	} while (isDataLoaded == false);
	return apartments;
}

int getSizeFromFile(int size, std::ifstream& file) {
	if (!(file >> size) || size <= 0) {
		cout << "Неправильный размер массива." << endl;
		return 0;
	}
	return size;
}

bool isFileCorrect(std::string filePath)
{
	bool isFileCorrect = false;

	do {
		if (!std::ifstream(filePath)) {
			std::cout << "Файл не существует. Попробуйте снова." << std::endl;
			return false;
		}

		std::error_code ec;
		if (std::filesystem::is_regular_file(filePath, ec) == false) {
			std::cout << "Адрес содержит недопустимые значения. Попробуйте снова." << std::endl;
			return false;
		}

		isFileCorrect = true;
	} while (isFileCorrect == false);
	return true;
}