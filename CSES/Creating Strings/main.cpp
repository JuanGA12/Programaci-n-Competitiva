#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char,int>m;
string sol;
int n;
long long int cont;
void recursive(int i){
    if (i == 0){
        cout <<sol<<endl;
    }else{
        for(auto &e:m){
            char c = e.first;
            int t = e.second;
            if(t>0){
                sol.push_back(c);
                m[c]--;
                recursive(i-1);
                sol.pop_back();
                m[c]++;
            }
        }
    }
}
long long int fact(int k){
    return(k==0)?1:k*fact(k-1);
}
long long total = 1;
int main(){
    string s;
    cin >> s;
    n = s.length();
    for(auto &i:s){
        m[i]++;
    }
    for(auto &i:m){
        total *=fact(i.second);
    }
    cout<<fact(n)/total<<endl;
    recursive(n);
    return 0;
}