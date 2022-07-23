#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e9; 
int sum,n,ans,total;
int weight[N];

// void recursive(int b){
//     if(b == n) ans = min(ans,abs(2*sum-total));
//     else{
//         recursive(b+1);
//         sum+=weight[b];
//         recursive(b+1);
//         sum-=weight[b];
//     }
// }
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin>>weight[i];
        total += weight[i];
    }
    ans=total+100;
    //recursive(0);
    for(int i = 0; (1<<n); i++){
        sum = 0;
        for(int j = 0; j < n;j++){
            if( ((i>>j) & 1) == 1){
                sum+= weight[j];
            }
        }
        ans = min(ans,abs(2*sum-total));
    }
    cout<<ans<<endl;
}