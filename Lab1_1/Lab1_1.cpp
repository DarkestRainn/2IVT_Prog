#include <iostream>
#include "windows.h"

using namespace std;

void lab1_1_1();
void lab1_1_2();

void main() {
	setlocale(LC_ALL, "Russian");
	int c;
	do {
		cout << "����� ������� ���������? (��� ������ ������� 0): ";
		cin >> c;
		switch (c) {
		case 1:
			lab1_1_1();
			break;
		case 2:
			lab1_1_2();
			break;
		case 0:
			break;
		default:
			cout<<"������ �����!"<<endl;
			break;
		} 
	} while (!c == 0);
}

void lab1_1_1() {
	float R;
	cout << "������� ������ ����������: ";
	cin >> R;
	cout << "����� ���������� �����: " << 2 * 3.14*R << endl << "������� ����� �����: " << 3.14*pow(R,2)<<endl;
}


void lab1_1_2() {
	float S, t;
	cout << "������� ���������� ����� �������� (��): ";
	cin >> S;
	cout << "������� ��������� ����� (�): ";
	cin >> t;
	cout << "��� ����� ����� �� ��������� " << S / t << " ��/� ����� ���������� ������ �� " << t <<" �����"<<endl;
}