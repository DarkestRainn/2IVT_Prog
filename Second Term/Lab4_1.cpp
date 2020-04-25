#include <iostream>
#include "Windows.h"
#include "time.h"
#include <vector>

using namespace std;

void main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n;
	cin >> n;
	vector <int> arr(n);
	for(int i = 0; i < n; i++){
		arr[i] = rand() % 10-3;
	}
	for(vector<int>::iterator iter = arr.begin(); iter != arr.end();iter++){
		cout << *iter << endl;
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1; j++) {
			if (arr[j+1] > arr[j]) {
				swap(arr[j+1],arr[j]);
			}
		}
	}
	cout << endl << endl;
	for(vector<int>::iterator iter = arr.begin(); iter != arr.end();iter++){
		cout << *iter << endl;
	}
}