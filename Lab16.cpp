#include <iostream>
#include "Windows.h"
#include <string>
#include "time.h"

using namespace std;
void task1();
void task2();
void task3();
void generate(int*, int, int, int);
void generate(int**, int, int, int, int);
void display(int*, int);
void display(int**, int, int);
void sortBubbleCol(int**, int, int);
void swapCol(int**, int, int, int);

void main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int sw;
	do {
		cout << "Какое задание запустить? (Для выхода введите 0): ";
		cin >> sw;
		cin.ignore();
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
	string str;
	cout << "Введите строку-предложение: ";
	getline(cin, str);
	str = str + '\0';
	int from = 0, to = 0, minLenght = 0, minTo, minFrom = 0;
	bool flag = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			to = i;
			minLenght = i;
			minTo = to;
			break;
		}
	}
	for (int i = minLenght; i < str.length(); i++) {
		if (str[i] == ' ' || str[i] == '\0') {
			if (!flag) {
				to = i;
				if ((to - from) < minLenght){
					minLenght = to - from;
					minFrom = from;
					minTo = to;
				}
				flag = true;
			}
		}
		if (flag && (str[i] != ' ')) {
			flag = false;
			from = i;
		}
	}
	cout << "Самое короткое слово в строке: ";
	for (int i = minFrom; i < minTo; i++) {
		cout << str[i];
	}
	cout << endl;
}

void task2() {
	int n = 10;
	int from = 0, maxFrom = 0, maxTo, maxLenght = 0;
	bool flag = false;
	int* arr = new int[n];
	generate(arr,n, 3, -1);
	display(arr, n);
	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[i + 1]) {
			flag = true;
		} else if (arr[i] != arr[i + 1]) {
			if (flag) {
				flag = false;
				if (i - from > maxLenght) {
					maxFrom = from;
					maxTo = i;
					maxLenght = (maxTo - maxFrom);
				}
			}
			from = i + 1;
		}
	}
	cout << "Длиннейшая серия: " << endl;
	for (int i = maxFrom; i <= maxTo; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl << "Преобразованный массив:" << endl;
	int* arr2 = new int[n + 1];
	for (int i = 0; i <= maxTo; i++) {
		arr2[i] = arr[i];
	}
	arr2[maxTo+1] = 0;
	for (int i = maxTo+2; i < n+1; i++) {
		arr2[i] = arr[i - 1];
	}
	display(arr2, n + 1);
	delete[] arr;
	delete[] arr2;
}

void task3() {
	int n = 3, m = 3;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	generate(arr, n, m, 50, -1);
	display(arr, n, m);
	cout << endl;
	sortBubbleCol(arr, n, m);
	//поиск максимальных элементов в столбцах
	int* maxs = new int[m];
	for (int j = 0; j < m; j++) {
		maxs[j] = arr[0][j];
		for (int i = 1; i < n; i++) {
			if (arr[i][j] > maxs[j])
				maxs[j] = arr[i][j];
		}
	}

	int k;
	for (int i = 0; i < m; i++) {
		k = i;
		for (int j = i + 1; j < m; j++) {
			if (maxs[j] > maxs[k])
				k = j;
		}

		if (i != k) {
			swap(maxs[i], maxs[k]);
			for (int j = 0; j < n; j++)
				swap(arr[j][i], arr[j][k]);
		}
	}
	display(arr, n, m);
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

void generate(int* arr,int n,int q1, int q2) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % q1 - q2;
	}
}

void generate(int** arr, int n, int m, int q1, int q2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % q1 - q2;
		}
	}
}

void display(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void display(int** arr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j]<<"\t";
		}
		cout << endl;
	}
}

void sortBubbleCol(int** arr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int g = 0; g < n; g++) {
				if (arr[j][i] < arr[g][i]) {
					swap(arr[g][i], arr[j][i]);
				}
			}
		}
	}
}