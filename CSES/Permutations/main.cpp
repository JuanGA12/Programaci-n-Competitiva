#include<iostream>

typedef long long int lli;
using namespace std;

int main(){
    lli n;
    cin>>n;
    if(n==2 or n==3){
        cout<<"NO SOLUTION"<<endl;
    }else{
        for(int i=2; i<=n; i+=2){
            cout<<i<<" ";
        }
        for(int i=1; i<=n; i+=2){
            cout<<i<<" ";
        }
    }
}