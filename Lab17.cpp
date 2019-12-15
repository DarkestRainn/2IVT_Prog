#include <iostream>
#include "Windows.h"

using namespace std;

void deleteItem(int*, int&, int);
bool isPrime(int);

void main() {
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Введите N: ";
	cin >> N;
	int N2 = N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[j] % arr[i] == 0) {
				deleteItem(arr, N, j+1);
			}
		}
	}
	deleteItem(arr, N, 1);
	cout << "Простые числа до N:" << endl;
	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
	int* arrS = new int[N];
	for (int i = 0; i < N; i++) {
		if (isPrime(i+1)) {
			arrS[i] = arr[i];
		}
	}
	cout << "Сверхпростые числа до N:" << endl;
	for (int i = 0; i < N; i++) {
		if (arrS[i] > 0) {
			cout << arrS[i] << "\t";
		}
	}
	cout << endl;
	int S = 1;
	cout << "Совершенные числа до N: " << endl;
	for (int i = 6; i < N2; i++) {
		for (int j = 2; j < i && S <= i; j++) {
			if (i % j == 0) {
				S += j;
			}
		}
		if (i == S) {
			cout << S << "\t";
		}
		S = 1;
	}
	cout << endl;
	delete[] arr;
	delete[] arrS;
}

void deleteItem(int* arr, int &N, int I) {
	for (int i = I; i < N; i++) {
		arr[i-1] = arr[i];
	}
	N = N - 1;
}


bool isPrime(int k) {
	for (int d = 2; d <= k/d; d++) {
		if (k % d == 0) {
			return false;
		}
	}
	return k > 1;
}