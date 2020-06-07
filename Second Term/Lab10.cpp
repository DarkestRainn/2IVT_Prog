#include <iostream>
#include "Windows.h"
#include <string>

using namespace std;
void task1();
void task2();

string arabicToRome(unsigned int);
int romeToArabic(string);

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
  setlocale(LC_ALL, "Russian");
  int a;
  cout << "Введите число: ";
  cin >> a;
  cout << "Ваше число: ";
  if (a < 0) {
    cout << "Минусовое число";
  }
  switch (a / 100) {
  case 1: cout << "Сто "; break;
  case 2: cout << "Двести "; break;
  case 3: cout << "Триста "; break;
  case 4: cout << "Четыреста "; break;
  case 5: cout << "Пятсот "; break;
  case 6: cout << "Шестьсот "; break;
  case 7: cout << "Семьсот "; break;
  case 8: cout << "Восемьсот "; break;
  case 9: cout << "Девятьсот "; break;
  }
  switch ((a % 100) / 10) {
  case 2: cout << "двадцать "; break;
  case 3: cout << "тридцать "; break;
  case 4: cout << "сорок "; break;
  case 5: cout << "пятдесят "; break;
  case 6: cout << "шестьдесят "; break;
  case 7: cout << "Семьдесят "; break;
  case 8: cout << "Восемьдесят "; break;
  case 9: cout << "Девяносто "; break;
  }
  if ((a % 100 >= 10) & (a % 100 < 20)) {
    switch (a % 100) {
    case 10: cout << "десять"; break;
    case 11: cout << "одинадцать"; break;
    case 12: cout << "двенадцать"; break;
    case 13: cout << "тринадцать"; break;
    case 14: cout << "четырнадцать"; break;
    case 15: cout << "пятнадцать"; break;
    case 16: cout << "шестнадцать"; break;
    case 17: cout << "семнадцать"; break;
    case 18: cout << "восемнадцать"; break;
    case 19: cout << "девятнадцать"; break;
    }
  } else {
    switch (a % 10) {
    case 0: cout << "ноль"; break;
    case 1: cout << "один"; break;
    case 2: cout << "два"; break;
    case 3: cout << "три"; break;
    case 4: cout << "четыре"; break;
    case 5: cout << "пять"; break;
    case 6: cout << "шесть"; break;
    case 7: cout << "семь"; break;
    case 8: cout << "восемь"; break;
    case 9: cout << "девять"; break;
    }
  }
  cout << endl;
}

void task2() {
  setlocale(LC_ALL, "Russian");
  unsigned int arabic;
  //перевод из арабском в римскую
  cout << "Введите арабское число: ";
  cin >> arabic;
  cout << "Римская запись: " << arabicToRome(arabic) << endl;
  //перевод из римской в арабскую
  string lat;
  cout << "Введите римское число: ";
  cin.ignore();
  getline(cin, lat);
  cout << "Арабская запись: " << romeToArabic(lat) << endl;
}

string arabicToRome(unsigned int arabic) {

  const struct TNumber {
    string rome;
    unsigned arabic;
  };
  TNumber CNumber[] = {{"I",    1}, {"IV",   4}, {"V",   5}, {"IX",   9},
                   {"X",   10}, {"XL",  40}, {"L",  50}, {"XC",  90},
                   {"C",  100}, {"CD", 400}, {"D", 500}, {"CM", 900},
                   {"M", 1000}};
  unsigned i = sizeof(CNumber) / sizeof(*CNumber) - 1;
  string rome;

  while (arabic) {

    while (CNumber[i].arabic > arabic) {
      --i;
    }

    rome += CNumber[i].rome;
    arabic -= CNumber[i].arabic;
  }

  return rome;
}

int romeToArabic(string lat) {
  int count = 0;
  for (int i = 0; i < lat.length(); i++) {
    switch (lat[i]) {
    case 'M':
      count += 1000;
      break;
    case 'D':
      count += 500;
      break;
    case 'C':
      if (i + 1 < lat.length() && (lat[i + 1] == 'D' || lat[i + 1] == 'M'))
        count -= 100;
      else
        count += 100;
      break;
    case 'L':
      count += 50;
      break;
    case 'X':
      if (i + 1 < lat.length() && (lat[i + 1] == 'L' || lat[i + 1] == 'C' || lat[i + 1] == 'M'))
        count -= 10;
      else
        count += 10;
      break;
    case 'V':
      count += 5;
      break;
    case 'I':
      if (i + 1 < lat.length() && (lat[i + 1] == 'V' || lat[i + 1] == 'X' || lat[i + 1] == 'C'))
        count -= 1;
      else count += 1;
      break;
    }
  }
  return count;
}
