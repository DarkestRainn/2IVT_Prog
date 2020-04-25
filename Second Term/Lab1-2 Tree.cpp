#include <iostream>
#include "Windows.h"
#include "time.h"

using namespace std;

struct BinaryTree {
	int data;
	BinaryTree *left;
	BinaryTree *right;
};

void makeBinaryTree(BinaryTree **, int);
void printBinaryTree(BinaryTree *, int);
void preOrderBinaryTree(BinaryTree *);
void postOrderBinaryTree(BinaryTree *);
void insertNodeBinaryTree(BinaryTree **, int);
void deleteBinaryTree(BinaryTree *Node);
void deleteNodeBinaryTree(BinaryTree **Node, int data);

BinaryTree *Btree = NULL;

void main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	makeBinaryTree(&(Btree), 3);
	postOrderBinaryTree(Btree);
}

void makeBinaryTree(BinaryTree **Node, int n) {
	BinaryTree **ptr;
	srand(time(NULL) * 1000);
	while (n > 0) {
		ptr = Node;
		while (ptr != Node) {
			if ((double) rand() / RAND_MAX < 0.5) {
				ptr = &((*ptr)->left);
			} else ptr = &((*ptr)->right);
		}
		(*ptr) = new BinaryTree();
		cout << "Введите значение ";
		cin >> (*ptr)->data;
		n--;
	}
}

void printBinaryTree(BinaryTree *Node, int l) {
	int i;
	if (Node != NULL) {
		printBinaryTree(Node->right, l + 1);
		for (i = 0; i < l; i++) {
			cout << "  ";
		}
		cout << Node->data;
		printBinaryTree(Node->left, l + 1);
	} else cout << endl;
}

void preOrderBinaryTree(BinaryTree *Node) {
	if (Node != NULL) {
		cout << Node->data;
		preOrderBinaryTree(Node->left);
		preOrderBinaryTree(Node->right);
	}
}

void postOrderBinaryTree(BinaryTree *Node) {
	if (Node != NULL) {
		postOrderBinaryTree(Node->left);
		postOrderBinaryTree(Node->right);
		cout << Node->data;
	}
}

void insertNodeBinaryTree(BinaryTree **Node, int data) {
	BinaryTree *newNode = new BinaryTree;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	BinaryTree **ptr = Node;
	srand(time(NULL) * 1000);
	while (*ptr != NULL) {
		double q = (double) rand() / RAND_MAX;
		if (q < 1 / 3.0) ptr = &((*ptr)->right);
		else break;
	}
	if (*ptr != NULL) {
		if ((double) rand() / RAND_MAX < 0.5)
			newNode->left = *ptr;
		*ptr = newNode;
	} else {
		*ptr = newNode;
	}
}

void deleteBinaryTree(BinaryTree *Node) {
	if (Node != NULL) {
		deleteBinaryTree(Node->left);
		deleteBinaryTree(Node->right);
		delete (Node);
	}
}

void deleteNodeBinaryTree(BinaryTree **Node, int data) {
	if ((*Node) != NULL) {
		if ((*Node)->data = data) {
			BinaryTree *ptr = (*Node);
			if ((*Node)->left == NULL && (*Node)->right == NULL) (*Node) = NULL;
			else if ((*Node)->left == NULL) (*Node) = ptr->right;
			else if ((*Node)->right == NULL) (*Node) = ptr->left;
			else {
				(*Node) = ptr->right;
				BinaryTree **ptr1;
				ptr1 = Node;
				while (*ptr1 != NULL)
					ptr1 = &((*ptr1)->left);
				(*ptr1) = ptr->left;
			}
			delete(ptr);
			deleteNodeBinaryTree(Node, data);
		}
		else {
			deleteNodeBinaryTree(&((*Node)->left), data);
			deleteNodeBinaryTree(&((*Node)->right), data);
		}
	}
}