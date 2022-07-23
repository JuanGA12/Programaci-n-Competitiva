#include <iostream>

using namespace std;

int main(){
    string dna;
    cin >> dna;
    long long int ans = 0;
    long long int cnt = 1; 
    for(long long i = 1; i < (long long)dna.size(); i++){
        if(dna[i] == dna[i-1]){
            cnt++;
        }else{
            ans = max(ans,cnt);
            cnt = 1;
        }
    }
    cout<<max(ans,cnt)<<endl;
    return 0;
}