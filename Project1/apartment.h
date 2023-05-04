#pragma once

#include <iostream>
#include <string>

using namespace std;

class Apartment {
private:
	string address_;
	int floor_;
	int numberOfRooms_;
	double square_;
	int id_;

	static int counter_;

public:
	~Apartment();
	Apartment(string address = "", int floor = 0, int numberOfRooms = 0, double square = 0.0);

	string getAddress();
	int getFloor();
	int getNumberOfRooms();
	double getSquare();
	int getId();

	void setAddress();
	void setFloor();
	void setNumberOfRooms();
	void setSquare();

	void setAddress(string value);
	void setFloor(int value);
	void setNumberOfRooms(int value);
	void setSquare(double value);
	void setId(int value);

	void cleanCounter();
	void showInfo();

	friend std::istream& operator>> (std::istream&, Apartment&);
	friend std::ostream& operator<< (std::ostream&, Apartment&);
};
