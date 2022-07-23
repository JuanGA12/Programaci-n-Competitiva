#include <iostream>
typedef long long int lli;

using namespace std;

int main(){

    lli size = lli(0), moves = lli(0), prev, curr;

    cin>>size>>prev;
    for(;size - 1 > 0;--size){
        cin>>curr;
        if(curr<prev){
            moves+=prev-curr;
        }else{
            prev = curr;
        }
    }
    cout<<moves<<endl;
}