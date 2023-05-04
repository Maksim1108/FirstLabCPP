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
		cout << "���� �1 ��������. ������ ��������� ������ �1" << endl;
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
		cout << "���� �1 ��������. ������ ��������� ������ �2" << endl;
		return false;
	}

	apartmentsResult = searchByNumbersOfRooms(apartments, apartmentsResult, SIZE, numbersOfRooms);
	apartmentsResult->cleanCounter();

	if (countApartments == ANSWER) {
		if (apartmentsResult[0].getNumberOfRooms() == numbersOfRooms) {
			cout << "\n���� �1 �������" << endl;
			return true;
		}
		else {
			cout << "���� �1 ��������." << endl;
			cout << "���������: " << ANSWER << " �������� � " << numbersOfRooms << "������." << endl;
			cout << "��������: " << countApartments << " ������� �: " << apartmentsResult[0].getNumberOfRooms() << endl;
			return false;
		}
	}
	else {
		cout << "���� �1 ��������." << endl;
		cout << "���������: ���������� ������� = " << ANSWER << endl;
		cout << "��������: ���������� ������� = " << countApartments << endl << endl;
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
		cout << "���� �2 ��������. ������ ��������� ������ �1" << endl;
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
		cout << "���� �2 ��������. ������ ��������� ������ �2" << endl;
		return false;
	}

	apartmentsResult = searchByNumbersOfRooms(apartments, apartmentsResult, SIZE, numbersOfRooms);
	apartmentsResult->cleanCounter();

	if (countApartments == ANSWER) {
		if (apartmentsResult[0].getNumberOfRooms() == numbersOfRooms && apartmentsResult[1].getNumberOfRooms() == numbersOfRooms) {
			cout << "���� �2 �������" << endl;
			return true;
		}
		else {
			cout << "���� �2 ��������." << endl;
			cout << "���������: " << ANSWER << " �������� � " << numbersOfRooms << " � " << secondNumbersOfRooms << "������." << endl;
			cout << "��������: " << countApartments << " ������� �" << apartmentsResult[0].getNumberOfRooms() << endl;
			return false;
		}
	}
	else {
		cout << "���� �2 ��������." << endl;
		cout << "���������: ���������� ������� = " << ANSWER << endl;
		cout << "��������: ���������� ������� = " << countApartments << endl << endl;
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
		cout << "���� 3 ��������. ������ ��������� ������ �1" << endl;
		return false;
	}

	apartments[0].setFloor(floorTwo);
	apartments[0].setNumberOfRooms(numbersOfRooms);

	Apartment* apartmentsResult = nullptr;

	int countApartments = getCountApartmentsForNumbersOfRoomsAndInterval(apartments, SIZE, numbersOfRooms, intervalLow, intervalUp);
	apartments->cleanCounter();

	if (allocateArray(&apartmentsResult, countApartments) == false) {
		cout << "���� 3 ��������. ������ ��������� ������ �2" << endl;
		return false;
	}

	apartmentsResult = searchInInterval(apartments, apartmentsResult, SIZE, numbersOfRooms, intervalLow, intervalUp);
	apartmentsResult->cleanCounter();

	if (countApartments == ANSWER) {
		if (apartmentsResult[0].getNumberOfRooms() == numbersOfRooms && apartments[0].getFloor() >= intervalLow && apartments[0].getFloor() <= intervalUp) {
			cout << "���� �3 �������" << endl;
			return true;
		}
		else {
			std::cout << "���� 3 ��������." << std::endl;
			std::cout << "���������: " << ANSWER << " �������� � ��������� " << intervalLow << "-" << intervalUp << "." << std::endl;
			cout << "���������� ������ � ��������: " << numbersOfRooms << endl;
			std::cout << "��������: " << countApartments << " : " << apartmentsResult[0].getId() << std::endl;
			return false;
		}
	}
	else {
		std::cout << "���� 3 ��������." << std::endl;
		std::cout << "���������: ���������� ������� = " << ANSWER << std::endl;
		std::cout << "��������: ���������� ������� = " << countApartments << std::endl << std::endl;
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
		cout << "���� �4 ��������. ������ ��������� ������ �1" << endl;
		return false;
	}

	apartments[0].setSquare(firstSquare);
	apartments[1].setSquare(secondSquare);

	Apartment* apartmentsResult = nullptr;

	int countApartments = getCountApartmentsForSquare(apartments, SIZE, SQUARE);
	apartments->cleanCounter();

	if (allocateArray(&apartmentsResult, countApartments) == false) {
		cout << "���� 4 ��������. ������ ��������� ������ �2" << endl;
		return false;
	}

	apartmentsResult = searchBySquare(apartments, apartmentsResult, SIZE, SQUARE);
	apartmentsResult->cleanCounter();

	if (countApartments == ANSWER) {
		if (apartments[1].getSquare() > SQUARE) {
			cout << "���� �4 �������" << endl;
			return true;
		}
		else {
			std::cout << "���� 4 ��������." << std::endl;
			std::cout << "���������: " << ANSWER << "�������� � �������� ������" << SQUARE << std::endl;
			std::cout << "��������: " << countApartments << " : " << apartmentsResult[0].getSquare() << std::endl;
			return false;
		}
	}
	else {
		std::cout << "���� 4 ��������." << std::endl;
		std::cout << "���������: ���������� ������� = " << ANSWER << std::endl;
		std::cout << "��������: ���������� ������� = " << countApartments << std::endl << std::endl;
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
		cout << "���� �5 ��������. ������ ��������� ������ �1" << endl;
		return false;
	}

	apartments[0].setSquare(firstSquare);
	apartments[1].setSquare(secondSquare);
	apartments[2].setSquare(thirdSquare);

	Apartment* apartmentsResult = nullptr;

	int countApartments = getCountApartmentsForSquare(apartments, SIZE, SQUARE);
	apartments->cleanCounter();

	if (allocateArray(&apartmentsResult, countApartments) == false) {
		cout << "���� 5 ��������. ������ ��������� ������ �2" << endl;
		return false;
	}

	apartmentsResult = searchBySquare(apartments, apartmentsResult, SIZE, SQUARE);
	apartmentsResult->cleanCounter();

	if (countApartments == ANSWER) {
		if (apartmentsResult[0].getSquare() > SQUARE && apartmentsResult[1].getSquare() > SQUARE) {
			cout << "���� �5 �������" << endl;
			return true;
		}
		else {
			std::cout << "���� 5 ��������." << std::endl;
			std::cout << "���������: " << ANSWER << "�������� ������" << SQUARE << std::endl;
			std::cout << "��������: " << countApartments << " : " << apartmentsResult[0].getSquare() << std::endl;
			return false;
		}
	}
	else {
		std::cout << "���� 5 ��������." << std::endl;
		std::cout << "���������: ���������� ������� = " << ANSWER << std::endl;
		std::cout << "��������: ���������� ������� = " << countApartments << std::endl << std::endl;
		return false;
	}

	return false;
}

void Tests::runAllTests()
{
	Tests test;

	if (test.testCase1() && test.testCase2() && test.testCase3() && test.testCase4() && test.testCase5())
	{
		std::cout << "\n��� ��������� ����� ��������!\n" << std::endl;
	}
	else
	{
		std::cout << "\n��������� ����� �� ��������.\n" << std::endl;
	}
}