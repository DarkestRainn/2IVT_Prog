#include <iostream>
#include "Windows.h"
#include <math.h>
#include <iomanip>

using namespace std;

float func(float, float, float);
void brick(int, int, int, int);
void brick(float, float, float, float);
void decom(float, int);

template <typename T> T ex1(T A, T B, T C) {
	if (A == B || B == C || A == C) {
		cout << "Введены одинаковые числа!" << endl;
		return 0;
	}
	T max , middle, low;
	T mas[3] = {A, B, C};
	max = A;
	low = A;
	for (int i = 1; i < 3; i++) {
		if (mas[i] > max) max = mas[i];
		if (mas[i] < low) low = mas[i];
	}
	for (int i = 0; i < 3; i++) {
		if (mas[i] != max && mas[i] != low) middle = mas[i];
	}
	cout << "Max: " << max << "\t middle: " << middle << "\t lowest: " << low << endl;
	cout << "Max/lowest: " << max / low << "\t middle-lowest: " << middle - low << "\t low * 5: " << low * 5 << endl;
	return 0;
}

void main() {
	setlocale(LC_ALL, "Russian");
	float a, b, c, x;
	int n;
	int sw;
	do {
		cout << "Какое задание запустить? (Для выхода введите 0): ";
		cin >> sw;
		switch (sw) {
		case 1:
			cout << func(1.12, -0.14, 2.49) << endl;
			break;
		case 2:
			cout << "Введите x: ";
			cin >> x;
			cout << "Введите n: ";
			cin >> n;
			decom(x, n);
			break;
		case 3:
			cout << "Введите 3 числа: " << endl;
			cin >> a;
			cin >> b;
			cin >> c;
			ex1(a, b, c);
			break;
		case 4:
			cout << "Введите сторону отверстия: ";
			cin >> x;
			cout << "Введите ширину, высоту, длину кирпича: ";
			cin >> a;
			cin >> b;
			cin >> c;
			brick(x, a, b, c);
			break;
		case 0:
			break;
		default:
			cout << "Неправильно выбрано задание!" << endl;
			break;
		}
	} while (!sw == 0);
}

float func(float a, float b, float x) {
	float z = 0;
	z = 1 / pow(2, x) * asin(x / (sqrt(1 + pow(x, 2)))) - 1 / pow(3, b * x) * cos(x + b) + log((x + a) / (x + b)) / (1 / pow(2, x) + 1 / pow(3, b * x));
	return z;
}

void decom(float x, int n) {
	if (x <= 0) {
		cout << "Ошибка ввода x!" << endl;
		return;
	}
	float ch, zn, res = 0;
	cout << setw(4) << "n" << setw(4) << "|" << setw(8) << "ln x" << endl << "-------------------" << endl;
	for (int i = 1; i <= n; i += 2) {
		ch = pow(x - 1, i);
		zn = i * pow(x + 1, i);
		res += ch / zn;
		cout << setw(4) << i << setw(4) << "|" << setw(11) << 2 * res << endl;
	}
}

void brick(int x, int a, int b, int c) {
	if (x == 0 || a == 0 || b == 0) {
		cout << "x или a или b не могут быть равны 0!" << endl;
		return;
	}
	if ((a <= x && b <= x) || (b <= x && c <= x) || (c <= x && a <= x)) {
		cout << "Можно!" << endl;
	} else cout << "Нельзя!" << endl;
}

void brick(float x, float a, float b, float c) {
	if (x == 0 || a == 0 || b == 0 || c == 0) {
		cout << "x или a или b не могут быть равны 0!" << endl;
		return;
	}
	if ((a <= x && b <= x) || (b <= x && c <= x) || (c <= x && a <= x)) {
		cout << "Можно!" << endl;
	} else cout << "Нельзя!" << endl;
}