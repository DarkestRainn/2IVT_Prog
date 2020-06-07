#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Windows.h"

using namespace std;

struct Stack {
	int data;
	Stack *next;
};

void stackPush(int, Stack **, int &);
int stackPop(Stack **);
int stackShow(Stack **);
int searchMinInStack(Stack **);
vector<int> searchLinesWithMin(Stack **, int, int);

Stack *topStack;


struct Node {
	char *data;
	Node *next;
};

struct Queue {
	Node *first;
	Node *last;
};

void makeQueue(Queue *);
void addElemQueue(char *, Queue *);
char *popQueue(Queue *);
void showQueue(Queue *);
Node *getElemQueue(Queue *);
void sortingQueue(Queue *, int);
void deleteQueue(Queue *);

Queue lines;


void main() {
	//задание #1
	setlocale(LC_ALL, "Russian");
	//стек
	int stackSize = 0;
	fstream file;
	file.open("file.txt", ios::in);

	string str;
	vector <string> vecstr;
	while(!file.eof()){
		getline(file, str);
		vecstr.push_back(str);
		stackPush(str.length(), &topStack, stackSize);
	}
	file.close();
	cout << "Кол-во элементов стека: " << stackSize << endl;
	int min = searchMinInStack(&topStack);
	cout << "Min length: " << min << endl;
	auto vj = searchLinesWithMin(&topStack, stackSize, min);
	auto iter = vj.rbegin();
	cout << "Lines with min length: ";
	while (iter != vj.rend()) {
		cout << *iter << "  ";
		++iter;
	}
	cout << endl;

	//очередь
	makeQueue(&lines);
	char **arrchars = new char *[stackSize];
	for (int i = 0; i < stackSize; i++) {
		arrchars[i] = new char[100];
	}

	int i = 0;
	auto iter2 = vecstr.begin();
	while (iter2 != vecstr.end()) {
		strcpy(arrchars[i], (*iter2).c_str());
		++iter2;
		++i;
	}

	for (int i = 0; i < stackSize; i++) {
		addElemQueue(arrchars[i], &lines);
	}

	cout << endl <<"Before sorting:" << endl;
	showQueue(&lines);
	cout << endl;
	
	sortingQueue(&lines, stackSize);
	
	cout << "After sorting:" << endl;
	showQueue(&lines);

	deleteQueue(&lines);
}


void stackPush(int D, Stack **topStack, int &stackSize) {
	stackSize++;
	Stack *newItem = new Stack;
	newItem->data = D;
	if (topStack == NULL) {
		*topStack = newItem;
	} else {
		newItem->next = *topStack;
		*topStack = newItem;
	}
}

int stackPop(Stack **topStack) {
	Stack *q = *topStack;
	if (*topStack != NULL) {
		int temp = q->data;
		*topStack = q->next;
		delete q;
		return temp;
	} else return -1;
}

int stackShow(Stack **topStack) {
	Stack *q = *topStack;
	if (*topStack != NULL) {
		int temp = q->data;
		return temp;
	} else return -1;
}

int searchMinInStack(Stack **topStack) {
	Stack *current = *topStack;
	int min = current->data;
	do {
		current = current->next;
		if (current->data < min) {
			min = current->data;
		}
	} while (current->next != NULL);
	return min;
}

vector<int> searchLinesWithMin(Stack **topStack, int stackSize, int min) {
	vector<int> j;
	int i = 0;
	Stack *current = *topStack;
	while (current != NULL) {
		if (current->data == min) {
			j.push_back(stackSize - i);
		}
		i++;
		current = current->next;
	}
	return j;
}


void makeQueue(Queue *Q) {
	Q->first = new Node;
	Q->first->next = NULL;
	Q->last = Q->first;
}

void addElemQueue(char *_data, Queue *Q) {
	Q->last->next = new Node;
	Q->last = Q->last->next;
	Q->last->data = _data;
	Q->last->next = NULL;
}

char *popQueue(Queue *Q) {
	char nil[1] = "";
	if (Q->first->next != NULL) {
		Node *q = Q->first;
		char *temp = Q->first->next->data;
		Q->first = Q->first->next;
		delete q;
		return temp;
	} else return nil;
}

void showQueue(Queue *Q) {
	Node *temp = Q->first->next;
	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}

Node *getElemQueue(Queue *Q) {
	Node *temp = Q->first->next;
	return temp;
}

void sortingQueue(Queue *Q, int stackSize) {
	for (int i = stackSize - 1; i >= 0; i--) {
		Node *current = getElemQueue(&lines);
		for (int j = 0; j < i; j++) {
			if (strlen(current->data) < strlen(current->next->data)) {
				char *temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
			}
			current = current->next;
		}
	}
}

void deleteQueue(Queue *Q) {
	while (Q->first != NULL) {
		Node *current = Q->first;
		Q->first = Q->first->next;
		delete current;
	}
}
