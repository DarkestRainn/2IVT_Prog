#include <iostream>
#include "windows.h"
#include <stdlib.h> 
#include <time.h> 

using namespace std;

void lab5_1();
void lab5_2();
void lab5_3();

void main() {
	setlocale(LC_ALL, "Russian");
	int c;
	do {
		cout << "Какое задание запустить? (Для выхода введите 0): ";
		cin >> c;
		switch (c) {
		case 1:
			lab5_1();
			break;
		case 2:
			lab5_2();
			break;
		case 3:
			lab5_3();
			break;
		case 0:
			break;
		default:
			cout << "Неправильно выбрано задание!" << endl;
			break;
		}
	} while (!c == 0);
}

void lab5_1() {
	float mas[15], s = 0;

	cout << "Введите 15 элементов: ";
	for (int i = 0; i < 15; i++) {
		cout << i+1 << ": ";
		cin >> mas[i];
		s += mas[i];
	}
	cout << "Среднее арифметическое :" << s / 15 << endl;
}

void lab5_2() {
	const int n = 20;
	const int m = 15;
	int mas[20][15];

	for (int i = 0; i < n; i++) {
		if (i < 10) {
			cout << 0 << i << ": ";
		} else cout << i << ": ";
		
		for (int j = 0; j < m; j++) {
			if ((j+1) % 2 == 1) {
				mas[i][j] = 1;
			} else if ((j + 1) % 2 == 0) {
				mas[i][j] = 0;
			}
			cout <<  mas[i][j] << "\t";
		}
		cout << endl;
	}
}

void lab5_3() {
	
}