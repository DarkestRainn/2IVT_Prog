#include <iostream>
#include "Windows.h"
#include "time.h"

using namespace std;

struct Node {
	int data;
	Node *next;
	Node *prev;
};

struct Deque {
	Node *head;
	Node *tail;
};


void pushDequeBack(int, Deque *);
void pushDequeFront(int, Deque *);
int popDequeBack(Deque *);
int popDequeFront(Deque *);
void printDeque(Deque *);
void clearDeque(Deque *);

Deque myDeque;

void main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	pushDequeFront(rand() % 100 + 1, &myDeque);
	pushDequeBack(rand() % 100 + 1, &myDeque);
	printDeque(&myDeque);
	clearDeque(&myDeque);
}

void pushDequeBack(int data, Deque *D) {
	Node *newItem = new Node;
	newItem->data = data;
	if (D->head != NULL) {
		newItem->prev = D->tail;
		newItem->next = NULL;
		D->tail->next = newItem;
		D->tail = newItem;
	} else {
		D->head = newItem;
		D->tail = D->head;
		D->tail->next = NULL;
		D->head->prev = NULL;
	}
}

void pushDequeFront(int data, Deque *D) {
	Node *newItem = new Node;
	newItem->data = data;
	if (D->head != NULL) {
		newItem->next = D->head;
		newItem->prev = NULL;
		D->head->prev = newItem;
		D->head = newItem;
	} else {
		D->head = newItem;
		D->tail = D->head;
		D->tail->next = NULL;
		D->head->prev = NULL;
	}
}

int popDequeBack(Deque *D) {
	if (D->head != NULL) {
		Node *current = D->tail;
		int temp = current->data;
		D->tail = D->tail->prev;
		D->tail->next = NULL;
		delete current;
		return temp;
	}
}

int popDequeFront(Deque *D) {
	if (D->head != NULL) {
		Node *current = D->head;
		int temp = current->data;
		D->head = D->head->next;
		D->head->prev = NULL;
		delete current;
		return temp;
	}
}

void printDeque(Deque *D) {
	Node *temp = D->head;
	while (temp != NULL) {
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << endl;
}

void clearDeque(Deque *D) {
	while (D->head != NULL) {
		Node *current = D->head;
		D->head = D->head->next;
		delete current;
	}
}
