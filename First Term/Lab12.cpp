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
		cout << "��������: ";
		getline(cin,library[i].name);
		cout << "�����: ";
		getline(cin,library[i].author);
		cout << "����: ";
		getline(cin,library[i].genre);
		cout << "�������: ";
		cin >> library[i].has;
		cin.ignore();
	}
	cout << "����: ";
	getline(cin, key);
	for(int i = 0; i < n; i++){
		if((key == library[i].name) || (key == library[i].author) || (key == library[i].genre)){
			cout << "����� ������� � ";
		} else cout << "����� �� �������"<<endl;
	}
	cout << "����� � �������:"<<endl;
	for(int i = 0; i < n; i++){
		if(library[i].has){
			cout << "��������: " << library[i].name << "  " 
				<< "�����: " << library[i].author << "  " 
				<< "����: " << library[i].genre<<endl;
		}
	}
}