#include <iostream>
#include "windows.h"
#include <stdlib.h> 
#include <time.h> 
#include "math.h"

using namespace std;

void lab6_1();

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
		case 0:
			break;
		default:
			cout << "Неправильно выбрано задание!" << endl;
			break;
		}
	} while (!c == 0);
}

void lab6_1() {
	const int n = 6;
	int mas[n], temp;

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		mas[i] = rand() % 20 - 10;
	}
	cout << "Исходный массив: ";
	for (int i = 0; i < n; i++) {
		cout << mas[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1; j++) {
			if (mas[j+1] > mas[j]) {
				temp = mas[j+1];
				mas[j+1] = mas[j];
				mas[j] = temp;
			}
		}
	}
	cout << "Конечный массив: ";
	for (int i = 0; i < n; i++) {
		cout << mas[i] << "\t";
	}
	cout << endl;
}