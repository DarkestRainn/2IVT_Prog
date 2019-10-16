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
	
}

void lab5_2() {
	const int n = 100;
	int mas[n];
	int max, num = 0, amount = 0;
	srand(time(NULL));
	cout << "Массив:\n";
	for (int i = 0; i < n; i++) {
		mas[i] = rand() % 500;
		cout << i + 1 << ": " << mas[i] << endl;
	}
	max = mas[0];
	for (int i = 1; i < n; i++) {
		if (mas[i] > max) {
			max = mas[i];
			num = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (mas[i] == max) {
			amount++;
			cout << "Номер в массиве: " << i + 1 << ". Значение: " << mas[i] << endl;
		}
	}
	cout << "Кол-во максимальных элементов в массиве: " << amount << endl;
}

void lab5_3() {
	const int n = 5;
	const int m = 5;
	int mas[n][m];
	int i, j, amount_column_with_0 = 0;
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		cout << "Строка " << i<<": ";
		for (j = 0; j < m; j++) {
			mas[i][j] = rand() % 5;
			cout << mas[i][j] << "\t";
		}
		cout << endl;
	}
	for (j = 0; j < n; j++) {
		for (i = 0; i < m; i++) {
			if (mas[i][j] == 0) {
				amount_column_with_0++;
				break;
			}
		}
	}
	cout << amount_column_with_0 << endl;
}