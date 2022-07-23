#include <iostream>
#include <vector>
#include <string>
//#include <bits/stdc++.h>

const int N = 1e9;
typedef long long int lli;
using namespace std;

lli n;
std::string sol;
bool b [N];
void recursive(lli i){
    if (i == 0){
        cout<<sol<<endl;
    }else{
        sol.push_back(!b[i]? '0':'1');
        recursive(i-1);
        sol.pop_back();
        sol.push_back(!b[i]? '1':'0');
        recursive(i-1);
        sol.pop_back();
        b[i]=!b[i];
    }
}
int main(){
    cin>>n;
    recursive(n);
}