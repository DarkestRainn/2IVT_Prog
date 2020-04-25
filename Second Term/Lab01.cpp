#include <iostream>
#include "Windows.h"
#include <fstream>
#include <queue>
#include <vector>

using namespace std;
void task1();
void task2();

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
	fstream file;
	file.open("file.txt", ios::out);
	int N;
	cin >> N;
	for(int i = 2; i < N+1; i++){
		int k = i;
		while(k % 2 == 0){
			k /= 2;
		}
		while (k % 3 == 0){
			k /= 3;
		}
		while (k % 5 == 0){
			k /= 5;
		}
		if(k == 1){
			cout << i << "\t";
			if(file.is_open()){
				file << i << endl;
			}
		}
	}
	file.close();
}

void task2() {
	vector <double> fib(2,1);
	int n;
	cin >> n;
	for(int i = 2; i < n+1; i++){
		fib.push_back(fib[i-1]+fib[i-2]);
	}
	double res;
	res = pow(fib[n-1],2)-(fib[n-2]*fib[n]);
	cout << res<<endl;
}