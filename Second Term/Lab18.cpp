#include <iostream>
#include "Windows.h"
#include <string>

using namespace std;

class Person {
public:
  Person();
  Person(string, int, string, string);
  void changeName(string);
  void changeAge(int);
  void changeGender(string);
  void changePhoneNumber(string);
  void print();
private:
  string _name;
  int _age;
  string _gender;
  string _phoneNumber;
};

Person::Person() {
  _name = "";
  _age = -1;
  _gender = "";
  _phoneNumber = "";
}

Person::Person(string name, int age, string gender, string phoneNumber) {
  _name = name;
  _age = age;
  _gender = gender;
  _phoneNumber = phoneNumber;
}

void Person::changeName(string name) {
  _name = name;
  cout << "Имя изменено" << endl;
}

void Person::changeAge(int age) {
  _age = age;
  cout << "Возраст изменён" << endl;
}

void Person::changeGender(string gender) {
  _gender = gender;
  cout << "Пол изменён" << endl;
}

void Person::changePhoneNumber(string phoneNumber) {
  _phoneNumber = phoneNumber;
  cout << "Номер телефона изменён" << endl;
}

void Person::print() {
  cout << "Имя: " << _name << endl;
  cout << "Возраст: " << _age << endl;
  cout << "Пол: " << _gender << endl;
  cout << "Номер телефона: " << _phoneNumber << endl;
}


class Student :public Person {
public:
  Student();
  Student(string, int, string, string, int, string);
  void changeCourse(int);
  void changeFormOfEducation(string);
  void print();
private:
  int _course;
  string _formOfEducation;
};

Student::Student() {
  _course = 0;
  _formOfEducation = "";
}

Student::Student(string name, int age, string gender, string phoneNumber, int course, 
  string formOfEducation):Person(name, age, gender, phoneNumber) {
  Student::_course = course;
  Student::_formOfEducation = formOfEducation;
}

void Student::changeCourse(int course) {
  _course = course;
  cout << "Курс изменён" << endl;
}

void Student::changeFormOfEducation(string formOfEducation) {
  _formOfEducation = formOfEducation;
  cout << "Форму обучения изменена" << endl;
}

void Student::print() {
  Person::print();
  cout << "Курс: " << _course << endl;
  cout << "Форму обучения: " << _formOfEducation << endl;
}



void main() {
  setlocale(LC_ALL, "Russian");
  Person A("Дмитрий", 19, "мужской", "8-800-555-35-35");
  A.print();
  A.changeAge(20);
  A.changePhoneNumber("7-800-555-35-35");
  A.print();
  Student B("Иван", 18, "мужской", "7-55-55-555-55", 2, "Бюджет");
  B.print();
  B.changeFormOfEducation("Контракт");
  B.changeCourse(3);
  B.print();
}