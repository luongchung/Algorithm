#include<iostream>
using namespace std;
string s1="AQSRWRTXEDDY",s2="AEQWSRRSFXTGDD";
int A[1000][1000];
char vt[1000][1000];
void quyhoachdong() {
    for (int j = 0; j <= s1.length(); ++j) A[0][j] = 0;
    for (int i = 1; i <= s2.length(); ++i) {
        A[i][0] = 0;
        for (int j = 1; j <= s1.length(); ++j) {
            if (s2[i - 1] == s1[j - 1]) {
                A[i][j] = A[i - 1][j - 1] + 1;
                vt[i][j] = 'c';

            } else {
                A[i][j] = max(A[i - 1][j], A[i][j - 1]);
                vt[i][j] = (A[i - 1][j] > A[i][j - 1]) ? 'l' : 't';
            }
        }
    }
}

void hienbang(){
    cout<<endl;
    for (int i = 0; i <= s2.length(); ++i) {
        for (int j = 0; j <=s1.length(); ++j) {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 0; i <= s2.length(); ++i) {
        for (int j = 0; j <=s1.length(); ++j) {
            cout<<vt[i][j]<<" ";
        }
        cout<<endl;
    }
}
void truyvet(int i,int j){
    if(i<1) return;
    if(j<1) return;
    if(vt[i][j]=='c'){
        truyvet(i-1,j-1);
        cout<<s2[i-1];
    } else if(vt[i][j]=='l'){
        truyvet(i-1,j);
    } else{
        truyvet(i,j-1);
    }
}
int main(){
    quyhoachdong();
    hienbang();
    cout<<endl<<"Ket qua: ";
    truyvet(s2.length(),s1.length());
}
