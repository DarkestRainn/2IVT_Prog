#include <iostream>
#include "windows.h"
#include <stdlib.h> 
#include <time.h> 

using namespace std;

void lab5_1();
void lab5_2();
void lab5_3();

void main() {
	setlocale(LC_ALL, "Russian");
	int c;
	do {
		cout << "Какое задание запустить? (Для выхода введите 0): ";
		cin >> c;
		switch (c) {
		case 1:
			lab5_1();
			break;
		case 2:
			lab5_2();
			break;
		case 3:
			lab5_3();
			break;
		case 0:
			break;
		default:
			cout<<"Неправильно выбрано задание!"<<endl;
			break;
		} 
	} while (!c == 0);
}

void lab5_1() {
	int mas[100];
	int max;
	srand(time(NULL));
	for(int i=0; i<100; i++){
		mas[i] = rand() % 500;
		cout << mas[i]<<endl;
	}
	max = mas[0];
	for (int i = 1;i<100;i++){
		if(mas[i]>max){
			max = mas[i];
		}

	}
}

void lab5_2() {
	
}

void lab5_3() {
	
}