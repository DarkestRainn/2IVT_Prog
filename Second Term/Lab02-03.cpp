#include <iostream>
#include "Windows.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;
void task1();
void task2();
void task3();
void task4();

struct Word {
	string data;
	int count = 0;
};

bool compareSymbolWithArray(char, char*, int);
bool hasStringOnArrWords(string, Word *, int);
bool hasStringOnArrWords(string, vector <Word>, int);
int searchIndexOfStringInArrWords(string, Word *, int);
int searchIndexOfStringInArrWords(string, vector <Word>, int);
void addWordInVecWords(string, vector <Word> *);

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
		case 3:
			task3();
			break;
		case 4:
			task4();
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
	vector <string> arrstr;
	string str;
	char punctuationСharacters[] = {' ', ',', '.', '!', '?', ';', '\0', '\n'};
	int size = sizeof(punctuationСharacters) / sizeof(char);
	cout << "Введите строку:" << endl;
	cin.ignore();
	getline(cin, str);
	str += '\0';
	string temp;
	for (int i = 0; i < str.length(); i++) {
		if (compareSymbolWithArray(str[i], punctuationСharacters, size)) {//выделяю слова
			if (!temp.empty()) {
				arrstr.push_back(temp);//добавляю слово в вектор слов
				temp.clear();
			}
		} else {
			temp += str[i];
		}
	}
	int i = 1;
	auto iter = arrstr.begin();
	while (iter != arrstr.end()) {
		cout << i << ": " << *iter << endl;
		++iter;
		++i;
	}
	temp.clear();
}

void task2() {
	string str2;
	char punctuationСharacters2[] = {' ', ',', '.', '!', '?', ';', '\0', '\n'};
	int size2 = sizeof(punctuationСharacters2) / sizeof(char);
	cout << "Введите строку:" << endl;
	cin.ignore();
	getline(cin, str2);
	str2 += '\0';
	int from = 0, to = 0, maxLength = 0, maxTo, maxFrom = 0;
	bool flag = false;
	for (int i = 0; i < str2.length(); i++) {//нахожу индексы первого слова строки
		if (compareSymbolWithArray(str2[i], punctuationСharacters2, size2)) {
			to = i;
			maxLength = i;
			maxTo = to - 1;
			break;
		}
	}
	for (int i = maxLength; i < str2.length(); i++) {//нахожу индексы остальных слов
		if (compareSymbolWithArray(str2[i], punctuationСharacters2, size2)) {
			if (!flag) {
				to = i;
				if ((to - from) > maxLength) {//если длина текущего слова больше длины прошлого максимального
					maxLength = to - from;
					maxFrom = from + 1;
					maxTo = to - 1;
				}
				flag = true;
			}
		}
		if (flag && compareSymbolWithArray(str2[i], punctuationСharacters2, size2)) {//нахожу начало след. слова
			flag = false;
			from = i;
		}
	}
	cout << "Самое длинное слово в строке: ";
	for (int i = maxFrom; i <= maxTo; i++) {
		cout << str2[i];
	}
	cout << endl;
}

void task3() {
	string str3;
	char punctuationСharacters3[] = {' ', ',', '.', ':', '-', '\'','\0'};
	vector <string> vecPronouns = {"i", "he", "she", "it", "me", "him", "her", "his", "we", "you", "they", "us", "them"};
	int sizePuncChars3 = sizeof(punctuationСharacters3) / sizeof(char);
	int size3 = vecPronouns.size();

	Word *arrPronouns = new Word[size3];

	for (int i = 0; i < size3; i++) {
		arrPronouns[i].data = vecPronouns[i];
	}
	string tempstr;
	fstream file;
	file.open("file3.txt", ios::in);
	while (!file.eof()) {
		getline(file, tempstr);
		str3 += tempstr;
	}
	file.close();
	str3 += '\0';
	string temp;

	for (int i = 0; i < str3.length(); i++) {
		if (compareSymbolWithArray(str3[i], punctuationСharacters3, sizePuncChars3)) {//выделяю слова
			if (!temp.empty()) {
				if (hasStringOnArrWords(temp, arrPronouns, size3)) {//если это слово является местоимением
					int tempIndex3 = searchIndexOfStringInArrWords(temp, arrPronouns, size3);//получаю его индекс в массиве местоимений
					if (tempIndex3 >= 0) {
						arrPronouns[tempIndex3].count++;//увеличиваю число появлений слова
					}
					tempIndex3 = -1;
				}
				temp.clear();
			}
		} else {
			temp += tolower(str3[i]);
		}
	}
	cout << "Местоимения(их кол-во):" << endl;
	for (int i = 0; i < size3; i++) {
		if (arrPronouns[i].count > 0) {
			cout << arrPronouns[i].data << "(" << arrPronouns[i].count << ")" << endl;
		}
	}
	temp.clear();
}

void task4() {
	string str4;
	char punctuationСharacters4[] = {' ', ',', '.', ':', '-', '\0'};
	int sizePuncChars4 = sizeof(punctuationСharacters4) / sizeof(char);
	string tempstr;
	fstream file4;
	file4.open("file4.txt", ios::in);
	while (!file4.eof()) {
		getline(file4, tempstr);
		str4 += tempstr;
	}
	file4.close();
	str4 += '\0';
	string temp;
	vector <Word> vecWords;

	for (int i = 0; i < str4.length(); i++) {
		if (compareSymbolWithArray(str4[i], punctuationСharacters4, sizePuncChars4)) {//выделяю слова
			if (!temp.empty()) {
				if (hasStringOnArrWords(temp, vecWords, vecWords.size())) {//если слово уже есть в векторе слов
					int tempIndex4 = searchIndexOfStringInArrWords(temp, vecWords, vecWords.size());//получаю его индекс в векторе слов
					if (tempIndex4 >= 0) {
						vecWords[tempIndex4].count++;//увеличиваю число появлений слова
					}
				} else {
					addWordInVecWords(temp, &vecWords);//иначе добавляю в вектор слов
				}
				temp.clear();
			}
		} else {
			temp += tolower(str4[i]);
		}
	}

	for (int i = vecWords.size() - 1; i >= 0; i--) {//сортировка вектора слов
		for (int j = 0; j < i; j++) {
			if (vecWords[j].count < vecWords[j + 1].count) {
				Word tempItem = vecWords[j];
				vecWords[j] = vecWords[j + 1];
				vecWords[j + 1] = tempItem;
			}
		}
	}

	cout << "5 наиболее часто встречающихся слов и число их появлений:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << vecWords[i].data << "(" << vecWords[i].count << ")" << endl;
	}

	temp.clear();
}

bool compareSymbolWithArray(char c, char *arr, int size) {//функция сравнения символа с массивом символов
	for (int i = 0; i < size; i++) {
		if (c == arr[i]) {
			return true;
		}
	}
	return false;
}

bool hasStringOnArrWords(string str, Word *P, int size) {
	for (int i = 0; i < size; i++) {
		if (str == P[i].data) {
			return true;
		}
	}
	return false;
}

bool hasStringOnArrWords(string str, vector<Word> v, int size) {
	for (int i = 0; i < size; i++) {
		if (str == v[i].data) {
			return true;
		}
	}
	return false;
}

int searchIndexOfStringInArrWords(string str, Word *P, int size) {
	for (int i = 0; i < size; i++) {
		if (str == P[i].data) {
			return i;
		}
	}
	return -1;
}

int searchIndexOfStringInArrWords(string str, vector<Word> v, int size) {
	for (int i = 0; i < size; i++) {
		if (str == v[i].data) {
			return i;
		}
	}
	return -1;
}

void addWordInVecWords(string str, vector<Word> *v) {
	Word *newItem = new Word;
	newItem->count = 1;
	newItem->data = str;
	(*v).push_back(*newItem);
}
