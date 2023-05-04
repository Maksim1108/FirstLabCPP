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
                cout << "\nСписок квартир пуст." << endl;
                break;
            }
            else {
                cout << "\nНайти квартиры по количеству комнат." << endl;
                cout << "\nВведите число комнат: ";
                cin >> numberOfRooms;

                counter = getCountApartmentsForNumbersOfRooms(apartments, size, numberOfRooms);
                apartmentsResult = searchByNumbersOfRooms(apartments, apartmentsResult, size, numberOfRooms);

                CHOICE userChoice = static_cast<CHOICE>(0);

                if (apartmentsResult) {
                    bool isDataSaved = false;
                    cout << "Информация о квартирах с " << numberOfRooms << " комнат" << endl;
                    showApartments(apartmentsResult, counter);

                    apartmentsResult->cleanCounter();
                    do
                    {
                        cout << endl << "Сохранить в файл?" << endl;
                        showChoice();
                        userChoice = getChoice();

                        switch (userChoice) {

                        case CHOICE::YES:
                            saveByNumbersOfRooms(apartmentsResult, counter, numberOfRooms);
                            isDataSaved = true;
                            break;

                        case CHOICE::NO:
                            cout << endl << "Вы решили не сохранять данные в файл.\n" << endl;
                            isDataSaved = true;
                            break;

                        default:
                            cout << "Неправильный ввод, попробуйте снова." << endl;
                            break;
                        }
                    } while (userChoice != CHOICE::NO && isDataSaved == false);
                }
                else
                {
                    cout << "\nНет таких квартир с данным количеством комнат.\n" << endl;
                }

                clearData(apartmentsResult);
            }
            break;

        case MENU_ITEM::BY_ROOMS_AND_FLOOR:
            if (!apartments) {
                cout << "\nСписок квартир пуст." << endl << endl;
                break;
            }
            else {
                cout << "\nНайти квартиры в интервале" << endl;
                do
                {
                    cout << "Введите нижний предел интервала: ";
                    intervalLow = getPositiveInt();
                    cout << "Введите верхний предел интервала: ";
                    intervalUp = getPositiveInt();
                    cout << "Введите количество комнат: ";
                    numberOfRooms = getPositiveInt();

                    if (intervalLow > intervalUp) {
                        cout << "Нижняя граница интервала не может быть больше верхней. Попробуйте снова." << endl << endl;
                    }

                    if (intervalUp > size) {
                        cout << "Верхняя граница интервала не может быть больше " << size << "." << endl << endl;
                    }

                } while (intervalLow > intervalUp || intervalUp > size);

                counter = getCountApartmentsForNumbersOfRoomsAndInterval(apartments, size, numberOfRooms, intervalLow, intervalUp);
                apartmentsResult = searchInInterval(apartments, apartmentsResult, size, numberOfRooms, intervalLow, intervalUp);

                CHOICE userChoice = static_cast<CHOICE>(0);

                if (apartmentsResult) {
                    bool isDataSaved = false;
                    cout << "Информация о квартирах в интервале от " << intervalLow << " до " << intervalUp << endl;
                    cout << "Количество комнат в квартире: " << numberOfRooms << endl;
                    showApartments(apartmentsResult, counter);

                    apartmentsResult->cleanCounter();
                    do
                    {
                        cout << endl << "Сохранить в файл?" << endl;
                        showChoice();
                        userChoice = getChoice();

                        switch (userChoice) {
                        case CHOICE::YES:
                            saveByNumbersOfRoomsAndInterval(apartmentsResult, counter, numberOfRooms, intervalLow, intervalUp);
                            isDataSaved = true;
                            break;

                        case CHOICE::NO:
                            cout << endl << "Вы решили не сохранять данные в файл." << endl;
                            isDataSaved = true;
                            break;

                        default:
                            cout << "Неправильный ввод, попробуйте снова." << endl << endl;
                            break;
                        }
                    } while (userChoice != CHOICE::NO && isDataSaved == false);
                }
                else
                {
                    cout << "\nВ данном интервале нет квартир.\n" << endl;
                }

                clearData(apartmentsResult);
            }
            break;

        case MENU_ITEM::BY_SQUARE:
            if (!apartments) {
                cout << "\nСписок квартир пуст." << endl << endl;
                break;
            }
            else {

                cout << "Введите площадь квартиры: " << endl;
                square = getPositiveDouble();


                counter = getCountApartmentsForSquare(apartments, size, square);
                apartmentsResult = searchBySquare(apartments, apartmentsResult, size, square);

                CHOICE userChoice = static_cast<CHOICE>(0);

                if (apartmentsResult) {
                    bool isDataSaved = false;
                    cout << "Информация о квартирах с " << square << " + площадью." << endl;

                    showApartments(apartmentsResult, counter);

                    apartmentsResult->cleanCounter();

                    do {
                        cout << "Сохранить данные в файл ?" << endl;
                        showChoice();
                        userChoice = getChoice();
                        switch (userChoice) {
                        case CHOICE::YES:
                            saveBySquare(apartmentsResult, counter, square);
                            isDataSaved = true;
                            break;
                        case CHOICE::NO:
                            cout << endl << "Вы решили не сохранять данные в файл." << endl;
                            isDataSaved = true;
                            break;
                        default:
                            cout << "Неправильный ввод, попробуйте снова." << endl << endl;
                            break;
                        }

                    } while (isDataSaved == false && userChoice != CHOICE::NO);
                }
                else {
                    cout << "Квартир с такой площадью нет в списке!" << endl;
                }
                clearData(apartmentsResult);
            }
            break;


        case MENU_ITEM::EDIT: {
            if (apartments) {
                cout << "\n[!] У вас уже есть заполненный список квартир." << endl << endl;
                cout << "Вы можете создать новый лист квартир." << endl;
                cout << "Создать новый и удалить старые данные?" << endl << endl;
            }
            else
            {
                cout << "\nВы можете создать новый лист квартир." << endl;
                cout << "Создать новый лист?" << endl;
            }

            CHOICE userChoice = static_cast<CHOICE>(0);
            showChoice();
            userChoice = getChoice();

            switch (userChoice) {
            case CHOICE::YES: {
                bool isDataLoaded = false;
                if (apartments) { // STR: Создать - Удалить - Создать - Поиск - Удалить
                    clearData(apartments);
                    clearData(apartmentsResult);
                    cout << "Прошлые данные удалены." << endl;
                }
                do {
                    cout << "Загрузить данные из файла?" << endl;
                    showChoice();
                    userSecondChoice = getSecondChoice();

                    switch (userSecondChoice) {
                    case SECOND_CHOICE::YES: {
                        std::cout << "Загрузить из: ";
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
                        cout << "\nВы решили заполнить данные о квартирах самостоятельно." << endl;
                        size = getSize("Введите количество квартир: ");
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
                cout << "\nВы решили не добавлять квартиры.\n" << endl;
                break;

            default:
                cout << "\nНеправильный ввод, попробуйте снова.\n" << endl;
                cout << ">" << endl;
                break;
            }
            break;
        }
        case MENU_ITEM::SHOW:
            if (!apartments) {
                cout << "\n[!]Список квартир пуст\n" << endl;
                break;
            }
            else {
                cout << "\n[Информация о квартирах]" << endl;
                showApartments(apartments, size);

                bool isDataSaved = false;
                CHOICE userChoice = static_cast<CHOICE>(0);

                do
                {
                    cout << "Сохранить данные в файл?" << endl;
                    showChoice();
                    userChoice = getChoice();

                    switch (userChoice) {
                    case CHOICE::YES:
                        saveInFile(apartments, size);
                        isDataSaved = true;
                        break;

                    case CHOICE::NO:
                        cout << "Вы решили не сохранять данные в файл." << endl;
                        isDataSaved = true;
                        break;

                    default:
                        cout << "Неправильный ввод, попробуйте снова." << endl;
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
            cout << "Выход из программы.";
            break;

        default:
            cout << "Неправильный ввод. Попробуйте снова." << endl;
            break;
        }
    } while (userMenuChoice != MENU_ITEM::QUIT);
    return EXIT_SUCCESS;
}