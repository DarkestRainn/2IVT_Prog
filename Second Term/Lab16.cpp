#include <iostream>
#include "Windows.h"
#include <string>

using namespace std;

class Reception;

class Hotel {
public:
	friend Reception;
	void fillInfo(int, int, string, int);
	void show();
	bool getOccupancy();
private:
	int _roomNumber;
	int _floor;
	string _roomClass;
	int _numberOfPlaces;
	bool _isBusy = false;
};

void Hotel::fillInfo(int roomNumber, int floor, string roomClass, int numberOfPlaces) {
	_roomNumber = roomNumber;
	_floor = floor;
	_roomClass = roomClass;
	_numberOfPlaces = numberOfPlaces;
}

void Hotel::show() {
	cout << "Номер комнаты: " << _roomNumber << "   Этаж: " << _floor <<
		"   Класс: " << _roomClass << "  Количество мест: " << _numberOfPlaces << endl;
}

bool Hotel::getOccupancy() {
	return _isBusy;
}


class Reception {
public:
	void setOccupancy(Hotel *, bool);
};

void Reception::setOccupancy(Hotel *H, bool isBusy) {
	H->_isBusy = isBusy;
}

void main() {
	setlocale(LC_ALL, "Russian");
	const int n = 2;
	Hotel hardRock[n];
	int tempRoomNumber;
	int tempFloor;
	int tempNumberOfPlaces;
	string tempRoomClass;
	for (int i = 0; i < n; i++) {
		cout << "Введите номер комнаты: ";
		cin >> tempRoomNumber;
		cout << "Введите этаж: ";
		cin >> tempFloor;
		cout << "Введите класс команты: ";
		cin >> tempRoomClass;
		cout << "Введите кол-во мест: ";
		cin >> tempNumberOfPlaces;
		hardRock[i].fillInfo(tempRoomNumber, tempFloor, tempRoomClass, tempNumberOfPlaces);
	}
	Reception reception;
	reception.setOccupancy(&hardRock[0], true);
	for (int i = 0; i < n; i++) {
		if (!hardRock[i].getOccupancy()) {
			hardRock[i].show();
		}
	}
}