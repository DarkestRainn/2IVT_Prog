#include <iostream>
#include "windows.h"

using namespace std;

void lab1_1();
void lab1_2();
void lab1_3();
void lab1_4();
void lab1_5();
void lab1_6();
void lab1_7();

void main() {
	setlocale(LC_ALL, "Russian");
	int c;
	do {
		cout<<"����� ������� ���������?\n��� ������ ������� 0"<<endl;
		cin>>c;
		switch(c){
			case 1:
				lab1_1();
				break;
			case 2:
				lab1_2();
				break;
			case 3:
				lab1_3();
				break;
			case 4:
				lab1_4();
				break;
			case 5:
				lab1_5();
				break;
			case 6:
				lab1_6();
				break;
			case 7:
				lab1_7();
				break;
		}
	} while (!c==0);
}

void lab1_1() {
	cout<<"********************************"<<endl;
	cout<<"*    ������������ ������ �1    *"<<endl;
	cout<<"*    �������� ��.��. 2-���     *"<<endl;
	cout<<"*  �������� ������� ���������  *"<<endl;
	cout<<"********************************"<<endl<<endl;
}


void lab1_2() {
	int a,b;
	cout<<"������� ���� � �����������(��):";
	cin>>a;
	cout<<"������� ��� � �������(�):";
	cin>>b;
	cout<<"��� ���� "<<float(a)/100<<" �"<<endl<<"��� ��� "<<b/1000<<" ��"<<endl;
}


void lab1_3() {
	int a,b,c;
	cout<<"������� 3 �����:"<<endl<<"a: ";
	cin>>a;
	cout<<"b: ";
	cin>>b;
	cout<<"c: ";
	cin>>c;
	
	cout<<"������� ��������������: "<<(float(a)+float(b)+float(c))/3<<endl<<endl;
}



void lab1_4() {
	int a,b;
	cout<<"������� ����: ";
	cin>>a;
	cout<<"������� ������: ";
	cin>>b;
	cout<<"����� ������: "<<(a*60*60)+(b*60)<<endl<<endl;
}

void lab1_5() {
	float x,y,ch,zn;
	cout<<"������� x: ";
	cin>>x;
	cout<<"������� y: ";
	cin>>y;
	if(x-y==0 || x+y==0){
		cout<<"������!�������� ������"<<endl;
	} else {
		ch=(2*x*x)+(2*y*y);
		zn=(x-y)*(x+y);
		cout<<"���������: "<<ch/zn<<endl<<endl;
	}
}


void lab1_6() {
	float x,y,N;
	cout << "������� ���� ����� �����: ";
	cin >> y;
	cout << "������� ������ ������: ";
	cin >> x;
	cout << "������� ��������� ������: ";
	cin >> N;
	y=y-(N-N*x/100);
	cout<<"� ��� ��������� "<<y<<" ������"<<endl<<endl;
}

void lab1_7() {
	float y,x,N;
	cout << "������� ���������� ����������� �������: ";
	cin >> x;
	cout << "������� ������� ����������� �������: ";
	cin >> y;
	y=y/100;
	N=x/y;
	cout << "����� ������� � �����: " << int(N) << endl;
}

