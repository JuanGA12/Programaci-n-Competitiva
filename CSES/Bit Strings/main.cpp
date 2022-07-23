#include <iostream>
//#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
const int mod = 1e9+7;

lli recursive(int n){
    if(n == 1){
        return 2;
    }else{
        lli aux;
        if(n%2==0){
            aux = recursive(n/2);
            return (aux*aux) %mod;
        }else{
            aux = recursive((n-1)/2);
            return (2*aux*aux) %mod;
        }
    }
}
lli n;
int main (){
    cin >> n;
    cout<<recursive(n)%mod<<endl;
    return 0;
}