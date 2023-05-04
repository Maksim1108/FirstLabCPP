#include <iostream>
#include <string>

#include "apartment.h"
#include "inputValidation.h"

int Apartment::counter_ = 0;

Apartment::~Apartment() = default;

Apartment::Apartment(string address, int floor, int numberOfRooms, double square)
{
	address_ = address;
	floor_ = floor;
	numberOfRooms_ = numberOfRooms;
	square_ = square;
	id_ = ++counter_;
};

string Apartment::getAddress() {
	return address_;
};
int Apartment::getFloor() {
	return floor_;
};
int Apartment::getNumberOfRooms() {
	return numberOfRooms_;
};
double Apartment::getSquare() {
	return square_;
};
int Apartment::getId() {
	return id_;
};


void Apartment::setAddress() {
	string address;
	getline(cin >> std::ws, address);
	address_ = address;
}

void Apartment::setAddress(string address) {
	address_ = address;
};

void Apartment::setFloor() {
	int floor;
	floor = getPositiveInt();
	floor_ = floor;
};

void Apartment::setFloor(int floor) {
	floor_ = floor;
};

void Apartment::setNumberOfRooms() {
	int numberOfRooms;
	numberOfRooms = getPositiveInt();
	numberOfRooms_ = numberOfRooms;
};

void Apartment::setNumberOfRooms(int numberOfRooms) {
	numberOfRooms_ = numberOfRooms;
};

void Apartment::setSquare() {
	double square;
	square = getPositiveDouble();
	square_ = square;
};

void Apartment::setSquare(double square) {
	square_ = square;
};

void Apartment::setId(int value) {
	id_ = value;
};

void Apartment::cleanCounter() {
	counter_ = 0;
};

void Apartment::showInfo() {
	cout << "Информация о квартире №" << id_<< endl
		<< "Адрес:" << address_ << endl
		<< "Этаж:" << floor_ << endl
		<< "Количество комнат:" << numberOfRooms_ << endl
		<< "Площадь:" << square_ << endl << endl;
};

std::istream& operator>> (std::istream& in, Apartment& p)
{
	getline(in >> ws, p.address_);
	in >> p.floor_;
	in >> p.numberOfRooms_;
	in >> p.square_;				
	return in;
}

std::ostream& operator<<(std::ostream& out, Apartment& p)
{
	out << p.address_ << std::endl << p.floor_ << std::endl << p.numberOfRooms_ <<
		std::endl << p.square_ << std::endl;
	return out;
}
