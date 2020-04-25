#include <iostream>
#include "Windows.h"

using namespace std;

class Array {
private:
	int *arr;
	int size;
public:
	Array(int n) {
		arr = new int[n];
		size = n;
	}

	~Array() {
		delete arr;
	}

	void fillArray() {
		for (int i = 0; i < size; i++) {
			cout << "Введите значение: ";
			cin >> arr[i];
		}
	}

	void printArray() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << "\t";
		}
		cout << endl;
	}

	float arrayAverage() {
		int sum = 0;
		float avg = 0;
		for (int i = 0; i < size; i++) {
			sum += arr[i];
		}
		avg = sum / (float)size;
		return avg;
	}
};

void main() {
	setlocale(LC_ALL, "Russian");
	Array A(2);
	A.fillArray();
	A.printArray();
	cout << "Среднее арифметическое массива: " << A.arrayAverage() << endl;
}