#include <iostream>
#include "Windows.h"
#include "time.h"

using namespace std;

struct Numbers {
	float Data;
	Numbers *Next;
};

void makeList(int, Numbers **);
void printList(Numbers *);
bool isEmpty(Numbers *);
void deleteList(Numbers *);
void sumElemList(Numbers *, float &);
int numberElemList(Numbers *, int);

Numbers *Head;

void main() {
	setlocale(LC_ALL, "Russian");
	float sum = 0;
	int count = 0;
	srand(time(NULL));
	makeList(rand() % 5, &Head);
	if (!isEmpty(Head)) {
		cout << "Элементы списка: ";
		printList(Head);
		sumElemList(Head, sum);
		count = numberElemList(Head, count);
		cout << "Среднее арифметическое элементов списка: " << sum / count << endl;
	} else cout << "Список пуст" << endl;
	deleteList(Head);
}

void makeList(int n, Numbers **Head) {
	if (n > 0) {
		(*Head) = new Numbers();
		(*Head)->Data = rand() % 10;
		(*Head)->Next = NULL;
		makeList(n - 1, &((*Head)->Next));
 	}
}

void printList(Numbers *Head) {
	if (Head != NULL) {
		cout << Head->Data << "\t";
		printList(Head->Next);
	} else cout << endl;
}

bool isEmpty(Numbers *Head) {
	if (Head != NULL) {
		return false;
	} return true;
}

void deleteList(Numbers *Head) {
	if (Head != NULL) {
		deleteList(Head->Next);
		delete Head;
	}
}

void sumElemList(Numbers *Head, float &sum) {
	if (Head != NULL) {
		sum += Head->Data;
		sumElemList(Head->Next, sum);
	}
}

int numberElemList(Numbers *Head,  int count) {
	if (Head != NULL) {
		++count;
		numberElemList(Head->Next, count);
	} else return count;
}