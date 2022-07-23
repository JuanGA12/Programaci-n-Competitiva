#include <iostream>

using namespace std;
const int N = 20;
int cnt = 0;
char board[N][N];
int col[N];
int diag1[N];
int diag2[N];

void recursive(int n){
    if(n == 8){
        cnt++;
        return;
    }
    for(int i=0;i<8;i++){
        if(col[i] or diag1[i+n] or diag2[i-n+7] or
           board[n][i] == '*'
        ){continue;}
        col[i] = diag1[i+n] = diag2[i-n+7] = 1;
        recursive(n+1);
        col[i] = diag1[i+n] = diag2[i-n+7] = 0;
    }
}
int main(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin>>board[i][j];
        }
    }
    recursive(0);
    cout<<cnt<<endl;
}