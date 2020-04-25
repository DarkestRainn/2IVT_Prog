#include <iostream>
#include "Windows.h"
#include <string>

using namespace std;

class Delivery;

class Supplier {
public:
	void changeAttributes(Delivery *, int);
	void changeAttributes(Delivery *, float);
	void changeAttributes(Delivery *, int, float);

};

class Delivery {
public:
	friend void Supplier::changeAttributes(Delivery *, int);
	friend void Supplier::changeAttributes(Delivery *, float);
	friend void Supplier::changeAttributes(Delivery *, int, float);
	void showAmountFromSpecificCountry(string, string);
	void fill();
	void fill(string,float, int, string);
private:
	string _nameOfProduct;
	float _costPerUnit;
	int _amount;
	string _countryOfDelivery;
};

void Delivery::showAmountFromSpecificCountry(string nameOfProduct, string countryOfDelivery) {
	if (nameOfProduct == _nameOfProduct && countryOfDelivery == _countryOfDelivery) {
		cout << "Кол-во поступаемого товара " << nameOfProduct << " из страны " << countryOfDelivery << ": " << _amount << endl;
	} else  cout << nameOfProduct << " из страны " << countryOfDelivery << "не поставляется" << endl;
}

void Delivery::fill() {
	cout << "Введите название товара: " << endl;
	getline(cin,_nameOfProduct);
	cout << "Введите стоимость товара за единицу" << endl;
	cin >> _costPerUnit;
	cout << "Введите кол-во товара" << endl;
	cin >> _amount;
	cin.ignore();
	cout << "Введите страну поставщика товара" << endl;
	getline(cin, _countryOfDelivery);
}

void Delivery::fill(string nameOfProduct, float costPerUnit, int amount, string countryOfDelivery) {
	_nameOfProduct = nameOfProduct;
	_costPerUnit = costPerUnit;
	_amount = amount;
	_countryOfDelivery = countryOfDelivery;
}



void Supplier::changeAttributes(Delivery *D, int amount) {
	D->_amount = amount;
	cout << "Количество товара успешно изменено" << endl;
}

void Supplier::changeAttributes(Delivery *D, float costPerUnit) {
	D->_costPerUnit = costPerUnit;
	cout << "Стоимость товара за единицу успешно изменена" << endl;
}

void Supplier::changeAttributes(Delivery *D, int amount, float costPerUnit) {
	D->_amount = amount;
	D->_costPerUnit = costPerUnit;
	cout << "Количество товара и его стоимость за единицу успешно изменены" << endl;
}



void main() {
	setlocale(LC_ALL, "Russian");
	const int n = 2;
	string tempNameOfProduct;
	string tempCountryOfDelivery;
	Delivery A[n];
	for (int i = 0; i < n; i++) {
		cout << "#" << i + 1 << ":" << endl;
		A[i].fill();
	}
	cout << "Введите искомые товар и страну поставщика:" << endl;
	getline(cin, tempNameOfProduct);
	getline(cin, tempCountryOfDelivery);
	A->showAmountFromSpecificCountry(tempNameOfProduct, tempCountryOfDelivery);
	Supplier B;
	B.changeAttributes(&A[0], 700.00f);
	A->showAmountFromSpecificCountry(tempNameOfProduct, tempCountryOfDelivery);
}