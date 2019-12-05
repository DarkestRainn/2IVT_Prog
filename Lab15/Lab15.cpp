#include <iostream>
#include "windows.h"
#include <stdlib.h> 
#include <time.h> 

using namespace std;

void task1();

void main() {
	setlocale(LC_ALL, "Russian");
	int c;
	do {
		cout << "Какое задание запустить? (Для выхода введите 0): ";
		cin >> c;
		switch (c) {
		case 1:
			task1();
			break;
		case 0:
			break;
		default:
			cout << "Неправильно выбрано задание!" << endl;
			break;
		}
	} while (!c == 0);
}

void task1() {
	const int n = 6;
	int** mas1 = new int*[n];
	int** mas2 = new int*[n];
	int* b = new int[n];
	for	(int i = 0; i < n; i++){
		mas1[i] = new int[n];
		mas2[i] = new int[n];
	}
	int i, j;
	//заполнение матриц случайными числами
	srand(time(NULL));
	cout << "Матрица 1: " << endl;
	for (i = 0; i < n; i++) {
		cout << i << ": ";
		for (j = 0; j < n; j++) {
			mas1[i][j] = rand() % 50-45;
			cout << mas1[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << "Матрица 2: " << endl;
	for (i = 0; i < n; i++) {
		cout << i << ": ";
		for (j = 0; j < n; j++) {
			mas2[i][j] = rand() % 50-45;
			cout << mas2[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (mas1[i][j] >= 0 || mas2[i][j] >= 0) {
				b[i] = 0;
				break;
			} b[i] = 1;
		}
	}
	//вывод массива b
	cout << "Массив b: ";
	for (i = 0; i < n; i++) {
		cout << b[i] << "\t";
	}
	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		delete[] mas1[i];
		delete[] mas2[i];
	}
	delete[] mas1;
	delete[] mas2;
}