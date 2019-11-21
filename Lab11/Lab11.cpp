#include <iostream>
#include "Windows.h"
#include "time.h"

using namespace std;
void task1();
void task2();
int searchIndex(int**,int*, int, int);
void sortBubble(int*, int);
int binSearch(int*, int, int, int);

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
	// первая подзадача
	int const n = 5;
	int mas[n][n];

	srand(time(NULL));
	cout << "Исходный массив:" << endl;
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int j = 0; j < n; j++) {
			mas[i][j] = rand() % 25+1;
			cout << mas[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	for (int g = 0; g < n; g++){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n-1; j++) {
				if (mas[i][j] > mas[i][j+1]) {
					swap(mas[i][j], mas[i][j+1]);
				}
			}
		}
	}
	cout << "Отсортированные по убыванию строки матрицы:" << endl;
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int j = 0; j < n; j++) {
			cout << mas[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	
	//вторая подзадача
	char strmas1[11][50] = {"Должиков", "Бондаренко", "Утробин", "Василенко", "Машталиров", "Дорошин",
						"Колесников", "Овчаров", "Кравец",  "Крюков", "Селезнёв"};
	char strmas2[11][50];
	for(int i = 0; i < 11; i++){
		for (int j = 0; j < 50; j++){
			strmas2[i][j] = NULL;
		}
	}
	//char s[43] = {"БбВвГгДдЖжЗзЙйКкЛлМмНнПпРрСсТтФфХхЦцЧчШшЩщ"};
	char s[21] = {"АаУуОоЫыИиЭэЯяЮюЁёЕе"};

	for(int i = 0; i < 11; i++){
		for(int j = 0; j < strlen(s); j++){
			if (strmas1[i][0] == s[j]){
				for(int g = 0; g < strlen(strmas1[i]); g++) {
					strmas2[i][g] = strmas1[i][g];
				}
			}
		}
	}

	cout << "Массив фамилий, начинающихся с гласных:" << endl;
	for(int i = 0; i < 11; i++){
		if (strmas2[i][0] != NULL){
			cout << i << ": ";
		}
		for (int j = 0; j < strlen(strmas2[i]);j++){
			if (strmas2[i][j] != NULL){
			cout << strmas2[i][j];
			}
		}
		if (strmas2[i][0] != NULL){
			cout << endl;
		}
	}

	cout << endl;

	//третья подзадача
	const int p = 5;
	int arr[p][p];
	int sort[9];
	int g = p-1, t = 0;
	int h = 0;

	// заполнение массива случайными числами
	cout << "Исходный массив:" << endl;
	for (int i = 0; i < p; i++) {
		cout << i << ": ";
		for (int j = 0; j < p; j++) {
			arr[i][j] = rand() % 50 + 25;
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;

	for (int j = p - 1; j >= floor(p / 2.); j--) {
		for (int i = t; i <= g; i++) {
			sort[h] = arr[i][j];
			h++;
		}
		g--;
		t++;
	}
	sortBubble(sort, 9);
	cout << "Отсортированные элементы диапазона массива: ";
	for (int i = 0; i < 9; i++) {
		cout << sort[i] << "  ";
	}
	cout << endl;
}

void task2() {
	int const n = 10;
	int A[10];
	int** B = new int*[n];
	for (int i = 0; i < n; i++) {
		B[i] = new int[n];
	}
	int index;
	int** C = new int*[10];
	for (int i = 0; i < n; i++) {
		C[i] = new int[n + 1];
	}

	srand(time(NULL));
	//заполнение матрицы
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			B[i][j] = rand() % 100 + 1;
		}
	}

	//заполнение массива A
	cout << "Матрица A: ";
	for (int i = 0; i < 10; i++) {
		A[i] = rand() % 50 + 1;
		cout << A[i] << "  ";
	}
	cout << endl;
	//сортировка первой строки
	sortBubble(B[0], 10);
	cout << "\nИсходная матрица B:" << endl;
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int j = 0; j < n; j++) {
			cout << B[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	index =  searchIndex(B, A, n, n);
	//копирование из массива B в новый массив C
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = B[i][j];
		}
	}
	//сдвиг элементов и вставка в ряд под номером index матрицы A
	for (int i = 0; i < n; i++) {
		for (int j = n; j >= index; j--) {
			C[i][j] = C[i][j-1];
		}
		C[i][index] = A[i];
	}
	cout << "Новая матрица B с вставленной матрицей A:" << endl;
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int j = 0; j < n+1; j++) {
			cout << C[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	//очистка памяти
	for (int i = 0; i < n; i++) {
		delete[] B[i];
		delete[] C[i];
	}
	delete[] B;
	delete[] C;
}

int searchIndex(int **mas, int* A, int n, int m) {
	int* arr;
	arr = new int[n + 1];
	for (int i = 0; i < n; i++) {
		arr[i] = mas[0][i];
	}
	
	arr[n] = A[0];
	sortBubble(arr, n + 1);
	int t = binSearch(arr, 0, n, A[0]);
	delete[] arr;
	return t;
}

void sortBubble(int* a, int k) {
	for (int i = k-1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

int binSearch(int* a, int l, int r, int k) {
	int mid = 0;
	while (true) {
		mid = (l + r) / 2;
		if (k < a[mid])
			r = mid - 1;
		else if (k > a[mid])
			l = mid + 1;
		else return mid;
		if (l > r)
			return -1;
	}
}
