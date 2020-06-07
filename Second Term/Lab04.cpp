#include <iostream>
#include "Windows.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
void task1();
void task2();

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
	const int size = 5;
	int array[size][size];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			array[i][j] = 0;
		}
	}
	int x, y; //начальная точка
	if (size % 2 == 0) {
		x = size / 2 - 1;
		y = size / 2 - 1;
	} else {
		x = size / 2;
		y = size / 2;
	}
	int step = 1;
	int dir = 1;//направление движения
	int k = 0;//счётчик для поворотов
	int count = 0;//счётчик заполненных элементов
	do {
		int dx = dir / 10, dy = dir % 10;//определяем приращения в зависмости от направления движения
		for (int i = 0; i < step; i++) {
			if (x >= 0 && x < size && y >= 0 && y < size) {//заполняем массив числом step
				array[y][x] = step;
				count++;
			}
			x += dx;
			y += dy;//выполняем приращение
		}
		if (dir == 10) { //10 - вправо
			dir = -1;
		} else if (dir == -1) {//-1 - вверх
				dir = -10;
		} else if (dir == -10) { // -10 - влево
			dir = 1;
		} else if (dir == 1) {//1 - вниз
			dir = 10;
			}
		k++;
		if (k == 2) {//каждые 2 шага поворачиваем
			step++; //и увеличиваем step
			k = 0;
		}
	} while (count < (size*size));

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << setw(2) << array[i][j] << " ";
		}
		cout << endl;
	}
}

void task2() {
	fstream file;
	fstream file2;
	file.open("input.txt", ios::in);
	file2.open("output.txt", ios::out);
	string temp;
	vector <int> digits;
	digits.push_back(-1);
	digits.push_back(-1);//для того, чтобы не выходить за границы вектора
	int initialValue;
	if (file.is_open()) {
		getline(file, temp);
		initialValue = stoi(temp);//считываем и запоминаем начальное значение
		int digit;
		while (!file.eof()) {//считываем в вектор все значения из файла
			getline(file, temp);
			digit = stoi(temp);
			digits.push_back(digit);
		}
		file.close();
	}



	if (file2.is_open()) {
		file2 << initialValue << endl;
		for (int i = 2; i < digits.size(); i++) {
			if (digits[i] == digits[i - 1] && digits[i - 1]  == digits[i - 2] && digits[i - 2] == digits[i]) {
				//если три подряд идущие цифры совпадают
				if (digits[i] != initialValue) {// и они не равны установившемуся 
					file2 << digits[i] << endl;//выводим в файл новое значение
					initialValue = digits[i];//меняем установившееся значение на новое
				} else {
					file2 << initialValue << endl; //иначе выводим установившееся значение
				}
			} else {
				file2 << initialValue << endl; //иначе выводим установившееся значение
			}
		}
		file2.close();
	}
}