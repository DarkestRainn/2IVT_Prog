#include <iostream>
#include "Windows.h"
#include <iomanip>
#include "time.h"

using namespace std;

const int n = 5;

int multip_elem(int [], int);
void counter(int [], int [], int, int);
void display(int [], int);
void display(int [][n], int, int);
void min_elem_line(int [][n], int, int);

void main() {
	setlocale(LC_ALL, "Russian");
	int sw;
	srand(time(NULL));
	int z, m[n];
	int mas1[n], mas2[n];
	do {
		cout << "Какое задание запустить? (Для выхода введите 0): ";
		cin >> sw;
		switch (sw) {
		case 1:
			for (int i = 0; i < n; i++) {
				m[i] = rand() % 3 + 1;
				cout << m[i] << setw(4);
			}
			z = multip_elem(m, n);
			cout << endl << "Произведение равно: " << z << endl;
			break;
		case 2:
			for (int i = 0; i < n; i++) {
				mas1[i] = rand() & 10 + 1;
				mas2[i] = rand() % 10 + 1;
			}
			cout << "Массив 1: ";
			display(mas1, n);
			cout << "Массив 2: ";
			display(mas2, n);
			counter(mas1, mas2, n, n);
			break;
		case 3:
			int mas3[n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					mas3[i][j] = rand() % 10;
				}
			}
			display(mas3, n, n);
			cout << endl;
			min_elem_line(mas3, n, n);
			break;
		case 0:
			break;
		default:
			cout << "Неправильно выбрано задание!" << endl;
			break;
		}
	} while (!sw == 0);
}

void display(int mas[], int size) {
	for (int i = 0; i < size; i++) {
		cout << mas[i] << "\t";
	}
	cout << endl;
}

void display(int mas[][n], int size1, int size2) {
	for (int i = 0; i < size1; i++) {
		cout << i << ": ";
		for (int j = 0; j < size2; j++) {
			cout << mas[i][j] << "\t";
		}
		cout << endl;
	}
}

int multip_elem(int mas[], int size) {
	int res = 1;
	for (int i = 0; i < size; i++) {
		res *= mas[i];
	}
	return res;
}

void counter(int mas1[], int mas2[], int size1, int size2) {
	int num_even = 0, num_noteven = 0;
	for (int i = 0; i < size1; i++) {
		if (mas1[i] % 2 == 0) {
			num_even++;
		} else num_noteven++;
	}
	for (int i = 0; i < size2; i++) {
		if (mas2[i] % 2 == 0) {
			num_even++;
		} else num_noteven++;
	}
	cout << "Кол-во чётных: " << num_even << endl << "Кол-во нечётных: " << num_noteven << endl;
}

void min_elem_line(int mas[][n], int size1, int size2) {
	int b[n] = {mas[0][0], mas[1][0], mas[2][0], mas[3][0], mas[4][0]};
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (mas[i][j] < b[i]) b[i] = mas[i][j];
		}
	}
	for (int i = 0; i < size1; i++) {
		cout << "Минимальный элемент в " << i << " строке: " << b[i] << endl;
	}
}