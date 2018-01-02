#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int n=6;
int A[n][n]={
    {1,1,0,1,0,0},
    {1,1,1,0,0,0},
    {0,1,1,1,0,0},
    {1,0,1,1,0,0},
    {0,0,0,0,1,1},
    {0,0,0,0,1,1},
};
queue<int> hangdoi;
int B[n],D[n],F[n],t=0;
void DFS_VISIT(int u,vector<int> &tmp){
    B[u]=1;
    for (int i = 0; i < n; ++i) {
        if(A[u][i]==1 && B[i]==0){
            tmp.push_back(i);
            DFS_VISIT(i,tmp);
        }
    }
    B[u]=-1;
}
void BFS_VISIT(int u){
    B[u]=1;
    D[u]=0;
    hangdoi.push(u);
    int tmp;
    while (!hangdoi.empty()){
        tmp=hangdoi.front();
        hangdoi.pop();
        cout<<"Duyet dinh: "<<tmp+1<<endl;
        for (int i = 0; i < n; ++i) {
            if(A[tmp][i]==1 && B[i]==0){
                B[i]=1;
                D[i]=D[u]+1;
                cout<<"Them đinh "<<i+1<<" vào hang doi."<<endl;
                hangdoi.push(i);
            }
        }
        B[tmp]=-1;
    }
}
void DFS_VISIT(int u){
    t++;
    D[u]=t;
    B[u]=1;
    cout<<"Duyet dinh: "<<u<<endl;
    cout<<"Thoi gian bat dau dinh ["<<u<<"]="<<D[u]<<endl;
    for (int i = 0; i < n; ++i) {
        if(A[u][i]==1 && B[i]==0){
            DFS_VISIT(i);
        }
    }
    B[u]=-1;
    t++;
    F[u]=t;
    cout<<"Thoi gian ket thuc dinh ["<<u<<"]= "<<F[u]<<endl;

}
void TIM_ALL_THANH_PHAN_LIEN_THONG(){

    for (int i = 0; i < n; ++i) {
        if(B[i]==0){
            vector<int> tmp;
            tmp.push_back(i);
            DFS_VISIT(i,tmp);
            cout<<"lien thong:";
            for (int k:tmp) {
                cout<<k<<" ";
            }
            cout<<endl;
        }

    }
}
void khoitao(){
    for (int i = 0; i < n; ++i) {B[i]=0;F[i]=-1;D[i]=-1;}
}
int main() {
    khoitao();
    TIM_ALL_THANH_PHAN_LIEN_THONG();
    //duyệt theo chiều sâu
    DFS_VISIT(0);
    //duyệt theo chiều rộng
    BFS_VISIT(0);
    return 0;
}