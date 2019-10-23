#include <iostream>
#include "windows.h"
#include <stdlib.h> 
#include <time.h> 
#include "math.h"

using namespace std;

void lab6_1();
void lab6_2();
void lab6_3();

void main() {
	setlocale(LC_ALL, "Russian");
	int c;
	do {
		cout << "Какое задание запустить? (Для выхода введите 0): ";
		cin >> c;
		switch (c) {
		case 1:
			lab6_1();
			break;
		case 2:
			lab6_2();
			break;
		case 3:
			lab6_3();
			break;
		case 0:
			break;
		default:
			cout << "Неправильно выбрано задание!" << endl;
			break;
		}
	} while (!c == 0);
}

void lab6_1() {
	float mas[15], s = 0;

	cout << "Введите 15 элементов: ";
	for (int i = 0; i < 15; i++) {
		cout << i+1 << ": ";
		cin >> mas[i];
		s += mas[i];
	}
	cout << "Среднее арифметическое :" << s / 15 << endl;
}

void lab6_2() {
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

void lab6_3() {
	const int n = 5;
	int mas[n][n];
	int g = n, j = 0, max;
	
	// заполнение массива случайными числами
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int j = 0; j < n; j++) {
			mas[i][j] = rand() % 50+25;
			cout << mas[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	// поиск максимального элемента в области
	max = mas[0][0];

	for (int i = 0; i < ceil(n/2.); i++) {
		for (j =+ i; j < g; j++) {
			if (mas[i][j] > max) {
				max = mas[i][j];
			}
		}
		g--;
	}
	cout << "Максимальный элемент из области: " << max << endl;
}