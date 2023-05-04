#pragma once

#include "Apartment.h"
#include <fstream>

bool saveInFile(Apartment* apartments, int size);
bool saveByNumbersOfRooms(Apartment* aprtmentsResult, int size, int numberOfRooms);
bool saveByNumbersOfRoomsAndInterval(Apartment* aprtmentsResult, int size, int numberOfRooms, int intervalLow, int intervalUp);
bool saveBySquare(Apartment* aprtmentsResult, int size, double square);
Apartment* uploadFromFile(Apartment* apartments, int size, std::ifstream& file);
int getSizeFromFile(int size, std::ifstream& file);
bool isFileCorrect(std::string filePath);

