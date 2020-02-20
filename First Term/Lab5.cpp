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
	const int n = 6;
	const int q = 50;
	const int q1 = 25;
	int mas1[n][n], mas2[n][n],b[n], i, j;
	//заполнение матриц случайными числами
	srand(time(NULL));
	cout << "Матрица 1: " << endl;
	for (i = 0; i < n; i++) {
		cout << i << ": ";
		for (j = 0; j < n; j++) {
			mas1[i][j] = rand() % q-q1;
			cout << mas1[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << "Матрица 2: " << endl;
	for (i = 0; i < n; i++) {
		cout << i << ": ";
		for (j = 0; j < n; j++) {
			mas2[i][j] = rand() % q-q1;
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
}

void lab5_2() {
	const int n = 100;
	int mas[n];
	int max, num = 0, amount = 0;
	srand(time(NULL));
	cout << "Массив:\n";
	//заполнение матриц случайными числами
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
	const int n = 10;
	const int m = 10;
	const int q = 20;
	int mas[n][m], b[m], h[m], i, j, amount_column_with_0 = 0, num_str, max = 0;
	bool flag = false;
	srand(time(NULL));
	// заполнение массива случайными значениями
	for (i = 0; i < n; i++) {
		cout << "Строка " << i<<": ";
		for (j = 0; j < m; j++) {
			mas[i][j] = rand() % q;
			cout << mas[i][j] << "\t";
		}
		cout << endl;
	}
	// поиск кол-ва столбцов с хотя бы одним нулём
	for (j = 0; j < n; j++) {
		for (i = 0; i < m; i++) {
			if (mas[i][j] == 0) {
				amount_column_with_0++;
				break;
			}
		}
	}
	cout << "Кол-во столбцов, содержащих хотя бы один нулевой элемент: " << amount_column_with_0 << endl;
	// заполнение нулями массивов
	for (i = 0; i < m; i++) {
		b[i] = h[i] = 0;
		
	}
	// вычисление серий одинаковых элементов каждой строки
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (mas[i][j] == mas[i][j + 1]) {
				if (j + 1 > m) {
					break;
				}
				b[i]++;
				flag = true;
				if (b[i] > h[i]) {
					h[i] = b[i];
				}
			} else { b[i] = 0; }
		}
	}
	//выбор строки с максимальной серией
	if (flag) {
		cout << "Самая длинная серия элементов находится в строке(строках): ";
		for (i = 0; i < m; i++) {
			if (h[i] > max) {
				max = h[i];
				num_str = i;
			}
		}
		for (i = 0; i < m; i++) {
			if (h[i] == max) {
				cout << "#" << i << " ";
			}
		}
	} else cout << "Серий нет" << endl;
	cout << endl;
}