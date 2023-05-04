#pragma once

#include "apartment.h"

bool allocateArray(Apartment** array, int size);
void clearData(Apartment* apartments);
void showApartments(Apartment* apartments, int size);
void fillApartments(Apartment* apartments, int size);
int getCountApartmentsForNumbersOfRooms(Apartment* apartments, int size, int numberOfRooms);
int getCountApartmentsForNumbersOfRoomsAndInterval(Apartment* apartments, int size, int numberOfRooms, int intervalLow, int intervalUp);
int getCountApartmentsForSquare(Apartment* apartments, int size, double square);

Apartment* searchByNumbersOfRooms(Apartment* apartments, Apartment* apartmentsResult, int size, int numberOfRooms);
Apartment* searchInInterval(Apartment* apartments, Apartment* apartmentsResult, int size, int numberOfRooms, int intervalLow, int intervalUp);
Apartment* searchBySquare(Apartment* apartments, Apartment* apartmentsResult, int size, double square);