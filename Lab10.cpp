#include <iostream>
#include "Windows.h"

using namespace std;
void task1();
void task2();
void task3();
int NOD(int, int);
int NOK(int, int);
long double factor(int);
float stepen(int, int);

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
		case 3:
			task3();
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
	int a, b, c;
	cout << "Введите три числа:"<<endl;
	cin >> a >> b >> c;
	cout << "НОД трёх введённых чисел: " << NOD(NOD(a, b), c) << endl;
}

void task2() {
	int a, b, c;
	cout << "Введите три числа:" << endl;
	cin >> a >> b >> c;
	cout << "НОК трёх введённых чисел: " << NOK(NOK(a, b), c) << endl;
}

void task3() {
	int n, a;
	cout << "Введите n: ";
	cin >> n;
	cout << "Факториал n: " << factor(n) << endl;
	cout << "Введите число, которое нужно возвести в n-ю степень: ";
	cin >> a;
	cout << "Введите степень, в которую нужно возвести число a: ";
	cin >> n;
	cout << "Результат: " << stepen(a, n) << endl;

}

int NOD(int a, int b) {
	if (a < b) swap(a, b);
	if (b == 0) {
		return a;
	}
	int r = a % b;
	NOD(b, r);
}

int NOK(int a, int b) {
	return (a * b) / NOD(a, b);
}

long double factor(int a) {
	if (a == 0 || a == 1) {
		return 1;
	}
	return a * factor(a - 1);
}

float stepen(int X, int N) {
	if (N == 0)
		return 1;
	else if (N < 0)
		return 1 / stepen(X, -N);
	else
		return X * stepen(X, N - 1);
}