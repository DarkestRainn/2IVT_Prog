#include <iostream>
#include "Windows.h"
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
void task1();
void task2();
void task3();
void task4();
void SelectFirstAndLastWords(char[]);
char changeToUpperCase(char);

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
		case 4:
			task4();
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
	char string[100];
	int sum = 0;
	cout << "Введите 10 строк:" << endl;
	for (int i = 0; i <= 10; i++) {
		cin.getline(string, 100);
		sum += strlen(string);
	}
	cout << "Сумма символов введённых строк: " << sum << endl;
}

void task2() {
	string strFirst, strLast, strFinal;
	char s[50];
	cin.ignore();
	cin.getline(s, 50);
	SelectFirstAndLastWords(s);
}

void task3() {
	string mas[10];
	cin.ignore();
	cout << "Введите 10 строк: " << endl;
	for (int i = 0; i < 10; i++) {
		getline(cin, mas[i]);
		mas[i] += '!';
	}
	cout << "Обработанный массив строк:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << mas[i] << endl;
	}
}

void task4() {
	int const n = 2;
	int num = 0;
	char mas[n][80];
	string strmas[n];
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "Введите строку #" << i + 1 << endl;
		cin.getline(mas[i], 80);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 80 && mas[i][j] != '\0'; j++) {
			if ((mas[i][j] > '0' && mas[i][j] < '9' ) && mas[i][j] % 2 == 0) num++;
		}
		if (num >= 3) {
			for (int j = 0; j < 80 && mas[i][j] != '\0'; j++) {
				mas[i][j] = NULL;
			}
		}
		num = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 80 && mas[i][j] != '\0'; j++) {
			if (mas[i][j] != NULL) {
				strmas[i] += mas[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << strmas[i] << endl;
	}
}

void SelectFirstAndLastWords(char src[]) {
	// выделение первого слова и перевод в UpperCase
	int from;
	string strFirst;
	for (from = 0; from < strlen(src) && src[from] != ' '; from++) {
		strFirst = strFirst + src[from];
	}
	transform(strFirst.begin(), strFirst.end(), strFirst.begin(), changeToUpperCase);
	// выделение последнего слова и перевод в UpperCase
	int to;
	string strLast;
	for (to = strlen(src) - 1; to >= 0 && src[to] != ' '; to--);
	for (int i = to + 1; i < strlen(src); i++) {
		strLast = strLast + src[i];
	}
	transform(strLast.begin(), strLast.end(), strLast.begin(), changeToUpperCase);
	// соедение трансформированных слов и остатка строки
	string strFinal;
	for (int i = 0; i < strlen(src); i++) {
		strFinal += src[i];
	}
	cout << strFirst + strFinal.substr(from, to - from + 1) + strLast << endl;
}

char changeToUpperCase(char c) {
	if (isupper(c)) {
		return c;
	 } else return toupper(c);
}