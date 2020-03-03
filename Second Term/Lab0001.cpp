#include <iostream>
#include "Windows.h"
#include "time.h"
#include "math.h"

using namespace std;

struct Stack {
	float data;
	Stack *next;
};

void task1();
void task2();
void stackPush(float, Stack **);
float stackPop(Stack **);

Stack *topStack;

void main() {
	setlocale(LC_ALL, "Russian");
	int sw;
	do {
		cout << "Какое выражение посчитать? (Для выхода введите 0): ";
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
	float *x = new float;
	float *y = new float;
	float *c = new float;
	cout << "Введите последовательно x, y и c: ";
	cin >> *x >> *y >> *c;
	float *temp = new float;
	*temp = pow(*x, 3);
	*temp *= 2;
	stackPush(*temp, &topStack);
	*temp = 2 * *(y);
	stackPush(*temp, &topStack);
	*temp = 8 * *(c);
	stackPush(*temp, &topStack);
	*temp = *x;
	stackPush(*temp, &topStack);
	float *res = new float;
	*res = 0;
	*res += stackPop(&topStack);
	*res -= stackPop(&topStack);
	*res += stackPop(&topStack);
	*res += stackPop(&topStack);
	cout << "Ответ: " << *res << endl;
	delete temp;
	delete x;
	delete y;
	delete c;
	delete res;
}

void task2() {
	float *x = new float;
	cout << "Введите  x: ";
	cin >> *x;
	float *temp = new float;
	*temp = sin(*x);
	stackPush(*temp, &topStack);
	*temp = (sin(2 * *(x))) / 2;
	stackPush(*temp, &topStack);
	*temp = (sin(3 * *(x))) / 3;
	stackPush(*temp, &topStack);
	float *res = new float;
	*res = 0;
	*res += stackPop(&topStack);
	*res -= stackPop(&topStack);
	*res += stackPop(&topStack);
	cout << "Ответ: " << *res << endl;
	delete temp;
	delete x;
	delete res;
}

void stackPush(float D, Stack **topStack) {
	Stack *newItem = new Stack;
	newItem->data = D;
	if (topStack == NULL) {
		*topStack = newItem;
	} else {
		newItem->next = *topStack;
		*topStack = newItem;
	}
}

float stackPop(Stack **topStack) {
	Stack *q = *topStack;
	if (topStack != NULL) {
		float temp = q->data;
		*topStack = q->next;
		delete q;
		return temp;
	}
}