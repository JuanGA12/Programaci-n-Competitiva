#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, int from, int to){
    if(n == 0){
        return;
    }else{
        int mid = 6 - from - to;
        hanoi(n-1,from,mid);
        cout<<from<<" "<<to<<endl;
        hanoi(n-1,mid,to);
    }
}

int main(){
    int n;
    cin >> n;
    cout << pow(2,n)-1<<"\n";
    hanoi(n,1,3);
    return 0;
}