#include <iostream>
#include "windows.h"
#include <string>

using namespace std;

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char c;
	int points = 0;
	cout << "������ ������ � �������, ����� �� ��������� ��������� � ������������"<<endl<<"��������� ��������� ����������� ������ ����."<<endl;
	cout << "1. ���� ������� ���� ������ ������, ��:" <<endl
		 << "�) ������� ������� � ������������ ����-������ ����������� ��� ���-������ ��������;"<<endl
		 << "�) �������������� � ��������, �� ���������� �� ������� ���� ������� �������� �� ��������� ��� � ����;"<<endl
		 << "�) ����� ���� �����, ��� ���� ���-������ �������� � ��������� �����-������ ������ �������� �����."<<endl;
	cin >> c;
	switch (c) {
	case '�':
		points += 7;
		break;
	case '�':
		points += 5;
		break;
	case '�':
		points += 1;
		break;
	default:
		cout << "������ �����!"<<endl;
	}
	cout << "2. ��������� �� ���������, ��� �� ��������� �����?" <<endl
		 << "�) ��������� ��, � ��� ���������� ���� �����������;"<<endl
		 << "�) ������� � ��������, ��� ���������� ������ ���;"<<endl
		 << "�) ����������� ������ �������(��) ����� (�������), � ��� ������ ��������� �������� ��������������."<<endl;
	cin >> c;
	switch (c) {
	case '�':
		points += 7;
		break;
	case '�':
		points += 5;
		break;
	case '�':
		points += 3;
		break;
	default:
		cout << "������ �����!"<<endl;
	}	
	cout << "3. ���� ������� ���������� � ������ ����� ������ ��� �� 15 ���, ��� �� ����������:" <<endl
		 << "�) ����������� �������������� ����������� �������� � ������ �� ����� ������������ �������;"<<endl
		 << "�) ����� ���������, ��� ����-������ � ������ ������� ������ ����� ���� � �����, �, ��� ������ ����� ���� ����������, � �������� �� �������������;"<<endl
		 << "�) ���������, ��� ��� ����� ���� � �����, ���� ������� ���� ������ � ������������."<<endl;
	cin >> c;
	switch (c) {
	case '�':
		points += 7;
		break;
	case '�':
		points += 5;
		break;
	case '�':
		points += 3;
		break;
	default:
		cout << "������ �����!"<<endl;
	}
	cout << "4. � ����� �������� �������������� ��� ���� �������. ������ ���� �������?" <<endl
		 << "�) ����� ������� �������� �� ����� �����;"<<endl
		 << "�) ����� �������������, ��� ��� �� �����;"<<endl
		 << "�) ��� ��� ������, ��� ������ ����� � ����������� � ���������� � ��� �����������."<<endl;
	cin >> c;
	switch (c) {
	case '�':
		points += 7;
		break;
	case '�':
		points += 5;
		break;
	case '�':
		points += 3;
		break;
	default:
		cout << "������ �����!"<<endl;
	}	
	cout << "5. ��� ���������� ���� ������ ������������?" <<endl
		 << "�) ������������ ��������, ������, �������, ����������� ����������� ��� ���� �����;"<<endl
		 << "�) ������������ �����, �������� ��������� �� �������, ����������� � ������������;"<<endl
		 << "�) ���������� ���, ��� ��� ������� � ������������."<<endl;
	cin >> c;
	switch (c) {
	case '�':
		points += 7;
		break;
	case '�':
		points += 5;
		break;
	case '�':
		points += 3;
		break;
	default:
		cout << "������ �����!"<<endl;
	}
	cout << "�� ������� " << points << " ������" <<endl;
	if (points > 29 && points < 35 ) {
		cout << "�� ��������� ����� ��������� ������!" <<endl;
	} else if (points > 22 && points < 28) {
		cout << "��, �� ���� ���������, ���������� ��������������� � ��������� � ���� �������."<<endl;
	} else if (points < 21 ){
		cout << "��, ������, �������, ������ �����." <<endl;
	}
}
