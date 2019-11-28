#include <iostream>
#include "Windows.h"
#include "time.h"

using namespace std;
void task1();
void task2();
void sortBubble(int*, int);

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
	srand(time(NULL));
	int n, max;
	cout << "Введите размер массива: ";
	cin >> n;
	if (n <= 0) {
		cout << "Невозможно выделить заданное количество памяти для массива" << endl;
		return;
	}
	int* mas = new int[n];
	int* num = new int[n];
	for (int i = 0; i < n; i++) {
		mas[i] = rand() % 3 + 1;
		cout << mas[i] << "\t";
		// заполнение NULL'ами массива num
		num[i] = -1;
	}
	sortBubble(mas, n);
	cout << endl << "Отсортированный массив:" << endl;
	for (int i = 0; i < n; i++) {
		cout << mas[i] << "\t";
	}
	cout << endl;
	max = mas[0];
	for (int i = 0; i < n; i++) {
		if (mas[i] > max) {
			max = mas[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (mas[i] == max) {
			num[i] = i;
		}
	}
	cout << "Максимальный элемент: " << max << endl << "Его номера: " << "\t";
	for (int i = 0; i < n; i++) {
		if (num[i] >= 0) {
			cout << num[i]+1 << "\t";
		}
	}
	cout << endl;
}

void task2() {
	srand(time(NULL));
	int const n = 200;
	int amount = 0, temp = 0;
	int* mas = new int[n];
	bool flag1 = true;
	for (int i = 0; i < n; i++) {
		mas[i] = rand() % 100;
	}
	for (int j = 0; j < n; j++) {
		if (mas[j] <= mas[j + 1]) {
			flag1 = true;
			temp++;
		} else {
			flag1 = false;
		}
		if (!flag1 & temp >= 1) {
			amount++;
			temp = 0;
			flag1 = true;
		}
	}
	cout << "Кол-во участков непрерывных последовательностей чисел с неуменьшающимися значениями: " << amount << endl;
}

void sortBubble(int* a, int k) {
	for (int i = k - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}
