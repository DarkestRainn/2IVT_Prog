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
		cout<<"Какое задание запустить?\nДля выхода введите 0"<<endl;
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
	cout<<"*    Лабораторная работа №1    *"<<endl;
	cout<<"*    Выполнил ст.гр. 2-ИВТ     *"<<endl;
	cout<<"*  Должиков Дмитрий Сергеевич  *"<<endl;
	cout<<"********************************"<<endl<<endl;
}


void lab1_2() {
	int a,b;
	cout<<"Введите рост в сантиметрах(см):";
	cin>>a;
	cout<<"Введите вес в граммах(г):";
	cin>>b;
	cout<<"Ваш рост "<<float(a)/100<<" м"<<endl<<"Ваш вес "<<b/1000<<" кг"<<endl;
}


void lab1_3() {
	int a,b,c;
	cout<<"Введите 3 числа:"<<endl<<"a: ";
	cin>>a;
	cout<<"b: ";
	cin>>b;
	cout<<"c: ";
	cin>>c;
	
	cout<<"Среднее арифметическое: "<<(float(a)+float(b)+float(c))/3<<endl<<endl;
}



void lab1_4() {
	int a,b;
	cout<<"Введите часы: ";
	cin>>a;
	cout<<"Введите минуты: ";
	cin>>b;
	cout<<"Итого секунд: "<<(a*60*60)+(b*60)<<endl<<endl;
}

void lab1_5() {
	float x,y,ch,zn;
	cout<<"Введите x: ";
	cin>>x;
	cout<<"Введите y: ";
	cin>>y;
	if(x-y==0 || x+y==0){
		cout<<"Ошибка!Неверные данные"<<endl;
	} else {
		ch=(2*x*x)+(2*y*y);
		zn=(x-y)*(x+y);
		cout<<"Результат: "<<ch/zn<<endl<<endl;
	}
}


void lab1_6() {
	float x,y,N;
	cout << "Введите вашу сумму денег: ";
	cin >> y;
	cout << "Введите размер скидки: ";
	cin >> x;
	cout << "Введите стоимость товара: ";
	cin >> N;
	y=y-(N-N*x/100);
	cout<<"У вас останется "<<y<<" рублей"<<endl<<endl;
}

void lab1_7() {
	float y,x,N;
	cout << "Введите количество прочитанных страниц: ";
	cin >> x;
	cout << "Введите процент прочитанных страниц: ";
	cin >> y;
	y=y/100;
	N=x/y;
	cout << "Всего страниц в книге: " << int(N) << endl;
}

