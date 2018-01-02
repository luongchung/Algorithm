#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s1="AABAB",s2="ABBBAB";
int A[1000][1000];
void quyhoachdong(string s1,string s2){
    for (int i=1; i<=s1.length(); i++)A[0][i]=i;
    for (int j=1; j<=s2.length(); j++)A[j][0]=j;
    A[0][0]=0;
    int tmp;
    for (int i=1; i<=s1.length(); i++) {
        for (int j=1; j<=s2.length(); j++) {
            tmp=1;
            if(s1[i-1]==s2[j-1]) tmp=0;
            A[i][j]=min(A[i-1][j-1]+tmp,min(A[i-1][j]+1,A[i][j-1]+1));
        }
    }
}
int main(){
    quyhoachdong(s1,s2);
    cout<<"Ket qua: "<<A[s1.length()][s2.length()]<<endl;
    return 0;
}
