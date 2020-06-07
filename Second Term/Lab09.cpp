#include <iostream>
#include "Windows.h"
#include <string>

using namespace std;
void task1();
void task2();

string insertHyphen(string, int);

void main() {
	setlocale(LC_ALL, "Russian");
	int sw;
	do {
		cout << "Какое задание запустить? (Для выхода введите 0): ";
		cin >> sw;
		cin.clear();
		while (cin.get() != '\n');
		switch (sw) {
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 0:
			break;
		default:
			cout << "Неправильно выбрано задание!" << endl;
			break;
		}
	} while (!sw == 0);
}

void task1() {
	string str;
	string str2;
	cout << "Введите номер телефона: ";
	getline(cin, str);
	str += '\0';
	str2 = str;
	int i = 0;
	while (str[i] != '\0') {
		if (i == 3) {
			str = insertHyphen(str, i);
		}
		if (i == 7) {
			str = insertHyphen(str, i);
		}
		if (i == 11) {
			str = insertHyphen(str, i);
		}
		++i;
	}
	i = 0;
	while (str2[i] != '\0') {
		if (i == 1) {
			str2 = insertHyphen(str2, i);
		}
		if (i == 5) {
			str2 = insertHyphen(str2, i);
		}
		if (i == 9) {
			str2 = insertHyphen(str2, i);
		}
		++i;
	}
	cout << "Номер, разбитый на триады:" << endl;
	cout << "Начиная с первых цифр: " << str << endl;
	cout << "Начиная с последних цифр: " << str2 << endl;
}

void task2() {
	int num;
	cout << "Введите сумму цифр: ";
	cin >> num;
	cout << "Все трёхзначные номера, сумма чисел которых равна N:" << endl;
	cin.ignore();
	int temp = 0;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				if ((i + j + k) == num) {
					temp = i*100 + j*10 + k;
				}
				if (temp > 0) {
					cout << i << j << k <<  endl;
					temp = 0;
				}
			}
		}
	}
}

string insertHyphen(string _str, int _i) {
	string str = _str;
	str += ' ';
	for (int i = _str.length(); i > _i; i--) {
		str[i] = str[i - 1];
	}
	str[_i] = '-';
	return str;
}