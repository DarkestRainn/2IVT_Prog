#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	string name;
	int group;
	int ses[5];
public:
	void fill();
	string getName();
	int getGroup();
	int getSes(int);
};

string Student::getName() {
	return name;
}

int Student::getGroup() {
	return group;
}

int Student::getSes(int i) {
	return ses[i];
}

void Student::fill() {
	cout << "Введите фамилию и инициалы: ";
	getline(cin, Student::name);
	cout << "Введите номер группы: ";
	cin >> Student::group;
	cout << "Введите 5 оценок:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "#" << i + 1 << ": "; 
		cin >> Student::ses[i];
	}
	cin.ignore();
}

void sortByName(Student *, const int);
void display(Student *, const int);

int main() {
	const int n = 2;
	setlocale(LC_ALL, "Russian");
	Student Stud1[n];
	for (int i = 0; i < n; i++) {
		Stud1[i].fill();
	}
	sortByName(Stud1, n);
	cout << "" << endl;
	display(Stud1, n);
}

void sortByName(Student *arr, const int n) {
	Student temp;
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j].getName() > arr[j + 1].getName()) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void display(Student *arr, const int n) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i].getSes(j) == 2) {
				flag = true;
				cout << "Студент: " << arr[i].getName() << "\t" << "Номер группы: " << arr[i].getGroup() << endl;
				break;
			}
		}
	}
	if (!flag) {
		cout << "Студентов с оценкой 2 нет" << endl;
	}
}