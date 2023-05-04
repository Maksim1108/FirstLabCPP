#include <iostream>
#include <string>
#include <filesystem>

#include "enum.h"
#include "interface.h"
#include "apartment.h"
#include "inputValidation.h"
#include "fileWork.h"
#include "algorithms.h"
#include "tests.h"


using namespace std; 

int main() {
    setlocale(LC_ALL, "Russian");

    Apartment* apartments = nullptr;
    Apartment* apartmentsResult = nullptr;

    int size = 0;
    int intervalLow = 0;
    int intervalUp = 0;
    int counter = 0;

    int numberOfRooms;
    double square;

    MENU_ITEM userMenuChoice = static_cast<MENU_ITEM>(0);
    SECOND_CHOICE userSecondChoice = static_cast<SECOND_CHOICE>(0);

    showInfo();

    do {

        string filePath;

        showMenu();
        cout << "> ";
        userMenuChoice = getMenuVariant();

        switch (userMenuChoice) {
        case MENU_ITEM::BY_ROOMS:
            if (!apartments) {
                cout << "\n������ ������� ����." << endl;
                break;
            }
            else {
                cout << "\n����� �������� �� ���������� ������." << endl;
                cout << "\n������� ����� ������: ";
                cin >> numberOfRooms;

                counter = getCountApartmentsForNumbersOfRooms(apartments, size, numberOfRooms);
                apartmentsResult = searchByNumbersOfRooms(apartments, apartmentsResult, size, numberOfRooms);

                CHOICE userChoice = static_cast<CHOICE>(0);

                if (apartmentsResult) {
                    bool isDataSaved = false;
                    cout << "���������� � ��������� � " << numberOfRooms << " ������" << endl;
                    showApartments(apartmentsResult, counter);

                    apartmentsResult->cleanCounter();
                    do
                    {
                        cout << endl << "��������� � ����?" << endl;
                        showChoice();
                        userChoice = getChoice();

                        switch (userChoice) {

                        case CHOICE::YES:
                            saveByNumbersOfRooms(apartmentsResult, counter, numberOfRooms);
                            isDataSaved = true;
                            break;

                        case CHOICE::NO:
                            cout << endl << "�� ������ �� ��������� ������ � ����.\n" << endl;
                            isDataSaved = true;
                            break;

                        default:
                            cout << "������������ ����, ���������� �����." << endl;
                            break;
                        }
                    } while (userChoice != CHOICE::NO && isDataSaved == false);
                }
                else
                {
                    cout << "\n��� ����� ������� � ������ ����������� ������.\n" << endl;
                }

                clearData(apartmentsResult);
            }
            break;

        case MENU_ITEM::BY_ROOMS_AND_FLOOR:
            if (!apartments) {
                cout << "\n������ ������� ����." << endl << endl;
                break;
            }
            else {
                cout << "\n����� �������� � ���������" << endl;
                do
                {
                    cout << "������� ������ ������ ���������: ";
                    intervalLow = getPositiveInt();
                    cout << "������� ������� ������ ���������: ";
                    intervalUp = getPositiveInt();
                    cout << "������� ���������� ������: ";
                    numberOfRooms = getPositiveInt();

                    if (intervalLow > intervalUp) {
                        cout << "������ ������� ��������� �� ����� ���� ������ �������. ���������� �����." << endl << endl;
                    }

                    if (intervalUp > size) {
                        cout << "������� ������� ��������� �� ����� ���� ������ " << size << "." << endl << endl;
                    }

                } while (intervalLow > intervalUp || intervalUp > size);

                counter = getCountApartmentsForNumbersOfRoomsAndInterval(apartments, size, numberOfRooms, intervalLow, intervalUp);
                apartmentsResult = searchInInterval(apartments, apartmentsResult, size, numberOfRooms, intervalLow, intervalUp);

                CHOICE userChoice = static_cast<CHOICE>(0);

                if (apartmentsResult) {
                    bool isDataSaved = false;
                    cout << "���������� � ��������� � ��������� �� " << intervalLow << " �� " << intervalUp << endl;
                    cout << "���������� ������ � ��������: " << numberOfRooms << endl;
                    showApartments(apartmentsResult, counter);

                    apartmentsResult->cleanCounter();
                    do
                    {
                        cout << endl << "��������� � ����?" << endl;
                        showChoice();
                        userChoice = getChoice();

                        switch (userChoice) {
                        case CHOICE::YES:
                            saveByNumbersOfRoomsAndInterval(apartmentsResult, counter, numberOfRooms, intervalLow, intervalUp);
                            isDataSaved = true;
                            break;

                        case CHOICE::NO:
                            cout << endl << "�� ������ �� ��������� ������ � ����." << endl;
                            isDataSaved = true;
                            break;

                        default:
                            cout << "������������ ����, ���������� �����." << endl << endl;
                            break;
                        }
                    } while (userChoice != CHOICE::NO && isDataSaved == false);
                }
                else
                {
                    cout << "\n� ������ ��������� ��� �������.\n" << endl;
                }

                clearData(apartmentsResult);
            }
            break;

        case MENU_ITEM::BY_SQUARE:
            if (!apartments) {
                cout << "\n������ ������� ����." << endl << endl;
                break;
            }
            else {

                cout << "������� ������� ��������: " << endl;
                square = getPositiveDouble();


                counter = getCountApartmentsForSquare(apartments, size, square);
                apartmentsResult = searchBySquare(apartments, apartmentsResult, size, square);

                CHOICE userChoice = static_cast<CHOICE>(0);

                if (apartmentsResult) {
                    bool isDataSaved = false;
                    cout << "���������� � ��������� � " << square << " + ��������." << endl;

                    showApartments(apartmentsResult, counter);

                    apartmentsResult->cleanCounter();

                    do {
                        cout << "��������� ������ � ���� ?" << endl;
                        showChoice();
                        userChoice = getChoice();
                        switch (userChoice) {
                        case CHOICE::YES:
                            saveBySquare(apartmentsResult, counter, square);
                            isDataSaved = true;
                            break;
                        case CHOICE::NO:
                            cout << endl << "�� ������ �� ��������� ������ � ����." << endl;
                            isDataSaved = true;
                            break;
                        default:
                            cout << "������������ ����, ���������� �����." << endl << endl;
                            break;
                        }

                    } while (isDataSaved == false && userChoice != CHOICE::NO);
                }
                else {
                    cout << "������� � ����� �������� ��� � ������!" << endl;
                }
                clearData(apartmentsResult);
            }
            break;


        case MENU_ITEM::EDIT: {
            if (apartments) {
                cout << "\n[!] � ��� ��� ���� ����������� ������ �������." << endl << endl;
                cout << "�� ������ ������� ����� ���� �������." << endl;
                cout << "������� ����� � ������� ������ ������?" << endl << endl;
            }
            else
            {
                cout << "\n�� ������ ������� ����� ���� �������." << endl;
                cout << "������� ����� ����?" << endl;
            }

            CHOICE userChoice = static_cast<CHOICE>(0);
            showChoice();
            userChoice = getChoice();

            switch (userChoice) {
            case CHOICE::YES: {
                bool isDataLoaded = false;
                if (apartments) { // STR: ������� - ������� - ������� - ����� - �������
                    clearData(apartments);
                    clearData(apartmentsResult);
                    cout << "������� ������ �������." << endl;
                }
                do {
                    cout << "��������� ������ �� �����?" << endl;
                    showChoice();
                    userSecondChoice = getSecondChoice();

                    switch (userSecondChoice) {
                    case SECOND_CHOICE::YES: {
                        std::cout << "��������� ��: ";
                        cin >> filePath;

                        filePath = filePath + ".txt";

                        if (isFileCorrect(filePath) == false) {
                            continue;
                        }

                        else {
                            std::ifstream file(filePath);
                            size = getSizeFromFile(size, file);

                            if (size <= 0)
                            {
                                break;
                            }

                            file.ignore();

                            apartments = uploadFromFile(apartments, size, file);

                            file.close();
                        }
                        apartments->cleanCounter();
                        isDataLoaded = true;
                        std::cout << std::endl;
                        break;
                    }

                    case SECOND_CHOICE::NO:
                        cout << "\n�� ������ ��������� ������ � ��������� ��������������." << endl;
                        size = getSize("������� ���������� �������: ");
                        cout << endl;

                        if (allocateArray(&apartments, size) == false) {
                            break;
                        }

                        fillApartments(apartments, size);

                        apartments->cleanCounter();
                        break;
                    }
                } while ((userSecondChoice != SECOND_CHOICE::NO || userSecondChoice >= static_cast<SECOND_CHOICE>(3)) && isDataLoaded == false);
                break;
            }
            case CHOICE::NO:
                cout << "\n�� ������ �� ��������� ��������.\n" << endl;
                break;

            default:
                cout << "\n������������ ����, ���������� �����.\n" << endl;
                cout << ">" << endl;
                break;
            }
            break;
        }
        case MENU_ITEM::SHOW:
            if (!apartments) {
                cout << "\n[!]������ ������� ����\n" << endl;
                break;
            }
            else {
                cout << "\n[���������� � ���������]" << endl;
                showApartments(apartments, size);

                bool isDataSaved = false;
                CHOICE userChoice = static_cast<CHOICE>(0);

                do
                {
                    cout << "��������� ������ � ����?" << endl;
                    showChoice();
                    userChoice = getChoice();

                    switch (userChoice) {
                    case CHOICE::YES:
                        saveInFile(apartments, size);
                        isDataSaved = true;
                        break;

                    case CHOICE::NO:
                        cout << "�� ������ �� ��������� ������ � ����." << endl;
                        isDataSaved = true;
                        break;

                    default:
                        cout << "������������ ����, ���������� �����." << endl;
                        break;
                    }
                } while (isDataSaved == false && userChoice != CHOICE::NO);
            }
            break;

        case MENU_ITEM::TEST:
            Tests test;
            test.runAllTests();
            break;

        case MENU_ITEM::QUIT:
            cout << "����� �� ���������.";
            break;

        default:
            cout << "������������ ����. ���������� �����." << endl;
            break;
        }
    } while (userMenuChoice != MENU_ITEM::QUIT);
    return EXIT_SUCCESS;
}