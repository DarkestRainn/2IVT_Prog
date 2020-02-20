#include <iostream>
#include "windows.h"

using namespace std;

void lab1_1_1();
void lab1_1_2();

void main() {
	setlocale(LC_ALL, "Russian");
	int c;
	do {
		cout << "Какое задание запустить? (Для выхода введите 0): ";
		cin >> c;
		switch (c) {
		case 1:
			lab1_1_1();
			break;
		case 2:
			lab1_1_2();
			break;
		case 0:
			break;
		default:
			cout<<"Ошибка ввода!"<<endl;
			break;
		} 
	} while (!c == 0);
}

void lab1_1_1() {
	float R;
	cout << "Введите радиус окружности: ";
	cin >> R;
	cout << "Длина окружности равна: " << 2 * 3.14*R << endl << "Площадь круга равна: " << 3.14*pow(R,2)<<endl;
}


void lab1_1_2() {
	float S, t;
	cout << "Введите расстояние между городами (км): ";
	cin >> S;
	cout << "Введите требуемое время (ч): ";
	cin >> t;
	cout << "Вам нужно ехать со скоростью " << S / t << " км/ч чтобы достигнуть города за " << t <<" часов"<<endl;
}