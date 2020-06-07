#include < conio.h>
#include <iostream>

using namespace std;

int main() {


  int i, j, N = 2, M = 2, a[2][2], b[2][2]; int c[2][2]; // N - число столбцев. М - число рядков.
  char quit;


  do {
    cout << "\nInput matrix A \n";

    for (i = 0; i < N; i++) {

      for (j = 0; j < M; j++)


        cin >> a[i][j];

    }
    cout << "Input matrix B " << endl;

    for (i = 0; i < N; i++) {

      for (j = 0; j < M; j++)

        cin >> b[i][j];

    }
    for (i = 0; i < N; i++) {
      for (j = 0; j < M; j++)

        c[i][j] = a[i][j] + b[i][j];

    }
    system("cls");
    cout << " \t Summation Matrix \n";
    for (i = 0; i < N; i++) {

      for (j = 0; j < M; j++)

        cout << "\t" << c[i][j] << "\t";
      cout << endl;

    }

    cout << "\n\t To continue press y - ";
  } while (cin >> quit && quit == 'y');
  return 0;
}