#include <iostream>
#include <string>
using namespace std;
string w, s;
int dequy(int m, int n) {
  if ((m == 0) || (n == 0)) return 0;
  if (w[m-1] == s[n-1]) return 1 + dequy(m-1, n-1);
  return max(dequy(m-1, n),dequy(m, n-1));
}
int a[50][50];
void quyhoachdong(int m, int n) {
  for (int i = 0; i <= n; i++) a[0][i] = 0;
  for (int i = 1; i <= m; i++) {
    a[i][0] = 0;
    for (int j = 1; j <= n; j++)
      if (w[i-1] == s[j-1]) a[i][j] = 1 + a[i-1][j-1];
      else a[i][j] = max(a[i-1][j], a[i][j-1]);
  }
}
void inA(int m, int n) {
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }
}
void inXauCon(int m, int n) {
  if ((m == 0) || (n == 0)) return;
  if (w[m-1] == s[n-1]) {
    inXauCon(m-1, n-1);
    cout << w[m-1];
    return;
  }
  if (a[m][n] == a[m-1][n]) inXauCon(m-1, n);
  else inXauCon(m, n-1);
}

int main() {
  cout << "W = "; getline(cin, w);
  cout << "S = "; getline(cin, s);
  //tính dộ dài dãy con chung bằng đệ quy
  cout << "Do dai day con chung dai nhat = " << dequy(w.length(), s.length()) << endl;
  //tính bằng quy hoạch động
  quyhoachdong(w.length(), s.length());
  inA(w.length(), s.length());
  //truy vết
  inXauCon(w.length(), s.length());
}