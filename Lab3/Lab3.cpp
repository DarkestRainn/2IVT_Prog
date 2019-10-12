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
		cout << "����� ������� ���������? (��� ������ ������� 0): ";
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
			cout<<"����������� ������� �������!"<<endl;
			break;
		} 
	} while (!c == 0);
}

void lab3_1() {
	int n;
	do {
	cout << "������� ����������� ������������� �����: ";
	cin >> n;
	if (n < 999 || n > 9999) {
		cout << "������ �����!" <<endl;
	}
	} while (n < 999 || n > 9999);
	cout << "������������� ����� �������� �����: " << (n/10) % 10<<endl<<endl;
}

void lab3_2() {
	int n;
	float res;
	float a = 0, b = 0;
	do {
	cout << "������� ����������� �����: ";
	cin >> n;
	if (n < 1) {
		cout << "������ �����!" <<endl;
	}
	} while (n < 1);
	a = cos(float(1));
	b = sin(float(1));
	res = a/b;
	for (float i = 2; i <= n; i++) {
		a += cos(i);
		b += sin(i);
		res *= a/b;
	}
	cout << "���������: "<< res <<endl<<endl;
}

void lab3_3() {
	int N = 0;
	long res = 1;
	int arr[999];
	cout << "������� ������������������ ����� (����� ����� ����� 777): "<<endl;
	for (int i = 0; i < 999; i++){
		cin >> arr[i];
		N++;
		if (arr[i] == 777){
			arr[i] = 1;
			i = 1024;
		}
	}
	for (int i = 0; i < N; i++){
		res *= arr[i];
	}
	cout << "������������ ������������������ �����: " << res<<endl<<endl;
}

void lab3_4() {
	
}

void lab3_5() {
	
}

void lab3_6() {
	
}