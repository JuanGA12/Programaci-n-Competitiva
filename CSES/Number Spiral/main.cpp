#include <iostream>

typedef long long int lli;

using namespace std;

int main(){
    lli t, y,x;
    cin>>t;
    for(int i = 0; i<t; i++){
        cin>>y>>x;
        lli lvl = max(y,x);
        lli point = (lvl*lvl) - lvl + 1;
        lli offset = abs(x-y); 
        if(lvl%2==0){
            if(y<x){
                cout<<point-offset<<endl;
            }else{
                cout<<point+offset<<endl;
            }
        }else{
            if(y<x){
                cout<<point+offset<<endl;
            }else{
                cout<<point-offset<<endl;
            }
        }

    }
    return 0;
}