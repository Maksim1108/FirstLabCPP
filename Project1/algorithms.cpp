#include "algorithms.h"

bool allocateArray(Apartment** array, int size) {
	try {
		*array = new Apartment[size];
	}
	catch (const bad_alloc& error) {
		cout << "Ошибка выделения памяти:" << error.what() << endl;
		cout << "Попробуйте снова";
		return false;
	}
	return true;
}

void clearData(Apartment* apartments) {
	delete[] apartments;
	apartments = nullptr;
}

void showApartments(Apartment* apartments, int size) {
	for (int i = 0; i < size; i++) {
		apartments[i].showInfo();
	}
}

void fillApartments(Apartment* apartments, int size) {
	cout << "Заполните информацию о " << size << " квартирах" << endl;
	int apartmentId = 1;

	for (int i = 0; i < size; i++, apartmentId++) {
		cout << "Заполните информацию о квартире номер " << apartmentId << endl;

		cout << "Адрес:" << endl;
		cout << "> ";
		apartments[i].setAddress();
		cout << "Количество комнат: " << endl;
		cout << "> ";
		apartments[i].setNumberOfRooms();
		cout << "Этаж: " << endl;
		cout << "> ";
		apartments[i].setFloor();
		cout << "Площадь: " << endl;
		cout << "> ";
		apartments[i].setSquare();
	}
}

int getCountApartmentsForNumbersOfRooms(Apartment* apartments, int size, int numberOfRooms) {
	int counter = 0;

	for (int i = 0; i < size; i++) {
		if (numberOfRooms == apartments[i].getNumberOfRooms()) {
			counter++;
		}
	}

	return counter;
}

int getCountApartmentsForNumbersOfRoomsAndInterval(Apartment* apartments, int size, int numberOfRooms, int intervalLow, int intervalUp) {
	int counter = 0;

	for (int i = 0; i < size; i++) {
		if (numberOfRooms == apartments[i].getNumberOfRooms() && apartments[i].getFloor() >= intervalLow && apartments[i].getFloor() <= intervalUp) {
			counter++;
		}
	}

	return counter;
}

int getCountApartmentsForSquare(Apartment* apartments, int size, double square) {
	int counter = 0;

	for (int i = 0; i < size; i++) {
		if (apartments[i].getSquare() > square) {
			counter++;
		}
	}

	return counter;
}

Apartment* searchByNumbersOfRooms(Apartment* apartments, Apartment* apartmentsResult, int size, int numberOfRooms) {
	Apartment* apartmentTemp = nullptr;
	int counter = 0;

	if (allocateArray(&apartmentTemp, size) == false) {
		return apartmentsResult;
	}

	for (int i = 0; i < size; i++) {
		if (numberOfRooms == apartments[i].getNumberOfRooms()) {
			counter++;
			apartmentTemp[i] = apartments[i];
		}
	}

	apartmentTemp->cleanCounter();

	int j = 0;
	if (counter == 0) {
		delete[] apartmentTemp;
		apartmentTemp = nullptr;
		apartmentsResult = nullptr;
		return apartmentsResult;
	}
	else {
		if (allocateArray(&apartmentsResult, counter) == false) {
			return apartmentsResult;
		}
		else {
			for (int i = 0; i < size; i++) {
				if (j < counter) {
					if (apartmentTemp[i].getNumberOfRooms() != numberOfRooms) {
						continue;
					}
					else {
						apartmentsResult[j] = apartmentTemp[i];
						j++;
					}
				}
			}
		}
	}

	delete[] apartmentTemp;
	apartmentTemp = nullptr;
	return apartmentsResult;
}

Apartment* searchInInterval(Apartment* apartments, Apartment* apartmentsResult, int size, int numberOfRooms, int intervalLow, int intervalUp)
{
	Apartment* apartmentTemp = nullptr;
	int counter = 0;

	if (allocateArray(&apartmentTemp, size) == false) {
		return apartmentsResult;
	}

	for (int i = 0; i < size; i++) {
		if (numberOfRooms == apartments[i].getNumberOfRooms() && apartments[i].getFloor() >= intervalLow && apartments[i].getFloor() <= intervalUp) {
			counter++;
			apartmentTemp[i] = apartments[i];
		}
	}
	apartmentTemp->cleanCounter();

	int j = 0;
	if (counter == 0) {
		delete[] apartmentTemp;
		apartmentTemp = nullptr;
		apartmentsResult = nullptr;
		return apartmentsResult;
	}
	else {
		if (allocateArray(&apartmentsResult, counter) == false) {
			return apartmentsResult;
		}
		else {
			for (int i = 0; i < size; i++) {
				if (j < counter) {
					if (numberOfRooms == apartments[i].getNumberOfRooms() && apartments[i].getFloor() >= intervalLow && apartments[i].getFloor() <= intervalUp) {
						apartmentsResult[j] = apartmentTemp[i];
						j++;
					}
					else {
						continue;
					}
				}
			}
		}
	}

	delete[] apartmentTemp;
	apartmentTemp = nullptr;
	return apartmentsResult;
}

Apartment* searchBySquare(Apartment* apartments, Apartment* apartmentsResult, int size, double square) {
	Apartment* apartmentTemp = nullptr;
	int counter = 0;

	if (allocateArray(&apartmentTemp, size) == false) {
		return apartmentsResult;
	}

	for (int i = 0; i < size; i++) {
		if (apartments[i].getSquare() > square) {
			counter++;
			apartmentTemp[i] = apartments[i];
		}
	}

	apartmentTemp->cleanCounter();

	int j = 0;
	if (counter == 0) {
		delete[] apartmentTemp;
		apartmentTemp = nullptr;
		apartmentsResult = nullptr;
		return apartmentsResult;
	}
	else {
		if (allocateArray(&apartmentsResult, counter) == false) {
			return apartmentsResult;
		}
		else {
			for (int i = 0; i < size; i++) {
				if (j < counter) {
					if (apartmentTemp[i].getSquare() < square) {
						continue;
					}
					else {
						apartmentsResult[j] = apartmentTemp[i];
						j++;
					}
				}
			}
		}
	}

	delete[] apartmentTemp;
	apartmentTemp = nullptr;
	return apartmentsResult;
}