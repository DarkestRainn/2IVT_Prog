#include <iostream>
#include "Windows.h"
#include "time.h"

using namespace std;
void task1();
int searchIndex(int**,int*, int, int);
void sortBubble(int*, int);
int binSearch(int*, int, int, int);

void main() {
	setlocale(LC_ALL, "Russian");
	int sw;
	do {
		cout << "����� ������� ���������? (��� ������ ������� 0): ";
		cin >> sw;
		switch (sw) {
		case 1:
			task1();
			break;
		case 0:
			break;
		default:
			cout << "����������� ������� �������!" << endl;
			break;
		}
	} while (!sw == 0);
}


void task1() {
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
	//���������� �������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			B[i][j] = rand() % 100 + 1;
		}
	}

	//���������� ������� A
	cout << "������� A: ";
	for (int i = 0; i < 10; i++) {
		A[i] = rand() % 50 + 1;
		cout << A[i] << "  ";
	}
	cout << endl;
	//���������� ������ ������
	sortBubble(B[0], 10);
	cout << "\n�������� ������� B:" << endl;
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int j = 0; j < n; j++) {
			cout << B[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	index =  searchIndex(B, A, n, n);
	//����������� �� ������� B � ����� ������ C
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = B[i][j];
		}
	}
	//����� ��������� � ������� � ��� ��� ������� index ������� A
	for (int i = 0; i < n; i++) {
		for (int j = n; j >= index; j--) {
			C[i][j] = C[i][j-1];
		}
		C[i][index] = A[i];
	}
	cout << "����� ������� B � ����������� �������� A:" << endl;
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int j = 0; j < n+1; j++) {
			cout << C[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	//������� ������
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
