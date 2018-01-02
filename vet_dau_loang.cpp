#include <iostream>
using namespace std;
const int MAX = 50;
int a[MAX][MAX] = {
        { 0, 1, 1, 1, 0, 1 },
        { 1, 0, 1, 1, 0, 1 },
        { 1, 1, 0, 0, 1, 0 },
        { 0, 1, 1, 0, 0, 1 },
        { 0, 1, 0, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 1 },

};
int b[MAX][MAX];
int m = 8, n = 6;
void printB() {
    system("cls");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cout << b[i][j] << " ";
        cout << endl;
    }
    system("pause");
}
void danhdau(int hang, int cot, int mau) {
    if (a[hang][cot] == 0) return;
    if (b[hang][cot] != 0) return;
    b[hang][cot] = mau;
    printB();
    if (hang > 0)   danhdau(hang - 1, cot, mau);
    if (hang < m-1) danhdau(hang + 1, cot, mau);
    if (cot > 0)    danhdau(hang, cot - 1, mau);
    if (cot < n-1)  danhdau(hang, cot + 1, mau);
}
int main() {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) b[i][j] = 0;
    int mau = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if ((a[i][j] == 1) && (b[i][j] == 0)) {
                mau = mau + 1;
                danhdau(i, j, mau);
            }
}