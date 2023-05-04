#include <iostream>
#include "inputValidation.h"
#include "enum.h"

using namespace std;

template<typename T>

T getInput() {
    while (true)
    {
        T userInput = 0;
        cin >> userInput;

        if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            cout << "Попробуйте еще раз!" << endl;
            cout << "> ";
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else {
            return userInput;
        }
    }
}


int getInt() {
	return getInput<int>();
}

double getDouble() {
    return getInput<double>();
}

MENU_ITEM getMenuVariant() {
	return static_cast<MENU_ITEM>(getInt());
}

CHOICE getChoice() {
    return static_cast<CHOICE>(getInt());
}


SECOND_CHOICE getSecondChoice()
{
    return static_cast<SECOND_CHOICE>(getInt());
}

int getSize(const char* message)
{
    int size = 0;

    do {
        std::cout << message;
        size = getInt();
        if (size <= 0) {
            std::cout << "Ошибка. Размер списка квартир не может быть равен или меньше 0." << std::endl;
        }
    } while (size <= 0);
    return size;
}

template<typename P>

P getPositiveInput() {
    while (true)
    {
        P userInput = 0;
        cin >> userInput;

        if (cin.fail() || userInput <= 0) {
            cout << "Попробуйте еще раз! Введите положительное число больше нуля." << endl;
            cout << "> ";
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else {
            return userInput;
        }
    }
}

int getPositiveInt() {
    return getPositiveInput<int>();
}

double getPositiveDouble() {
    return getPositiveInput<double>();
}