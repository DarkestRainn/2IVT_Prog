#include <iostream>
#include "windows.h"
#include "math.h"

using namespace std;

void lab3_1();
void lab3_2();
void lab3_3();
void lab3_4();
void lab3_5();
void lab3_6();

void main() {
	setlocale(LC_ALL, "Russian");
	int c;
	do {
		cout << "Какое задание запустить? (Для выхода введите 0): ";
		cin >> c;
		switch (c) {
		case 1:
			lab3_1();
			break;
		case 2:
			lab3_2();
			break;
		case 3:
			lab3_3();
			break;
		case 4:
			lab3_4();
			break;
		case 5:
			lab3_5();
			break;
		case 6:
			lab3_6();
			break;
		case 0:
			break;
		default:
			cout << "Неправильно выбрано задание!" << endl;
			break;
		}
	} while (!c == 0);
}

void lab3_1() {
	int n;
	do {
		cout << "Введите натуральное четырёхзначное число: ";
		cin >> n;
		if (n < 999 || n > 9999) {
			cout << "Ошибка ввода!" << endl;
		}
	} while (n < 999 || n > 9999);
	cout << "Предпоследняя цифра введёного числа: " << (n / 10) % 10 << endl << endl;
}

void lab3_2() {
	int n;
	float res;
	float a = 0, b = 0;
	do {
		cout << "Введите натуральное число: ";
		cin >> n;
		if (n < 1) {
			cout << "Ошибка ввода!" << endl;
		}
	} while (n < 1);
	a = cos(float(1));
	b = sin(float(1));
	res = a / b;
	for (float i = 2; i <= n; i++) {
		a += cos(i);
		b += sin(i);
		res *= a / b;
	}
	cout << "Результат: " << res << endl << endl;
}

void lab3_3() {
	int N = 0;
	double res = 1;
	int arr[999];
	cout << "Введите последовательность чисел (Конец ввода число 777): " << endl;
	for (int i = 0; i < 999; i++) {
		cin >> arr[i];
		N++;
		if (arr[i] == 777) {
			arr[i] = 1;
			i = 1024;
		}
	}
	for (int i = 0; i < N; i++) {
		res *= arr[i];
	}
	cout << "Произведение последовательности чисел: " << res << endl << endl;
}

void lab3_4() {
	float x_f, x_l, dx, a, b, c, f, t;
	cout << "Введите X начальное: ";
	cin >> x_f;
	t = x_f;
	cout << "Введите X конечное: ";
	cin >> x_l;
	cout << "Введите dx: ";
	cin >> dx;
	cout << "Введите числа a, b, c: \na: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	cout << "  X нач\t|    " << "X конеч    | \t" << "dx\t| \t" << "x\t| \t" << "F\n";
	cout << "-------------------------------------------------------------------------" << endl;
	for (x_f; x_f <= x_l; x_f += dx) {
		if (a < 0 && c != 0) {
			f = a * pow(x_f, 2) + b * x_f + c;
		} else if (a > 0 && c == 0) {
			f = -a / (x_f - c);
		} else {
			f = a * (x_f + c);
		}
		cout << "    " << t << "\t| \t" << x_l << "\t| \t" << dx << "\t| \t" << x_f << "\t| \t" << f << "\n";
	}
}

void lab3_5() {
	float t, x = 0, y, dx;
	cout << "Введите t: ";
	cin >> t;

	dx = 3.14 / 250;
	cout << "   x\t  |\t  y" << endl;
	while (x < 3.14-dx) {
		x += dx;
		y = (pow(sin(pow(x, t)), 2)) / (sqrt(1 + pow(x, 3)));
		cout << x << "\t  |   " << y << endl;
	}
}

void lab3_6() {

}