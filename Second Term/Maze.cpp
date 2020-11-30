#include <iostream>
#include "Windows.h"
#include <vector>
#include <deque>
#include "time.h"
#include <conio.h>
#include <iomanip>

using namespace std;

struct Cell {
  int x;
  int y;
  char symbol;
  bool isWall = false;
  bool isBorder = false;
  int directionOfExit = 0;
};

class Maze {
private:
  Cell **maze;
  //переменные размеров лабиринта
  int width;
  int height;

  int ax;
  int ay;//координаты начала
  int bx; //(userWidth * 2 - 1);
  int by;// = (userHeight * 2 - 1);//координаты конца

  bool initinitializedMaze = false;

  //переменные для поиска пути методом Ли
  const int WALL = -1; //стена
  const int BLANK = -2; //непосещённая ячейка
  int len; //длина пути выхода
  int *px, *py;//массивы координат пути

  //переменные для генерации лабиринта
  const int UP = 1;
  const int RIGHT = 2;
  const int DOWN = 3;
  const int LEFT = 4;

  vector <Cell> notVisitedCells;//вектор, хранящий непосещённые пустые ячейки лабиринта
  vector <Cell> emptyCells;//вектор, хранящий все ячейки, не являющиеся стенами
  vector<Cell> labyrinth;//вектор, хранящий ячейки готового лабиринта
  deque <Cell> path;//дек, хранящий путь движения по лабиринту во время очередного цикла генерации
public:
  void generateMaze();
  void display();
  void displayGrid();
  void generatePathFromEntranceToExit(); //генерация пути от начала к концу

  ~Maze() { //деструктор класса, очищающий динамическую память
    for (int i = 0; i < height; i++) {
      delete[] maze[i];
    }
    delete[] maze;
    delete[] px;
    delete[] py;
  }
protected:
  void deleteCellFromNotVisited(Cell, vector<Cell> &);//функция удаления ячейки из вектора непосещённых ячеек
  bool isHasInVector(Cell, const vector<Cell> &);//функция проверки наличия ячейки в векторе
  bool compareCells(Cell, Cell);//функция сравнения двух ячеек
  Cell shiftInDirection(Cell, const vector<Cell> &); //функция перемещения по направление выхода к след. ячейке
  int getIndexCell(Cell, const deque<Cell> &);//получение индекса ячейка в деке и
  int getIndexCell(Cell, const vector<Cell> &);//векторе соответственно
};

void Maze::generateMaze() {
  srand(time(NULL));
  //ввод размерности лабиринта
  int *temp = new int;
  cout << "Введите размер лабиринта одним числом." << endl << "Он может быть только квадратным (N x N)" <<
    endl << "Например, для размера 7x7 нужно ввести число 7 один раз" <<
    endl << "Размер: ";
  do {
    cin >> *temp;
    cout << endl;
    if (*temp > 1) {
      Maze::height = *temp * 2 + 1;
      Maze::width = *temp * 2 + 1;
    } else {
      cout << "Размерность не может быть меньше 2x2! " << endl << "Повторите ввод: ";
    }
  } while (*temp <= 1);

  delete temp;

  //создание двумерного массива типа Cell
  maze = new Cell * [height];
  for (int i = 0; i < height; i++) {
    maze[i] = new Cell[width];
  }
  initinitializedMaze = true;
  //заполнение сетки стенами
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      maze[i][j].x = i;
      maze[i][j].y = j;
      //каждую ячейку, у которой любая координата чётная, делаем стеной
      if (i % 2 == 0 || j % 2 == 0) {
        maze[i][j].symbol = '#';
        maze[i][j].isWall = true;
      } else maze[i][j].symbol = ' '; //остальные делаем пустой ячейкой
      if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {//обозначаем границы лабиринта
        maze[i][j].isBorder = true;
      }
    }
  }
  Maze::displayGrid(); //вывод сетки

  //ввод координат ячеек
  bool coordsOK;

  cout << "Введите координаты входа и выхода в виде x1 y1 x2 y2" << endl <<
    "Координатами x обозначаются номера строк (Отсчёт от 0, границы и стенки не учитываются)" << endl <<
    "Координатыми y обозначаются номера столбцов (Отсчёт от 0, границы и стенки не учитываются)" << endl <<
    "(Одна и та же ячейка не может быть и входом и выходом): ";
  int *x1 = new int;
  int *y1 = new int;
  int *x2 = new int;
  int *y2 = new int;

  do {
    cin.clear();
    while (cin.get() != '\n');
    cin >> *x1;
    cin >> *y1;
    cin >> *x2;
    cin >> *y2;
    Maze::ax = (*x1) * 2 + 1;
    Maze::ay = (*y1) * 2 + 1;
    Maze::bx = (*x2) * 2 + 1;
    Maze::by = (*y2) * 2 + 1;
    if (ax <= 0 || ay <= 0 || ax >= height || ay >= width || /* если координаты ax, ay вне границ лабиринта*/
      bx <= 0 || by <= 0 || bx >= height || by >= width || /*если координаты bx, by вне границ лабиринта*/
      (ax == bx && ay == by)) { /*если ячейка входа и выхода одна и та же*/
      coordsOK = false;
      cout << "Повторите ввод:" << endl;
    } else {
      coordsOK = true;
    }
  } while (!coordsOK);

  delete x1;
  delete y1;
  delete x2;
  delete y2;

  //заполнение вектора непосещённых пустых ячеек
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (!maze[i][j].isWall && !maze[i][j].isBorder) {
        notVisitedCells.push_back(maze[i][j]);
      }
    }
  }
  //заполняем вектор пустых ячеек
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (!maze[i][j].isWall && !maze[i][j].isBorder) {
        emptyCells.push_back(maze[i][j]);
      }
    }
  }

  Cell randFirstCell = notVisitedCells[rand() % notVisitedCells.size()];//выбираем случайную ячейку из непосещённых
  labyrinth.push_back(randFirstCell);//добавляем её к готовому лабиринту
  deleteCellFromNotVisited(randFirstCell, notVisitedCells);//удаляем из непосещённых

  //случайное перемещение по лабиринту
  while (!notVisitedCells.empty()) {//пока есть непосещённые ячейки
    //выбираем случайную ячейку из непосещённых и добавляем её в путь
    path.push_front(notVisitedCells[rand() % notVisitedCells.size()]);
    while (!path.empty()) {//если путь не пустой
      Cell currentCell = path.front();//выбираем первый элемент из пути как текущую ячейку
      vector <Cell> nextSteps;//вектор, для хранения всех возможных следующих шагов
      //ищем все соседние ячейки, которые находятся в границах лабиринта и добавляем их в вектор nextSteps
      if (currentCell.x > 1) {
        nextSteps.push_back(maze[currentCell.x - 2][currentCell.y]);
      }
      if (currentCell.x < width - 2) {
        nextSteps.push_back(maze[currentCell.x + 2][currentCell.y]);
      }
      if (currentCell.y > 1) {
        nextSteps.push_back(maze[currentCell.x][currentCell.y - 2]);
      }
      if (currentCell.y < height - 2) {
        nextSteps.push_back(maze[currentCell.x][currentCell.y + 2]);
      }

      if (!nextSteps.empty()) {//если следующие шаги есть
        Cell nextCell = nextSteps[rand() % nextSteps.size()];//выбираем случайную ячейку из соседей следующей
        //запоминаем в какую сторону по отношению к текущей ячейке мы вышли
        if (currentCell.x != nextCell.x) {
          if (currentCell.x - nextCell.x > 0) {
            path[getIndexCell(currentCell, path)].directionOfExit = UP;
            emptyCells[getIndexCell(currentCell, emptyCells)].directionOfExit = UP;
          } else
            if (currentCell.x - nextCell.x < 0) {
              path[getIndexCell(currentCell, path)].directionOfExit = DOWN;
              emptyCells[getIndexCell(currentCell, emptyCells)].directionOfExit = DOWN;
            }
        }
        if (currentCell.y != nextCell.y) {
          if (currentCell.y - nextCell.y > 0) {
            path[getIndexCell(currentCell, path)].directionOfExit = LEFT;
            emptyCells[getIndexCell(currentCell, emptyCells)].directionOfExit = LEFT;
          } else
            if (currentCell.y - nextCell.y < 0) {
              path[getIndexCell(currentCell, path)].directionOfExit = RIGHT;
              emptyCells[getIndexCell(currentCell, emptyCells)].directionOfExit = RIGHT;
            }
        }

        if (isHasInVector(nextCell, labyrinth)) {//если мы дошли до ячейки, которая уже в лабиринте
          Cell _FirstCell = path.back();//запоминаем начальную ячейку из пути
          Cell _cell;
          auto iter2 = path.begin();
          while (iter2 != path.end()) {//выбираем ближайшую к концу пути ячейку, которая соответствует первой
            if (compareCells(_FirstCell, (*iter2))) {
              _cell = (*iter2);
              break;
            }
            ++iter2;
          }

          //восстановление пути
          while (!isHasInVector(_cell, labyrinth)) {//пока текущая ячейка не в готовом лабиринте 
            if (_cell.directionOfExit == UP) {//если мы ушли наверх
              maze[_cell.x - 1][_cell.y].symbol = ' ';
              maze[_cell.x - 1][_cell.y].isWall = false;//убираем стену между текущей ячейкой и той, в которую ушли
            } else
              if (_cell.directionOfExit == DOWN) {//если мы ушли вниз
                maze[_cell.x + 1][_cell.y].symbol = ' ';
                maze[_cell.x + 1][_cell.y].isWall = false;//убираем стену между текущей ячейкой и той, в которую ушли
              } else
                if (_cell.directionOfExit == RIGHT) {//если мы ушли вправо
                  maze[_cell.x][_cell.y + 1].symbol = ' ';
                  maze[_cell.x][_cell.y + 1].isWall = false;//убираем стену между текущей ячейкой и той, в которую ушли
                } else
                  if (_cell.directionOfExit == LEFT) {//если мы ушли влево
                    maze[_cell.x][_cell.y - 1].symbol = ' ';
                    maze[_cell.x][_cell.y - 1].isWall = false;//убираем стену между текущей ячейкой и той, в которую ушли
                  }
                labyrinth.push_back(_cell);//добавляем в готовый лабиринт текущую ячейку
                Cell _newCell = shiftInDirection(_cell, emptyCells);//запоминаем ячейку, в которую ушли
                deleteCellFromNotVisited(_cell, notVisitedCells);//удаляем ячейку, из которой ушли
                _cell = _newCell;//делаем ячейку, в которую ушли текущей
          }
          path.clear();//очищаем путь
          auto iter = emptyCells.begin();
          while (iter != emptyCells.end()) {//обнуляем направления выхода
            (*iter).directionOfExit = 0;
            ++iter;
          }
        } else {//если не дошли до ячейки, которая в готовом лабиринте
          path.push_front(nextCell);//добавляем следующую ячейку в путь и двигаемся дальше
        }
      }
    }
  }
  Maze::display();
}

void Maze::generatePathFromEntranceToExit() {
  int **grid = new int *[height];
  for (int i = 0; i < height; i++) {
    grid[i] = new int[width];
  }

  //заполняем массив grid стенами и непосещёнными ячейками
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      switch (maze[i][j].symbol) {
      case '#':
        grid[i][j] = WALL;
        break;
      case ' ':
        grid[i][j] = BLANK;
        break;
      }
    }
  }


  bool pathFound = true;

  px = new int[width * height];
  py = new int[width * height];

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};//приращения координат для хождения к соседям ячейки
  int d, x, y, k;
  bool stop;


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

  if (pathFound) {//если путь найден
    //прорисовка пути от входа к выходу символом точки
    for (int i = 0; i <= len; i++) {
      maze[px[i]][py[i]].symbol = '.';
    }
    Maze::display();
  } else {
    cout << "Путь не найден" << endl;
  }

  //очищение памяти
  for (int i = 0; i < height; i++) {
    delete[] grid[i];
  }
  delete[] grid;
}

void Maze::display() {
  //вывод лабиринта
  if (initinitializedMaze) {
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        cout << Maze::maze[i][j].symbol << ' ';
      }
      cout << endl;
    }
    cout << endl;
  } else cout << "Лабиринт не сгенерирован!";
}

void Maze::displayGrid() {
  //вывод сетки
  cout << "    ";
  for (int i = 0; i < height; i++) {
    if (i % 2 == 1) {
      cout << setw (2) <<floor(i / 2) << ' ';
    } else {
      cout << ' ';
    }
  }
  cout << endl;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (j == 0) {
        if (i % 2 == 1) {
          cout << setw (3) << floor(i / 2) << ' ';
        } else cout << setw (4) << " ";
      }
      cout << Maze::maze[i][j].symbol << ' ';
    }
    cout << endl;
  }
  cout << endl;
}


void Maze::deleteCellFromNotVisited(Cell _cell, vector<Cell> &v) {
  auto iter = v.begin();
  while (iter != v.end()) {
    if (_cell.x == (*iter).x && _cell.y == (*iter).y) {
      v.erase(iter);
      break;
    }
    ++iter;
  }
}

bool Maze::isHasInVector(Cell _cell, const vector<Cell> &v) {
  for (int i = 0; i < v.size(); i++) {
    if (_cell.x == v[i].x && _cell.y == v[i].y) {
      return true;
    }
  }
  return false;
}

bool Maze::compareCells(Cell _cell, Cell _cell2) {
  if (_cell.x == _cell2.x && _cell.y == _cell2.y) {
    return true;
  }
  return false;
}

Cell Maze::shiftInDirection(Cell _cell, const vector<Cell> &v) {
  if (_cell.directionOfExit == UP) {
    for (int i = 0; i < v.size(); i++) {
      if (_cell.x - 2 == v[i].x && _cell.y == v[i].y) {
        return v[i];
      }
    }
  }
  if (_cell.directionOfExit == DOWN) {
    for (int i = 0; i < v.size(); i++) {
      if (_cell.x + 2 == v[i].x && _cell.y == v[i].y) {
        return v[i];
      }
    }
  }
  if (_cell.directionOfExit == RIGHT) {
    for (int i = 0; i < v.size(); i++) {
      if (_cell.x == v[i].x && _cell.y + 2 == v[i].y) {
        return v[i];
      }
    }
  }
  if (_cell.directionOfExit == LEFT) {
    for (int i = 0; i < v.size(); i++) {
      if (_cell.x == v[i].x && _cell.y - 2 == v[i].y) {
        return v[i];
      }
    }
  }
}

int Maze::getIndexCell(Cell _cell, const deque<Cell> &d) {
  for (int i = 0; i < d.size(); i++) {
    if (_cell.x == d[i].x && _cell.y == d[i].y) {
      return i;
    }
  }
}

int Maze::getIndexCell(Cell _cell, const vector<Cell> &v) {
  for (int i = 0; i < v.size(); i++) {
    if (_cell.x == v[i].x && _cell.y == v[i].y) {
      return i;
    }
  }
}


void main() {
  setlocale(LC_ALL, "Russian");
  cout << "Генератор лабиринта и поиск оптимального пути" << endl;
  int sw;
  do {
    cout << "Меню:" << endl << "Для генерации лабиринта и поиска оптимального пути введите введите 1" << endl <<
      "Для выхода введите 0" << endl << "Ваша команда: ";
    cin >> sw;
    if (sw == 1) {
      Maze M;
      M.generateMaze();
      cout << "Для построения оптимального пути нажмите любую клавишу..." << endl << endl;
      _getch();
      M.generatePathFromEntranceToExit();
    } else if (sw != 1 && sw != 0) {
      cout << "Неправильно выбрана команда!" << endl;
    }
  } while (sw != 0);
}