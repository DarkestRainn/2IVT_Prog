#include <iostream>
#include "Windows.h"

using namespace std;

struct Node {
	char data[1];
	Node *next;
};

struct Queue {
	Node *first;
	Node *last;
};

void makeQueue(Queue *);
void addElemQueue(char, Queue *);
char popQueue(Queue *);

Queue sequence;

void main() {
	//задание #2
	setlocale(LC_ALL, "Russian");
	char seq[]{'D','O','S','$','.'};
	int size = sizeof(seq) / sizeof(char);
	char specialChar; 
	bool deleteSpecialChar = true; //удалять спец. символ
	cout << "Введите специальный символ: ";
	cin >> specialChar;
	makeQueue(&sequence);
	for (int i = 0; i < size; i++) {
		if (seq[i+1] != specialChar) {
			if (seq[i] == specialChar && deleteSpecialChar) {
				addElemQueue('\0', &sequence);
			} else addElemQueue(seq[i], &sequence);
		} else addElemQueue('\0', &sequence);
	}
	for (int i = 0; i < size; i++) {
		char s = popQueue(&sequence);
		if (s != '\0') {
			cout << s;
		}
	}
	cout << endl;
}

void makeQueue(Queue *Q) {
	Q->first = new Node;
	Q->first->next = nullptr;
	Q->last = Q->first;
}

void addElemQueue(char data, Queue *Q) {
	Q->last->next = new Node;
	Q->last = Q->last->next;
	Q->last->data[0] = data;
	Q->last->next = nullptr;
}

char popQueue(Queue *Q) {
	if (Q->first->next != nullptr) {
		Node *q = Q->first;
		char temp = Q->first->next->data[0];
		Q->first = Q->first->next;
		delete q;
		return temp;
	} else return '\0';
}