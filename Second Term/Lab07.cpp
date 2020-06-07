#include <iostream>
#include "Windows.h"
#include <fstream>
#include <string>

using namespace std;
void task1();
void task2();

void separationFiles();
void combineFiles();
void convertToMozre(string);
void convertFromMozre(string);

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
	separationFiles();
	combineFiles();
}

void task2() {
  void convert(char[50]);
  string eng;
	cin.ignore();
  getline(cin, eng);
	convertToMozre(eng);
	string str;
	cout << "Введите строку Морзе (буквы через 1 пробел, слова через 2 пробела):" << endl;
	getline(cin, str);
	str += ' ';
	string temp;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ' ') {
      if (!temp.empty()) {
        convertFromMozre(temp);
        temp.clear();
      }
      if (str[i] == ' ' && str[i + 1] == ' ') {
        cout << " ";
      }
    } else {
      temp += str[i];
    }
  }
  cout << endl;
}

void separationFiles() {
	fstream sourceFile;
	fstream fileOutput1;
	fstream fileOutput2;
	sourceFile.open("input.txt", ios::in);
	fileOutput1.open("output1.txt", ios::out);
	fileOutput2.open("output2.txt", ios::out);
	string temp;
	int i = 1;
	while (!sourceFile.eof()) {
		getline(sourceFile, temp);
		if (i % 2 == 0) {
			fileOutput2 << temp << endl;
		} else {
			fileOutput1 << temp << endl;
		}
		++i;
		temp.clear();
	}
	cout << "Разделение файлов закончено" << endl;
	sourceFile.close();
	fileOutput1.close();
	fileOutput2.close();
}

void combineFiles() {
	fstream combinedFile;
	fstream fileOutput1;
	fstream fileOutput2;
	combinedFile.open("combined.txt", ios::out);
	fileOutput1.open("output1.txt", ios::in);
	fileOutput2.open("output2.txt", ios::in);
	string temp;
	int i = 1;
	while (!fileOutput1.eof() && !fileOutput2.eof()) {
		if (i % 2 == 0) {
			getline(fileOutput2, temp);
			if (!temp.empty()) {
				combinedFile << temp << endl;
			}
		} else {
			getline(fileOutput1, temp);
			if (!temp.empty()) {
				combinedFile << temp << endl;
			}
		}
		++i;
		temp.clear();
	}
	cout << "Объединение файлов закончено" << endl;
	combinedFile.close();
	fileOutput1.close();
	fileOutput2.close();
}

void convertToMozre(string str) {
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ' ')
      cout << " ";
    else if (str[i] == 'A' || str[i] == 'a')
      cout << ".-" << " ";
    else if (str[i] == 'B' || str[i] == 'b')
      cout << "-..." << " ";
    else if (str[i] == 'C' || str[i] == 'c')
      cout << "-.-." << " ";
    else if (str[i] == 'D' || str[i] == 'd')
      cout << "-.." << " ";
    else if (str[i] == 'E' || str[i] == 'e')
      cout << "." << " ";
    else if (str[i] == 'F' || str[i] == 'f')
      cout << "..-." << " ";
    else if (str[i] == 'G' || str[i] == 'g')
      cout << "--." << " ";
    else if (str[i] == 'H' || str[i] == 'h')
      cout << "...." << " ";
    else if (str[i] == 'I' || str[i] == 'i')
      cout << ".." << " ";
    else if (str[i] == 'J' || str[i] == 'j')
      cout << ".---" << " ";
    else if (str[i] == 'K' || str[i] == 'k')
      cout << "-.-" << " ";
    else if (str[i] == 'L' || str[i] == 'l')
      cout << ".-.." << " ";
    else if (str[i] == 'M' || str[i] == 'm')
      cout << "--" << " ";
    else if (str[i] == 'N' || str[i] == 'n')
      cout << "-." << " ";
    else if (str[i] == 'O' || str[i] == 'o')
      cout << "---" << " ";
    else if (str[i] == 'P' || str[i] == 'p')
      cout << ".--." << " ";
    else if (str[i] == 'Q' || str[i] == 'q')
      cout << "--.-" << " ";
    else if (str[i] == 'R' || str[i] == 'r')
      cout << ".-." << " ";
    else if (str[i] == 'S' || str[i] == 's')
      cout << "..." << " ";
    else if (str[i] == 'T' || str[i] == 't')
      cout << "-" << " ";
    else if (str[i] == 'U' || str[i] == 'u')
      cout << "..-" << " ";
    else if (str[i] == 'V' || str[i] == 'v')
      cout << "...-" << " ";
    else if (str[i] == 'W' || str[i] == 'w')
      cout << ".--" << " ";
    else if (str[i] == 'X' || str[i] == 'x')
      cout << "-..-" << " ";
    else if (str[i] == 'Y' || str[i] == 'y')
      cout << "-.--" << " ";
    else if (str[i] == 'Z' || str[i] == 'z')
      cout << "--.." << " ";
  }
  cout << endl;
}

void convertFromMozre(string str) {
  if (str == ".-")
    cout << "a";
  else if (str == "-...")
    cout << "b";
  else if (str == "-.-.")
    cout << "c";
  else if (str == "-..")
    cout << "d";
  else if (str == ".")
    cout << "e";
  else if (str == "..-.")
    cout << "f";
  else if (str == "--.")
    cout << "g";
  else if (str == "....")
    cout << "h";
  else if (str == "..")
    cout << "i";
  else if (str == ".---")
    cout << "j";
  else if (str == "-.-")
    cout << "k";
  else if (str == ".-..")
    cout << "l";
  else if (str == "--")
    cout << "m";
  else if (str == "-.")
    cout << "n";
  else if (str == "---")
    cout << "o";
  else if (str == ".--.")
    cout << "p";
  else if (str == "--.-")
    cout << "q";
  else if (str == ".-.")
    cout << "r";
  else if (str == "...")
    cout << "s";
  else if (str == "-")
    cout << "t";
  else if (str == "..-")
    cout << "u";
  else if (str == "...-")
    cout << "v";
  else if (str == ".--")
    cout << "w";
  else if (str == "-..-")
    cout << "x";
  else if (str == "-.--")
    cout << "y";
  else if (str == "--..")
    cout << "z";
}