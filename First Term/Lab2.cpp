#include <iostream>
#include "windows.h"

using namespace std;

void lab2_1();
void lab2_2();

void main() {
	setlocale(LC_ALL, "Russian");
	int c;
	do {
		cout << "Какое задание запустить? (Для выхода введите 0): ";
		cin >> c;
		switch (c) {
		case 1:
			lab2_1();
			break;
		case 2:
			lab2_2();
			break;
		case 0:
			break;
		default:
			cout<<"Ошибка ввода!"<<endl;
			break;
		} 
	} while (!c == 0);
}

void lab2_1() {
	int x, y, z;
	cout << "Введите x и y: ";
	cin>>x;
	cin>>y;
	if (x>0 && y>0){
		z = x*y;
	} else {
		z = -y-x+1;
	}
	cout << "z = " << z <<endl<<endl;
}

void lab2_2() {
	int a,b;
	cout << "Введите числа a и b: ";
	cin >> a;
	cin >> b;
	if (a>b){
		a *= 4;
		b *= 2;
	} else {
		b *= 4;
		a *= 2;
	}
	cout << "a = " << a << endl << "b = " << b <<endl<<endl; 
}