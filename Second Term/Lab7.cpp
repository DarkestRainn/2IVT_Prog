#include <iostream>
#include "Windows.h"

using namespace std;

void main() {
  setlocale(LC_ALL, "Russian");
  const int WALL = -1; //стена
  const int BLANK = -2; //непосещённая ячейка
  int height = 7;
  int width = height;//размеры лабиринта
  int **grid = new int *[height];
  for (int i = 0; i < height; i++) {
    grid[i] = new int[width];
  }

  //здесь по лабиринту заполняется сетка grid стенами и непосещёнными ячейками

  bool pathFound = true;

  int *px = new int[width * height];
  int *py = new int[width * height];

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};//приращения координат для хождения к соседям ячейки
  int d, x, y, k;
  bool stop;
  int ax, ay; //стартовая ячейка
  int bx, by; //финишная ячейка
  int len; //длина пути


  //распространение волны
  d = 0; //цифра волны
  grid[ax][ay] = 0;//для начальных координат задаём d = 0
  do {
    stop = true;
    for (int x = 0; x < height; x++) {
      for (int y = 0; y < width; y++) {
        if (grid[x][y] == d) {//если ячейка с координатами x, y равна d
          for (int k = 0; k < 4; k++) {//ходим по соседям
            int ix = x + dx[k];
            int iy = y + dy[k];
            //если текущий сосед в границах лабиринта и он непосещённая ячейка
            if (ix > 0 && ix < width && iy > 0 && iy < height && grid[ix][iy] == BLANK) {
              stop = false;
              grid[ix][iy] = d + 1;//записываем ячейке след. цифру волны
            }
          }
        }
      }
    }
    d++;//увеличиваем цифру волны
  } while (!stop && grid[bx][by] == BLANK);//выполняем пока ячейка выхода непосещена

  if (grid[bx][by] == BLANK) {//если ячейка выхода всё ещё непосещённая
    pathFound = false;// то путь не найден
  }

  //восстановление пути
  len = grid[bx][by];//запоминаем длину пути к выходу
  x = bx;
  y = by;
  d = len;
  while (d > 0) {
    px[d] = x;
    py[d] = y;//добавляем в массив координат пути координаты x, y, начиная с конца
    d--;
    for (int k = 0; k < 4; k++) {//ходим по соседям
      int ix = x + dx[k],
        iy = y + dy[k];
      if (ix >= 0 && ix < width && iy >= 0 && iy < height && grid[ix][iy] == d) {//ищем следующую ячейку пути
        x = x + dx[k];
        y = y + dy[k];//приращиваем координаты
        break;
      }
    }
  }
  px[0] = ax;
  py[0] = ay;
  
  //здесь два массива координат используются для отрисовки пути выхода из лабиринта

  //очищение памяти
  for (int i = 0; i < height; i++) {
    delete[] grid[i];
  }
  delete[] grid;
}