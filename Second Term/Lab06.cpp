#include <iostream>
#include "Windows.h"
#include <string>

using namespace std;
void task1();
void task2();

int findMaxLenghtAndAlignLength(string &, string &);
bool vacation(int, int, int, int);

void main() {
	setlocale(LC_ALL, "Russian");
	int sw;
	do {
		cout << "Какое задание запустить? (Для выхода введите 0): ";
		cin >> sw;
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
	string str1;
	string str2;
	string sum;
	cout << "Введите первое слагаемое (только положительные): ";
	cin >> str1;
	cout << "Введите второе слагаемое (только положительные): ";
	cin >> str2;
	int maxLenght = findMaxLenghtAndAlignLength(str1, str2);
	int surplus = 0;
	for (int i = maxLenght - 1; i >= 0; i--) {
		char buff[2];
		buff[0] = str1[i];
		buff[1] = '\0';
		str1[i] = '0';
		int a = atoi(buff);
		buff[0] = str2[i];
		buff[1] = '\0';
		str2[i] = '0';
		int b = atoi(buff);
		int s = a + b;
		if (surplus != 0) {
			s += surplus;
			surplus = 0;
		}
		if (s > 9) {
			surplus++;
			sum += to_string(s % 10);
		} else {
			sum += to_string(s);
		}
		if (surplus != 0 && i == 0) {
			i++;
		}
	}
	string sum2 = sum;
	for (int i = 0; i < sum.length(); i++) {
		sum2[i] = sum[sum.length() - i - 1];
	}
	cout << "Сумма: " << sum2 << endl << endl;
}

void task2() {
	int a1, b1, a2, b2;
	cout << "Введите дни начала и конца отпуска первого человека:" << endl;
	cin >> a1 >> b1;
	cout << "Введите дни начала и конца отпуска второго человека:" << endl;
	cin >> a2 >> b2;
	if (a1 > b1 || a2 > b2 || a1 < 0 || a2 < 0 || b1 > 366 || b2 > 366) {
		cout << "Неправильный ввод дней!" << endl;
	} else {
		if (vacation(a1, b1, a2, b2)) {
			cout << "Всё в порядке!" << endl;
		} else cout << "Так нельзя!" << endl;
	}
}

int findMaxLenghtAndAlignLength(string &str1, string &str2) {
	string temp;
	bool flag = false;
	int maxLength = str1.length();
	if (str2.length() > maxLength) {
		maxLength = str2.length();
		flag = true;
	}
	if (flag) {
		for (int i = 0; i < maxLength - str1.length(); i++) {
			temp += '0';
		}
		temp += str1;
		str1 = temp;
	} else {
		for (int i = 0; i < maxLength - str2.length(); i++) {
			temp += '0';
		}
		temp += str2;
		str2 = temp;
	}
	return maxLength;
}

bool vacation(int a1, int b1, int a2, int b2) {
	if (((a2 < b1 && a2 > a1) || (b2 > a1 && b2 < b1)) || ((a1 < b2 && a1 > a2) || (b1 > a2 && b1 < b2))) {
		return false;
	} else {
		if ((a2 - b1 <= 2) && (a1 - b2 <= 2)) {
			return false;
		} else {
			return true;
		}
	}
}
