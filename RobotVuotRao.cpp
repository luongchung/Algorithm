#include <iostream>
#include <iomanip>
using namespace std;
int m = 5, n = 7;
int a[5][7] =  {
  { 5, 6, 7, 3, 2, 4, 5 },
  { 4, 1,-9, 3, 3, 5, 2 },
  { 4, 2, 3, 5, 4, 4, 3 },
  { 7, 7, 7, 7, 1, 3, 2 },
  { 2, 3, 4, 2, 2, 4, 3 },
};
int b[5][7];
void printB() {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) cout << std::setw(3) << b[i][j];
    cout << endl;
  }
  cout << endl;
}
void initB() {
  for (int i = 0; i < n; i++) b[0][i] = a[0][i];
  for (int i = 1; i < m; i++) {
    b[i][0] = a[i][0] + min(b[i-1][0], b[i-1][1]);
    for (int j = 1; j < n-1; j++)
      b[i][j] = a[i][j] + min(b[i-1][j-1], min(b[i-1][j], b[i-1][j+1]));
    b[i][n-1] = a[i][n-1] + min(b[i-1][n-2], b[i-1][n-1]);
  }
}
void show(int p, int q) {
  if (p > 0) {
    if (b[p][q] == (a[p][q]+b[p-1][q]))show(p-1, q);
    else
      if ((q > 0) && (b[p][q] == (a[p][q]+b[p-1][q-1]))) show(p-1, q-1);
      else show(p-1, q+1);
  }
  cout << "[" << p << ", " << q << "] ";
}
findMinB() {
  int x = 0;
  for (int i = 1; i < n; i++)
    if (b[m-1][i] < b[m-1][x]) x = i;
    show(m-1, x);
}
int main() {
  initB();
  printB();
  findMinB();
}