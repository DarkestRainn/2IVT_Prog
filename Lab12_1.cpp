#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Windows.h"
#include <string>


using namespace std;

void addNewBook(int);
void searchInHasBooks(string);
void displayCharStr(char*);

struct Book {
	char name[10];
	char author[10];
	char genre[10];
	char has[1];
};
int amount;
Book* library;

void main() {
	setlocale(LC_ALL, "Russian");
	char key[10];
	int sw;
	do {
		cout << "Выберите: запись новой книги (1) или поиск по книгам в наличии (2)(Выход 0)";
		cin >> sw;
		switch (sw) {
		case 1:
			cout << "Сколько книг хотите добавить? ";
			cin >> amount;
			cin.ignore();
			addNewBook(amount);
			break;
		case 2:
			cout << "Ключ: ";
			cin >> key;
			searchInHasBooks(key);
			break;
		case 0:
			break;
		default:
			cout << "Неправильный выбор!" << endl;
			break;
		}
	} while (sw != 0);


}

void addNewBook(int amount) {
	library = new Book[amount];
	char amountChar[2];
	fstream file;
	file.open("library.txt", ios::out);
	if (file.is_open()) {
		_itoa(amount, amountChar, 10);
		file.write(amountChar, 2);
		for (int i = 0; i < amount; i++) {
			cout << "Название: ";
			cin >> library[i].name;
			file.write(library[i].name, 10);
			cout << "Автор: ";
			cin >> library[i].author;
			file.write(library[i].author, 10);
			cout << "Жанр: ";
			cin >> library[i].genre;
			file.write(library[i].genre, 10);
			cout << "Наличие: ";
			cin >> library[i].has;
			file.write(library[i].has, 1);
		}
		file.close();
	}
}

void searchInHasBooks(string key) {
	char amountChar[2];
	int amount;
	fstream file;
	file.open("library.txt", ios::in);
	char c, strName[10], strAuthor[10], strGenre[10];
	if (file.is_open()) {
		file.read(amountChar, 2);
		amount = atoi(amountChar);
		for (int i = 0; i < amount; i++) {
			file.seekg(30, ios::cur);
			file >> c;
			if (c == '1') {
				file.seekg(-31, ios::cur);
				file.read(strName, 10);
				file.read(strAuthor, 10);
				file.read(strGenre, 10);
				if (key == strName || key == strAuthor || key == strGenre) {
					cout << "Название: "; displayCharStr(strName);
					cout << "Автор: "; displayCharStr(strAuthor);
					cout << "Жанр: "; displayCharStr(strGenre);
				} else cout << "Таких книг нет в наличии";
				file.seekg(1, ios::cur);
			}
		}
	}
	cout << endl;
}

void displayCharStr(char* str) {
	for (int i = 0; i < strlen(str); i++) {
		cout << str[i];
	}
	cout << endl;
}