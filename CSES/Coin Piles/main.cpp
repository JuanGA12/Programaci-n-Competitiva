#include <iostream>
#include <bits/stdc++.h>
typedef long long int lli;

using namespace std;
lli t;
int a;
int b;

int main(){
    cin>>t;
    while(t--){
        cin>>a;
        cin>>b;
        if( (2*a-b>=0) and (2*b-a>=0) and ((2*a-b)%3 == 0) and ((2*b-a)%3 == 0) ){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
   }
}