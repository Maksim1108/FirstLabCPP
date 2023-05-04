#include "tests.h"
#include "apartment.h"
#include "algorithms.h"

bool Tests::testCase1() {
	const int SIZE = 2;
	const int ANSWER = 1;

	Apartment* apartments = nullptr;
	int numbersOfRooms = 2;
	int secondNumbersOfRooms = 3;

	if (allocateArray(&apartments, SIZE) == false) {
		cout << "Тест №1 провален. Ошибка выделения памяти №1" << endl;
		return false;
	}

	apartments[0].setNumberOfRooms(numbersOfRooms);
	apartments[1].setNumberOfRooms(secondNumbersOfRooms);

	for (int i = 1; i <= SIZE; i++)
	{
		apartments[i - 1].setId(i);
	}

	Apartment* apartmentsResult = nullptr;

	int countApartments = getCountApartmentsForNumbersOfRooms(apartments, SIZE, numbersOfRooms);
	apartments->cleanCounter();

	if (allocateArray(&apartmentsResult, countApartments) == false) {
		cout << "Тест №1 провален. Ошибка выделения памяти №2" << endl;
		return false;
	}

	apartmentsResult = searchByNumbersOfRooms(apartments, apartmentsResult, SIZE, numbersOfRooms);
	apartmentsResult->cleanCounter();

	if (countApartments == ANSWER) {
		if (apartmentsResult[0].getNumberOfRooms() == numbersOfRooms) {
			cout << "\nТест №1 пройден" << endl;
			return true;
		}
		else {
			cout << "Тест №1 провален." << endl;
			cout << "Ожидалось: " << ANSWER << " квартира с " << numbersOfRooms << "комнат." << endl;
			cout << "Получено: " << countApartments << " квартир с: " << apartmentsResult[0].getNumberOfRooms() << endl;
			return false;
		}
	}
	else {
		cout << "Тест №1 провален." << endl;
		cout << "Ожидалось: количество квартир = " << ANSWER << endl;
		cout << "Получено: количество квартир = " << countApartments << endl << endl;
		return false;
	}

	return false;
}

bool Tests::testCase2() {
	const int SIZE = 3;
	const int ANSWER = 2;

	Apartment* apartments = nullptr;
	int numbersOfRooms = 2;
	int secondNumbersOfRooms = 3;

	if (allocateArray(&apartments, SIZE) == false) {
		cout << "Тест №2 провален. Ошибка выделения памяти №1" << endl;
		return false;
	}

	apartments[0].setNumberOfRooms(numbersOfRooms);
	apartments[1].setNumberOfRooms(secondNumbersOfRooms);
	apartments[2].setNumberOfRooms(numbersOfRooms);

	for (int i = 1; i <= SIZE; i++)
	{
		apartments[i - 1].setId(i);
	}

	Apartment* apartmentsResult = nullptr;

	int countApartments = getCountApartmentsForNumbersOfRooms(apartments, SIZE, numbersOfRooms);
	apartments->cleanCounter();

	if (allocateArray(&apartmentsResult, countApartments) == false) {
		cout << "Тест №2 провален. Ошибка выделения памяти №2" << endl;
		return false;
	}

	apartmentsResult = searchByNumbersOfRooms(apartments, apartmentsResult, SIZE, numbersOfRooms);
	apartmentsResult->cleanCounter();

	if (countApartments == ANSWER) {
		if (apartmentsResult[0].getNumberOfRooms() == numbersOfRooms && apartmentsResult[1].getNumberOfRooms() == numbersOfRooms) {
			cout << "Тест №2 пройден" << endl;
			return true;
		}
		else {
			cout << "Тест №2 провален." << endl;
			cout << "Ожидалось: " << ANSWER << " квартиры с " << numbersOfRooms << " и " << secondNumbersOfRooms << "комнат." << endl;
			cout << "Получено: " << countApartments << " квартир с" << apartmentsResult[0].getNumberOfRooms() << endl;
			return false;
		}
	}
	else {
		cout << "Тест №2 провален." << endl;
		cout << "Ожидалось: количество квартир = " << ANSWER << endl;
		cout << "Получено: количество квартир = " << countApartments << endl << endl;
		return false;
	}

	return false;
}

bool Tests::testCase3() {
	const int SIZE = 1;
	const int ANSWER = 1;

	int intervalLow = 1;
	int intervalUp = 3;
	int numbersOfRooms = 2;
	int floorTwo = 2;

	Apartment* apartments = nullptr;

	if (allocateArray(&apartments, SIZE) == false) {
		cout << "Тест 3 провален. Ошибка выделения памяти №1" << endl;
		return false;
	}

	apartments[0].setFloor(floorTwo);
	apartments[0].setNumberOfRooms(numbersOfRooms);

	Apartment* apartmentsResult = nullptr;

	int countApartments = getCountApartmentsForNumbersOfRoomsAndInterval(apartments, SIZE, numbersOfRooms, intervalLow, intervalUp);
	apartments->cleanCounter();

	if (allocateArray(&apartmentsResult, countApartments) == false) {
		cout << "Тест 3 провален. Ошибка выделения памяти №2" << endl;
		return false;
	}

	apartmentsResult = searchInInterval(apartments, apartmentsResult, SIZE, numbersOfRooms, intervalLow, intervalUp);
	apartmentsResult->cleanCounter();

	if (countApartments == ANSWER) {
		if (apartmentsResult[0].getNumberOfRooms() == numbersOfRooms && apartments[0].getFloor() >= intervalLow && apartments[0].getFloor() <= intervalUp) {
			cout << "Тест №3 пройден" << endl;
			return true;
		}
		else {
			std::cout << "Тест 3 провален." << std::endl;
			std::cout << "Ожидалось: " << ANSWER << " квартира в интервале " << intervalLow << "-" << intervalUp << "." << std::endl;
			cout << "Количество комнат в квартире: " << numbersOfRooms << endl;
			std::cout << "Получено: " << countApartments << " : " << apartmentsResult[0].getId() << std::endl;
			return false;
		}
	}
	else {
		std::cout << "Тест 3 провален." << std::endl;
		std::cout << "Ожидалось: количество квартир = " << ANSWER << std::endl;
		std::cout << "Получено: количество квартир = " << countApartments << std::endl << std::endl;
		return false;
	}

	return false;
}

bool Tests::testCase4() {
	const int SIZE = 2;
	const int ANSWER = 1;
	const double SQUARE = 30.0;

	Apartment* apartments = nullptr;
	double firstSquare = 25.5;
	double secondSquare = 45.5;

	if (allocateArray(&apartments, SIZE) == false) {
		cout << "Тест №4 провален. Ошибка выделения памяти №1" << endl;
		return false;
	}

	apartments[0].setSquare(firstSquare);
	apartments[1].setSquare(secondSquare);

	Apartment* apartmentsResult = nullptr;

	int countApartments = getCountApartmentsForSquare(apartments, SIZE, SQUARE);
	apartments->cleanCounter();

	if (allocateArray(&apartmentsResult, countApartments) == false) {
		cout << "Тест 4 провален. Ошибка выделения памяти №2" << endl;
		return false;
	}

	apartmentsResult = searchBySquare(apartments, apartmentsResult, SIZE, SQUARE);
	apartmentsResult->cleanCounter();

	if (countApartments == ANSWER) {
		if (apartments[1].getSquare() > SQUARE) {
			cout << "Тест №4 пройден" << endl;
			return true;
		}
		else {
			std::cout << "Тест 4 провален." << std::endl;
			std::cout << "Ожидалось: " << ANSWER << "квартира с площадью больше" << SQUARE << std::endl;
			std::cout << "Получено: " << countApartments << " : " << apartmentsResult[0].getSquare() << std::endl;
			return false;
		}
	}
	else {
		std::cout << "Тест 4 провален." << std::endl;
		std::cout << "Ожидалось: количество квартир = " << ANSWER << std::endl;
		std::cout << "Получено: количество квартир = " << countApartments << std::endl << std::endl;
		return false;
	}

	return false;
}

bool Tests::testCase5() {
	const int SIZE = 3;
	const int ANSWER = 2;
	const double SQUARE = 30.0;

	Apartment* apartments = nullptr;
	double firstSquare = 25.5;
	double secondSquare = 45.5;
	double thirdSquare = 31.5;

	if (allocateArray(&apartments, SIZE) == false) {
		cout << "Тест №5 провален. Ошибка выделения памяти №1" << endl;
		return false;
	}

	apartments[0].setSquare(firstSquare);
	apartments[1].setSquare(secondSquare);
	apartments[2].setSquare(thirdSquare);

	Apartment* apartmentsResult = nullptr;

	int countApartments = getCountApartmentsForSquare(apartments, SIZE, SQUARE);
	apartments->cleanCounter();

	if (allocateArray(&apartmentsResult, countApartments) == false) {
		cout << "Тест 5 провален. Ошибка выделения памяти №2" << endl;
		return false;
	}

	apartmentsResult = searchBySquare(apartments, apartmentsResult, SIZE, SQUARE);
	apartmentsResult->cleanCounter();

	if (countApartments == ANSWER) {
		if (apartmentsResult[0].getSquare() > SQUARE && apartmentsResult[1].getSquare() > SQUARE) {
			cout << "Тест №5 пройден" << endl;
			return true;
		}
		else {
			std::cout << "Тест 5 провален." << std::endl;
			std::cout << "Ожидалось: " << ANSWER << "площадью больше" << SQUARE << std::endl;
			std::cout << "Получено: " << countApartments << " : " << apartmentsResult[0].getSquare() << std::endl;
			return false;
		}
	}
	else {
		std::cout << "Тест 5 провален." << std::endl;
		std::cout << "Ожидалось: количество квартир = " << ANSWER << std::endl;
		std::cout << "Получено: количество квартир = " << countApartments << std::endl << std::endl;
		return false;
	}

	return false;
}

void Tests::runAllTests()
{
	Tests test;

	if (test.testCase1() && test.testCase2() && test.testCase3() && test.testCase4() && test.testCase5())
	{
		std::cout << "\nВсе модульные тесты пройдены!\n" << std::endl;
	}
	else
	{
		std::cout << "\nМодульные тесты не пройдены.\n" << std::endl;
	}
}