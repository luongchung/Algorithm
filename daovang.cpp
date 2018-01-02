//// cho các ô giống mảng A, làm sao đi từ trái sang phải mà nhận dược nhiều vàng nhất
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int n=5,m=7;
int a[n][m] =  {
  { 5, 6, 7, 3, 2, 4, 5 },
  { 4, 1,-9, 3, 3, 5, 2 },
  { 4, 2, 3, 5, 4, 4, 3 },
  { 7, 7, 7, 7, 1, 3, 2 },
  { 2, 3, 4, 2, 2, 4, 3 },
};
int b[1000][1000];
void quyhoachdong(){
  for (int i=0;i<n;i++){
    b[i][0]=a[i][0];
  }
  for (int i=1; i<m; i++) {
    b[0][i]=max(b[0][i-1],b[1][i-1])+a[0][i];
    for (int j=1;j<n-1;j++){
      b[j][i]=max(b[j][i-1],max(b[j-1][i-1],b[j+1][i-1]))+a[j][i];
    }
    b[n-1][i]=max(b[0][i-1],b[n-2][i-1])+a[n-1][i];
  }
}
void hienthibang(){
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout<<b[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main(){
  quyhoachdong();
  //hien thi bang
  hienthibang();
  //tinh kq
  int max=0;
  for (int i = 0; i <n ; ++i) max=(max<b[i][m-1])?b[i][m-1]:max;
  //hien thi kq
  cout<<"Ket qua: "<<max;
  return 0;
}