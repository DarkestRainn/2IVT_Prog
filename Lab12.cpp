#include <iostream>
#include "Windows.h"
#include <string>

using namespace std;

struct Book {
		string name;
		string author;
		string genre;
		int has;
	};
	const int n = 1;
	Book library[n];

void main() {
	setlocale(LC_ALL, "Russian");
	string key;

	for(int i = 0; i < n; i++){
		cout << "Название: ";
		getline(cin,library[i].name);
		cout << "Автор: ";
		getline(cin,library[i].author);
		cout << "Жанр: ";
		getline(cin,library[i].genre);
		cout << "Наличие: ";
		cin >> library[i].has;
		cin.ignore();
	}
	cout << "Ключ: ";
	getline(cin, key);
	for(int i = 0; i < n; i++){
		if((key == library[i].name) || (key == library[i].author) || (key == library[i].genre)){
			cout << "книга найдена и ";
		} else cout << "книга не найдена"<<endl;
	}
	cout << "Книги в наличии:"<<endl;
	for(int i = 0; i < n; i++){
		if(library[i].has){
			cout << "Название: " << library[i].name << "  " 
				<< "Автор: " << library[i].author << "  " 
				<< "Жанр: " << library[i].genre<<endl;
		}
	}
}