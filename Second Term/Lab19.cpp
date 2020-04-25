#define _USE_MATH_DEFINES
#include <iostream>
#include "Windows.h"
#include <string>
#include "math.h"

using namespace std;

class CPoint {
public:
  CPoint();
  void fillData();
  void changeData(float, float);
  void displayData();
private:
  float _x;
  float _y;
};

CPoint::CPoint() {
  _x = 0;
  _y = 0;
}

void CPoint::fillData() {
  cout << "Введите координаты x и y: ";
  cin >> _x >> _y;
}

void CPoint::changeData(float x, float y) {
  _x = x;
  _y = y;
  cout << "Координаты изменены" << endl;
}

void CPoint::displayData() {
  cout << "Координаты:" << endl << "X: " << _x << endl << "Y: " << _y << endl;
}

class CCircle :public CPoint {
public:
  CCircle();
  void fillData();
  void changeData(float, float, float);
  void displayData();
  void calculateAreaOfCircle();
private:
  float _radius;
};

CCircle::CCircle():CPoint() {
  _radius = 0;
}

void CCircle::fillData() {
  CPoint::fillData();
  cout << "Введите радиус: ";
  cin >> _radius;
}

void CCircle::changeData(float x, float y, float radius) {
  CPoint::changeData(x, y);
  _radius = radius;
  cout << "Радиус изменён" << endl;
}

void CCircle::displayData() {
  CPoint::displayData();
  cout << "Радиус: " << _radius << endl;
}

void CCircle::calculateAreaOfCircle() {
  if (!_radius == 0) {
    float S = M_PI*pow(_radius,2);
    cout << "Площадь круга: " << S << endl;
  } else cout << "Радиус ещё не задан" << endl;
}

class CSquare {
public:
  CSquare();
  void fillData();
  void changeData(float);
  void displayData();
  void calculateAreaOfSquare();
  void calculatePerimeterOfSquare();
protected:
  float getLengthOfFirstSide();
private:
  float _lengthOfFirstSide;
};

CSquare::CSquare() {
  _lengthOfFirstSide = 0;
}

void CSquare::fillData() {
  cout << "Введите длину стороны: ";
  cin >> _lengthOfFirstSide;
}

void CSquare::changeData(float lengthOfFirstSide) {
  _lengthOfFirstSide = lengthOfFirstSide;
  cout << "Длина стороны изменена" << endl;
}

void CSquare::displayData() {
  cout << "Длина стороны: " << _lengthOfFirstSide << endl;
}

void CSquare::calculateAreaOfSquare() {
  if (!_lengthOfFirstSide == 0) {
    float S = pow(_lengthOfFirstSide, 2);
    cout << "Площадь квадрата: " << S << endl;
  } else cout << "Длина стороны не задана" << endl;
}

void CSquare::calculatePerimeterOfSquare() {
  if (!_lengthOfFirstSide == 0) {
    float P = _lengthOfFirstSide * 4;
    cout << "Периметр квадрата: " << P << endl;
  } else cout << "Длина стороны не задана" << endl;
}

float CSquare::getLengthOfFirstSide() {
  return _lengthOfFirstSide;
}

class CRectangle :public CSquare {
public:
  CRectangle();
  void fillData();
  void changeData(float, float);
  void displayData();
  void calculateAreaOfSquare();
  void calculatePerimeterOfSquare();
private:
  float _lengthOfSecondSide;
};

CRectangle::CRectangle():CSquare() {
  _lengthOfSecondSide = 0;
}

void CRectangle::fillData() {
  CSquare::fillData();
  cout << "Введите длину второй стороны: ";
  cin >> _lengthOfSecondSide;
}

void CRectangle::changeData(float lengthOfFirstSide, float lengthOfSecondSide) {
  CSquare::changeData(lengthOfFirstSide);
  _lengthOfSecondSide = lengthOfSecondSide;
  cout << "Длина второй стороны изменена" << endl;
}

void CRectangle::displayData() {
  CSquare::displayData();
  cout << "Длина второй стороны: " << _lengthOfSecondSide << endl;
}

void CRectangle::calculateAreaOfSquare() {
  if (!((CSquare::getLengthOfFirstSide() == 0) || (_lengthOfSecondSide == 0))) {
    float S = CSquare::getLengthOfFirstSide()*_lengthOfSecondSide;
    cout << "Площадь прямоугольника: " << S << endl;
  } else cout << "Одна из длин сторон не задана" << endl;
}

void CRectangle::calculatePerimeterOfSquare() {
  if (!((CSquare::getLengthOfFirstSide() == 0) || (_lengthOfSecondSide == 0))) {
    float P = (CSquare::getLengthOfFirstSide()+_lengthOfSecondSide)*2;
    cout << "Периметр прямоугольника: " << P << endl;
  } else cout << "Одна из длин сторон не задана" << endl;
}

void main() {
  setlocale(LC_ALL, "Russian");
  CCircle A;
  A.fillData();
  A.displayData();
  A.calculateAreaOfCircle();
  CRectangle B;
  B.fillData();
  B.displayData();
  B.calculateAreaOfSquare();
  B.changeData(3.0f, 2.0f);
  B.calculatePerimeterOfSquare();
}