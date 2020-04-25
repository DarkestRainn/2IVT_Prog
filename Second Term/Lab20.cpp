#include <iostream>
#include "Windows.h"
#include <string>

using namespace std;

template <class T> class MyEllipse {
private:
  T _a;
  T _b;
public:
  MyEllipse(T a, T b){
    _a = a;
    _b = b;
  }
  T perimeter() {
    T squaredDifference = pow(_a, 2) - 2 * _a * _b + pow(_b, 2);
    return 4 * ((3.1415 * _a * _b + squaredDifference) / (_a + _b));
  }
  bool operator< (MyEllipse E) {
    if (perimeter() < E.perimeter()) {
      return true;
    } else return false;
  }
};

template <class T> class Circle : public MyEllipse <T> {
private:
  T _radius;
public:
  Circle(T radius) : MyEllipse<T> (radius, radius){
    _radius = radius;
  }
  T perimeter() {
    return MyEllipse<T>::perimeter();
  }
};

void main() {
  setlocale(LC_ALL, "Russian");
  MyEllipse <double> e(2, 3);
  cout << e.perimeter() << endl;
  Circle <double> C(3);
  cout << C.perimeter() << endl;
  if (e.perimeter() < C.perimeter()) {
    cout << "Истина" << endl;
  } else cout << "Ложь" << endl;
}